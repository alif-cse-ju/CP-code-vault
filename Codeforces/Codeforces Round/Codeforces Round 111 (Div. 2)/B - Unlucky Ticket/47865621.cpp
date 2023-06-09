#include<bits/stdc++.h>
using namespace std;
vector<int>num1;
vector<int>num2;
int main()
    int i,n;
    bool flag=0;
    char c[210];
    scanf("%d",&n);
    scanf("%s",c);
    for(i=0; i<n; i++)
    {
        num1.push_back(c[i]-48);
    }
    for(i=n; i<2*n; i++)
    {
        num2.push_back(c[i]-48);
    }
    sort(num1.begin(),num1.end());
    sort(num2.begin(),num2.end());
    for(i=0; i<n; i++)
    {
        if(num1[i]>=num2[i])
        {
            flag=1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("YES\n");
    }
    else
    {
        flag=0;
        for(i=0; i<n; i++)
        {
            if(num1[i]<=num2[i])
            {
                printf("NO\n");
                flag=1;
                break;
            }
        }
        if(flag == 0)
        {
            printf("YES\n");
        }
    }
    return 0;
}