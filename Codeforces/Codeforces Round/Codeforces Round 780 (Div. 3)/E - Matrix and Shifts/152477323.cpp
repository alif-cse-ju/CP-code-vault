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
const int N=2e6+5;
const int mod=1e9+7;
const int sz = 2e3+5;
char grid[sz+sz][sz+sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt,i,j,k,mx,n,t,tmp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt=0;
        for(i=1;i<=n;i++)
        {
            cin >> grid[i]+1;
            for(j=1;j<=n;j++)cnt += (grid[i][j] == '1');
            for(j=n+1;j<=n+n;j++)grid[i][j]=grid[i][j-n];
        }
        for(i=n+1;i<n+n;i++)
        {
            for(j=1;j<n+n;j++)grid[i][j]=grid[i-n][j];
        }
        mx=0;
        for(i=1;i<n+n;i++)
        {
            tmp=0;
            deque<char>dq;
            for(j=1, k=i;j<n+n  &&  k < n+n;j++,k++)
            {
                if(grid[j][k] == '1')++tmp;
                dq.emplace_back(grid[j][k]);
                if((int)dq.size() > n)tmp -= (dq.front() == '1'), dq.pop_front();
                mx=max(mx, tmp);
            }
        }
        for(i=2;i<n+n;i++)
        {
            tmp=0;
            deque<char>dq;
            for(j=i, k=1;j<n+n  &&  k < n+n;j++,k++)
            {
                if(grid[j][k] == '1')++tmp;
                dq.emplace_back(grid[j][k]);
                if((int)dq.size() > n)tmp -= (dq.front() == '1'), dq.pop_front();
                mx=max(mx, tmp);
            }
        }
        cout << n-mx+cnt-mx << '\n';
    }
    return 0;
}