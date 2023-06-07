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
const int M=3e5+5;
const int N=2e6+5;
const int mod=998244353;
ll a[100];
int FindMax()
    ll i,v;
    for(i=v=a[0]=1; ;i++)
    {
        v *= 3;
        if(v > 1e9)return i;
        a[i]=v;
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m=FindMax(),n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n > m)cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(i=0;i<n;i++)cout << a[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}