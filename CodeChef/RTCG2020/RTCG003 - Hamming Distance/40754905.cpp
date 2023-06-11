#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,ans=0;
    string a,b;
    cin >> a >> b;
    l=(int)a.size();
    for(i=0;i<l;i++)ans+=(a[i] != b[i]);
    cout << ans;
    return 0;
}