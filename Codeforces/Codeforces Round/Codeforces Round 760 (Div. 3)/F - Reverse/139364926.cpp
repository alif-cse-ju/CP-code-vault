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
bool Check(vector<int>x,vector<int>y)
    int i,j,k,lx=(int)x.size(),ly=(int)y.size();
    for(i=0;i+lx<=ly;i++)
    {
        for(j=0;j<lx;j++)
        {
            if(x[j] != y[i+j])break;
        }
        if(j == lx)
        {
            for(j=i-1;j>=0;j--)
            {
                if(y[j] == 0)break;
            }
            for(k=i+lx;k<ly;k++)
            {
                if(y[k] == 0)break;
            }
            if(j == -1  &&  k == ly)return 1;
        }
    }
    return 0;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y;
    cin >> x >> y;
    if(x == y)cout << "YES";
    else if(!(y%2ll))cout << "NO";
    else
    {
        vector<int>vx,vy;
        while(x)vx.emplace_back(x%2), x/=2ll;
        while(y)vy.emplace_back(y%2), y/=2ll;
        reverse(vx.begin(),vx.end());
        reverse(vy.begin(),vy.end());
        if(Check(vx,vy))
        {
            cout << "YES";
            return 0;
        }
        reverse(vx.begin(),vx.end());
        if(Check(vx,vy))
        {
            cout << "YES";
            return 0;
        }
        reverse(vx.begin(),vx.end());
        while(!vx.back())vx.pop_back();
        if(Check(vx,vy))cout << "YES";
        else
        {
            reverse(vx.begin(),vx.end());
            if(Check(vx,vy))cout << "YES";
            else cout << "NO";
        }
    }
    return 0;
}