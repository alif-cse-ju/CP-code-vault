#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,j,l,t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=s.size();
        for(i=1;i<l;i++)
        {
            if(s[i] < s[i-1])break;
        }
        if(i < l)
        {
            for(j=i;j<l;j++)s[j]='9';
            for(j=i-1;j>0;j--)
            {
                if(s[j] == s[j-1])s[j]='9';
                else
                {
                    --s[j];
                    break;
                }
            }
            if(j == 0)--s[0];
        }
        if(s[0] > '0')cout << s[0];
        for(i=1;i<l;i++)cout << s[i];
        cout << '\n';
    }
    return 0;
}