#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l;
    string s;
    vector<char>v;
    cin >> l >> s;
    for(char c : s)
    {
        if(c == 'x')
        {
            l=(int)v.size();
            if(l > 1  &&  v[l-2] == 'f'  &&  v[l-1] == 'o')
            {
                v.pop_back();
                v.pop_back();
            }
            else v.emplace_back(c);
        }
        else v.emplace_back(c);
    }
    cout << (int)v.size();
    return 0;
}
