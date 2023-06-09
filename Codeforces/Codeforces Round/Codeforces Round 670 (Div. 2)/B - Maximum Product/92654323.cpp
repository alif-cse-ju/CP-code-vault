#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t,lp,ln;
    long long x,ans,temp;
    cin >> t;
    while(t--)
    {
        ans=1;
        cin >> n;
        vector<long long>neg,pos;
        for(i=0;i<n;i++)
        {
            cin >> x;
            ans*=x;
            if(x < 0)neg.emplace_back(x);
            else pos.emplace_back(x);
        }
        if(n == 5)
        {
            cout << ans << '\n';
            continue;
        }
        lp=pos.size();
        ln=neg.size();
        sort(pos.begin(),pos.end());
        sort(neg.rbegin(),neg.rend());
        if(lp == n)
        {
            ans=1;
            n=5;
            while(n--)
            {
                ans*=pos.back();
                pos.pop_back();
            }
        }
        else if(ln == n)
        {
            ans=1;
            for(i=0;i<5;i++)ans*=neg[i];
        }
        else
        {
            ans=LLONG_MIN;
            for(i=0;i<=min(5,ln);i++)
            {
                temp=1;
                if(i & 1)
                {
                    for(j=0;j<i;j++)temp*=neg[j];
                    if(5-i > lp)temp=LLONG_MIN;
                    else
                    {
                        for(j=0;j<5-i;j++)temp*=pos[j];
                    }
                }
                else
                {
                    for(j=0;j<i;j++)temp*=neg[ln-j-1];
                    if(5-i > lp)temp=LLONG_MIN;
                    else
                    {
                        for(j=0;j<5-i;j++)temp*=pos[lp-j-1];
                    }
                }
                ans=max(ans,temp);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}