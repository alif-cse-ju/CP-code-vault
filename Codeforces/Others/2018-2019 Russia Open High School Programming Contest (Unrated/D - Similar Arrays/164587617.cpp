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
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int a[M],b[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;cin >> n >> m;
    map<pair<int,int>,bool>mark;
    for(int i=0;i<m;i++)
    {
        int x,y;cin >> x >> y;
        if(x > y)swap(x,y);
        mark[{x,y}]=1;
    }
    if(n < 2  ||  m >= (1ll*n*(n-1))/2)cout << "NO";
    else
    {
        cout << "YES\n";
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(mark.find({i,j}) == mark.end())
                {
                    a[i]=1, a[j]=2, b[i]=b[j]=1;
                    int cur=2;
                    for(int k=1;k<=n;k++)
                    {
                        if(k == i  ||  k == j)continue;
                        a[k]=b[k]=++cur;
                    }
                    for(int k=1;k<=n;k++)cout << a[k] << ' ';
                    cout << '\n';
                    for(int k=1;k<=n;k++)cout << b[k] << ' ';
                    return 0;
                }
            }
        }
        cout << "NO";
    }
    return 0;
}