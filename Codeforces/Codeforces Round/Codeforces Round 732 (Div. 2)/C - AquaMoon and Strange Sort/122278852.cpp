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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M],pos[M][2];
bool Solve()
    int i,n;
    cin >> n;
    for(i=1;i<M;i++)pos[i][0]=pos[i][1]=0;
    for(i=1;i<=n;i++)cin >> a[i],++pos[a[i]][i%2];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        if(pos[a[i]][i%2])--pos[a[i]][i%2];
        else return 0;
    }
    return 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        if(Solve())cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}