#include<bits/stdc++.h>
using namespace std;
const int M=5e3+5;
int l1,l2,dp[M][M];
vector<int>occ,notOcc;
int DP(int pOcc,int pNotOcc)
    if(pOcc == l1)return 0;
    int x=occ[pOcc],y=notOcc[pNotOcc];
    int &ans=dp[x][y];
    if(ans > -1)return ans;
    int rem=l1-pOcc-1;
    ans=abs(x-y)+DP(pOcc+1,pNotOcc+1);
    if(pNotOcc < l2-rem-1)ans=min(ans,DP(pOcc,pNotOcc+1));
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(x)occ.emplace_back(i);
        else notOcc.emplace_back(i);
    }
    l1=(int)occ.size();
    l2=(int)notOcc.size();
    memset(dp,-1,sizeof(dp));
    cout << DP(0,0);
    return 0;