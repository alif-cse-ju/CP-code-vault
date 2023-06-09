#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    LL i,j,n,q,col,row,sum;
    cin >> n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout << ((i & 1) << (i+j));
            if(j < n)cout << ' ';
            else cout << '\n';
        }
    }
    cout << flush;
    cin >> q;
    while(q--)
    {
        cin >> sum;
        cout << "1 1\n";
        row=col=0;
        for(i=1;i<2*n-1;i++)
        {
            if(((row+1) & 1)  ==  ((sum >> i) & 1))++row;
            else ++col;
            cout << row+1 << ' ' << col+1 << '\n';
        }
        cout << flush;
    }
    return 0;