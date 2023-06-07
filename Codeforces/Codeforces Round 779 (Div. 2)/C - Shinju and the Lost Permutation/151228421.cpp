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
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
int a[M],cnt[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cnt[i]=0;
        for(i=1;i<=n;i++)cin >> a[i], cnt[a[i]]++;
        if(cnt[1] != 1  ||  cnt[n] > 1)cout << "NO\n";
        else
        {
            for(i=1;a[i]!=1;i++);
            l=i;
            for(i=l+1;i<=n;i++)
            {
                if(a[i] < a[i-1])continue;
                if(a[i] >= a[i-1]  &&  a[i]-a[i-1] < 2)continue;
                break;
            }
            if(i <= n)cout << "NO\n";
            else
            {
                a[0]=a[n];
                for(i=1;i<l;i++)
                {
                    if(a[i] < a[i-1])continue;
                    if(a[i] >= a[i-1]  &&  a[i]-a[i-1] < 2)continue;
                    break;
                }
                if(i < l)cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }
    return 0;
}