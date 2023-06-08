#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
pair<int,int>a[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt,i,j,k,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i=1;i<=n;i++)cin >> x,a[i]={x,i};
        cnt=0;
        sort(a+1,a+n+1);
        for(i=1;i<=n;i=j)
        {
            ++cnt;
            for(j=i+1;j<=n  &&  a[j].second == a[j-1].second+1;j++);
        }
        cout << (cnt <= k ? "Yes\n" : "No\n");
    }
    return 0;
}