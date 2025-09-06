#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int a,b; cin >> a >> b;
      int g = gcd(a,b);
      int n; cin >> n;
      vector<int> factors;
      for( int i =1 ; i*i <= g; i++){
            if( g%i == 0){
                  factors.push_back(i);
                  factors.push_back(g/i);
            }
      }
      sort(factors.begin(), factors.end());
      while(n--){
            int l, r;
            cin >> l >> r;
            int itr = upper_bound( factors.begin(), factors.end(), r) - factors.begin();
            if(itr == 0 or factors[itr-1] < l){
                  cout << -1 << '\n';
            }else{
                  cout << factors[itr-1] << '\n';
            }
      }
}

