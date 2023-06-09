#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define PB push_back
#define LL long long int
#define PII pair<int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    MII mp;
    int i,x,mark=0;
    for(i=0;i<4;i++)
    {
        scanf("%d",&x);
        if(mp[x] == 0)
        {
            mp[x]=++mark;
        }
    }
    printf("%d",4-mark);
    return 0;