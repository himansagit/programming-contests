#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;

#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;
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

const int N = 2e5+10;
Z fact[N];
Z nck(int n, int k){
      if( k > n) return Z(0);
      if( n == k) return Z(1);
      return fact[n]/(fact[k]*fact[n-k]);
}
void solve(){
      int n; cin >> n;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      i64 sum = accumulate(a.begin(), a.end(),0LL);
      if( sum != n){
            cout << "0\n"; return;
      }
      vector<int> pre = {0};
      for(int j = (n+1)/2; j < n; j++){
            if( a[j] != 0){
                  cout << "0\n"; return;
            }
      }
      for( int j = (n-1)/2; j >= 0 ;j--){
            pre.push_back(a[j]);
      }
      int t = pre.size();
      vector<int> avail(t,2);
      avail[0] = 0;
      if( n%2 == 1) avail[1] = 1;
      //debug(pre); debug(avail);
      for( int i = 1; i < t; i++){
            pre[i] += pre[i-1];
            avail[i] += avail[i-1];
      }
      //debug(pre); debug(avail);
      Z ans = 1;
      for(int i = 1; i < t; i++){
            int a = avail[i] - pre[i-1];
            int b = pre[i] - pre[i-1];
            if( a < b ){
                  cout << "0\n"; return;
            }
            ans *= nck(a,b);
      }
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      fact[0] = 1;
      fact[1] = 1;
      for( int i = 2; i < N; i++) fact[i] = i*fact[i-1];
      int tc; cin >> tc;
      while(tc--) solve();
}

