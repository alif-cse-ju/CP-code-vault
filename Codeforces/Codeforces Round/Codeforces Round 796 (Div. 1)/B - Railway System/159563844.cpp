#pragma GCC optimize("Ofast")
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
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    vector<pair<int,int>>edges;
    string s="";
    for(int i=0;i<m;i++)s += "0";
    for(int i=1;i<=m;i++)
    {
        s[i-1]='1';
        cout << "? " << s << endl;
        s[i-1]='0';
        int x;cin >> x;
        edges.emplace_back(x,i);
    }
    sort(edges.begin(),edges.end());
    int ans=0,prev=0;
    for(int i=0;i<m;i++)
    {
        s[edges[i].second-1]='1';
        cout << "? " << s << endl;
        int x;cin >> x;
        if(x == prev+edges[i].first)ans += edges[i].first;
        prev=x;
    }
    cout << "! " << ans << endl;
    return 0;
}