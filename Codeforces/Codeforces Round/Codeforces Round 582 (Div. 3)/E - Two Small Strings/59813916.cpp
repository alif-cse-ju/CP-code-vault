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
//    freopen("input.txt","w",stdout);
     bool flag;
    int i,j,k,n;
    string a,b,s;
    cin >> n >> a >> b;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(i != j)
            {
                for(k=0; k<3; k++)
                {
                    if(i != k  &&  j != k)
                    {
                        s.C;
                        s+=('a'+i);
                        s+=('a'+j);
                        s+=('a'+k);
                        flag=true;
                        if(s[0] == a[0]  &&  s[1] == a[1])
                        {
                            flag=false;
                        }
                        else if(s[1] == a[0]  &&  s[2] == a[1])
                        {
                            flag=false;
                        }
                        else if(n > 1  &&  s[2] == a[0]  &&  s[0] == a[1])
                        {
                            flag=false;
                        }
                        else if(s[0] == b[0]  &&  s[1] == b[1])
                        {
                            flag=false;
                        }
                        else if(s[1] == b[0]  &&  s[2] == b[1])
                        {
                            flag=false;
                        }
                        else if(n > 1  &&  s[2] == b[0]  &&  s[0] == b[1])
                        {
                            flag=false;
                        }
                        if(flag)
                        {
                            cout << "YES\n";
                            for(i=0; i<n; i++)
                            {
                                cout << s;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if(a[0] == b[0])
    {
        cout << "YES\n";
        for(i=0; i<n; i++)
        {
            cout << a[1];
        }
        for(i=0; i<n; i++)
        {
            cout << b[1];
        }
        for(i=0; i<n; i++)
        {
            cout << a[0];
        }
        return 0;
    }
    if(a[1] == b[1])
    {
        cout << "YES\n";
        for(i=0; i<n; i++)
        {
            cout << a[1];
        }
        for(i=0; i<n; i++)
        {
            cout << a[0];
        }
        for(i=0; i<n; i++)
        {
            cout << b[0];
        }
        return 0;
    }
    if(a[0] == b[1]  &&  a[1] == b[0])
    {
        char c;
        if(a[0]=='a')
        {
            if(a[1] == 'b')
                c='c';
            else
                c='b';
        }
        else if(a[0] == 'b')
        {
            if(a[1] == 'a')
                c='c';
            else
                c='a';
        }
        else
        {
            if(a[1] == 'b')
                c='a';
            else
                c='b';
        }
        cout << "YES\n";
        for(i=0;i<n;i++)
        {
            cout << a[0];
        }
        for(i=0;i<n;i++)
        {
            cout << c;
        }
        for(i=0;i<n;i++)
        {
            cout << a[1];
        }
        return 0;
    }
    cout << "NO";
    return 0;
}