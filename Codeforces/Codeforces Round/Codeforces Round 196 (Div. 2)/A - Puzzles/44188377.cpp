#include<bits/stdc++.h>
using namespace std;
int main()
    int n,m,i,f[55],min=2000;
    scanf("%d %d",&n,&m);
    for(i=0; i<m; i++)
    {
        scanf("%d",&f[i]);
    }
    sort(f,f+m);
    for(i=0; i<=m-n; i++)
    {
        if(f[i+n-1]-f[i]<min)
        {
            min=f[i+n-1]-f[i];
        }
    }
    printf("%d",min);
    return 0;