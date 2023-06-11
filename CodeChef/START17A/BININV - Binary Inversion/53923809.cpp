#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int _0[M],_1[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll ans,cnt;
    int i,j,m,n,t;
    cin >> t;
    while(t--)
    {
        ans=cnt=0;
        priority_queue<pair<ll,ll>>pq;
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            cin >> s;
            _0[i]=_1[i]=0;
            for(char c : s)
            {
                if(c == '0')++_0[i], ans+=_1[i];
                else ++_1[i];
            }
            pq.emplace(-_1[i],_0[i]);
        }
        while(!pq.empty())
        {
            ans+=cnt*pq.top().second;
            cnt += -pq.top().first;
            pq.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}