#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
const int N=1e3+5;
const int mod=1e9+7;
int a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        cnt=0;
        for(i=2;i<=n;i++)cnt+=(a[i] < a[i-1]);
        vector<pair<int,pair<int,int>>>ans;
        if(cnt > n/2)
        {
            cnt=(1 << 30)-1;
            ans.push_back({4,{1,cnt}});
            for(i=1;i<=n;i++)a[i] ^= cnt;
        }
        for(i=2;i<=n;i++)
        {
            if(a[i] < a[i-1])ans.push_back({2,{i,a[i-1]-a[i]}});
        }
        cout << (int)ans.size() << '\n';
        for(auto it : ans)cout << it.first << ' ' << it.second.first << ' ' << it.second.second << '\n';
    }
    return 0;
}
//