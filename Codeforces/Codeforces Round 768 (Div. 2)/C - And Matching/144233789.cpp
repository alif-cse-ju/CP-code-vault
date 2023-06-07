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
const int MX=(1 << 16)+10;
bool mark[MX];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(k == n-1)
        {
            if(n == 4)cout << "-1\n";
            else
            {
                for(i=0; i<n; i++)mark[i]=0;
                cout << n-2 << ' ' << n-1 << '\n';
                cout << 1 << ' ' << 3 << '\n';
                mark[1]=mark[3]=mark[n-2]=mark[n-1]=1;
                for(i=n-1; i>=0; i--)
                {
                    if(mark[i])continue;
                    if(!mark[(i ^ (n-1))])
                    {
                        cout << i << ' ' << (i ^ (n-1)) << '\n';
                        mark[i]=mark[(i ^ (n-1))]=1;
                    }
                    else
                    {
                        cout << i << ' ' << 0 << '\n';
                        mark[i]=mark[0]=1;
                    }
                }
            }
        }
        else
        {
            for(i=0; i<n; i++)mark[i]=0;
            cout << k << ' ' << n-1 << '\n';
            mark[k]=mark[n-1]=1;
            for(i=n-1; i>=0; i--)
            {
                if(mark[i])continue;
                if(!mark[(i ^ (n-1))])
                {
                    cout << i << ' ' << (i ^ (n-1)) << '\n';
                    mark[i]=mark[(i ^ (n-1))]=1;
                }
                else
                {
                    cout << i << ' ' << 0 << '\n';
                    mark[i]=mark[0]=1;
                }
            }
        }
    }
    return 0;
}