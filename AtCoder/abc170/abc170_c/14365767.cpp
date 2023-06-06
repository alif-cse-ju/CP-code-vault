#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    bool mark[105]={0};
    int i,n,x,y,z;
    cin >> x >> n;
    while(n--)
    {
        cin >> y;
        mark[y]=1;
    }
    for(i=x-1;i>-1;i--)
    {
        if(!mark[i])
        {
            y=i;
            break;
        }
    }
    for(i=x;i<102;i++)
    {
        if(!mark[i])
        {
            z=i;
            break;
        }
    }
    if(z-x < x-y)cout << z;
    else cout << y;
    return 0;
}
