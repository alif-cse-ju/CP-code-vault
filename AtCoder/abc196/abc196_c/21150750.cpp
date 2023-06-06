#include<bits/stdc++.h>

using namespace std;

const int M=2e5+5;
const int N=5e2+5;
const int mod=1e9+7;

int l,ll;
string s,ss;
long long ans;

void Solve(int pos,bool start)
{
    if(pos == ll)
    {
        if(ll < l)++ans;
        else ans+=(ss <= s);
        return;
    }
    if(pos < ll/2)
    {
        for(char c=(start ? '1' : '0');c<='9';c++)
        {
            ss+=c;
            Solve(pos+1,0);
            ss.pop_back();
        }
    }
    else
    {
        ss+=ss[pos-ll/2];
        Solve(pos+1,0);
        ss.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    l=(int)s.size();
    ll=2;
    while(ll <= l)
    {
        Solve(0,1);
        ll+=2;
    }
    cout << ans;
    return 0;
}
//