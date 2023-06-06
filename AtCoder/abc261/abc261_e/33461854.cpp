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

ll a[M],pre[M][30][2],t[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,n;cin >> n >> c;
    for(int i=1;i<=n;i++)cin >> t[i] >> a[i];
    for(int i=1;i<=n;i++)
    {
        if(t[i] == 1)
        {
            for(int j=0;j<30;j++)
            {
                if((a[i] >> j) & 1)pre[i][j][0]=pre[i-1][j][0];
            }
        }
        else if(t[i] == 2)
        {
            for(int j=0;j<30;j++)
            {
                if((a[i] >> j) & 1)pre[i][j][0]=1;
                else pre[i][j][0]=pre[i-1][j][0];
            }
        }
        else
        {
            for(int j=0;j<30;j++)
            {
                if((a[i] >> j) & 1)pre[i][j][0]=1-pre[i-1][j][0];
                else pre[i][j][0]=pre[i-1][j][0];
            }
        }
    }
    for(int i=0;i<30;i++)pre[0][i][1]=1;
    for(int i=1;i<=n;i++)
    {
        if(t[i] == 1)
        {
            for(int j=0;j<30;j++)
            {
                if((a[i] >> j) & 1)pre[i][j][1]=pre[i-1][j][1];
            }
        }
        else if(t[i] == 2)
        {
            for(int j=0;j<30;j++)
            {
                if((a[i] >> j) & 1)pre[i][j][1]=1;
                else pre[i][j][1]=pre[i-1][j][1];
            }
        }
        else
        {
            for(int j=0;j<30;j++)
            {
                if((a[i] >> j) & 1)pre[i][j][1]=1-pre[i-1][j][1];
                else pre[i][j][1]=pre[i-1][j][1];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<30;j++)
        {
            if(pre[i][j][(c >> j) & 1] != ((c >> j) & 1))c=c^(1 << j);
        }
        cout << c << '\n';
    }
    return 0;
}
