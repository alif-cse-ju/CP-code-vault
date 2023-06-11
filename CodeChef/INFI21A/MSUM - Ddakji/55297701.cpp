#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int g,gp,gn,i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>pos,neg;
        for(i=0;i<n;i++)
        {
            cin >> x;
            if(x > 0)pos.emplace_back(x);
            else if(x < 0)neg.emplace_back(-x);
        }
        gp=0;
        for(int it : pos)gp=__gcd(gp,it);
        gn=0;
        for(int it : neg)gn=__gcd(gn,it);
        g=__gcd(gp,gn);
        if(pos.empty())cout << gn << '\n';
        else if(neg.empty())cout << gp << '\n';
        else
        {
            if(n == 2)cout << gp+gn << '\n';
            else cout << 2*g << '\n';
        }
    }
    return 0;
}