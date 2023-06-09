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
int mark[27],check[27];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,l;
    string s;
    cin >> s;
    l=s.size();
    for(i=0;i<l;i++)
    {
        mark[s[i]-'A']++;
    }
    cin >> s;
    l=s.size();
    for(i=0;i<l;i++)
    {
        mark[s[i]-'A']++;
    }
     cin >> s;
    l=s.size();
    for(i=0;i<l;i++)
    {
        check[s[i]-'A']++;
    }
     for(i=0;i<26;i++)
    {
        if(mark[i] != check[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}