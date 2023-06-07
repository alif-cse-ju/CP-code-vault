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
char a[M];
bool Check()
    int l;cin >> l >> a+1;
    a[0]=a[l+1]='W';
    for(int i=1;i<=l;i++)
    {
        if(a[i] != 'W')
        {
            if(a[i-1] == 'W'  &&  a[i+1] == 'W')return 0;
        }
    }
    bool B=0,R=0;
    for(int i=1;i<=l;i++)
    {
        if(a[i] == 'W')
        {
            if(B != R)return 0;
            B=R=0;
        }
        else if(a[i] == 'B')B=1;
        else R=1;
    }
    return B == R;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        if(Check())cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}