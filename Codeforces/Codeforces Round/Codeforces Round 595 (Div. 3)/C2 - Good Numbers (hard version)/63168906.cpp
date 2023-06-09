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
     //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int q;
    ULL l,m,n,ans1,ans2,ans3,check;
    cin >> q;
    while(q--)
    {
        cin >> n;
        if(n == 1)cout << "1\n";
        else if(n <= 3)cout << "3\n";
        else if(n == 4)cout << "4\n";
        else if(n <= 9)cout << "9\n";
        else
        {
            m=n;
            l=0;
            while(n > 0)
            {
                ++l;
                n/=3;
            }
            ans1=(ULL)pow(3ULL,l);
            ans2=ans1/3;
            if(ans1 > m)
            {
                check=ans2/3;
                ans3=2e18+500;
                while(ans2 < m  &&  check > 0)
                {
                    if(check <= m-ans2)ans2+=check;
                    else ans3=min(ans3,ans2+check);
                    check/=3;
                }
                //cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
                if(ans2 >= m)ans2=min(ans2,ans3);
                else ans2=ans3;
            }
            if(ans2 >= m)
                cout << min(ans1,ans2) << '\n';
            else
                cout << ans1 << '\n';
        }
    }
    return 0;
}