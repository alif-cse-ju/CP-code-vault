#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int n;
ll a[M],pw[20];
void PreCal()
{
    pw[0]=1;
    for(int i=1;i<18;i++)pw[i]=pw[i-1]*10;
}
ll Calculate(const ll& val)
{
    ll ans=0,x,y;
    int i,l,ln,m,r;
    for(i=1;i<=n;i++)
    {
        x=y=a[i], ln=0,l=1,r=n;
        while(x)++ln, x/=10;
        while(l <= r)
        {
            m=(l+r) >> 1;
            x=a[m]*pw[ln];
            if(x+y <= val)l=m+1;
            else r=m-1;
        }
        ans += l-1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l,r;
    int i,t;
    PreCal();
    cin >> t;
    while(t--)
    {
        cin >> n >> l >> r;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        cout << Calculate(r)-Calculate(l-1) << '\n';
    }
    return 0;
}