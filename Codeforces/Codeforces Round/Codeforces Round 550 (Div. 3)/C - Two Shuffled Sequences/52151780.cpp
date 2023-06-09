#include<bits/stdc++.h>
using namespace std;
vector<int>increasing;
vector<int>decreasing;
int a[200005];
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    bool flag=0;
    for(i=0; i<n; i++)
    {
        if(i>1 && a[i]==a[i-1] && a[i]==a[i-2])
        {
            flag=1;
            break;
        }
        else if(i>0 && a[i] == a[i-1])
        {
            increasing.push_back(a[i]);
        }
        else
        {
            decreasing.push_back(a[i]);
        }
    }
    if(flag == 1)
    {
        printf("NO");
    }
    else
    {
        printf("YES\n");
        int l;
        l=increasing.size();
        printf("%d\n",l);
        if(l > 0)
        {
            printf("%d",increasing[0]);
            for(i=1; i<l; i++)
            {
                printf(" %d",increasing[i]);
            }
        }
         printf("\n");
         l=decreasing.size();
        printf("%d\n",l);
        if(l > 0)
        {
            printf("%d",decreasing[l-1]);
            for(i=l-2; i>=0; i--)
            {
                printf(" %d",decreasing[i]);
            }
        }
    }
    return 0;
}