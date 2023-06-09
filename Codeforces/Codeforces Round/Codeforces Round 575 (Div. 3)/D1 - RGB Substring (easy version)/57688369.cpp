#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
        int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,q,n,k,cnt1,cnt2,cnt3,ans;
    string s;
    cin >> q;
    while(q--)
    {
        cin >> n >> k;
        cin >> s;
        ans=INT_MAX;
        for(i=0; i<=n-k; i++)
        {
            cnt1=cnt2=cnt3=0;
            for(j=i; j<i+k; j++)
            {
                if((j-i) % 3  ==  0)
                {
                    if(s[j] == 'R')
                    {
                        cnt2++;
                        cnt3++;
                    }
                    else if(s[j] == 'G')
                    {
                        cnt1++;
                        cnt3++;
                    }
                    else
                    {
                        cnt1++;
                        cnt2++;
                    }
                }
                else if((j-i) % 3  ==  1)
                {
                    if(s[j] == 'G')
                    {
                        cnt2++;
                        cnt3++;
                    }
                    else if(s[j] == 'B')
                    {
                        cnt1++;
                        cnt3++;
                    }
                    else
                    {
                        cnt1++;
                        cnt2++;
                    }
                }
                else
                {
                    if(s[j] == 'B')
                    {
                        cnt2++;
                        cnt3++;
                    }
                    else if(s[j] == 'R')
                    {
                        cnt1++;
                        cnt3++;
                    }
                    else
                    {
                        cnt1++;
                        cnt2++;
                    }
                }
            }
            ans=min(ans,min(cnt1,min(cnt2,cnt3)));
        }
        cout << ans << '\n';
    }
    return 0;
}