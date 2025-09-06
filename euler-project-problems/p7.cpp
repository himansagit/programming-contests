#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 2e5+1;
vector<bool> is_prime(N,true);
vector<int> primes;

void sieve(){
      is_prime[0] = is_prime[1] = false;
      for( int i = 2; i < N ;i++){
            if( is_prime[i] == false) continue;
            if( i*i >= N)
                  break;
            for( int j = i*i; j < N; j += i){
                  is_prime[j] = false;
            }
      }
      for( int i = 2; i < N; i++){
            if( is_prime[i]) primes.push_back(i);
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n = 10001;
      sieve();
      cout << primes.size() << '\n';
      cout << primes[n-1] << '\n';
}

