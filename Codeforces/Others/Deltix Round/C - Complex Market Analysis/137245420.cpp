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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int a[M],cnt[M];
deque<int>pos[M];
bool mark[N],primedhukche[M];
void Sieve()
    ll i,j;
    mark[1]=1;
    for(i=4;i<N;i+=2)mark[i]=1;
    for(i=3;i*i<N;i+=2)
    {
        if(!mark[i])
        {
            for(j=i*i;j<N;j+=2*i)mark[j]=1;
        }
    }
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Sieve();
    ll ans;
    int e,i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> e;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=0;i<e;i++)pos[i].clear(), cnt[i]=primedhukche[i]=0;
        ans=0;
        for(i=n;i;i--)
        {
            if(!mark[a[i]])
            {
                ans += cnt[i%e];
                if(primedhukche[i%e])
                {
                    while(pos[i%e].back() == 1)pos[i%e].pop_back();
                    pos[i%e].pop_back();
                }
                primedhukche[i%e]=1;
                pos[i%e].emplace_front(a[i]), cnt[i%e]=0;
            }
            else
            {
                if(a[i] > 1)pos[i%e].clear(), cnt[i%e]=primedhukche[i%e]=0;
                else
                {
                    if(primedhukche[i%e])ans += (int)pos[i%e].size()-cnt[i%e];
                    pos[i%e].emplace_front(1), ++cnt[i%e];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}