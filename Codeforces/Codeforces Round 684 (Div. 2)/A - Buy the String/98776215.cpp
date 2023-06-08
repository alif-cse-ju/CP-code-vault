#include<bits/stdc++.h>
 using namespace std;
 const int N=1e5+5;
const int mod=1e9+7;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int c0,c1,h,i,n,t,cnt0,cnt1;
    cin >> t;
    while(t--)
    {
        cin >> n >> c0 >> c1 >> h >> s;
        cnt0=cnt1=0;
        for(i=0;i<n;i++)
        {
            if(s[i] == '0')++cnt0;
            else ++cnt1;
        }
        cout << min(c0*cnt0+c1*cnt1,min(c0*cnt0+(h+c0)*cnt1,c1*cnt1+(h+c1)*cnt0)) << '\n';
    }
    return 0;
}