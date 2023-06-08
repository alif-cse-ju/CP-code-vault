#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    string s,ss;
    int i,j,l,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l=(int)s.size();
        ans=0,ss="";
        for(i=1;i<l;i++)ans+=9;
        for(i=0;i<l;i++)ss+='0';
        for(i=1;i<10;i++)
        {
            for(j=0;j<l;j++)ss[j]=(char)('0'+i);
            if(ss <= s)++ans;
            else break;
        }
        cout << ans << '\n';
    }
    return 0;