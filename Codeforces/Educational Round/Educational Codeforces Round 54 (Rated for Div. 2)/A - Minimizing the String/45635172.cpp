#include<bits/stdc++.h>
using namespace std;
char c[1000010];
int main()
    int l,i,max=0,flag,flag2=0;
    cin >> l;
    getchar();
    cin >> c[0];
    for(i=1; i<l; i++)
    {
        cin >> c[i];
        if(c[i-1]>c[i] && flag2==0)
        {
            max=c[i]-'a'+1;
            flag=i-1;
            flag2=1;
        }
    }
    if(flag2==0)
    {
        flag=l-1;
    }
    for(i=0; i<l; i++)
    {
        if(i!=flag)
        {
            printf("%c",c[i]);
        }
    }
    return 0;