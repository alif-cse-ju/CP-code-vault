#include <bits/stdc++.h>
#define debug(x) std::cout<<#x<<" = "<<x<<'\n'; 

constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
//        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

int main(){
	int n,a,b,c;
	std::cin>>n>>a>>b>>c;

	std::vector<Z> fac(n+1),finv(n+1);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i;
	finv[n]=fac[n].inv();
	for(int i=n-1;i>=0;i--) finv[i]=finv[i+1]*(i+1);
	
	auto C=[&](int n,int m)->Z{
		if(m>n||m<0) return 0;
		return fac[n]*finv[m]*finv[n-m];	
	};
	
	// sum C(n,m) = sum C(n-1,m) * 2 - C(n-1,m)
	Z res(0),sC[3]={1,1,1};
	for(int i=0;i<=n;i++){
		// i: selected
		if((n-i)&1) res-=C(n,i)*sC[0]*sC[1]*sC[2];
		else res+=C(n,i)*sC[0]*sC[1]*sC[2];
		sC[0]=sC[0]*2-C(i,a);
		sC[1]=sC[1]*2-C(i,b);
		sC[2]=sC[2]*2-C(i,c);
	}
	std::cout<<res.val();
	
	return 0;
}