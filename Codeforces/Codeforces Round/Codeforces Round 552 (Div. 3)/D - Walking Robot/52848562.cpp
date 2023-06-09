#include<bits/stdc++.h>
using namespace std;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,a,b,n,mark[200005];
    scanf("%d %d %d",&n,&b,&a);
    int max_a=a,max_b=b;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&mark[i]);
    }
    int cnt=0;
    for(i=1; i<=n && (b>0 || a>0); i++)
    {
        if(mark[i] == 1)
        {
            if(b > 0  &&  a < max_a)
            {
                b--;
                cnt++;
                a++;
            }
            else if(a <= max_a && a > 0)
            {
                a--;
                cnt++;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(a > 0)
            {
                a--;
                cnt++;
            }
            else if(b > 0)
            {
                b--;
                cnt++;
            }
            else
            {
                break;
            }
        }
        //cout << b << ' ' << a << endl;
    }
    printf("%d",cnt);
    return 0;
}