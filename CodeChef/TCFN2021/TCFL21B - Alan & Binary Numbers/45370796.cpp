#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
char a[M],b[M];
int main()
{
    FAST();
    a[0]=b[0]='0';
    int t;
    cin >> t;
    while(t--)
    {
        int l;
        cin >> l >> a+1 >> b+1;
        int last0A=0,last1A=0;
        for(int i=l;i>=0;i--)
        {
            if(a[i] == '0')
            {
                if(!last0A)last0A=i;
            }
            else
            {
                if(!last1A)last1A=i;
            }
        }
        int last0B=0,last1B=0;
        for(int i=l;i>=0;i--)
        {
            if(b[i] == '0')
            {
                if(!last0B)last0B=i;
            }
            else
            {
                if(!last1B)last1B=i;
            }
        }
        cout << 2*l-max(last0A+last0B,last1A+last1B) << ' ';
        cout << 2*l-max(last0A+last1B,last1A+last0B) << '\n';
    }
    return 0;
}