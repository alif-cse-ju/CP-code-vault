#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,t;
    string a,b,ans;
    cin >> t;
    while(t--)
    {
        cin >> l >> a;
        b="1";
        if(a[0] == '0')ans="1";
        else ans="2";
        for(i=1;i<l;i++)
        {
            if(a[i] == '1')
            {
                if(ans.back() == '2')
                {
                    b+='0';
                    ans+='1';
                }
                else
                {
                    b+='1';
                    ans+='2';
                }
            }
            else
            {
                if(ans.back() == '1')
                {
                    b+='0';
                    ans+='0';
                }
                else
                {
                    b+='1';
                    ans+='1';
                }
            }
        }
        cout << b << '\n';
    }
    return 0;
}