#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

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


void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for(int i = 0; i < n; i++) cin >> a[i];
      sort( a.begin(), a.end());
      int c = 1;
      vector<int> cns;
      for( int i = 1; i < n; i++){
           if( a[i] != a[i-1]){
                 cns.push_back(c);
                 c = 1;
           }else{
                 c++;
           }
      }
      cns.push_back(c);
      Z ans = 1;
      for( int x:cns){
            ans = ans * Z(x+1);
      }
      //vector<Z> dp(n+1);
      vector<Z> dp2(n+1);
      dp2[0] = 1;
      for( int x:cns){
            for( int j = n; j >= x ; j--){
                 //dp[j] += dp[j-x]; 
                 dp2[j] += (dp2[j-x]*Z(x));
            }
      }
      Z sub = 0;

      int t = *max_element(cns.begin(), cns.end());
      for( int i = 0; i < t; i++){
            sub += dp2[i];
      }
      Z res = ans - sub;
      cout << res << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

