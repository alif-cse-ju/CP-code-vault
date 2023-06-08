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
const int N=1e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int curUD,curLR,d,l,m,n,r,t,u;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s;
        curUD=curLR=d=l=r=u=0;
        for(char c : s)
        {
            if(c == 'U')++curUD;
            else if(c == 'D')--curUD;
            else if(c == 'L')++curLR;
            else --curLR;
            if(curUD > 0  &&  curUD > u)
            {
                if(u+d+1 == n)break;
                u=curUD;
            }
            else if(curUD < 0  &&  abs(curUD) > d)
            {
                if(u+d+1 == n)break;
                d=abs(curUD);
            }
            else if(curLR > 0  &&  curLR > l)
            {
                if(l+r+1 == m)break;
                l=curLR;
            }
            else if(curLR < 0  &&  abs(curLR) > r)
            {
                if(l+r+1 == m)break;
                r=abs(curLR);
            }
        }
        cout << u+1 << ' ' << l+1 << '\n';
    }
    return 0;
}