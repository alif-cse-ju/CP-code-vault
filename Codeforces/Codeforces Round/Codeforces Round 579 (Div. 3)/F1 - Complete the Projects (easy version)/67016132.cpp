#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,n,x,y,cur;
    cin >> n >> cur;
    V<PII>pos,neg;
    for(i=0;i<n;i++)
    {
        cin >> x >> y;
        if(y >= 0)pos.PSB({x,y});
        else neg.PSB({x,y});
    }
    sort(pos.B,pos.E);
    for(i=0;i<(int)pos.SZ;i++)
    {
        x=pos[i].FI,y=pos[i].SE;
        if(cur < x)
        {
            cout << "NO";
            return 0;
        }
        cur+=y;
    }
    int temp;
    bool flag;
    while(!neg.EM)
    {
        flag=true;
        for(i=0;i<(int)neg.SZ;i++)
        {
            temp=0;
            for(j=i-1;j>=0;j--)temp+=neg[j].SE;
            for(j=i+1;j<(int)neg.SZ;j++)temp+=neg[j].SE;
            if(cur+temp >= neg[i].FI  &&  cur+temp+neg[i].SE >= 0)
            {
                neg.erase(neg.B+i);
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}