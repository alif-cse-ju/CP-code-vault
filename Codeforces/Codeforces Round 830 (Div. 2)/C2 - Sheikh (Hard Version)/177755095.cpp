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
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
 ll a[M],sum[M],xr[M];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n,q;cin >> n >> q;
        ordered_set<int>nonZero;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i], sum[i]=sum[i-1]+a[i], xr[i]=xr[i-1]^a[i];
            if(a[i])nonZero.insert(i);
        }
        while(q--)
        {
            int l,r;cin >> l >> r;
            int L=l, R=r, len=r-l+1;
            ll ans=(sum[r]-sum[l-1]) - (xr[r]^xr[l-1]);
             if(!ans)
            {
                cout << l << ' ' << l << '\n';
                continue;
            }
             vector<int>pre,suf;
             int small=nonZero.order_of_key(l);
            for(int i=0;i<35  &&  small < (int)nonZero.size();i++)
            {
                int x=*(nonZero.find_by_order(small));
                if(x > r)break;
                ++small, pre.emplace_back(x);
            }
             int boro=nonZero.order_of_key(r+1)-1;
            for(int i=0;i<35  &&  boro >= 0;i++)
            {
                int x=*(nonZero.find_by_order(boro));
                if(x < l)break;
                --boro, suf.emplace_back(x);
            }
            reverse(suf.begin(),suf.end());
             for(int &it1 : pre)
            {
                for(int &it2 : suf)
                {
                    if(it1 > it2)continue;
                    if((sum[it2]-sum[it1-1]) - (xr[it2]^xr[it1-1])  >  ans)
                    {
                        ans=(sum[it2]-sum[it1-1]) - (xr[it2]^xr[it1-1]);
                        len=it2-it1+1, L=it1, R=it2;
                    }
                    else if((sum[it2]-sum[it1-1]) - (xr[it2]^xr[it1-1])  ==  ans)
                    {
                        if(it2-it1+1 < len)len=it2-it1+1, L=it1, R=it2;
                    }
                }
            }
            cout << L << ' ' << R << '\n';
        }
    }
    return 0;
}