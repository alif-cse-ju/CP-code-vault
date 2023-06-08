#include<bits/stdc++.h>
 using namespace std;
 const int N=2e5+5;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,t,x,ans,cnt,mn;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ans=cnt=0,mn=INT_MAX;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin >> x;
                ans+=abs(x);
                cnt+=(x < 0);
                mn=min(mn,abs(x));
            }
        }
        if(cnt & 1)ans-=2*mn;
        cout << ans << '\n';
    }
    return 0;
}