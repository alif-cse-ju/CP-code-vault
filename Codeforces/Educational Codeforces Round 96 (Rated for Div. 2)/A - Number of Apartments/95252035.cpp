#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n;
        x=y=z=0;
        for(i=0;i*3<=n;i++)
        {
            m=n-i*3;
            {
                for(j=0;j*5<=m;j++)
                {
                    if((m-j*5)%7 == 0)
                    {
                        x=i;
                        y=j;
                        z=(m-j*5)/7;
                        break;
                    }
                }
            }
            if(x  ||  y  ||  z)break;
        }
        if(x  ||  y  ||  z)cout << x << ' ' << y << ' ' << z << '\n';
        else cout << "-1\n";
    }
    return 0;
}