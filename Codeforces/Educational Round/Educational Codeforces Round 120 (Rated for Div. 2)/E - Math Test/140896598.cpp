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
const int M=1e4+5;
const int N=2e6+5;
const int mod=1e9+7;
string score[M];
int ans[M],cur[M];
vector<int>ids[12];
ll curScore[M],expectedScore[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mx,tmp;
    int cnt,i,j,l,m,mask,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=0;i<n;i++)cin >> expectedScore[i];
        for(i=0;i<n;i++)cin >> score[i], score[i]="#"+score[i];
        l=(1 << n), mx=0;
        for(i=1;i<=m;i++)ans[i]=i;
        for(mask=0;mask<l;mask++)
        {
            for(i=1;i<=m;i++)
            {
                cnt=0;
                for(j=0;j<n;j++)
                {
                    if(((mask >> j) & 1) == (score[j][i]-'0'))++cnt;
                }
                ids[cnt].emplace_back(i);
            }
            cnt=m;
            for(i=n;i>=0;i--)
            {
                while(!ids[i].empty())cur[ids[i].back()]=cnt--, ids[i].pop_back();
            }
            for(i=tmp=0;i<n;i++)
            {
                curScore[i]=0;
                for(j=1;j<=m;j++)
                {
                    if(score[i][j] == '1')curScore[i] += cur[j];
                }
                tmp += abs(expectedScore[i] - curScore[i]);
            }
            if(tmp > mx)
            {
                mx=tmp;
                for(i=1;i<=m;i++)ans[i]=cur[i];
            }
        }
        for(i=1;i<=m;i++)cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}