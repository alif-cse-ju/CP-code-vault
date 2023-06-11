#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int n,t,x,y;
    cin  >> t;
    while(t--)
    {
        cin >> n;
        n=4*n-1;
        map<int,int>mpX,mpY;
        while(n--)
        {
            cin >> x >> y;
            ++mpX[x],++mpY[y];
        }
        for(auto it : mpX)
        {
            if(it.second & 1)
            {
                x=it.first;
                break;
            }
        }
        for(auto it : mpY)
        {
            if(it.second & 1)
            {
                y=it.first;
                break;
            }
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}