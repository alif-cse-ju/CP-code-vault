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
ll h[M],hh[M];
int Solve(const int& n)
        int l=1,r=1e9;
        while(l <= r)
        {
                int m=(l+r) >> 1;
                for(int i=1;i<=n;i++)hh[i]=h[i];
                int i;
                for(i=n;i>2;i--)
                {
                        if(hh[i] < m)break;
                        ll d=min(h[i], hh[i]-m)/3ll;
                        hh[i-2]+=d+d, hh[i-1]+=d;
                }
                if(i > 2)r=m-1;
                else
                {
                        if(hh[1] >= m  &&  hh[2] >= m)l=m+1;
                        else r=m-1;
                }
        }
        return l-1;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
            int n;cin >> n;
            for(int i=1;i<=n;i++)cin >> h[i];
            cout << Solve(n) << '\n';
    }
    return 0;
}