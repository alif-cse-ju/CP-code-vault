#include<bits/stdc++.h>

using namespace std;

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e5+5;
const int N=2e5+5;
const int mod=998244353;

int C[N];
vector<int>pos[N];
long long dp[N][2],X[N],Y[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,cnt=0;
    cin >> n;
    set<int>st;
    for(i=1;i<=n;i++)
    {
        cin >> X[i] >> C[i];
        st.insert(C[i]);
    }
    map<int,int>idx;
    for(int it : st)idx[it]=++cnt;
    for(i=1;i<=n;i++)pos[idx[C[i]]].emplace_back(X[i]);
    for(i=1;i<=cnt;i++)
    {
        sort(pos[i].begin(),pos[i].end());
        X[i]=pos[i][0],Y[i]=pos[i].back();
        dp[i][0]=min(abs(Y[i]-X[i-1])+dp[i-1][0],abs(Y[i]-Y[i-1])+dp[i-1][1])+Y[i]-X[i];
        dp[i][1]=min(abs(X[i-1]-X[i])+dp[i-1][0],abs(Y[i-1]-X[i])+dp[i-1][1])+Y[i]-X[i];
    }
    cout << min(dp[cnt][0]+abs(X[cnt]),dp[cnt][1]+abs(Y[cnt]));
    return 0;
}
//