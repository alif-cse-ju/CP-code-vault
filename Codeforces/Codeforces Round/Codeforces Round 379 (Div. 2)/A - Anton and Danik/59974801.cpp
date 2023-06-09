#include<bits/stdc++.h>
using namespace std;
int main()
    int i,n,a_cnt=0,d_cnt=0;
    scanf("%d",&n);
    char s[n+3];
    scanf("%s",s);
    for(i=0; i<n; i++)
    {
        if(s[i] == 'A')
        {
            a_cnt++;
        }
        else
        {
            d_cnt++;
        }
    }
    if(a_cnt > d_cnt)
    {
        printf("Anton");
    }
    else if(d_cnt > a_cnt)
    {
        printf("Danik");
    }
    else
    {
        printf("Friendship");
    }
    return 0;