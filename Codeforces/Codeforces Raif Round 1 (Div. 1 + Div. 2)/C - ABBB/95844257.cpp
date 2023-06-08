#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        vector<char>v;
        for(char c : s)
        {
            if(c == 'B')
            {
                if(!v.empty())v.pop_back();
                else v.emplace_back(c);
            }
            else v.emplace_back(c);
        }
        cout << v.size() << '\n';
    }
    return 0;
}