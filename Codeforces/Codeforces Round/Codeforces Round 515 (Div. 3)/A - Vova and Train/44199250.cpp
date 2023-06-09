#include<bits/stdc++.h>
using namespace std;
int main()
    long long int i,t,Li,vi,li,ri,j,cnt;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        cnt=0;
        scanf("%lld %lld %lld %lld",&Li,&vi,&li,&ri);
        cnt=li/vi;
        if(li%vi==0)
        {
            cnt--;
        }
        cnt=cnt+(Li/vi)-(ri/vi);
        printf("%lld\n",cnt);
    }
    return 0;