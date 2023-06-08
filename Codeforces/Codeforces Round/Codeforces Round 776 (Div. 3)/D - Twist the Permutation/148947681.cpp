#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M],ans[M],b[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,l,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=n;i;i--)
        {
            for(j=i;j;j--)
            {
                if(a[j] == i)break;
            }
            if(i == j)ans[i]=0;
            else
            {
                l=0, ans[i]=j;
                for(k=j+1;k<=i;k++)b[++l]=a[k];
                for(k=1;k<=j;k++)b[++l]=a[k];
                for(k=i+1;k<=n;k++)b[++l]=a[k];
                for(j=1;j<=n;j++)a[j]=b[j];
            }
        }
        for(i=1;i<=n;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}