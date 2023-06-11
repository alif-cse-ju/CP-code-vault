#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=n-2;i>=0;i--)
    {
        if(a[i] < a[i+1])
        {
            printf("%d",a[i]);
            return 0;
        }
    }
    printf("0");
    return 0;
}