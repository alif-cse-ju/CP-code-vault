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
const int mod=95542721;
ll a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i];  sort(a+1,a+n+1);
        if(!a[1]  &&  !a[n])cout << "YES\n";//sobai 0
        else if(!a[2]  &&  !a[n])cout << "YES\n";//ekjon negative
        else if(!a[1]  &&  !a[n-1])cout << "YES\n";//ekjon positive
        else if(!a[2]  &&  !a[n-1]  &&  !(a[1]+a[n]))cout << "YES\n";//a[1]=-a[n], baki sob 0
        else if(n == 3)
        {
            ll s=a[1]+a[2]+a[3];
            if(s == a[1]  ||  s == a[2]  ||  s == a[3])cout << "YES\n";
            else cout << "NO\n";
        }
        else if(n == 4)
        {
            bool ok=1;
            ok &= ((a[1]+a[2]+a[3] == a[1]) | (a[1]+a[2]+a[3] == a[2]) | (a[1]+a[2]+a[3] == a[3]) | (a[1]+a[2]+a[3] == a[4]));
            ok &= ((a[1]+a[2]+a[4] == a[1]) | (a[1]+a[2]+a[4] == a[2]) | (a[1]+a[2]+a[4] == a[3]) | (a[1]+a[2]+a[4] == a[4]));
            ok &= ((a[1]+a[3]+a[4] == a[1]) | (a[1]+a[3]+a[4] == a[2]) | (a[1]+a[3]+a[4] == a[3]) | (a[1]+a[3]+a[4] == a[4]));
            ok &= ((a[2]+a[3]+a[4] == a[1]) | (a[2]+a[3]+a[4] == a[2]) | (a[2]+a[3]+a[4] == a[3]) | (a[2]+a[3]+a[4] == a[4]));
             if(ok)cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }
    return 0;
}