#pragma GCC optimize("Ofast")

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

const int M=3e5+5;
const int N=1e6+5;
const int mod=998244353;

int a[M];
bool visited[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    for(int i=1;i<=m+n;i++)cin >> a[i];
    int ans=0,cntB=0,cntW=0;
    for(int i=1;i<=m+n;i++)
    {
        if(!visited[i])
        {
            int sz = 0, j = i;
            bool allB=1, allW=1;
            while(!visited[j])
            {
                ++sz, visited[j]=1;
                allB &= (j <= n), allW &= (j > n);
                j = a[j];
            }
            ans += sz-1;
            if(sz > 1)cntB += allB, cntW += allW;
        }
    }
    cout << ans+(max(cntB, cntW) << 1);
    return 0;
}