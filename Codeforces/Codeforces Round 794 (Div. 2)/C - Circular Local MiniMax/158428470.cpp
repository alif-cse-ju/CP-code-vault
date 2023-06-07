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
int a[M],b[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)cin >> a[i];
        if(n & 1)cout << "NO\n";
        else
        {
            sort(a+1,a+n+1);
            bool ok=1;
            for(int i=1; i<=n/2; i++)b[2*i-1]=a[i], b[2*i]=a[n/2+i];
            b[0]=b[n], b[n+1]=b[1];
            for(int i=1; i<=n; i++)
            {
                if(i & 1)ok &= (b[i] < b[i-1]  &&  b[i] < b[i+1]);
                else ok &= (b[i] > b[i-1]  &&  b[i] > b[i+1]);
            }
            if(!ok)cout << "NO\n";
            else
            {
                cout << "YES\n";
                for(int i=1; i<=n; i++)cout << b[i] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}