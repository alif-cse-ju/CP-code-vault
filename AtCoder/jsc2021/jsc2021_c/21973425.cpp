#include<bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=1e3+5;
const int N=2e5+5;
const int mod=1e9+7;

int main()
{
    FAST();
    int i,a,b,l,r,ans=0;
    cin >> a >> b;
    for(i=1;i<=b;i++)
    {
        l=(a+i-1)/i,r=b/i;
        if(l < r)ans=i;
    }
    cout << ans;
    return 0;
}
