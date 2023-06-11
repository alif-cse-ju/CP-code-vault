#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,j,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i], a[i] += a[i-1];
        if(!a[n])
        {
            ans=0;
            for(i=1;i<=n;i++)ans += (a[i] == 0);
            cout << n-ans << '\n';
        }
        else
        {
            if(a[n] < 0)
            {
                for(i=1;i<=n;i++)a[i] *= (-1);
            }
            ans=1;
            for(i=1;i<n;i++)
            {
                if(a[i] <= 0  ||  a[n]%a[i])continue;
                for(j=i,k=a[i];j<n;j++)
                {
                    if(a[j] == k)
                    {
                        k += a[i];
                        if(k == a[n])break;
                    }
                }
                if(k == a[n])ans=max(ans, a[n]/a[i]);
            }
            cout << n-ans << '\n';
        }
    }
    return 0;
}