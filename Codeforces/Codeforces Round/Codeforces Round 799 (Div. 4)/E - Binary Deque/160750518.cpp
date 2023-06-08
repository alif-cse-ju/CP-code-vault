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
int a[M],pre[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n,s;cin >> n >> s;
        for(int i=1;i<=n;i++)cin >> a[i], pre[i]=pre[i-1]+a[i];
        if(pre[n] < s)cout << "-1\n";
        else if(pre[n] == s)cout << "0\n";
        else
        {
            map<int,int>firstPos;
            for(int i=0;i<=n;i++)
            {
                if(firstPos.find(pre[i]) == firstPos.end())firstPos[pre[i]]=i;
            }
            s=pre[n]-s;
            int ans=firstPos[s], suf=0;
            for(int i=n;i;i--)
            {
                suf += a[i];
                if(suf >= s)ans=min(ans, n-i+1);
                else ans=min(ans, (n-i+1)+firstPos[s-suf]);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}