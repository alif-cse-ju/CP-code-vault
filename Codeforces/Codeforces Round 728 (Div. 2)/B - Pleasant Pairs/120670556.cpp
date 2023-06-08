#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<queue>
#define maxn 200005
#define inf 10000000
#define LL long long
#define lowbit(x) (x&(-x))
using namespace std;
int t;
int n;
int a[maxn];
int flag[maxn];
void standing_by()
    scanf("%d",&t);
void complete()
    int i,j;
    int cnt=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        flag[a[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j*a[i]<=n*2;j++)
            if (flag[j]&&flag[j]>i)
            {
                if (i+flag[j]==j*a[i]) cnt++;
            }
    }
    printf("%d\n",cnt);
     for(i=1;i<=n;i++) flag[a[i]]=0;
}
 int main()
{
    standing_by();
    for(;t;t--)
        complete();
    return 0;
}