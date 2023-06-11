#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,l,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> l;
        if(k*l < n  ||  (n > 1  &&  k == 1))cout << "-1\n";
        else
        {
            for(i=0;i<n;i++)cout << (i%k)+1 << ' ';
            cout << '\n';
        }
    }
    return 0;
}