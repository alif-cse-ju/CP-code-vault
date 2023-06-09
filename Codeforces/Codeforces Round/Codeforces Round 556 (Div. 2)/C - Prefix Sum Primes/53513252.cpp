#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define PB push_back
#define LL long long int
#define PII pair<int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>
int i,n,x,cnt_1,cnt_2;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x;
        if(x == 1)
        {
            cnt_1++;
        }
        else
        {
            cnt_2++;
        }
    }
    if(cnt_1 <= 2)
    {
        if(cnt_2 > 0)
        {
            cout << 2 << ' ';
        }
        if(cnt_1 > 0)
        {
            cout << 1 << ' ';
        }
        for(i=2; i<=cnt_2; i++)
        {
            cout << 2 << ' ';
        }
        for(i=2; i<=cnt_1; i++)
        {
            cout << 1 << ' ';
        }
    }
    else
    {
        if(cnt_1 & 1)
        {
            for(i=1; i<=cnt_1; i++)
            {
                cout << 1 << ' ';
            }
        }
        else
        {
            for(i=1; i<cnt_1; i++)
            {
                cout << 1 << ' ';
            }
        }
        for(i=1; i<=cnt_2; i++)
        {
            cout << 2 << ' ';
        }
        if(cnt_1%2 == 0 && cnt_1 > 0)
        {
            cout << 1 << ' ';
        }
    }
    return 0;
}