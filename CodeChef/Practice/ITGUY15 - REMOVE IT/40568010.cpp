#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l,t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        vector<char>v;
        for(char c : s)
        {
            if(c == 'c')
            {
                l=(int)v.size();
                if(l > 1  &&  v[l-2] == 'a'  &&  v[l-1] == 'b')
                {
                    v.pop_back();
                    v.pop_back();
                }
                else v.emplace_back(c);
            }
            else v.emplace_back(c);
        }
        for(char c : v)cout << c;
        cout << '\n';
    }
    return 0;
}