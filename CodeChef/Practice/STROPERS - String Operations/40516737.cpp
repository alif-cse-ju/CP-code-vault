#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,j,l,t,cnt,cnt1;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=(int)s.size();
        set<pair<int,pair<int,int>>>st;
        for(i=0;i<l;i++)
        {
            cnt=cnt1=0;
            for(j=i;j<l;j++)
            {
                if(s[j] == '1')++cnt1;
                if(cnt1 & 1)++cnt;
                st.insert({j-i+1,{cnt1,cnt}});
            }
        }
        cout << (int)st.size() << '\n';
    }
    return 0;
}