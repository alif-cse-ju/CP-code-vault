#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int g,gp,gn,i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>pos,neg;
        for(i=0;i<n;i++)
        {
            cin >> x;
            if(x > 0)pos.emplace_back(x);
            else if(x < 0)neg.emplace_back(-x);
        }
        gp=0;
        for(int it : pos)gp=__gcd(gp,it);
        gn=0;
        for(int it : neg)gn=__gcd(gn,it);
        g=__gcd(gp,gn);
        if(pos.empty())cout << gn << '\n';
        else if(neg.empty())cout << gp << '\n';
        else
        {
            if(n == 2)cout << gp+gn << '\n';
            else cout << 2*g << '\n';
        }
    }
    return 0;
}