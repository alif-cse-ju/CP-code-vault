#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    string s;
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        s="";
        for(i=0;i<100;i++)s+='a';
        cout << s << '\n';
        for(i=0;i<n;i++)
        {
            cin >> x;
            if(s[x] == 'a')s[x]='b';
            else s[x]='a';
            cout << s << '\n';
        }
    }
    return 0;