#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=(int)s.size();
        for(i=0;i<l;i++)
        {
            if(i & 1)
            {
                if(s[i] == 'z')cout << 'y';
                else cout << 'z';
            }
            else
            {
                if(s[i] == 'a')cout << 'b';
                else cout << 'a';
            }
        }
        cout << '\n';
    }
    return 0;