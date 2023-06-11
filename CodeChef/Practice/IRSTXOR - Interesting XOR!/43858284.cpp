#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,l,t;
    long long a,b,c;
    cin >> t;
    while(t--)
    {
        cin >> c;
        for(i=30;i>=0;i--)
        {
            if((c >> i) & 1)
            {
                l=i;
                break;
            }
        }
        a=b=0;
        for(i=l;i>=0;i--)
        {
            if((c >> i) & 1)
            {
                if(i == l)a|=(1 << i);
                else b|=(1 << i);
            }
            else a|=(1 << i),b|=(1 << i);
        }
        cout << a*b << '\n';
    }
    return 0;
}
//