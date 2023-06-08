#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int ans[M],posA[M],posB[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok;
    int i,ia,ib,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<int,int>>va,vb;
        for(i=0;i<n;i++)cin >> x, va.emplace_back(x,i);
        for(i=0;i<n;i++)cin >> x, vb.emplace_back(x,i);
        sort(va.begin(),va.end());
        sort(vb.begin(),vb.end());
        for(i=0;i<n;i++)posA[va[i].second]=posB[vb[i].second]=i;
        ia=ib=n-1;
        for(i=0;i<n;i++)ans[i]=0;
        while(true)
        {
            ok=0;
            while(ia < (int)va.size())
            {
                i=va.back().second, va.pop_back();
                ans[i]=ok=1, ib=min(ib,posB[i]);
            }
            while(ib < (int)vb.size())
            {
                i=vb.back().second, vb.pop_back();
                ans[i]=ok=1, ia=min(ia,posA[i]);
            }
            if(!ok)break;
        }
        for(i=0;i<n;i++)cout << ans[i];
        cout << '\n';
    }
    return 0;
}