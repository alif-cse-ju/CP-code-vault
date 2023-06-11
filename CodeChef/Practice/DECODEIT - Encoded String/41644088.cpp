#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,j,l,t,cnt;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        for(i=0;i<l;i+=4)
        {
            cnt=0;
            for(j=i;j<i+4;j++)
            {
                if(s[j] == '1')cnt+=(1 << (3-j%4));
            }
            cout << (char)('a'+cnt);
        }
        cout << '\n';
    }
    return 0;
}