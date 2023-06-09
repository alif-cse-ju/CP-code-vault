#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,m,x;
    int box_odd=0,box_even=0;
    int key_odd=0,key_even=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x%2 == 1)
        {
            box_odd++;
        }
        else
        {
            box_even++;
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        if(x%2 == 1)
        {
            key_odd++;
        }
        else
        {
            key_even++;
        }
    }
    printf("%d",min(box_even,key_odd)+min(box_odd,key_even));
    return 0;
}