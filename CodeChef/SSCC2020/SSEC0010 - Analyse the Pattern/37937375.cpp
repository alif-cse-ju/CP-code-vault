#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        n%=7;
        if(n == 0)n=7;
        if(n == 1  ||  n == 7)cout << "83\n";
        else if(n == 2  ||  n == 6)cout << "83 83\n";
        else if(n == 3  ||  n == 5)cout << "83 83 69\n";
        else cout << "83 83 69 67\n";
    }
    return 0;
}