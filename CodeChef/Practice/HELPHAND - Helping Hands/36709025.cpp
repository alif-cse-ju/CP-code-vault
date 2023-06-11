#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=1e6;
int cnt[N+2];
bool mark[N+2];
void PreCal()
{
    int i,j,rt=1e3;
    for(i=4;i<=N;i+=2)mark[i]=1;
    for(i=3;i<=rt;i+=2)
    {
        if(!mark[i])
        {
            for(j=i*i;j<=N;j+=2*i)mark[j]=1;
        }
    }
    for(i=2;i<=N;i++)cnt[i]=cnt[i-1]+(!mark[i]);
}
int main()
{
    FAST();
    PreCal();
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n < 5)cout << n-1 << '\n';
        else cout << n+cnt[n]-3 << '\n';
    }
    return 0;
}