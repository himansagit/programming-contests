#include<bits/stdc++.h>


#ifdef LOCALll
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
const int mod = 1e9+7;
//#define int long long;
typedef struct mint{
      int x;
      mint(){
            x = 0;
      }
      mint(int b){
            x = b;
            if( x < 0) x += mod;
      }
      mint(long long b){
            x = b;
            if( x < 0) x += mod;
      }
      mint(const mint& b){
            x = b.x;
      }
      mint& operator=(const int& b){
            x = b;
            x = x%mod;
            return *this;
      }
      mint& operator=(const mint& b){
            if(this == &b)
                  return *this;
            x = b.x;
            return *this;
      }
      mint& operator++(){
            x++;
            if( x == mod) x = 0;
            return *this;
      }
      mint operator++(int){
            mint old = *this;
            x++;
            if( x == mod) x = 0;
            return old;
      }
      mint& operator--(){
            if( x == 0) x = mod;
            x--;
            return *this;
      }
      mint operator--(int){
            mint old = *this;
            if( x == 0) x = mod;
            x--;
            return old;
      }
      mint& operator+=(const mint& b){
           x += b.x;
           if( x >= mod) x -= mod;
           return *this;
      }
      mint& operator-=(const mint& b){
            x -= b.x;
            if( x < 0) x += mod;
            return *this;
      }
      mint& operator*=(const mint& b){
            long long z = (long long)x*b.x;
            x = z%mod;
            return *this;
      } 
       mint pow(int p)const{
             mint t = *this, r = 1;
             while(p){
                   if(p &1){
                         r *= t;
                   }
                   t *= t;
                   p >>= 1;
             }
             return r;
      }

      mint inverse()const{
            return pow(mod-2);
      }
      mint& operator/=(const mint& b){
            return *this = *this * b.inverse();
      }
      mint operator+()const{
            return *this;
      }
      mint operator-()const{
            return mint() - *this;
      }
      friend mint operator+(const mint& a, const mint& b) { return mint(a) += b; }
      friend mint operator-(const mint& a, const mint& b) { return mint(a) -= b; }
      friend mint operator*(const mint& a, const mint& b) { return mint(a) *= b; }
      friend mint operator/(const mint& a, const mint& b) { return mint(a) /= b; }
      friend bool operator==(const mint& a, const mint& b){ return a.x == b.x; };
      friend bool operator!=(const mint& a, const mint& b){ return a.x != b.x; };

     friend std::ostream& operator<<(std::ostream& os,const mint& a){
            return os << a.x;
      }
     explicit operator bool() const {
        return x != 0;
     }
} Z;

//code for following function is copied from 
//https://www.geeksforgeeks.org/dsa/print-all-prime-factors-of-a-given-number/
vector<i64> primeFactors(i64 n) {
    vector<i64> factors;

    // Store the number of 2s that divide n
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }

    // n must be odd at this point. So we can 
     // skip one element (i = i + 2)
    for (i64 i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2)
        factors.push_back(n);

    return factors;
}

//i64 nck(i64 n, i64 k){
//      i64 a = 1, b = 1;
//      for( i64 i = n; i > n-k; i--){
//            a = (a * i) %
//      }
//      for(int i = 2; i <= k; i++){
//            b *= Z(i);
//      }
//      return a/b;
//}
void multi( i64 &a, const i64 b){
      debug(a,b);
      a = (a*b)%mod;
}
i64 F( i64 a, i64 b){
      i64 ans = 1;
      for(i64 i = a; i >= b; i--){
            i64 j = i%mod;
            ans = (ans * j) %mod;
      }
      return ans;
}
void solve(){
           i64 n, a, b; cin >> n >> a >> b;
            if( b == 1){
                  cout << 1 << '\n';
                  return;
            }
           vector<i64> fact = primeFactors(b);
           vector<i64> uf;
           assert(fact.size() > 0);
           uf.push_back(fact[0]);
            for( int i = 1; i < fact.size(); i++){
                  if( fact[i] != fact[i-1]){
                        uf.push_back(fact[i]);
                  }
            }
           Z ans = 0;
           //Z N = n;
           for( i64 X = 1; X*X <= b; X++){
                 if( b%X == 0){
                       i64 x = X;
                       i64 y = b/x;
                       if( x > a) break;
                       i64 num = 1, den = 1;
                       if( x < y and y <= a) num *= 2;
                       debug(x,y,num);
                       for( i64 f:uf){
                             debug(x,y,f,num);
                             int c1 = 0, c2 = 0;
                             while( x%f == 0){
                                   x /= f;
                                   c1++;
                             }
                             while( y%f == 0){
                                   y /= f;
                                   c2++;
                             }
                             //m *= nck(n + c1-1,c1);
                             //m *= nck(n + c2-1,c2);
                             debug(c1,c2);
                             multi(num, F(n -1 + c1, n));
                             debug(num);
                             multi(den, F(c1,1LL));
                             multi(num, F(n + c2-1, n));
                             debug(num);
                             multi(den, F(c2,1LL));
                             debug(num,den);
                       }
                        ans += Z(num)/Z(den);
                 }
           }
           cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      for( int i = 1; i <= tc; i++){
            cout << "Case #" << i << ": ";
            solve();
      }
}

