#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int i,x,y;
    cin >> x >> y;
    if(y & 1)cout << "No";
    else
    {
        for(i=0;i<=y && i/2<=x;i+=2)
        {
            if(i+(x-i/2)*4 == y)
            {
                cout << "Yes";
                return 0;
            }
        }
        cout << "No";
    }
    return 0;
}
