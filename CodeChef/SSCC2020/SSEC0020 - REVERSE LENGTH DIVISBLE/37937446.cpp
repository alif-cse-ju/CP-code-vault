#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n=0;
    string s;
    cin >> s;
    l=s.size();
    for(i=0;i<l;i++)
    {
        n=n*10+s[i]-'0';
        if(n%(l-i))
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}