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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin >> n >> m;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a.begin(),a.end());
    string s;
    map<string,int>cnt;
    while(m--)cin >> s,++cnt[s];
    priority_queue<int>pq;
    for(auto [s,x] : cnt)pq.emplace(x);
    int i=0,j=n,mn=0,mx=0;
    while(!pq.empty())
    {
        int x=pq.top();
        pq.pop();
        mn+=a[i++]*x,mx+=a[--j]*x;
    }
    cout << mn << ' ' << mx;
    return 0;
}