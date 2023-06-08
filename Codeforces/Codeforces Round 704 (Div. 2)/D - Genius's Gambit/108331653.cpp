#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int ans[2][N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,i,k,n,x;
    cin >> a >> b >> k;
    if(!a)
    {
        if(!k)
        {
            cout << "Yes\n";
            for(i=0;i<b;i++)cout << '1';
            cout << '\n';
            for(i=0;i<b;i++)cout << '1';
            cout << '\n';
        }
        else cout << "No";
    }
    else if(b == 1)
    {
        if(!k)
        {
            cout << "Yes\n";
            cout << '1';
            for(i=0;i<a;i++)cout << '0';
            cout << '\n';
            cout << '1';
            for(i=0;i<a;i++)cout << '0';
            cout << '\n';
        }
        else cout << "No";
    }
    else
    {
        n=a+b;
        if(k > a+b-2)cout << "No";
        else
        {
            for(i=1;i<=b;i++)ans[0][i]=ans[1][i]=1;
            for(i=b+1;i<=n;i++)ans[0][i]=ans[1][i]=0;
            x=min(a,k);
            if(x)ans[1][b+x]=1,ans[1][b]=0;
            k-=x;
            for(i=b;i && k;i--)
            {
                swap(ans[1][i],ans[1][i-1]);
                --k;
            }
            cout << "Yes\n";
            for(i=1;i<=n;i++)cout << ans[0][i];
            cout << '\n';
            for(i=1;i<=n;i++)cout << ans[1][i];
        }
    }
    return 0;
}
//