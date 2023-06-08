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
char s[405][405];
int main()
    FAST();
    int i,j,n,t,x1,x2,y1,y2;
    cin >> t;
    while(t--)
    {
        cin >> n;
        x1=y1=0;
        for(i=1;i<=n;i++)
        {
            cin >> s[i]+1;
            for(j=1;j<=n;j++)
            {
                if(s[i][j] == '*')
                {
                    if(x1)x2=i,y2=j;
                    else x1=i,y1=j;
                }
            }
        }
        if(x1 == x2)
        {
            if(x1 == n)s[x1-1][y1]=s[x2-1][y2]='*';
            else s[x1+1][y1]=s[x2+1][y2]='*';
        }
        else if(y1 == y2)
        {
            if(y1 == n)s[x1][y1-1]=s[x2][y2-1]='*';
            else s[x1][y1+1]=s[x2][y2+1]='*';
        }
        else s[x1][y2]=s[x2][y1]='*';
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)cout << s[i][j];
            cout << '\n';
        }
    }
    return 0;
}