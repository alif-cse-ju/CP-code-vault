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
const int mod=998244353;

int n,lg[M];
pair<int,int>a[M],ans[M][20];

void Build()
{
   int i,j,k;
   lg[1]=0;
   k=log2(n)+1;
   for(i=0;i<n;i++)ans[i][0].first=ans[i][0].second=a[i].second;
   for(i=2;i<=n;i++)lg[i]=lg[i/2]+1;
   for(j=1;j<=k;j++)
   {
       for(i=0;i+(1 << j)<=n;i++)
       {
           ans[i][j].first=max(ans[i][j-1].first,ans[i+(1 << (j-1))][j-1].first);
           ans[i][j].second=min(ans[i][j-1].second,ans[i+(1 << (j-1))][j-1].second);
       }
   }
}

pair<int,int>Query(int l,int r)
{
    int j=lg[r-l+1];
    return {max(ans[l][j].first,ans[r-(1 << j)+1][j].first),min(ans[l][j].second,ans[r-(1 << j)+1][j].second)};
}

bool Check(const int& val)
{
    int i,l,m,r;
    pair<int,int>tmp;
    for(i=0;i<n;i++)
    {
        if(a[i].first+val > a[n-1].first)return 0;
        l=i+1,r=n-1;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(a[m].first < a[i].first+val)l=m+1;
            else r=m-1;
        }
        tmp=Query(r+1,n-1);
        if(max(abs(tmp.first-a[i].second),abs(tmp.second-a[i].second)) >= val)return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,m,r,x,y;
    cin >> n;
    for(i=0;i<n;i++)cin >> x >> y,a[i]={x,y};
    sort(a,a+n);
    Build();
    l=1,r=1e9;
    while(l <= r)
    {
        m=(l+r) >> 1;
        if(Check(m))l=m+1;
        else r=m-1;
    }
    cout << l-1;
    return 0;
}
