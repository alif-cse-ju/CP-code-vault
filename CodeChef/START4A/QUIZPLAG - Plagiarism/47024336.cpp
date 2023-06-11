#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int cnt[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(i=1;i<=n+m;i++)cnt[i]=0;
        set<int>st;
        while(k--)cin >> x,++cnt[x];
        for(i=1;i<=n;i++)
        {
            if(cnt[i] > 1)st.insert(i);
        }
        cout << (int)st.size();
        for(int it : st)cout << ' ' << it;
        cout << '\n';
    }
    return 0;
}