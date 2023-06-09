#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,k,l;
    vector<int>v;
    cin >> s >> k;
    l=(int)s.size();
    k=l-k;
    v.emplace_back(0);
    for(i=1;i<l;i++)
    {
        while(!v.empty()  &&  s[i] < s[v.back()]  && k)
        {
            --k;
            v.pop_back();
        }
        v.emplace_back(i);
    }
    while(k)
    {
        --k;
        v.pop_back();
    }
    for(int it : v)cout << s[it];
    return 0;