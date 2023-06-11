#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    FAST();
    int i,j,rt,t,x,y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        rt=sqrt(x+y);
        if(rt*rt != x+y)cout << "NO\n";
        else
        {
            for(i=1;i<rt;i++)
            {
                if(i*i+(rt-i)*(rt-i) == x  &&  2*i*(rt-i) == y)
                {
                    cout << "YES\n" << rt << '\n';
                    for(j=1;j<=rt-i;j++)cout << "1 " << j+1 << '\n';
                    for(j=2;j<=i;j++)cout << "2 " << rt-i+j << '\n';
                    break;
                }
            }
            if(i == rt)cout << "NO\n";
        }
    }
    return 0;
}