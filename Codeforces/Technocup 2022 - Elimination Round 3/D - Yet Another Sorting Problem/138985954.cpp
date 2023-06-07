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
const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M],n,sum[M];
void Update(int i)
    while(i <= n)++sum[i], i+=(i & -i);
int Query(int i)
    int ans=0;
    while(i)ans += sum[i], i-=(i & -i);
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll cnt;
    int i,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>st;
        for(i=1;i<=n;i++)cin >> a[i], st.insert(a[i]);
        if((int)st.size() < n)cout << "YES\n";
        else
        {
            cnt=0;
            for(i=1;i<=n;i++)sum[i]=0;
            for(i=1;i<=n;i++)cnt += Query(n)-Query(a[i]), Update(a[i]);
            if(cnt & 1)cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}