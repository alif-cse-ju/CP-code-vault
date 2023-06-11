#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        l--;
        for(i=0;i<l;i++)
        {
            if(s[i] == s.back())
            {
                cout << "YES\n";
                break;
            }
        }
        if(i == l)cout << "NO\n";
    }
    return 0;
}