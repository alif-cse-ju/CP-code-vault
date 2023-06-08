#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int cnt[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,mx=0,n,r;
    set<int>st;
    vector<pair<int,int>>v;
    cin >> n;
    while(n--)
    {
        cin >> l >> r;
        v.emplace_back(l,r);
        st.insert(l),st.insert(r);
    }
    map<int,int>mp;
    i=0;
    for(int it : st)mp[it]=++i;
    for(auto [l,r] : v)++cnt[mp[l]],--cnt[mp[r]];
    for(i=1;i<N;i++)
    {
        cnt[i]+=cnt[i-1];
        if(cnt[i] > mx)n=i,mx=cnt[i];
    }
    for(int it : st)
    {
        if(mp[it] == n)
        {
            cout << it;
            break;
        }
    }
    cout << ' ' << mx;
    return 0;
}