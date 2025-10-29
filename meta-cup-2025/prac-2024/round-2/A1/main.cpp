#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)
vector<i64> nums;

void solve(){
      i64 a,b,m;
      cin >> a >> b >> m;
      int c = 0;
      for( auto &x:nums){
            if( x >= a and x <= b and x%m == 0){
                  c++;
            }
      }
      cout << c << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      for( int k = 0; k < 9; k++){
            for( int i = k+1; i <= 9; i++){
                  i64 n = i;
                  for(int j = 0; j < k; j++){
                        n += (i-j-1)*pow(10LL,2*j+1);
                        n = n*10LL + i-j-1;
                  }
                  nums.push_back(n);
            }
      }
      int tc; cin >> tc;
      for( int i = 1; i <= tc; i++){
            cout << "Case #" << i << ": ";
            solve();
      }
}

