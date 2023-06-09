#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    string s;
    bool cell12,cell21,celln_1n,cellnn_1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cell12=cell21=celln_1n=cellnn_1=0;
        for(i=1;i<=n;i++)
        {
            cin >> s;
            if(i == 1)cell12=(s[1] == '0');
            else if(i == 2)cell21=(s[0] == '0');
            if(i == n-1)celln_1n=(s[n-1] == '0');
            else if(i == n)cellnn_1=(s[n-2] == '0');
        }
        if(cell12 == cell21)
        {
            if(celln_1n == cellnn_1  &&  celln_1n == cell12)cout << "2\n1 2\n2 1\n";
            else if(celln_1n == cell12)cout << "1\n" << n-1 << ' ' << n << '\n';
            else if(cellnn_1 == cell21)cout << "1\n" << n << ' ' << n-1 << '\n';
            else cout << "0\n";
        }
        else if(celln_1n == cellnn_1)
        {
            if(celln_1n == cell12  &&  cell21 == cell12)cout << "2\n1 2\n2 1\n";
            else if(celln_1n == cell12)cout << "1\n" << 1 << ' ' << 2 << '\n';
            else if(celln_1n == cell21)cout << "1\n" << 2 << ' ' << 1 << '\n';
            else cout << "0\n";
        }
        else
        {
            if(cell12 != cellnn_1)cout << "2\n1 2\n" << n << ' ' << n-1 << '\n';
            else cout << "2\n2 1\n" << n << ' ' << n-1 << '\n';
        }
    }
    return 0;
}