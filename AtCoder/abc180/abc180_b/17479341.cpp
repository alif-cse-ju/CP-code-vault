#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    long double euclid=0;
    long long x,man=0,cheb=0;
    cin >> n;
    while(n--)
    {
        cin >> x;
        man+=abs(x);
        cheb=max(cheb,abs(x));
        euclid+=x*x;
    }
    cout << man << '\n';
    cout << fixed << setprecision(15) << sqrt(euclid) << '\n';
    cout << cheb << '\n';
    return 0;
}
