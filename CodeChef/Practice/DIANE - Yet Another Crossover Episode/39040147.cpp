#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>ans;
        while(n > MAX-2)
        {
            ans.emplace_back(MAX);
            ans.emplace_back(MAX-1);
            ans.emplace_back(1);
            n-=MAX-2;
        }
        ans.emplace_back(n+1);
        ans.emplace_back(n+2);
        cout << ans.size() << '\n';
        for(int it : ans)cout << it << ' ';
        cout << '\n';
    }
    return 0;
}