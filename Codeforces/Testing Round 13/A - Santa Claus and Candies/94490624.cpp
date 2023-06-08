#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x;
    cin >> n;
    for(i=1; ;i++)
    {
        x=(i*(i+1))/2;
        if(x > n)
        {
            x=i-1;
            break;
        }
    }
    cout << x << '\n';
    for(i=1;i<x;i++)cout << i << ' ';
    cout << n-(x*(x-1))/2;
    return 0;
}