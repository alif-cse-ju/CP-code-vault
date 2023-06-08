#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
const int N=1e3+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,l,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> s;
        vector<pair<char,int>>v;
        reverse(s.begin(),s.end());
        while(!s.empty())
        {
            v.emplace_back(s.back(),0);
            while(!s.empty()  &&  s.back() == v.back().first)
            {
                ++v.back().second;
                s.pop_back();
            }
        }
        l=(int)v.size();
        x=INT_MAX,y=-1;
        for(i=0;i<l;i++)
        {
            if(v[i].first == '1'  &&  v[i].second > 1)x=min(x,i);
            else if(v[i].first == '0'  &&  v[i].second > 1)y=max(y,i);
        }
        if(x > y)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
//