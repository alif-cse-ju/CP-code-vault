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
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int cnt[M][26];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,j,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=0;i<m;i++)
        {
            for(j=0;j<26;j++)cnt[i][j]=0;
        }
        for(i=0;i<n;i++)
        {
            cin >> s;
            for(j=0;j<m;j++)++cnt[j][s[j]-'a'];
        }
        for(i=1;i<n;i++)
        {
            cin >> s;
            for(j=0;j<m;j++)++cnt[j][s[j]-'a'];
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<26;j++)
            {
                if(cnt[i][j] & 1)cout << (char)('a'+j);
            }
        }
        cout << endl;
    }
    return 0;
}