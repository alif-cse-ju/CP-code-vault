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
const int N=1e6+5;
const int mod=998244353;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l,t;
    char s[55],ans[55][55];
    cin >> t;
    while(t--)
    {
        cin >> l >> s+1;
        vector<int>v;
        for(i=1;i<=l;i++)
        {
            if(s[i] == '2')v.emplace_back(i);
        }
        if(!v.empty()  &&  (int)v.size() < 3)cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(i=1;i<=l;i++)
            {
                for(j=1;j<=l;j++)
                {
                    if(i == j)ans[i][j]='X';
                    else ans[i][j]='=';
                }
            }
            if(!v.empty())
            {
                for(i=1;i<(int)v.size();i++)ans[v[i-1]][v[i]]='+',ans[v[i]][v[i-1]]='-';
                ans[v.back()][v[0]]='+',ans[v[0]][v.back()]='-';
            }
            for(i=1;i<=l;i++)
            {
                for(j=1;j<=l;j++)cout << ans[i][j];
                cout << '\n';
            }
        }
    }
    return 0;
}