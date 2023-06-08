#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin >> a[i];
        for(int i=0;i<31;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)cnt+=((a[j] >> i) & 1);
            if(cnt < n)
            {
                for(int j=0;j<n;j++)
                {
                    if((a[j] >> i) & 1)a[j] ^= (1 << i);
                }
            }
        }
        sort(a.begin(),a.end());
        cout << a[n-1] << '\n';
    }
    return 0;
}