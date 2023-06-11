#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    vector<pair<char,int>>v;
    cin >> s;
    for(char c : s)
    {
        if(v.empty()  ||  v.back().first != c)
        {
            while(!v.empty()  &&  v.back().second%2 == 0)v.pop_back();
            if(v.empty()  ||  v.back().first != c)v.emplace_back(c,0);
        }
        ++v.back().second;
    }
    s="";
    for(auto it : v)
    {
        if(it.second & 1)s+=it.first;
    }
    if(s.empty())cout << "Empty String";
    else cout << s;
    return 0;
}
//