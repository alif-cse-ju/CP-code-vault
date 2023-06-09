#include<bits/stdc++.h>
using namespace std;
int main()
    int i,j,l;
    string a,s;
    cin >> a >> s;
    sort(s.begin(),s.end());
    l=a.size();
    i=s.size()-1;
    for(j=0; j<l; j++)
    {
        if(s[i]>a[j])
        {
            a[j]=s[i];
            if(i == 0)
            {
                break;
            }
            i--;
        }
    }
    cout << a << endl;
    return 0;