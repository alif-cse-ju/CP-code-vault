#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define PB push_back
#define LL long long int
#define PII pair<int,int>
#define PLL pair<long long int,long long int>
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,x,cnt=0,low,high;
    scanf("%d %d",&n,&x);
    low=high=x;
    for(i=1;i<n;i++)
    {
        scanf("%d",&x);
        if(x > high)
        {
            high=x;
            cnt++;
        }
        else if(x < low)
        {
            low=x;
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;