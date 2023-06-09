#include<bits/stdc++.h>
using namespace std;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,m,cnt=0;
    scanf("%d %d",&n,&m);
    if(m < n)
    {
        printf("-1");
    }
    else if(m == n)
    {
        printf("0");
    }
    else if(m%n != 0)
    {
        printf("-1");
    }
    else
    {
        int check=m/n;
        while(check%2 == 0)
        {
            cnt++;
            check/=2;
        }
        while(check%3 == 0)
        {
            cnt++;
            check/=3;
        }
        if(check == 1)
        {
            printf("%d\n",cnt);
        }
        else
        {
            printf("-1");
        }
    }
    return 0;
}
 