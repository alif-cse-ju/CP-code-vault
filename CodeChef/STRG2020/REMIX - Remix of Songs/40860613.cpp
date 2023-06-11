#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int l=INT_MAX;
    string s,ans,temp;
    getline(cin,s);
    stringstream ss(s);
    vector<string>v;
    while(ss >> temp)
    {
        if((int)temp.size() < l)
        {
            ans=temp;
            l=(int)temp.size();
        }
        v.emplace_back(temp);
    }
    cout << ans;
    for(string it : v)cout << ' ' << it << ' ' << ans;
    return 0;
}
//1060,1422