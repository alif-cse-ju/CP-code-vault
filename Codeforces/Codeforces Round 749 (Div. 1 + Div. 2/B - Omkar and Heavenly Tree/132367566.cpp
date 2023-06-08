#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
bool mark[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)mark[i]=0;
        while(m--)cin >> x >> y >> z, mark[y]=1;
        for(i=1;i<=n;i++)
        {
            if(!mark[i])x=i;
        }
        for(i=1;i<=n;i++)
        {
            if(x == i)continue;
            cout << x << ' ' << i << '\n';
        }
    }
    return 0;
}