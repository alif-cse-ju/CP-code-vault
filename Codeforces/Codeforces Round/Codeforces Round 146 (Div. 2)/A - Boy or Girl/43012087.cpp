#include<bits/stdc++.h>
using namespace std;
int a[30];
int main()
    int i,l,cnt=0;
    char c[110];
    scanf("%s",&c);
    l=strlen(c);
    for(i=0; i<l; i++)
    {
        a[c[i]-96]=1;
    }
    for(i=1; i<=26; i++)
    {
        if(a[i]==1)
        {
            cnt++;
        }
    }
    if(cnt%2==0)
    {
        printf("CHAT WITH HER!");
    }
    else
    {
        printf("IGNORE HIM!");
    }
    return 0;