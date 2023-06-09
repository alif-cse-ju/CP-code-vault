#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,a,b;
    cin >> a >> b;
    for(i=0;i<31;i++)
    {
        if(((a >> i) & 1)  &&  ((b >> i) & 1))
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;