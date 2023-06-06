#pragma GCC optimize("Ofast")

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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int h[4],w[4],a[4][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    for(int i=1;i<=3;i++)cin >> h[i];
    for(int i=1;i<=3;i++)cin >> w[i];
    for(a[1][1]=1;a[1][1]<=30;a[1][1]++)
    {
        for(a[1][2]=1;a[1][2]<=30;a[1][2]++)
        {
            for(a[2][1]=1;a[2][1]<=30;a[2][1]++)
            {
                for(a[2][2]=1;a[2][2]<=30;a[2][2]++)
                {
                    a[1][3]=h[1]-a[1][1]-a[1][2];
                    if(a[1][3] <= 0)continue;

                    a[2][3]=h[2]-a[2][1]-a[2][2];
                    if(a[2][3] <= 0)continue;

                    a[3][1]=w[1]-a[1][1]-a[2][1];
                    if(a[3][1] <= 0)continue;

                    a[3][2]=w[2]-a[1][2]-a[2][2];
                    if(a[3][2] <= 0)continue;

                    if(a[1][3]+a[2][3] < w[3]  &&  a[3][1]+a[3][2] < h[3]  &&  h[3]-a[3][1]-a[3][2] == w[3]-a[1][3]-a[2][3])++ans;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
