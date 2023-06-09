#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int m,n;
string s[10];
int Cnt(string x,string y)
    int i,cnt=0;
    for(i=0;i<m;i++)cnt+=(x[i] != y[i]);
    return cnt;
bool Check(string x)
    int i;
    for(i=0;i<n;i++)
    {
        if(Cnt(s[i],x) > 1)return false;
    }
    return true;
int main()
    FAST();
    int i,j,t;
    string ans,temp;
    cin >> t;
    while(t--)
    {
        ans="-1";
        cin >> n >> m;
        for(i=0;i<n;i++)cin >> s[i];
        for(i=0;i<n  &&  ans[0] == '-';i++)
        {
            temp=s[i];
            for(j=0;j<m  &&  ans[0] == '-';j++)
            {
                for(char c='a';c<='z';c++)
                {
                    temp[j]=c;
                    if(Check(temp))
                    {
                        ans=temp;
                        break;
                    }
                    temp[j]=s[i][j];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}