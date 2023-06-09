#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define LL long long
#define PB push_back
#define PII pair<int,int>
#define PLL pair<long long int,long long int>
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,l,a[12];
    string s;
    cin >> l >> s;
    for(i=1; i<10; i++)
    {
        cin >> a[i];
    }
    int cnt=0;
    for(i=0; i<l; i++)
    {
        if(s[i]-'0' <= a[s[i]-'0'] && cnt!=-1)
        {
            cout << a[s[i]-'0'];
            if(s[i]-'0' < a[s[i]-'0'])
            {
                cnt++;
            }
        }
        else
        {
            if(cnt > 0)
            {
                cnt=-1;
            }
            cout << s[i];
        }
    }
    return 0;
}