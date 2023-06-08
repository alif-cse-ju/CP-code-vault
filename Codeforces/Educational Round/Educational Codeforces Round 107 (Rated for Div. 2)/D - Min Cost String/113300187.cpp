#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
void Solve(int& n,const int& k)
    int i,j;
    for(i=0;i<k && n;i++)
    {
        --n,cout << (char)('a'+i);
        for(j=i+1;j<k  &&  n > 1;j++,n-=2)cout << (char)('a'+i) << (char)('a'+j);
        if(n  &&  j < k)--n,cout << (char)('a'+i);
    }
int main()
    FAST();
    int k,n;
    cin >> n >> k;
    while(n)Solve(n,k);
    return 0;