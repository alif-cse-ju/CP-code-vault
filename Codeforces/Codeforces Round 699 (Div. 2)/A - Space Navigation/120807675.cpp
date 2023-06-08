#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t,x,y,D,L,R,U;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> s;
        D=L=R=U=0;
        if(x >= 0)L=0,R=x;
        else L=-x,R=0;
        if(y >= 0)D=0,U=y;
        else D=-y,U=0;
        for(char &c : s)
        {
            D-=(c == 'D');
            L-=(c == 'L');
            R-=(c == 'R');
            U-=(c == 'U');
        }
        if(D <= 0  &&  L <= 0  &&  R <= 0  &&  U <= 0)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}