#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,ans,cnt[3];
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt[0]=cnt[1]=cnt[2]=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            ++cnt[x%3];
        }
        for(i=0;i<3;i++)cnt[i]-=(n/3);
        ans=0;
        if(cnt[0] > 0)ans+=cnt[0],cnt[1]+=cnt[0],cnt[0]=0;
        if(cnt[1] > 0)ans+=cnt[1],cnt[2]+=cnt[1],cnt[1]=0;
        if(cnt[2] > 0)ans+=cnt[2],cnt[0]+=cnt[2],cnt[2]=0;
        if(cnt[0] > 0)ans+=cnt[0],cnt[1]+=cnt[0],cnt[0]=0;
        if(cnt[1] > 0)ans+=cnt[1],cnt[2]+=cnt[1],cnt[1]=0;
        if(cnt[2] > 0)ans+=cnt[2],cnt[0]+=cnt[2],cnt[2]=0;
        cout << ans << '\n';
    }
    return 0;