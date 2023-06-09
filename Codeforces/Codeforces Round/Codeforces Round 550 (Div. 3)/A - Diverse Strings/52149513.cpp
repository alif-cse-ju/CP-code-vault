#include<bits/stdc++.h>
using namespace std;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,l,n;
    bool flag;
    string s;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> s;
        if(s.size() == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            sort(s.begin(),s.end());
            l=s.size();
            flag=0;
            for(j=1; j<l; j++)
            {
                if(s[j]-s[j-1] != 1)
                {
                    cout << "No" << endl;
                    flag=1;
                    break;
                }
            }
            if(flag == 0)
            {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}