#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int mod=1e9+7;
void Solve()
    string s;
    int i,j,l,x=0,y=0,px,py;
    cin >> s;
    l=(int)s.size();
    set<pair<int,int>>st;
    for(i=0;i<l;i++)
    {
        if(s[i] == 'L')--x;
        else if(s[i] == 'R')++x;
        else if(s[i] == 'U')++y;
        else --y;
        st.insert({x,y});
    }
    for(auto it : st)
    {
        px=py=0;
        x=it.first,y=it.second;
        for(j=0;j<l;j++)
        {
            if(s[j] == 'L')
            {
                --px;
                if(px == x  &&  py == y)++px;
            }
            else if(s[j] == 'R')
            {
                ++px;
                if(px == x  &&  py == y)--px;
            }
            else if(s[j] == 'U')
            {
                ++py;
                if(px == x  &&  py == y)--py;
            }
            else
            {
                --py;
                if(px == x  &&  py == y)++py;
            }
        }
        if(px == 0  &&  py == 0)
        {
            cout << x << ' ' << y << '\n';
            return;
        }
    }
    cout << "0 0\n";
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)Solve();
    return 0;
}