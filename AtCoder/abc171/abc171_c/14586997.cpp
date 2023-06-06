#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    LL n,x;
    string ans="";
    cin >> n;
    while(n > 0)
    {
        x=(n-1)%26;
        ans+=(char)(x+'a');
        n=(n-x-1)/26;
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
    return 0;
}
