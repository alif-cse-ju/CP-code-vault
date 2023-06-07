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
const int mod=998244353;
struct Node
    int cnt,child[2];
bitTree[20*M];
bool visited[M];
int curNode,xorUpdate;
void Insert(const int& x)
    int b,cur=0,i;
    for(i=19;i>=0;i--)
    {
        b=(x >> i) & 1;
        if(!bitTree[cur].child[b])bitTree[cur].child[b]=++curNode;
        cur=bitTree[cur].child[b], ++bitTree[cur].cnt;
    }
}
 int Query()
{
    int ans=0,b,cur=0,i;
    for(i=19;i>=0;i--)
    {
        b=(xorUpdate >> i) & 1;
        if(!bitTree[cur].child[b])return ans;
        if(bitTree[bitTree[cur].child[b]].cnt == (1 << i))ans += (1 << i), b ^= 1;
        cur=bitTree[cur].child[b];
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x;
    cin >> n >> m;
    while(n--)
    {
        cin >> x;
        if(!visited[x])Insert(x), visited[x]=1;
    }
    while(m--)
    {
        cin >> x, xorUpdate ^= x;
        cout << Query() << '\n';
    }
    return 0;
}