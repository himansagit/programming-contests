#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
const int mod = 998244353;
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

const int N = 1e5+10;
Z fact[N];

Z nck(int n,int k){
      if( k < 0 or k > n) return Z(0);
      return fact[n]/(fact[k]*fact[n-k]);
}
void solve(){
      int n;
      cin >> n;
      for( int i = 0;i < n; i++){
           if( i == 0 or 2*i > n-1) cout << "0 ";
           else{
                 Z res = nck(n-i-2,i-1);
                 res *= fact[2*i];
                 res *= fact[n-2*i+1];
                 cout << res << " ";
           }
      }
      cout << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      fact[0] = fact[1] = 1;
      for( int i = 2;i < N ;i++){
            fact[i] = fact[i-1]*i;
      }


      int tc; cin >> tc;
      while(tc--) solve();
}

