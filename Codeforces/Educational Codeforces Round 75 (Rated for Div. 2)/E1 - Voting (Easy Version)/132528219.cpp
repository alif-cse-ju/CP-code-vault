#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=5e3+5;
const int N=1e6+5;
const int mod=1e9+7;
vector<int>v[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans;
    int baki,i,lagbe,m,n,nichi,p,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0;i<n;i++)v[i].clear();
        for(i=0;i<n;i++)
        {
            cin >> m >> p;
            v[m].emplace_back(p);
        }
        multiset<int>mst;
        ans=nichi=0, baki=n;
        for(i=n-1;i>=0;i--)
        {
            baki -= (int)v[i].size();
            lagbe=i-baki;
            for(int it : v[i])mst.insert(it);
            while(nichi < lagbe)
            {
                ++nichi;
                ans += *(mst.begin());
                mst.erase(mst.begin());
            }
        }
        cout << ans << '\n';
    }
    return 0;
}