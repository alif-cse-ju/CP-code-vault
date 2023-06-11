#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int m,n,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>v;
        m=n;
        while(m)
        {
            v.emplace_back(m%10);
            m/=10;
        }
        ans=0;
        for(int it : v)
        {
            if(!it)continue;
            if(n%it == 0)++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}