#include<bits/stdc++.h>
using namespace std;
vector<int>even,odd;
int main()
    int i,n,x;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        if(x & 1)
        {
            odd.push_back(i);
        }
        else
        {
            even.push_back(i);
        }
    }
    if(odd.size() == 1)
    {
        cout << odd[0];
    }
    else
    {
        cout << even[0];
    }
    return 0;