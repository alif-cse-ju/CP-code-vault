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
const int mod=1e9+7;

struct query
{
    int l,r,id;
}q[N];
int l,r,k,sum,a[M],ans[N],cnt[M];

bool Compare(query &x,query &y)
{
    int a=x.l/k,b=y.l/k;
    if(a == b)return x.r < y.r;
    return a < b;
}

void Add(int x)
{
    x=a[x];
    sum -= cnt[x]/2;
    ++cnt[x];
    sum += cnt[x]/2;
}

void Reduce(int x)
{
    x=a[x];
    sum -= cnt[x]/2;
    --cnt[x];
    sum += cnt[x]/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,x;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    cin >> m;
    k=sqrt(m);
    for(i=0;i<m;i++)
    {
        cin >> x;
        q[i].l=x-1;
        cin >> x;
        q[i].r=x-1;
        q[i].id=i;
    }
    sort(q,q+m,Compare);
    l=0,r=-1,sum=0;
    for(i=0;i<m;i++)
    {
        while(l > q[i].l)Add(--l);
        while(r < q[i].r)Add(++r);
        while(l < q[i].l)Reduce(l++);
        while(r > q[i].r)Reduce(r--);
        ans[q[i].id]=sum;
    }
    for(i=0;i<m;i++)cout << ans[i] << '\n';
    return 0;
}