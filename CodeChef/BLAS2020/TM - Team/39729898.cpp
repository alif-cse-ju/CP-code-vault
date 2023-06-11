#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s,temp;
    int i,n,t,r,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> r;
        set<string>st;
        map<string,int>mp;
        map<string,string>mp2;
        for(i=0;i<n;i++)
        {
            cin >> s >> x;
            temp=s;
            sort(s.begin(),s.end());
            st.insert(s);
            mp[s]+=x;
            if(i < r)mp2[s]=temp;
        }
        vector<pair<int,string>>v;
        for(string it : st)v.emplace_back(-mp[it],mp2[it]);
        sort(v.begin(),v.end());
        for(auto it : v)cout << it.second << ' ' << -it.first << '\n';
    }
    return 0;
}