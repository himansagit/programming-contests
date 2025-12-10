#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
const i64 mod = 1e6+3;

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

const int N = 1e6+100;
i64 fact[N];
void solve(){
      int n; cin >> n;
      vector<int> a(n), b(n);
      for( int i = 0; i < n; i++) cin >> a[i];
      for( int i = 0; i < n; i++) cin >> b[i];
      Z ans = 1; 
      int steps = 0;
      while(true){
            int c = 0;
            bool last = false;
            for( int i = 0; i < n; i++){
                  if( b[i]%2 == 0){
                        if( b[i]/2 < a[i]){
                              last = true;
                              break;
                        }
                  }else{
                        c++;
                        if( (b[i]-1)/2 < a[i]){
                              last = true;
                              break;
                        }
                  }
            }
            if( last){
                  c = 0;
                  Z den = 1;
                  for( int i = 0; i < n; i++){
                        c += b[i] - a[i];
                        den *= fact[(b[i] - a[i])];
                  }
                  steps += c;
                  if( c >= mod){
                        ans = 0;
                  }
                  else{
                        ans *= fact[c];
                        ans /= den;
                  }
                  break;
            }else{
                  ans *= fact[c];
                  steps += c+1;
                  for( int i = 0; i < n; i++){
                        b[i] /= 2;
                  }
            }
      }
      cout << steps << " " << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      fact[0] = fact[1] =1;
      for( i64 i = 2; i < N; i++){
            fact[i] = (i*fact[i-1])%mod;
      }
      int tc; cin >> tc;
      while(tc--) solve();
}

