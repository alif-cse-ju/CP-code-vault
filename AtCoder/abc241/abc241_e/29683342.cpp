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

ll a[M];
pair<ll,ll>dhon[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0,i,k,moveCnt=0,n,rem,temp;
    cin >> n >> k;
    for(i=0;i<n;i++)cin >> a[i], dhon[i]={-1,-1};
    for(i=0;i<k;i++)
    {
        if(dhon[ans%n].first != -1)break;
        dhon[ans%n]={ans,moveCnt};
        ++moveCnt, ans += a[ans%n];
    }
    if(i < k)
    {
        rem=k-i, moveCnt=moveCnt-dhon[ans%n].second, temp=ans - dhon[ans%n].first;
        i=ans%n, ans += temp*(rem/moveCnt), rem %= moveCnt;
        while(rem--)ans += a[i], i=ans%n;
    }
    cout << ans;
    return 0;
}
