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
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
int a[M],nodeCnt,_tree[20*M][2];
void Insert(const int& x)
    int b,cur=0,i;
    for(i=16;i>=0;i--)
    {
        b=(x >> i) & 1;
        if(!_tree[cur][b])_tree[cur][b]=++nodeCnt;
        cur=_tree[cur][b];
    }
int FindMax(const int& x)
    int ans=0,b,cur=0,i;
    for(i=16;i>=0;i--)
    {
        b=(x >> i) & 1;
        if(_tree[cur][1-b])ans|=(1 << i), cur=_tree[cur][1-b];
        else cur=_tree[cur][b];
    }
    return ans;
}
 int FindMin(const int& x)
{
    int ans=0,b,cur=0,i;
    for(i=16;i>=0;i--)
    {
        b=(x >> i) & 1;
        if(_tree[cur][b])cur=_tree[cur][b];
        else ans|=(1 << i), cur=_tree[cur][1-b];
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,mn,mx,n,r,t,x;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        for(i=0;i<=nodeCnt;i++)_tree[i][0]=_tree[i][1]=0;
        n=r-l+1, nodeCnt=0;
        for(i=1;i<=n;i++)cin >> a[i], Insert(a[i]);
        for(i=1;i<=n;i++)
        {
            x=(a[i] ^ l);
            mn=FindMin(x);
            mx=FindMax(x);
            if(mn == l  &&  mx == r)
            {
                cout << x << '\n';
                break;
            }
        }
    }
    return 0;
}