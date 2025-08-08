#include<bits/stdc++.h>

using namespace std;

class PNC{
      public:
      static long long mod;
      static long long n;
      static vector<long long> factorial;

      PNC(){
            factorial.assign(n+1,0);
            factorial[0] = factorial[1] = 1;
            for( long long i = 2; i <= n; i++){
                  factorial[i] = ( factorial[i-1]*i) % mod;
            }
      }
      static long long pow( long long a, long long b){
            long long c = 1;
            while( b > 1){
                  if( b&1 ){
                        c = (c * a) % mod;
                        b--;
                  }
                  a = (a*a) % mod;
                  b /= 2;
            }
            return (c*a)%mod;
      }
     static long long inverse(long long a){
           return pow(a, mod-2);
     }
      static long long fact(long long a){
           return factorial[a];
     }
     static long long nck(long long n, long long k){
           if( k < 0 or k > n) return 0LL;
           long long res = factorial[n];
           long long den = ( factorial[k] * factorial[n-k]) % mod;
           return ( res * inverse(den)) % mod;
     }
     static long long npk(long long n, long long k){
           if( k < 0 or k > n) return 0LL;
           long long res = factorial[n];
           long long den = factorial[n-k];
           return ( res * inverse(den)) % mod;
     }
};
vector<long long> PNC::factorial;
long long PNC::mod = 1e9+7;
long long PNC::n = 2e5+1;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      cout << PNC::pow(2,100) << " \n";   
      PNC p;
      cout << PNC::nck(100,23) << "\n";
}

