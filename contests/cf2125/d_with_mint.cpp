#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define sz(x)	(int)(x).size() 
#define pb push_back
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG

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

using P = array<Z,3>;
bool comp(P a, P b){
      if( a[0].x == b[0].x)
            return a[1].x < b[1].x;
      else
            return a[0].x < b[0].x;
}
void solve(){
     int n, m;
     cin >> n >> m;
     vector<P> a(n);
     Z neg = 1;
     rep(i,0,n){
           int l, r, p , q;
           cin >> l >> r >> p >> q;
           Z t = Z(p)/Z(q);
           cerr << t << endl;
           neg *=  1  - t;
           a[i][0] = l;
           a[i][1] = r;
           a[i][2] = (t/ (1 - t));
     }
     sort( a.begin(), a.end(), comp); // not good to compare Z, should be 
                                      // avoided but works here because 
                                      // a[i][0] and a[i][1] are just 
                                      // int <= 2e5;
     rep(i,0,n) cerr << a[i][0] <<" "<< a[i][1]<<" " << a[i][2] << endl;
      vector<Z> dp(m+1);
      dp[0] = neg;
      rep(i,0,n){
            int l = a[i][0].x;
            int r = a[i][1].x;
            dp[r] += dp[l-1]*a[i][2];
      }
      cout << dp[m];
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

