#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    bool check;
    int i,j,n,t;
    LL Cor,a[100002];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        if(n > 60)check=false;
        else
        {
            check=true;
            set<LL>st;
            for(i=1;check  &&  i<=n;i++)
            {
                Cor=0;
                for(j=i;j<=n;j++)
                {
                    Cor |= a[j];
                    if(st.find(Cor) == st.end())st.insert(Cor);
                    else
                    {
                        check=false;
                        break;
                    }
                }
            }
        }
        if(check)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}