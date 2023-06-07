#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

const int sz=1e3+5;

char grid[sz][sz];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> n >> m;
        for(int i=1;i<=n;i++)cin >> grid[i]+1;
        int mnipj=INT_MAX, mxipj=-1, mnimj=INT_MAX, mximj=INT_MIN;
        pair<int,int>ans, ipjmn, ipjmx, imjmn, imjmx;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(grid[i][j] == 'B')
                {
                    if(mnipj > i+j)mnipj=i+j, ipjmn={i,j};
                    if(mxipj < i+j)mxipj=i+j, ipjmx={i,j};

                    if(mnimj > i-j)mnimj=i-j, imjmn={i,j};
                    if(mximj < i-j)mximj=i-j, imjmx={i,j};
                }
            }
        }

        int mn=INT_MAX;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int dist=-1;
                dist=max(dist, abs(i-ipjmn.first) + abs(j-ipjmn.second));
                dist=max(dist, abs(i-ipjmx.first) + abs(j-ipjmx.second));
                dist=max(dist, abs(i-imjmn.first) + abs(j-imjmn.second));
                dist=max(dist, abs(i-imjmx.first) + abs(j-imjmx.second));

                if(dist < mn)mn=dist, ans={i,j};
            }
        }

        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}