#include<bits/stdc++.h>

using namespace std;

int X[102],Y[102];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,k,n;
    cin >> n;
    for(i=1;i<=n;i++)cin >> X[i] >> Y[i];
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=j+1;k<=n;k++)
            {
                if((X[k]-X[i]) * (Y[i]-Y[j])  ==  (Y[k]-Y[i]) * (X[i]-X[j]))
                {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
    return 0;
}