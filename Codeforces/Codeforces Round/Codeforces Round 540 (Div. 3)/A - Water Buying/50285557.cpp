#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    long long int n,a,b,check1,check2;
    cin >> q;
    while(q--)
    {
        cin >> n >> a >> b;
        if(n == 1)
        {
            cout << a << endl;
        }
        else
        {
            check1=n*a;
            if(n%2 == 0)
            {
                check2=(n/2)*b;
            }
            else
            {
                check2=(n/2)*b+a;
            }
            cout << min(check1,check2) << endl;
        }
    }
    return 0;