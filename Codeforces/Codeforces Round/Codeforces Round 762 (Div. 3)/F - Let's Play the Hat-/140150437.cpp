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
const int M=5e5+5;
const int N=2e6+5;
const int mod=1e9+7;
void Solve()
    int b,bc,c,cc,cur,i,j,k,m,n,r,start=0;
    cin >> n >> m >> k;
    b=(n+m-1)/m, c=n/m, bc=n%m, cc=m-bc;
    vector<vector<int>>ans;
    for(r=0;r<k;r++)
    {
        cur=start;
        for(i=0;i<bc;i++)
        {
            vector<int>v;
            for(j=0;j<b;j++)v.emplace_back(cur), cur=(cur+1)%n;
            ans.emplace_back(v);
        }
        for(i=0;i<cc;i++)
        {
            vector<int>v;
            for(j=0;j<c;j++)v.emplace_back(cur), cur=(cur+1)%n;
            ans.emplace_back(v);
        }
         start=(start+1ll*b*bc)%n;
    }
    for(vector<int>v : ans)
    {
        cout << (int)v.size();
        for(int it : v)cout << ' ' << it+1;
        cout << '\n';
    }
    cout << '\n';
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)Solve();
    return 0;
}