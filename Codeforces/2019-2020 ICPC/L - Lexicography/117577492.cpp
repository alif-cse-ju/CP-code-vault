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
const int M=1e3+5;
const int N=2e5+5;
const int mod=1e9+7;
int len[M];
char ans[M][M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,j,k,l,n,pvt=1;
    cin >> n >> l >> k >> s;
    sort(s.begin(),s.end());
    deque<int>dq;
    for(char c : s)dq.emplace_back(c);
    for(i=1;i<=l;i++)
    {
        for(j=pvt;j<=k;j++)
        {
            ans[j][++len[j]]=dq.front();
            dq.pop_front();
        }
        while(pvt < k)
        {
            if(ans[pvt][i] == ans[k][i])break;
            ++pvt;
        }
    }
    for(i=1;i<=n;i++)
    {
        while(len[i] < l)
        {
            ans[i][++len[i]]=dq.front();
            dq.pop_front();
        }
        for(j=1;j<=l;j++)cout << ans[i][j];
        cout << '\n';
    }
    return 0;
}