#include<bits/stdc++.h>
using namespace std;
bool mark[1000010];
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    memset(mark,0,sizeof(mark));
    int i,m,n,k,x,y,ans=1;
    bool flag=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0; i<m; i++)
    {
        scanf("%d",&x);
        mark[x]=1;
    }
    for(i=0; i<k; i++)
    {
        scanf("%d %d",&x,&y);
        if(flag == 0)
        {
            if(mark[ans] == 1)
            {
                flag=1;
            }
            else
            {
                if(ans == x)
                {
                    ans=y;
                }
                else if(ans == y)
                {
                    ans=x;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}