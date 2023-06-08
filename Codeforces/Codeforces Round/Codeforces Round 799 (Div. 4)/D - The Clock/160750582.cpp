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
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        string s;cin >> s;
        int k;cin >> k;
        int ans=0, cnt=0, hr=(s[0]-'0')*10+(s[1]-'0'), mint=(s[3]-'0')*10+(s[4]-'0'), val=hr*60+mint;
        bool ok=1;
        vector<bool>visited(1440, 0);
        for(int i=hr;ok;i++)
        {
            for(int j=(i == hr ? mint : 0);j<60;j++)
            {
                if(cnt%k == 0)
                {
                    int val=((i%24)*60+j)%1440;
                    if(visited[val])
                    {
                        ok=0;
                        break;
                    }
                    visited[val]=1;
                    ans += (((i%24)%10 == j/10) & ((i%24)/10 == j%10));
                }
                ++cnt;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}