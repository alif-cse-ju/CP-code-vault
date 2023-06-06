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

const int sz = 1e3+5;

char grid[sz][sz];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt,i,ii,j,jj,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> grid[i]+1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j+5 <= n)
            {
                for(cnt=jj=0;jj<6;jj++)cnt += (grid[i][j+jj] == '#');
                if(cnt > 3)
                {
                    cout << "Yes";
                    return 0;
                }
            }
            if(i+5 <= n)
            {
                for(cnt=ii=0;ii<6;ii++)cnt += (grid[i+ii][j] == '#');
                if(cnt > 3)
                {
                    cout << "Yes";
                    return 0;
                }
            }
            if(i+5 <= n  &&  j+5 <= n)
            {
                for(cnt=ii=0;ii<6;ii++)cnt += (grid[i+ii][j+ii] == '#');
                if(cnt > 3)
                {
                    cout << "Yes";
                    return 0;
                }
            }
            if(i+5 <= n  &&  j > 5)
            {
                for(cnt=ii=0;ii<6;ii++)cnt += (grid[i+ii][j-ii] == '#');
                if(cnt > 3)
                {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
    return 0;
}
