#include<bits/stdc++.h>
using namespace std;
int a,b;
int making_reverse_of_b(int n)
    int x=0;
    while(n>0)
    {
        x=x*10+n%10;
        n/=10;
    }
    return x;
bool checking(int n)
    int x=0,check=0;
    while(n>0)
    {
        check=n%10;
        if(check == 4   ||   check == 7)
        {
            x=x*10+check;
        }
        n/=10;
    }
    if(x == b)
    {
        return 1;
    }
    return 0;
int main()
    scanf("%d %d",&a,&b);
    b=making_reverse_of_b(b);
    a++;
    while(checking(a) == 0)
    {
        a++;
    }
    printf("%d\n",a);
    return 0;
}