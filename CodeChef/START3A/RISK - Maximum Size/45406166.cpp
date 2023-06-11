#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int m,n,cnt;
vector<string>grid;
void DFS(int i,int j)
{
    if(i < 0  ||  i == n  ||  j < 0  ||  j == m  ||  grid[i][j] == '0')return;
    ++cnt;
    grid[i][j]='0';
    for(int k=0;k<4;k++)DFS(i+dx[k],j+dy[k]);
}
int main()
{
    FAST();
    string s;
    int i,j,l,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        grid.clear();
        for(i=0;i<n;i++)
        {
            cin >> s;
            grid.emplace_back(s);
        }
        vector<int>v;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    cnt=0;
                    DFS(i,j);
                    v.emplace_back(cnt);
                }
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        l=(int)v.size();
        ans=0;
        for(i=1;i<l;i+=2)ans+=v[i];
        cout << ans << '\n';
    }
    return 0;
}