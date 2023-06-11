#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,j,n,t;
    char s[10][10];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=8;i++)
        {
            for(j=1;j<=8;j++)s[i][j]='X';
        }
        n--,s[1][1]='O';
        for(i=1;i<=8  &&  n > 0;i++)
        {
            if(i == 1)j=2;
            else j=1;
            while(j <= 8  &&  n--)s[i][j++]='.';
        }
        for(i=1;i<=8;i++)
        {
            for(j=1;j<=8;j++)cout << s[i][j];
            cout << '\n';
        }
    }
    return 0;
}