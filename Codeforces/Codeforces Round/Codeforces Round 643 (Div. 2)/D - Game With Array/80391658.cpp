#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,n,x,y,sum;
    cin >> n >> sum;
    if(sum/n == 1)cout << "NO";
    else
    {
        cout << "YES\n";
        x=sum/n,y=sum%n;
        for(i=1;i<=n;i++)
        {
            if(i <= y)cout << x+1 << ' ';
            else cout << x << ' ';
        }
        cout << "\n1";
    }
    return 0;