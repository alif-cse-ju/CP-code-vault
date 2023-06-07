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
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
int a[M],_xor[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,k,n,x,x1,x2;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i], _xor[i]=(_xor[i-1] ^ a[i]);
    for(i=2;i<n;i++)
    {
        if(((a[i]^a[i-1]) > a[i+1])  ||  ((a[i]^a[i+1]) < a[i-1]))
        {
            cout << "1";
            return 0;
        }
    }
    ans=a[n+1]=INT_MAX;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            x=_xor[j] ^ _xor[i-1];
            if(x < a[i-1]  ||  x > a[j+1])ans=min(ans,j-i);
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=i+2;j<=n;j++)
        {
            for(k=i+1;k<j;k++)
            {
                x1=_xor[k] ^ _xor[i-1];
                x2=_xor[k] ^ _xor[j];
                if(a[i-1] > x1  ||  x1 > x2  ||  x2 > a[j+1])ans=min(ans,j-i-1);
            }
        }
    }
    if(ans > n)ans=-1;
    cout << ans;
    return 0;
}