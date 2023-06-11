#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    long long int i,n,t,l,cnt,temp;
    char s[1000010],c;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        scanf("%s %c",&s,&c);
        l=cnt=temp=0;
        for(i=0; i<n; i++)
        {
            if(s[i] == c)
            {
                cnt+=(((i-l)*(i-l+1))/2);
                l=i+1;
                temp++;
            }
        }
        if(temp == 0)
        {
            printf("0\n");
        }
        else
        {
            if(l > 0 && l < n)
            {
                cnt+=(((i-l)*(i-l+1))/2);
            }
            printf("%lld\n",(n*(n+1))/2-cnt);
        }
    }
    return 0;
}