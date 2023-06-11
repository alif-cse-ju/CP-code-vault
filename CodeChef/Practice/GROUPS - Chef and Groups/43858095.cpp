#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int t,ans;
    cin >> t;
    while(t--)
    {
        cin >> s;
        ans=0;
        while(!s.empty())
        {
            if(s.back() == '1')
            {
                ++ans;
                while(!s.empty()  &&  s.back() == '1')s.pop_back();
            }
            while(!s.empty()  &&  s.back() == '0')s.pop_back();
        }
        cout << ans << '\n';
    }
    return 0;
}
//