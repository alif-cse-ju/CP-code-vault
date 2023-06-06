#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int Check(int x,int y,int z)
{
    return x*x+y*y+z*z+x*y+x*z+y*z;
}

int main()
{
    FAST();
    int i,j,k,n,x,cnt[10002]={0};
    cin >> n;
    for(i=1;i<101;i++)
    {
        for(j=1;j<101;j++)
        {
            for(k=1;k<101;k++)
            {
                x=Check(i,j,k);
                if(x <= n)++cnt[x];
            }
        }
    }
    for(i=1;i<=n;i++)cout << cnt[i] << '\n';
    return 0;
}
