#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,ans;
    string s;
    cin >> l >> ans >> s;
    for(char c : s)
    {
        if(c == 'o')++ans;
        else ans=max(0,ans-1);
    }
    cout << ans;
    return 0;
}
