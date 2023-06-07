#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define ld long double
ll const MX = 1e5+6, lim = 1e5;
ll inf = 1e18;
ll pos[MX] , num[MX];
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int main()
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, tc;
    cin>>test;
    for(tc=1; tc<=test; tc++)
    {
        ordered_set vc;
        ll i,j,k,s,d=0,r,m,n;
        cin>>n;
        for(i=1; i<=n; i++) cin>>r, pos[r]=i;
        for(i=1; i<=n; i++) cin>>num[i];
        s=1;
        for(i=n-1; i>=1; i--)
        {
           if(pos[num[i]] < pos[num[i+1]]) {s++; continue;}
           else break;
        }
          cout<<n-s<<endl;
     }
}
    