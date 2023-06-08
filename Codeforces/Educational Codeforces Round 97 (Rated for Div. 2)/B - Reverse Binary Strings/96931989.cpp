#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,l,t,cnt;
    cin >> t;
    while(t--)
    {
        cin >> l >> s;
        cnt=0;
        for(i=1;i<l;i++)
        {
            if(s[i] == s[i-1])++cnt;
        }
        cout << (cnt+1)/2 << '\n';
    }
    return 0;
}