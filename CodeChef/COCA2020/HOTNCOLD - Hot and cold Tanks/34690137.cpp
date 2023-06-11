#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int n,t,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y;
        z=y-x;
        if(z%3 == 0  &&  z/3 <= n)cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}