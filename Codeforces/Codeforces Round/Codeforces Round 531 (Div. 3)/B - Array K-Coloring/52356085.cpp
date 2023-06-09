#include<bits/stdc++.h>
using namespace std;
int a[5010];
int mark[5010];
vector<int>ans[5010];
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,n,k,cnt=0;
    scanf("%d %d",&n,&k);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        mark[a[i]]++;
    }
    for(i=1; i<=5000; i++)
    {
        if(mark[i] > k)
        {
            printf("NO\n");
            return 0;
        }
        else
        {
            for(j=0; j<mark[i]; j++)
            {
                ans[i].push_back(cnt%k+1);
                cnt++;
            }
        }
    }
    memset(mark,0,sizeof(mark));
    printf("YES\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",ans[a[i]][mark[a[i]]++]);
    }
    return 0;
}