#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
const int mod=1e9+7;

int l;
string s,x;
bool dp[N][7],visited[N][7];

bool DP(int pos,int val)
{
    if(pos == l)return (val == 0);
    if(visited[pos][val])return dp[pos][val];
    visited[pos][val]=1;
    bool &ans=dp[pos][val];
    if(x[pos] == 'T')
    {
        ans=0;
        ans |= DP(pos+1,(val*10)%7);
        ans |= DP(pos+1,(val*10+s[pos]-48)%7);
    }
    else
    {
        ans=1;
        ans &= DP(pos+1,(val*10)%7);
        ans &= DP(pos+1,(val*10+s[pos]-48)%7);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> s >> x;
    if(DP(0,0))cout << "Takahashi";
    else cout << "Aoki";
    return 0;
}
//