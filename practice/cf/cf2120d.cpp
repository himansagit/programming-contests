#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
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
using i64 = long long;

void multi( i64 &a, i64 b){
      b = b%mod;
      a = (a*b)%mod;
}
void solve(){
      i64 a,b,k; cin >> a >> b >> k;
      i64 n = k*(a-1) + 1;
      //Z m = k;
      i64 num = k, den = 1;
      for( i64 i = 0; i < a; i++){
            multi(num,n-i);
            multi(den,i+1);
      }
       Z m = Z(num)/Z(den);

      Z M = 0;
      for( int i = 0; i < b-1; i++){
            M += m;     
      }
      
      M++;
      cout << n%mod << " " << M << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}
// 
// 001 010 100
