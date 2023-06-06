#include<bits/stdc++.h>

using namespace std;

const int N=2e6+5;
const int mod=1e9+7;

int box[55];
bool mark[55];
pair<int,int>baggage[55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,n,q,r,ans;
    cin >> n >> m >> q;
    for(i=1;i<=n;i++)cin >> baggage[i].second >> baggage[i].first;
    for(i=1;i<=m;i++)cin >> box[i];
    sort(baggage+1,baggage+n+1);
    reverse(baggage+1,baggage+n+1);
    while(q--)
    {
        cin >> l >> r;
        ans=0;
        for(i=1;i<=n;i++)mark[i]=0;
        vector<int>v;
        for(i=1;i<l;i++)v.emplace_back(box[i]);
        for(i=r+1;i<=m;i++)v.emplace_back(box[i]);
        sort(v.begin(),v.end());
        for(int it : v)
        {
            for(i=1;i<=n;i++)
            {
                if(!mark[i]  &&  baggage[i].second <= it)
                {
                    ans+=baggage[i].first;
                    mark[i]=1;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
//