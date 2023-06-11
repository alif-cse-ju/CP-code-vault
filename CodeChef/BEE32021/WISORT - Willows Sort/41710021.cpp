#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,n,t,tc;
    cin >> t;
    for(tc=1;tc<=t;tc++)
    {
        cin >> n;
        vector<string>v;
        for(i=0;i<n;i++)
        {
            cin >> s;
            reverse(s.begin(),s.end());
            v.emplace_back(s);
        }
        sort(v.begin(),v.end());
        cout << "Case " << tc << ":\n";
        for(i=0;i<n;i++)
        {
            reverse(v[i].begin(),v[i].end());
            cout << v[i] << '\n';
        }
    }
    return 0;
}