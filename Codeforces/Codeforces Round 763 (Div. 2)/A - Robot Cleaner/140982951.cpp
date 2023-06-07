// Problem: A. Robot Cleaner
// Contest: Codeforces - Codeforces Round #763 (Div. 2)
// URL: https://codeforces.com/contest/1623/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
#include<bits/stdc++.h>
using namespace std;
int main()
 int a,ans,b,c,d,m,n,t;
 cin >> t;
 while(t--)
 {
  cin >> n >> m >> a >> b >> c >> d;
  ans=INT_MAX;
  if(a <= c)ans=min(ans,c-a);
  else ans=min(ans,n-c+n-a);
    if(b <= d)ans=min(ans,d-b);
  else ans=min(ans,m-d+m-b);
    cout << ans << '\n';
 }
 return 0;