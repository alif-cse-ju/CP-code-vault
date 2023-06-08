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
int a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i];
        if(n == 1)cout << "0\n";
        else
        {
            vector<pair<int,int>>ans;
            if((a[1]+a[n]) & 1)a[n]=a[1];
            else a[1]=a[n];
            ans.emplace_back(1,n);
            for(int i=2;i<n;i++)
            {
                if(a[i]%2 != a[1]%2)ans.emplace_back(1,i);
                else ans.emplace_back(i,n);
            }
            cout << (int)ans.size() << '\n';
            for(auto [l,r] : ans)cout << l << ' ' << r << '\n';
        }
    }
    return 0;
}