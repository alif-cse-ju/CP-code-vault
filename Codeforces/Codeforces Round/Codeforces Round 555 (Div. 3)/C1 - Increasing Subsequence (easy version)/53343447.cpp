#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define LL long long
#define PB push_back
#define PII pair<int,int>
#define PLL pair<long long int,long long int>
string s;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,a[200010];
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    int  cnt=0;
    i=1;
    int j=n,mark=-1;
    while(i <= j)
    {
        if(a[i] > mark && a[j] > mark)
        {
            cnt++;
            if(a[i] <= a[j])
            {
                mark=a[i];
                i++;
                s.push_back('L');
            }
            else
            {
                mark=a[j];
                j--;
                s.push_back('R');
            }
        }
        else if(a[i] > mark)
        {
            cnt++;
            mark=a[i];
            i++;
            s.push_back('L');
        }
        else if(a[j] > mark)
        {
            cnt++;
            mark=a[j];
            j--;
            s.push_back('R');
        }
        else
        {
            break;
        }
    }
    if(i == j && a[i] > mark)
    {
        cnt++;
        s.push_back('R');
    }
    printf("%d\n",cnt);
    cout << s;
    return 0;
}