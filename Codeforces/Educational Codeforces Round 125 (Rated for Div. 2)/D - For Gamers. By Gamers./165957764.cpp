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

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

ll dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,C;cin >> n >> C;
    for(int i=1;i<=n;i++)
    {
        ll c,d,h;cin >> c >> d >> h;
        dp[c]=max(dp[c], d*h);
    }
    for(int i=1;i<=C;i++)
    {
        for(int j=i;j<=C;j+=i)dp[j]=max(dp[j], dp[i]*(j/i));
    }
    for(int i=1;i<=C;i++)dp[i]=max(dp[i], dp[i-1]);
    int q;cin >> q;
    while(q--)
    {
        ll D,H;cin >> D >> H;
        if(D*H >= dp[C])cout << "-1 ";
        else
        {
            int l=1, r=C;
            while(l <= r)
            {
                int m=(l+r) >> 1;
                if(dp[m] > D*H)r=m-1;
                else l=m+1;
            }
            cout << r+1 << ' ';
        }
    }
    return 0;
}