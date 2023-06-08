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
const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int m,n;
bool mark[M];
vector<int>a[M];
vector<bool>bit[M];
bool Check(const int& v)
    int i,j;
    for(i=1;i<=n;i++)mark[i]=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i][j] >= v)bit[i][j]=mark[j]=1;
            else bit[i][j]=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(!mark[i])return 0;
    }
    int cnt;
    for(i=1;i<=m;i++)
    {
        cnt=0;
        for(j=1;j<=n;j++)cnt += bit[i][j];
        if(cnt > 1)return 1;
    }
    return 0;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l,md,r,t;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        for(i=1;i<=m;i++)
        {
            a[i].resize(n+1);
            bit[i].resize(n+1);
            for(j=1;j<=n;j++)cin >> a[i][j];
        }
        l=1,r=1e9;
        while(l <= r)
        {
            md=(l+r) >> 1;
            if(Check(md))l=md+1;
            else r=md-1;
        }
        cout << l-1 << '\n';
    }
    return 0;
}