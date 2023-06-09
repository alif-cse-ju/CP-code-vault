#include<bits/stdc++.h>
using namespace std;
int main()
    int n,i,a,ans=-1,flag=0,max=0;
    cin >> n;
    cin >> a;
    if(a!=0)
    {
        ans=1;
        flag=1;
    }
    for(i=1; i<n; i++)
    {
        cin >> a;
        if(flag==0)
        {
            if(a<=max+1)
            {
                if(a>max)
                {
                    max=a;
                }
            }
            else
            {
                ans=i+1;
                flag=1;
            }
        }
    }
    cout << ans;
    return 0;