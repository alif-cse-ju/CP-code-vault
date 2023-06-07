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
const int M=1e5+5;
const int N=2e6+5;
const int mod=998244353;
bool mark[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int k,n;cin >> n >> k;
        k=min(k,n);
        map<int,int>cnt;
        for(int i=0;i<=n;i++)mark[i]=0;
        for(int i=1;i<=n;i++)
        {
            int x;cin >> x;
            ++cnt[x];
            if(x <= n)mark[x]=1;
        }
        int l,kk=k;
        for(l=0; ;l++)
        {
            if(!mark[l])
            {
                if(!kk)break;
                --kk;
            }
        }
        priority_queue<int>pq;
        for(auto [x,y] : cnt)
        {
            if(x >= l)pq.emplace(-y);
        }
        while(!pq.empty())
        {
            int x=-pq.top();
            if(x <= k)k-=x, pq.pop();
            else break;
        }
        cout << (int)pq.size() << '\n';
    }
    return 0;
}