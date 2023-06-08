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
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int l;cin >> l;
        string s;cin >> s;
        if(s[0] != '9')
        {
            for(int i=0;i<l;i++)cout << ('9'-s[i]);
        }
        else
        {
            int carry=0;
            vector<int>v;
            for(int i=l-1;i>=0;i--)
            {
                int x=(s[i]-'0'+carry);
                if(x == 1)carry=0, v.emplace_back(0);
                else v.emplace_back((11-x)%10), carry=(x > 0);
            }
            while(!v.empty())cout << v.back(), v.pop_back();
        }
        cout << '\n';
    }
    return 0;
}