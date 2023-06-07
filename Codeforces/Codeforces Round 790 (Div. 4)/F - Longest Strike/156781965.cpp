#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
            int k,n;cin >> n >> k;
            set<int>st;
            map<int,int>cnt;
            for(int i=0;i<n;i++)
            {
                    int x;cin >> x;
                    ++cnt[x];
                    if(cnt[x] >= k)st.insert(x);
            }
            if(st.empty())cout << "-1\n";
            else
            {
                    vector<int>v;
                    for(int it : st)v.emplace_back(it);
                    int cur=0,ii=0,l,mx=-1,r;
                    for(int i=0;i<(int)v.size();i++)
                    {
                            if(v[ii]+cur == v[i])++cur;
                            else
                            {
                                    if(cur > mx)mx=cur,l=ii,r=i-1;
                                    cur=1, ii=i;
                            }
                    }
                    if(cur > mx)l=ii, r=(int)v.size()-1;
                    cout << v[l] << ' ' << v[r] << '\n';
            }
    }
    return 0;
}