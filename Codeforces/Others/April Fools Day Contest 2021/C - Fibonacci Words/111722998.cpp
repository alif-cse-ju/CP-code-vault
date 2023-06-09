#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l;
    string s;
    cin >> s;
    l=(int)s.size();
    for(i=2;i<l;i++)
    {
        if('A'+(((s[i-2]-'A')+(s[i-1]-'A'))%26) != s[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;