#include<bits/stdc++.h>
using namespace std;
int main()
    int i,l;
    char a[105],b[105],ans[105];
    cin >> a >> b ;
    l=strlen(a);
    for(i=0; i<l; i++)
    {
        if(a[i] == b[i])
        {
            ans[i]='0';
        }
        else
        {
            ans[i]='1';
        }
    }
    for(i=0; i<l; i++)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;