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
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=998244353;
struct query
{
    int k,l,r,id;
}q[M];
int l,magic,n,r,a[M],ans[M],cnt[M],cntCnt[M];
///Mo part
bool Compare(query &x,query &y)
{
    int a=x.l/magic,b=y.l/magic;
    if(a == b)return x.r < y.r;
    return a < b;
}
void Add(int x)
{
    x=a[x], ++cnt[x], ++cntCnt[cnt[x]];
}
void Reduce(int x)
{
    x=a[x], --cntCnt[cnt[x]], --cnt[x];
}
///Mo part
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int qq;cin >> n >> qq;
        int dist=0; map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int x;cin >> x;
            if(mp.find(x) == mp.end())a[i]=mp[x]=++dist;
            else a[i]=mp[x];
        }
        magic=sqrt(qq);
        for(int i=0;i<qq;i++)
        {
            int l,r,k;cin >> l >> r >> k;
            q[i].k=k, q[i].l=l-1, q[i].r=r-1, q[i].id=i;
        }
        sort(q,q+qq,Compare), l=0, r=-1;
        for(int i=1;i<=n;i++)cnt[i]=cntCnt[i]=0;
        for(int i=0;i<qq;i++)
        {
            while(l > q[i].l)Add(--l);
            while(r < q[i].r)Add(++r);
            while(l < q[i].l)Reduce(l++);
            while(r > q[i].r)Reduce(r--);
            ans[q[i].id]=cntCnt[1] - cntCnt[q[i].k+1];
        }
        for(int i=0;i<qq;i++)cout << ans[i] << '\n';
    }
    return 0;
}