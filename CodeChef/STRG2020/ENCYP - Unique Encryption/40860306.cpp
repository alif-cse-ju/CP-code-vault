#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    a[0]=98;
    a[1]=57;
    a[2]=31;
    a[3]=45;
    a[4]=46;
    int i,l,t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        vector<int>v;
        for(char c : s)v.emplace_back(c-'A');
        l=(int)s.size();
        for(i=0;i<l;i++)v[i]=(v[i]+a[i])%26;
        for(int it : v)cout << (char)('A'+it);
        cout << '\n';
    }
    return 0;
}
//1060,1422