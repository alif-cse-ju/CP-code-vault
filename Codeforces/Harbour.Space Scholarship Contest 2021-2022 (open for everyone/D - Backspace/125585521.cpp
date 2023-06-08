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
const int mod=1e9+7;
char a[M],b[M];
int la,lb,dp[M][2];
ordered_set<int>pos[26][2];
int DP(int idxB,int idxA)
    if(idxB > lb)return (idxA%2 == la%2);
    int &ans=dp[idxB][idxA%2];
    if(ans > -1)return ans;
    ans=0;
    int idx=pos[b[idxB]-'a'][1-idxA%2].order_of_key(idxA);
    if(idx < (int)pos[b[idxB]-'a'][1-idxA%2].size())ans |= DP(idxB+1,*(pos[b[idxB]-'a'][1-idxA%2].find_by_order(idx)));
    return ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,i,t;
    cin >> t;
    while(t--)
    {
        cin >> a+1 >> b+1;
        la=strlen(a+1);
        lb=strlen(b+1);
        if(la < lb)cout << "NO\n";
        else
        {
            for(i=1;i<=lb;i++)dp[i][0]=dp[i][1]=-1;
            for(i=0;i<26;i++)pos[i][0].clear(),pos[i][1].clear();
            for(i=1;i<=la;i++)pos[a[i]-'a'][i%2].insert(i);
            ans=DP(1,0) | DP(1,1);
            if(ans)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}