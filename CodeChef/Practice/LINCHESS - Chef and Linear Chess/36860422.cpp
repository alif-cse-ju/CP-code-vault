#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,k,n,t,x,mn,pos;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        mn=INT_MAX;
        while(n--)
        {
            cin >> x;
            if(x < k)
            {
                if((k-x)%x == 0)
                {
                    i=x;
                    x=(k-x)/x;
                    if(x < mn)pos=i,mn=x;
                }
            }
        }
        if(mn == INT_MAX)cout << "-1\n";
        else cout << pos << '\n';
    }
    return 0;
}