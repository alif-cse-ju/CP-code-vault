#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    string s;
    int l,t,cnt;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=s.size();
        cnt=0;
        while(l > 1)
        {
            if(s[l-1] != s[l-2])++cnt,--l,s.pop_back();
            s.pop_back(),--l;
        }
        cout << cnt << '\n';
    }
    return 0;
}