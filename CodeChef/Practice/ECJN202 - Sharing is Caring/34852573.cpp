#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,t,x,sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=0;
        for(i=0;i<n;i++)cin >> x,sum+=x;
        if(sum%n)cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}