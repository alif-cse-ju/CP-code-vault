#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,a[1002];
    vector<int>ans;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    ans.emplace_back(a[1]);
    for(i=2;i<=n;i++)
    {
        if(__gcd(a[i],a[i-1]) > 1)ans.emplace_back(1);
        ans.emplace_back(a[i]);
    }
    cout << (int)ans.size()-n << '\n';
    for(int x : ans)cout << x << ' ';
    return 0;