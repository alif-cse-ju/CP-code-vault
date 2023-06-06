#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '?')s[i]='D';
    }
    cout << s;
    return 0;
}
