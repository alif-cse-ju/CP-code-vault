#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
char s[M];
int l[M],r[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s+1;
        l[0]=-2e9,r[n+1]=2e9;
        for(i=1;i<=n;i++)
        {
            l[i]=l[i-1];
            if(s[i] == '1')l[i]=i;
        }
        for(i=n;i;i--)
        {
            r[i]=r[i+1];
            if(s[i] == '1')r[i]=i;
        }
        for(i=1;i<=n;i++)
        {
            if(s[i] == '0')
            {
                if((i-l[i] <= m  ||  r[i]-i <= m)  &&  i-l[i] != r[i]-i)s[i]='1';
            }
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}