#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 2e6;

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int t; cin >> t;
      vector<int> prime(N,1);
      prime[0] = prime[1] = 0;
      for(int i = 2; i < N ;i++){
            if( prime[i] == 0) continue;
            for( int j = 2*i; j < N; j += i){
                  prime[j] = 0;
            }
      }
      for( int i = 2; i < N; i++){
            prime[i] += prime[i-1];
      }
      while(t--){
            int n; cin >> n;
            int s = sqrt(n);
            cout << prime[n] - prime[s] +1 << '\n';
      }

}

