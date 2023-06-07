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
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s[50];
    int c,cnt,i,j,m,n,r,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> r >> c;
        for(cnt=i=0;i<n;i++)
        {
            cin >> s[i];
            for(char &c : s[i])cnt += (c == 'B');
        }
        if(!cnt)cout << "-1\n";
        else
        {
            --r, --c;
            if(s[r][c] == 'B')cout << "0\n";
            else
            {
                cnt=0;
                for(i=0;i<m;i++)cnt += (s[r][i] == 'B');
                if(cnt)cout << "1\n";
                else
                {
                    cnt=0;
                    for(i=0;i<n;i++)cnt += (s[i][c] == 'B');
                    if(cnt)cout << "1\n";
                    else cout << "2\n";
                }
            }
        }
    }
    return 0;
}