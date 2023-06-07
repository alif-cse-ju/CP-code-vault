#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
#define PI acos(-1)
#define ll long long
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;
char s[M],ss[M];
int dp[M],pre[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        cin >> s+1;
        int cnto=0,cntc=0,cntq=0;
        int l=strlen(s+1);
        for(int i=1;i<=l;i++)
        {
            if(s[i] == '?')++cntq;
            else if(s[i] == '(')++cnto;
            else ++cntc;
        }
        if(l == 2  ||  cnto == l/2  ||  cntc == l/2)cout << "YES\n";
        else if(cntc == l/2-1  &&  s[l] == '?')cout << "YES\n";
        else
        {
            for(int i=1;i<=l;i++)ss[i]=s[i];
            int needO=l/2-cnto, mn=INT_MAX,L,R=INT_MAX;
            for(int i=1;i<=l;i++)
            {
                if(ss[i] == '?')
                {
                    if(needO)ss[i]='(', --needO, L=i;
                    else ss[i]=')', R=min(R, i);
                }
                if(ss[i] == '(')dp[i]=1;
                else dp[i]=-1;
            }
            swap(dp[L],dp[R]);
            for(int i=1;i<=l;i++)pre[i]=pre[i-1]+dp[i];
            for(int i=1;i<=l;i++)mn=min(mn, pre[i]);
            if(mn >= 0)cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}