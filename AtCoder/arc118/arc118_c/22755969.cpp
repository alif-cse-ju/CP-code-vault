#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int j,n;
    cin >> n;
    set<int>ans;
    ans.insert(10);
    ans.insert(15);
    for(j=6; j<=1e4  &&  (int)ans.size() < n; j+=6)ans.insert(j);
    for(j=10; j<=1e4  &&  (int)ans.size() < n; j+=10)ans.insert(j);
    for(j=15; j<=1e4  &&  (int)ans.size() < n; j+=15)ans.insert(j);
    for(int it : ans)cout << it << ' ';
    return 0;
}