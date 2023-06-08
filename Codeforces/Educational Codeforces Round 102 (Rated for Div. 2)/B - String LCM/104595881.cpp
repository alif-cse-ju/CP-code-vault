#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string a,b,aa,bb;
    int gcd,i,lcm,la,lb,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        la=(int)a.size();
        lb=(int)b.size();
        lcm=(la*lb)/__gcd(la,lb);
        aa=bb="";
        for(i=0;i<lcm/la;i++)aa+=a;
        for(i=0;i<lcm/lb;i++)bb+=b;
        if(aa == bb)cout << aa << '\n';
        else cout << "-1\n";
    }
    return 0;