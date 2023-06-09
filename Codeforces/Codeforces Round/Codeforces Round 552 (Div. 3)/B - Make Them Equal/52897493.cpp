#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,n,mark,ans,a[105],main_ans=INT_MAX;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    if(n == 2)
    {
        if((a[1]-a[0])%2 == 0)
        {
            printf("%d",(a[1]-a[0])/2);
        }
        else
        {
            printf("%d",a[1]-a[0]);
        }
    }
    else
    {
        for(i=a[0]; i<=a[n-1]; i++)
        {
            mp.clear();
            mark=0;
            ans=0;
            for(j=0; j<n; j++)
            {
                if(mp[abs(i-a[j])] == 0)
                {
                    mp[abs(i-a[j])]=++mark;
                    if(abs(i-a[j]) > 0)
                    {
                        ans=abs(i-a[j]);
                    }
                }
            }
            if(mark == 1)
            {
                printf("%d",ans);
                return 0;
            }
            else if(mark == 2  &&  mp[0] > 0)
            {
                main_ans=min(main_ans,ans);
            }
        }
        if(main_ans < INT_MAX)
        {
            printf("%d",main_ans);
        }
        else
        {
            printf("-1");
        }
    }
    return 0;
}