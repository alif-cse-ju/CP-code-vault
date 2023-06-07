#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=998244353;
int Ask(int x,int y)
    cout << "? " << x << ' ' << y << endl;
    int z;cin >> z;
    return z;
int Query(int a,int b,int c,int d)
    int x=Ask(a,c);
    if(!x)
    {
        x=Ask(b,d);
        if(x == 1)return b;
        return d;
    }
    else if(x == 1)
    {
        x=Ask(a,d);
        if(x == 1)return a;
        return d;
    }
    x=Ask(b,c);
    if(x == 1)return b;
    return c;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        vector<int>vnow,vprev;
        for(int i=1;i<=(1 << n);i++)vnow.emplace_back(i);
        while((int)vnow.size() >= 4)
        {
            vprev=vnow, vnow.clear();
            int l=(int)vprev.size();
            for(int i=4;i<=l;i+=4)vnow.emplace_back(Query(vprev[i-4], vprev[i-3], vprev[i-2], vprev[i-1]));
        }
        int ans;
        if((int)vnow.size() == 1)ans=vnow[0];
        else ans=(Ask(vnow[0], vnow[1]) == 1 ? vnow[0] : vnow[1]);
        cout << "! " << ans << endl;
    }
    return 0;
}