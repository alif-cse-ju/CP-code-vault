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

ll a[M],b[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    ll h,k,w,x=0,y=0;
    cin >> h >> w >> k;
    for(i=1;i<=h;i++)cin >> a[i], a[i]=((k-1)*w-a[i])%k, x += a[i];
    for(i=1;i<=w;i++)cin >> b[i], b[i]=((k-1)*h-b[i])%k, y += b[i];
    if(x%k != y%k)cout << "-1";
    else cout << h*(k-1)*w-max(x,y);
    return 0;
}