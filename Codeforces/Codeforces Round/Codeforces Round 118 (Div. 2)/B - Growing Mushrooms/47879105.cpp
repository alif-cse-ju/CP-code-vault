#include<bits/stdc++.h>
using namespace std;
vector<double>ans;
vector<double>gar;
int main()
    int i,j,n;
    double a,b,t1,t2,per,check,check1;
    scanf("%d %lf %lf %lf",&n,&t1,&t2,&per);
    per=per/100.00;
    for(i=0; i<n; i++)
    {
        scanf("%lf %lf",&a,&b);
        check1=a*t1;
        check1=check1-check1*per+b*t2;
        check=b*t1;
        check=check-check*per+a*t2;
        if(check1>check)
        {
            check=check1;
        }
        ans.push_back(check);
        gar.push_back(check);
    }
    sort(gar.begin(),gar.end());
    for(i=0; i<n; i++)
    {
        if(ans[i] == gar[n-1])
        {
            printf("%d %.2lf\n",i+1,ans[i]);
        }
    }
    for(j=n-2; j>=0; j--)
    {
        if(gar[j]!=gar[j+1])
        {
            for(i=0; i<n; i++)
            {
                if(ans[i] == gar[j])
                {
                    printf("%d %.2lf\n",i+1,ans[i]);
                }
            }
        }
    }
    return 0;
}