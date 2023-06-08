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
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
            int n;cin >> n;
            vector<string>s(n);
            map<string,bool>mp;
            for(int i=0;i<n;i++)cin >> s[i], mp[s[i]]=1;
            vector<bool>ans(n, 0);
            for(int i=0;i<n;i++)
            {
                    for(int j=1;j<(int)s[i].size();j++)
                    {
                            string a="",b="";
                            for(int k=0;k<j;k++)a+=s[i][k];
                            for(int k=j;k<(int)s[i].size();k++)b+=s[i][k];
                             if(mp.find(a) == mp.end())continue;
                            if(mp.find(b) == mp.end())continue;
                             ans[i]=1;break;
                    }
            }
            for(int i=0;i<n;i++)cout << ans[i];
            cout << '\n';
    }
    return 0;
}