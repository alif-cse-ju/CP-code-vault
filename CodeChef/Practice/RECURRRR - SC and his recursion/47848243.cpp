#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector <vector <long long int>> matrix_product(vector <vector <long long int>> a, vector <vector <long long int 
{
    vector <vector <long long int>> res(b.size());
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            long long int sum = 0;
            for(int k=0;k<a[i].size();k++)
            {
                sum += a[i][k]*b[k][j];
                sum %= MOD;
            }
            res[i].push_back(sum%MOD);
        }
    }
    return res;
}
vector <vector <long long int>> matrixFE(vector <vector <long long int>> a, long long int n)
{
    vector <vector <long long int>> iden = {{1,0,0},{0,1,0},{0,0,1}};
    if(n==0)
        return iden;
    else if(n==1)
        return a;
    else
    {
        vector <vector <long long int>> res = matrixFE(a,n/2);
        if(n%2==0)
        {
            return matrix_product(res,res);
        }
        else
        {
            return matrix_product(matrix_product(res,a),res);
        }
    }
}
long long int alterfib(long long int a, long long int n)
{
    if(n==0)
        return 1;
    else
    {
        vector <vector <long long int>> T = {{a%MOD,0,1},{0,1,0},{0,1,1}};
        vector <vector <long long int>> F = {{1},{1},{1}};
        vector <vector <long long int>> ans = matrix_product(matrixFE(T,n),F);
        return ans[0][0];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,q;
        cin>>a>>q;
        while(q--)
        {
            long long int n;
            cin>>n;
            cout<<alterfib(a,n)<<endl;
        }
    }
}