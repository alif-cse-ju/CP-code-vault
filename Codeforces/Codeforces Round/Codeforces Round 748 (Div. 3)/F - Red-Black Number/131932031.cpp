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
const int M=37+5;
const int N=1e6+5;
const int mod=1e9+7;
char s[M];
bool clr[M][M][M][M];
int A,B,n,dp[M][M][M][M];
int DP(int i,int a,int b,int cnt)
    if(i > n)
    {
        if(!a && !b)return abs(cnt-(n-cnt));
        return 100;
    }
    int &ans=dp[i][a][b][cnt];
    if(ans != -1)return ans;
    int x=DP(i+1,(a*10+(s[i]-'0'))%A,b,cnt+1);
    int y=DP(i+1,a,(b*10+(s[i]-'0'))%B,cnt);
    if(x <= y)clr[i][a][b][cnt]=0;
    else clr[i][a][b][cnt]=1;
    return ans=min(x,y);
}
 void Print(int i,int a,int b,int cnt)
{
    if(i > n)
    {
        cout << '\n';
        return;
    }
    if(!clr[i][a][b][cnt])cout << 'R', Print(i+1,(a*10+(s[i]-'0'))%A,b,cnt+1);
    else cout << 'B', Print(i+1,a,(b*10+(s[i]-'0'))%B,cnt);
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> A >> B >> s+1;
        memset(dp,-1,sizeof(dp));
        ans=DP(1,0,0,0);
        if(ans >= n)cout << "-1\n";
        else Print(1,0,0,0);
    }
    return 0;
}