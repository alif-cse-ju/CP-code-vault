#pragma GCC optimize("Ofast")
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
const int M=3e5+5;
const int N=1e6+5;
const int mod=1e9+7;
 const int mx = 2e3+5;
 ll a[mx],b[mx];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    ll sumA=0;
    for(int i=1;i<=n;i++)cin >> a[i], sumA+=a[i];
    int m;cin >> m;
    ll sumB=0;
    for(int i=1;i<=m;i++)cin >> b[i], sumB+=b[i];
    ll ans=abs(sumA-sumB);
    vector<pair<int,int>>idx;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ll tmp=abs((sumA-a[i]+b[j]) - (sumB-b[j]+a[i]));
            if(tmp < ans)ans=tmp, idx.clear(), idx.emplace_back(i,j);
        }
    }
    vector<tuple<ll,int,int>>ost;
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)ost.emplace_back(make_tuple(b[i]+b[i]+b[j]+b[j],i,j));
    }
    sort(ost.begin(), ost.end());
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ll lagbe=sumB+a[i]+a[i]+a[j]+a[j]-sumA;
            int id=lower_bound(ost.begin(),ost.end(),make_tuple(lagbe,0,0))-ost.begin();
            if(id)
            {
                auto [v,i1,j1]=ost[id-1];
                if(abs(lagbe-v) < ans)
                {
                    ans=abs(lagbe-v), idx.clear();
                    idx.emplace_back(i,i1), idx.emplace_back(j,j1);
                }
            }
            if(id < (int)ost.size())
            {
                auto [v,i1,j1]=ost[id];
                if(abs(lagbe-v) < ans)
                {
                    ans=abs(lagbe-v), idx.clear();
                    idx.emplace_back(i,i1), idx.emplace_back(j,j1);
                }
            }
        }
    }
    cout << ans << '\n' << (int)idx.size() << '\n';
    for(auto [l,r] : idx)cout << l << ' ' << r << '\n';
    return 0;
}