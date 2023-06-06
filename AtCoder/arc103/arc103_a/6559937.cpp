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





MII mp_even;
MII mp_odd;

int main()
{
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,x,max_even=0,max_odd=0,second_max_even=0,second_max_odd=0,even_mark,odd_mark;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> x;
        if(i & 1)
        {
            mp_odd[x]++;
            if(mp_odd[x] > max_odd)
            {
                if(x != odd_mark)
                {
                    second_max_odd=max(second_max_odd,max_odd);
                }
                max_odd=mp_odd[x];
                odd_mark=x;
            }
            if(x != odd_mark)
            {
                second_max_odd=max(second_max_odd,mp_odd[x]);
            }
        }
        else
        {
            mp_even[x]++;
            if(mp_even[x] > max_even)
            {
                if(x != even_mark)
                {
                    second_max_even=max(second_max_even,max_even);
                }
                max_even=mp_even[x];
                even_mark=x;
            }
            if(x != even_mark)
            {
                second_max_even=max(second_max_even,mp_even[x]);
            }
        }
    }
    if(even_mark != odd_mark)
    {
        cout << n-max_even-max_odd;
    }
    else
    {
        //cout << max_even << ' ' << second_max_even << ' ' << max_odd << ' ' << second_max_odd << '\n';
        cout << min(n-max_even-second_max_odd,n-second_max_even-max_odd);
    }
    return 0;
}
