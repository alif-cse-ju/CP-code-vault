#include<bits/stdc++.h>
 using namespace std;
 const int N=5e5+5;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin >> x;
                cout << x+(x%2 == (i+j)%2) << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}