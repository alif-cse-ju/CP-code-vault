#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int a[M],b[M],c[M];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ordered_set<int>L,R;
        for(i=1; i<=n; i++)
        {
            cin >> a[i];
            if(a[i] == 1)L.insert(i);
            else if(a[i] == 2)R.insert(i);
        }
        for(i=1; i<=m; i++)
        {
            cin >> b[i],c[i]=-1;
            if(b[i] == 1  ||  a[b[i]])c[i]=0;
            else
            {
                x=-1e9,y=1e9;
                j=L.order_of_key(b[i]);
                if(j)x=*(L.find_by_order(j-1));
                j=R.order_of_key(b[i]);
                if(j < (int)R.size())y=*(R.find_by_order(j));
                if(x > -1e9)c[i]=b[i]-x;
                if(y < 1e9)
                {
                    if(c[i] == -1)c[i]=y-b[i];
                    else c[i]=min(c[i],y-b[i]);
                }
            }
            cout << c[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}