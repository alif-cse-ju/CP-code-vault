#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int l,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=s.back()-'0'-1;
        ans=l*10;
        l=s.size();
        ans+=(l*(l+1))/2;
        cout << ans << '\n';
    }
    return 0;
}