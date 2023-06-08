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
char a[52][52],b[52][52];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1; i<=n; i++)cin >> a[i]+1;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(a[i][j] == '.')
                {
                    if(i & 1)
                    {
                        if(j & 1)b[i][j]='R';
                        else b[i][j]='W';
                    }
                    else
                    {
                        if(j & 1)b[i][j]='W';
                        else b[i][j]='R';
                    }
                }
                else
                {
                    if(i & 1)
                    {
                        if(j & 1)
                        {
                            if(a[i][j] == 'R')b[i][j]='R';
                            else break;
                        }
                        else
                        {
                            if(a[i][j] == 'W')b[i][j]='W';
                            else break;
                        }
                    }
                    else
                    {
                        if(j & 1)
                        {
                            if(a[i][j] == 'W')b[i][j]='W';
                            else break;
                        }
                        else
                        {
                            if(a[i][j] == 'R')b[i][j]='R';
                            else break;
                        }
                    }
                }
            }
            if(j <= m)break;
        }
        if(i > n)
        {
            cout << "YES\n";
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=m; j++)cout << b[i][j];
                cout << '\n';
            }
        }
        else
        {
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=m; j++)
                {
                    if(a[i][j] == '.')
                    {
                        if(i & 1)
                        {
                            if(j & 1)b[i][j]='W';
                            else b[i][j]='R';
                        }
                        else
                        {
                            if(j & 1)b[i][j]='R';
                            else b[i][j]='W';
                        }
                    }
                    else
                    {
                        if(i & 1)
                        {
                            if(j & 1)
                            {
                                if(a[i][j] == 'W')b[i][j]='W';
                                else break;
                            }
                            else
                            {
                                if(a[i][j] == 'R')b[i][j]='R';
                                else break;
                            }
                        }
                        else
                        {
                            if(j & 1)
                            {
                                if(a[i][j] == 'R')b[i][j]='R';
                                else break;
                            }
                            else
                            {
                                if(a[i][j] == 'W')b[i][j]='W';
                                else break;
                            }
                        }
                    }
                }
                if(j <= m)break;
            }
            if(i > n)
            {
                cout << "YES\n";
                for(i=1; i<=n; i++)
                {
                    for(j=1; j<=m; j++)cout << b[i][j];
                    cout << '\n';
                }
            }
            else cout << "NO\n";
        }
    }
    return 0;
}