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
const int M=2e3+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M][M],cnt[M];
int PreCal(const int& n)
    int i,j;
    bool changed;
    for(i=1;;i++)
    {
        for(j=1;j<M;j++)cnt[j]=0;
        for(j=1;j<=n;j++)++cnt[a[i-1][j]];
        for(j=1;j<=n;j++)a[i][j]=cnt[a[i-1][j]];
        changed=0;
        for(j=1;j<=n;j++)changed |= (a[i-1][j] != a[i][j]);
        if(!changed)return i-1;
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,l,n,t,q;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[0][i];
        l=PreCal(n);
        cin >> q;
        while(q--)
        {
            cin >> i >> k;
            k=min(k,l);
            cout << a[k][i] << '\n';
        }
    }
    return 0;
}