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

ll a[M];

bool Solve(ll n,ll m,const int& k)
{
    ll cnt=m*n;
    for(int i=1;i<=k  &&  cnt > 0;i++)
    {
        ll canTake=a[i]/n;
        if(canTake > 1)
        {
            if(canTake == m-1)--canTake;
            if(canTake == 1)continue;
            cnt -= canTake*n, m -= canTake;
        }
    }
    if(cnt > 0)return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        ll m,n; int k; cin >> n >> m >> k;
        for(int i=1;i<=k;i++)cin >> a[i];
        sort(a+1,a+k+1);
        if(Solve(m,n,k)  ||  Solve(n,m,k))cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
