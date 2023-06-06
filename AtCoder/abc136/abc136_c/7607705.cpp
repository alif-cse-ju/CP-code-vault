#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,n;
    cin >> n;
    int a[n+2],mx=0;
    for(i=0;i<n;i++) cin >> a[i];
    for(i=0;i<n;i++)
    {
        if(mx-a[i] > 1)
        {
            cout << "No";
            return 0;
        }
        mx=max(mx,a[i]);
    }
    cout << "Yes";
    return 0;
}
