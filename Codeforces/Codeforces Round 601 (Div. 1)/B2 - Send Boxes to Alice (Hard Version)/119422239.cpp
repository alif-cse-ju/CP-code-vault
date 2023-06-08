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
const int M=1e6+5;
const int N=2e5+5;
const int mod=1e9+7;
int n;
ll s[M];
ll Check(ll val)
    ll sum=0,x;
    for(int i=1;i<=n;i++)
    {
        x=s[i]%val;
        sum+=min(x,val-x);
    }
    return sum;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,x;
    ll ans=LLONG_MAX,tmp;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        s[i]=s[i-1]+x;
    }
    if(s[n] == 1)cout << "-1";
    else
    {
        tmp=s[n];
        if(tmp%2 == 0)
        {
            ans=min(ans,Check(2));
            while(tmp%2 == 0)tmp/=2;
        }
        for(ll i=3;i*i<=tmp;i+=2)
        {
            if(tmp%i == 0)
            {
                ans=min(ans,Check(i));
                while(tmp%i == 0)tmp/=i;
            }
        }
        if(tmp > 1)ans=min(ans,Check(tmp));
        cout << ans;
    }
    return 0;
}