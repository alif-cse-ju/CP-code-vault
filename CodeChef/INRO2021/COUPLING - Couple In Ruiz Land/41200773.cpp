#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n;
    long long x,y;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x;
        if(x == 2)y=1;
        else
        {
            y=0;
            for(j=0;j<31;j++)
            {
                if(j == 1)
                {
                    if(!((x >> j) & 1))y |= (1 << j);
                }
                else
                {
                    if((x >> j) & 1)y |= (1 << j);
                }
            }
        }
        cout << y << ' ';
    }
    return 0;
}