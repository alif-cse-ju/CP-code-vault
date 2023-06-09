#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << fixed << setprecision(10) << 1.0/(2.0*sin(PI/(4.0*n))) << '\n';
    }
    return 0;