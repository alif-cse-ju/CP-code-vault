#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int mod=1e9+7;
int n,a[N],dp[N],tree[N];
void Update(int i,int val)
    ++i;
    while(i <= n)
    {
        tree[i]=max(val,tree[i]);
        i+=i & (-i);
    }
int Query(int i)
    ++i;
    int ans=0;
    while(i > 0)
    {
        ans=max(ans,tree[i]);
        i-=i & (-i);
    }
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ++n;
        for(i=1;i<=n;i++)tree[i]=0;
        stack<int>stk;
        stk.emplace(0);
        for(i=1;i<n;i++)
        {
            cin >> a[i];
            dp[i]=Query(a[i])+1;
            Update(a[i],dp[i]);
            while(!stk.empty()  &&  a[stk.top()] <= a[i])
            {
                Update(a[stk.top()],dp[stk.top()]+1);
                stk.pop();
            }
            stk.emplace(i);
        }
        cout << *max_element(dp+1,dp+n) << '\n';
    }
    return 0;
}