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
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    vector<int>a(1 << n);
    for(int &x : a)cin >> x;
    for(int i=0;i<(1 << n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!((i >> j) & 1))
            {
                for(int k=j+1;k<n;k++)
                {
                    if(!((i >> k) & 1))
                    {
                        if(a[i+(1 << j)]+a[i+(1 << k)] < a[i]+a[i+(1 << j)+(1 << k)])
                        {
                            cout << i+(1 << j) << ' ' << i+(1 << k);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "-1";
    return 0;
}