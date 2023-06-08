#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
char s[N];
int main()
    FAST();
    bool flag;
    int a,b,i,l,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> s+1;
        l=a+b,flag=1;
        for(i=1;i<=l  &&  flag;i++)
        {
            if(s[i] != '?'  &&  s[l-i+1] != '?')
            {
                if(s[i] != s[l-i+1])flag=0;
                else
                {
                    if(s[i] == '0')
                    {
                        if(a)--a;
                        else flag=0;
                    }
                    else
                    {
                        if(b)--b;
                        else flag=0;
                    }
                }
            }
        }
        for(i=1;i<=l  &&  flag;i++)
        {
            if(s[i] == '?')
            {
                if(s[l-i+1] == '1')
                {
                    if(b > 1)s[i]='1',b-=2;
                    else flag=0;
                }
                else if(s[l-i+1] == '0')
                {
                    if(a > 1)s[i]='0',a-=2;
                    else flag=0;
                }
                else
                {
                    if(i == l-i+1)
                    {
                        if(a & 1)s[i]='0',--a;
                        else if(b & 1)s[i]='1',--b;
                        else flag=0;
                    }
                }
            }
        }
        for(i=1;i<=l  &&  flag;i++)
        {
            if(s[i] == '?')
            {
                if(a > 1)s[i]=s[l-i+1]='0',a-=2;
                else if(b > 1)s[i]=s[l-i+1]='1',b-=2;
                else flag=0;
            }
        }
        if(!flag)cout << "-1\n";
        else
        {
            for(i=1;i<=l;i++)cout << s[i];
            cout << '\n';
        }
    }
    return 0;
}