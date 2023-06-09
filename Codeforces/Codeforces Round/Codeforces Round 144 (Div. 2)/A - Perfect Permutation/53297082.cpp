#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    if(n & 1)
    {
        cout << -1;
    }
    else
    {
        int i;
        for(i=1;i<=n;i++)
        {
            if(i & 1)
            {
                cout << i + 1 << ' ';
            }
            else
            {
                cout << i - 1 << ' ';
            }
        }
    }
    return 0;