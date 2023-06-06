#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long i,s,p;
    cin >> s >> p;
    for(i=1;i*i<=p;i++)
    {
        if(p%i == 0)
        {
            if(i+p/i == s)
            {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}
