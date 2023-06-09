#include<bits/stdc++.h>
using namespace std;
long long int rate[55],cnt=0,point[7],ans[7],mark[7];
int main()
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        cin >> rate[i];
    }
    for(i=0; i<5; i++)
    {
        cin >> point[i];
        mark[i]=point[i];
    }
    sort(point,point+5);
    for(i=0; i<n; i++)
    {
        cnt+=rate[i];
        for(j=4; j>=0; j--)
        {
            if(cnt>=point[j])
            {
                for(k=0; k<5; k++)
                {
                    if(point[j] == mark[k])
                    {
                        ans[k]+=cnt/point[j];
                    }
                }
                cnt=cnt%point[j];
            }
        }
    }
    printf("%lld",ans[0]);
    for(i=1; i<5; i++)
    {
        printf(" %lld",ans[i]);
    }
    printf("\n%lld",cnt);
    return 0;
}