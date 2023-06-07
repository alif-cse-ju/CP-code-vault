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
int p[205];
bool visited[M];
ll Solve()
    int l;cin >> l;
    string s,ss;cin >> s, ss=s;
    for(int i=1;i<=l;i++)cin >> p[i], visited[i]=0;
    ll ans=0;
    for(int i=1;i<=l;i++)
    {
        if(!visited[i])
        {
            vector<int>v;
            v.emplace_back(i);
            for(int j=p[i];j!=i;j=p[j])v.emplace_back(j);
            deque<char>dq;
            for(int it : v)dq.emplace_back(s[it-1]), visited[it]=1;
            ll cnt=0;
            while(true)
            {
                ++cnt;
                dq.emplace_front(dq.back());
                dq.pop_back();
                bool ok=1;
                for(int j=0;j<(int)dq.size()  &&  ok;j++)ok &= (dq[j] == s[v[j]-1]);
                if(ok)
                {
                    if(!ans)ans=cnt;
                    else ans=(ans*cnt)/__gcd(ans,cnt);
                    break;
                }
            }
        }
    }
    return ans;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)cout << Solve() << '\n';
    return 0;
}