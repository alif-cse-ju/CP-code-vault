#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define LL long long
#define PB push_back
#define PII pair<int,int>
#define PLL pair<long long int,long long int>
map<int,int>mp;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int  n,cnt=0;
    scanf("%d",&n);
    if(n%10 == 0)
    {
        n++;
        cnt++;
    }
    while(mp[n] == 0)
    {
        while(n%10 == 0)
        {
            n/=10;
        }
        if(mp[n] == 0)
        {
            mp[n]=1;
            cnt++;
            n++;
        }
        else
        {
            break;
        }
    }
    printf("%d",cnt);
    return 0;
}