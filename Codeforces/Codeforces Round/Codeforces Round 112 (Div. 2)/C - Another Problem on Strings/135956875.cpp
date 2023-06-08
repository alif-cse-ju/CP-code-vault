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
char s[N];
int cnt[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=0;
    int i,k,l,L,m,n,r,R;
    cin >> k >> s+1;
    n=strlen(s+1);
    for(i=1;i<=n;i++)cnt[i]=cnt[i-1]+(s[i]-'0');
    for(i=1;i<=n;i++)
    {
        if(cnt[i] < k)continue;
        l=1,r=i;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(cnt[i]-cnt[m-1] > k)l=m+1;
            else r=m-1;
        }
        L=r+1;
        l=1,r=i;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if(cnt[i]-cnt[m-1] >= k)l=m+1;
            else r=m-1;
        }
        R=l-1;
        ans += (R-L+1);
    }
    cout << ans;
    return 0;
}