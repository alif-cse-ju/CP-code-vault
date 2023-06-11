#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int ans[N];
bool mark[N];
void Sieve()
{
    int i,j;
    mark[1]=1;
    for(i=4;i<N;i+=2)mark[i]=1;
    for(i=3;i*i<=N;i+=2)
    {
        if(!mark[i])
        {
            for(j=i*i;j<N;j+=2*i)mark[j]=1;
        }
    }
    for(i=1;i<N;i++)
    {
        if(mark[i])ans[i]=ans[i-1]+1;
        else ans[i]=min(ans[i-1],ans[i-2])+1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,r,t;
    Sieve();
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        if(l+1 == r)cout << "1\n";
        else cout << ans[r]-ans[l]+(mark[l]  &&  !mark[l+1]  &&  mark[l+2]) << '\n';
    }
    return 0;
}