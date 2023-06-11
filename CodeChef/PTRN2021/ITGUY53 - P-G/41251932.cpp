#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
//                x=(i-1)*n+j;
//                vector<int>ans;
//                while(x)
//                {
//                    ans.emplace_back(x%2);
//                    x/=2;
//                }
//                reverse(ans.begin(),ans.end());
//                for(int it : ans)cout << it;
//                cout << ' ';
                cout << i+j;
            }
            cout << '\n';
        }
    }
    return 0;
}
//1422