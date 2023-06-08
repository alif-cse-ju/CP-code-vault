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
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>v(n);
        for(int &x : v)cin >> x;
        sort(v.begin(),v.end());
        if(v[0] >= 0)
        {
            map<int,int>mp;
            for(int x : v)++mp[x];
            int gcd=0;
            for(int x : v)gcd=__gcd(gcd,x);
            if(v.back()/gcd < 301)
            {
                int x=min(v[0],gcd);
                vector<int>ans;
                while(x <= v.back())
                {
                    int y=max(1,mp[x]);
                    while(y--)ans.emplace_back(x);
                    x+=gcd;
                }
                if((int)ans.size() > 300)cout << "NO\n";
                else
                {
                    cout << "YES\n";
                    cout << (int)ans.size() << '\n';
                    for(int x : ans)cout << x << ' ';
                    cout << '\n';
                }
            }
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }
    return 0;
}