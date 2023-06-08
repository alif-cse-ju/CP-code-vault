#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,x,y,z,and12,and13,and23,xor12,xor13,xor23;
    cin >> n;
    for(i=2;i<=n;i++)
    {
        cout << "XOR " << i-1 << ' ' << i << endl;
        cin >> a[i];
    }
    cout << "AND 1 2" << endl;
    cin >> and12;
    cout << "AND 1 3" << endl;
    cin >> and13;
    cout << "AND 2 3" << endl;
    cin >> and23;
    xor12=a[2],xor13=(a[2] ^ a[3]),xor23=a[3];
    x=xor12+2*and12;
    y=xor13+2*and13;
    z=xor23+2*and23;
    a[1]=(x+y-z)/2;
    for(i=2;i<=n;i++)a[i] ^= a[i-1];
    cout << '!';
    for(i=1;i<=n;i++)cout << ' ' << a[i];
    cout << endl;
    return 0;