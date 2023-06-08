#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long a,b,i,x,y,ans,cnt,temp;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a%b)cout << a << '\n';
        else
        {
            vector<pair<long long,int>>v;
            cnt=0;
            while(b%2 == 0)++cnt,b/=2;
            if(cnt)v.emplace_back(2,cnt);
            for(i=3;i*i<=b;i+=2)
            {
                if(b%i == 0)
                {
                    cnt=0;
                    while(b%i == 0)++cnt,b/=i;
                    v.emplace_back(i,cnt);
                }
            }
            if(b > 1)v.emplace_back(b,1);
            ans=1;
            for(auto it : v)
            {
                x=it.first,y=it.second;
                temp=a;
                if(temp%x)continue;
                while(temp%x == 0)temp/=x;
                for(i=1;i<y;i++)temp*=x;
                ans=max(ans,temp);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}