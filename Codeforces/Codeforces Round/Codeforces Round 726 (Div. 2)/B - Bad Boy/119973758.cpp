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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,ii,j,jj,m,n,t,x1,x2,y1,y2,mx,temp;
    cin >> t;
    while(t--)
    {
        mx=-1;
        cin >> n >> m >> ii >> jj;
        vector<pair<int,int>>v;
        v.emplace_back(1,1);
        v.emplace_back(1,m);
        v.emplace_back(n,1);
        v.emplace_back(n,m);
        for(auto [u1,v1] : v)
        {
            for(auto [u2,v2] : v)
            {
                temp=abs(ii-u1)+abs(jj-v1)+abs(u1-u2)+abs(v1-v2)+abs(u2-ii)+abs(v2-jj);
                if(temp > mx)x1=u1,x2=u2,y1=v1,y2=v2,mx=temp;
            }
        }
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    }
    return 0;
}