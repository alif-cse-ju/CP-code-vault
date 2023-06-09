#include<bits/stdc++.h>
using namespace std;
int mark[7]= {2,1,1,2,3,1,3};
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int a,aa,b,bb,c,cc,ans,cnt,i,j,check;
    scanf("%d %d %d",&a,&b,&c);
    check=min(a/3,min(b/2,c/2));
    ans=check*7;
    a-=check*3;
    b-=check*2;
    c-=check*2;
    cnt=0;
    for(i=0; i<7; i++)
    {
        aa=a,bb=b,cc=c,j=i,check=0;
        while(1)
        {
            if(mark[j] == 1)
            {
                aa--;
            }
            else if(mark[j] == 2)
            {
                bb--;
            }
            else
            {
                cc--;
            }
            if(aa<0 || bb<0 || cc<0)
            {
                break;
            }
            check++;
            if(j == 6)
            {
                j=0;
            }
            else
            {
                j++;
            }
        }
        cnt=max(cnt,check);
    }
    ans+=cnt;
    printf("%d",ans);
    return 0;
}