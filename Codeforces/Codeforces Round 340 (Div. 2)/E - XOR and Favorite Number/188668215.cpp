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

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;

const int mx = (1 << 20);

struct query
{
    int l,r,id;
}q[M];
ll ans[M],tmp;
int k,l,magic,n,r,a[M],cnt[mx];

///Mo part
bool Compare(query &x,query &y)
{
    int a=x.l/magic,b=y.l/magic;
    if(a == b)return x.r < y.r;
    return a < b;
}

void Add(int x)
{
    x=a[x], tmp+=cnt[k^x], ++cnt[x];
}

void Reduce(int x)
{
    x=a[x], --cnt[x], tmp-=cnt[k^x];
}
///Mo part

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,qq;cin >> n >> qq >> k;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)a[i]=(a[i-1] ^ a[i]);
    magic=sqrt(qq);
    for(int i=0;i<qq;i++)
    {
        int l,r;cin >> l >> r;
        q[i].l=l-1, q[i].r=r, q[i].id=i;
    }
    sort(q,q+qq,Compare), l=0, r=-1;
    for(int i=0;i<qq;i++)
    {
        while(l > q[i].l)Add(--l);
        while(r < q[i].r)Add(++r);
        while(l < q[i].l)Reduce(l++);
        while(r > q[i].r)Reduce(r--);
        ans[q[i].id]=tmp;
    }
    for(int i=0;i<qq;i++)cout << ans[i] << '\n';
    return 0;
}