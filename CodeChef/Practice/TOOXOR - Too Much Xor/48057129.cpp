#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <map>
using namespace std; 
  long long readInt(long long l,long long r,char endd){
    long long x=0;
    int cnt=0;
    int fi=-1;
    bool is_neg=false;
    while(true){
        char g=getchar();
        if(g=='-'){
            assert(fi==-1);
            is_neg=true;
            continue;
        }
        if('0'<=g && g<='9'){
            x*=10;
            x+=g-'0';
            if(cnt==0){
                fi=g-'0';
            }
            cnt++;
            assert(fi!=0 || cnt==1);
            assert(fi!=0 || is_neg==false);
                        assert(!(cnt>19 || ( cnt==19 && fi>1) ));
        } else if(g==endd){
            if(is_neg){
                x= -x;
            }
            assert(l<=x && x<=r);
            return x;
        } else {
            assert(false);
        }
    }
}
string readString(int l,int r,char endd){
    string ret="";
    int cnt=0;
    while(true){
        char g=getchar();
        assert(g!=-1);
        if(g==endd){
            break;
        }
        cnt++;
        ret+=g;
    }
    assert(l<=cnt && cnt<=r);
    return ret;
}
long long readIntSp(long long l,long long r){
    return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
    return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
    return readString(l,r,'\n');
}
string readStringSp(int l,int r){
    return readString(l,r,' ');
}
struct OP{
    int i, j, k;
    OP(int i, int j, int k):i(i), j(j), k(k){}
};
bool valid(vector<int> A, vector<OP> op){
    int N = (int)A.size();
    if(N <= 2)return true;
    for(auto x:op){
        assert(x.i != x.j && x.j != x.k && x.i != x.k);
        A[x.k] = A[x.i]^A[x.j];
    }
    bool val = true;
    for(int i = 1; i< N-1; i++)val &= (A[i-1]^A[i]^A[i+1]) == A[i];
    for(int i = 0; i< N-1; i++)val &= (A[i]^A[i+1]) > 0;
    return val;
}
int main(){
        int T = readIntLn(1, 1000);
    int sumN = 0;
    int MX = (1<<30)-1;
    while(T-->0){
        int N = readIntLn(1, 10000);
        sumN += N;
        assert(sumN <= 20000);
        vector<int> A;
        for(int i = 0; i< N; i++){
            int x;
            if(i+1 < N)x = readIntSp(0, MX);
            else x = readIntLn(0, MX);
            A.push_back(x);
        }
        vector<OP> op;
        bool impossible = false;
        if(N == 1){}
        else if(N == 2){
            if(A[0] == A[1])
                impossible = true;
        }else if(N == 3){
            if(A[1] == 0){
                if(max(A[0], A[2]) == 0)impossible = true;//all zeros
                else{
                    //Middle element zero, making other two equal
                    if(A[0] > 0)op.push_back(OP(0,1,2));
                    else op.push_back(OP(2,1,0));
                }
            }else if(A[0] == A[2]){
                //Either all equal > 0, or already good
                if(A[0] != 0)op.push_back(OP(0,2,1));//making middle element 0
            }else impossible = true;
        }else{
            bool allzero = true;
            for(int x:A)allzero &= x == 0;
            if(allzero)impossible = true;
            else{
                bool even = true, odd = true;
                for(int i = 0; i< N; i+= 2)even &= A[i] == A[0];
                for(int i = 1; i< N; i+= 2)odd &= A[i] == A[1];
                if(even && odd){
                    if(A[0] == A[1]){
                        if(A[0] == 0)impossible = true;
                        else{
                            for(int i = 1; i< N; i += 2)op.push_back(OP(0, 2, i));
                        }
                    }
                }else if(!even){
                    int p = -1;
                    for(int i = 2; i< N; i+= 2)if(A[i] != A[0])p = i;
                    assert(p != -1);
                    for(int i = 1; i< N; i+= 2)op.push_back(OP(0, p, i));
                    for(int i = 0; i< N; i+= 2)op.push_back(OP(1, 3, i));
                }else if(!odd){
                    int p = -1;
                    for(int i = 3; i< N; i += 2)if(A[i] != A[1])p = i;
                    assert(p != -1);
                    for(int i = 0; i< N; i+= 2)op.push_back(OP(1, p, i));
                    for(int i = 1; i< N; i+= 2)op.push_back(OP(0, 2, i));
                }else assert(false);
            }
        }
        if(impossible)cout<<-1<<endl;
        else{
            assert(valid(A, op));
            cout<<op.size()<<endl;
            for(auto x:op)cout<<(1+x.i)<<" "<<(1+x.j)<<" "<<(1+x.k)<<endl;
        }
    }
    assert(getchar()==-1);
    cerr<<"SUCCESS\n";
}