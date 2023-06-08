#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    FAST();
    bool flag;
    string a,b;
    int i,j,k,la,lb,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        la=(int)a.size();
        lb=(int)b.size();
        ans=0;
        for(i=1;i<=min(la,lb);i++)
        {
            flag=0;
            for(j=0;j+i<=la  &&  !flag;j++)
            {
                for(k=0;k+i<=lb  &&  !flag;k++)
                {
                    if(a.substr(j,i) == b.substr(k,i))
                    {
                        ans=i;
                        flag=1;
                    }
                }
            }
        }
        cout << la+lb-2*ans << '\n';
    }
    return 0;
}