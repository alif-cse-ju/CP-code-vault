#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int i,x,y;
    for(i=1;i<=5;i++)
    {
        cin >> x;
        if(!x)y=i;
    }
    cout << y;
    return 0;
}
