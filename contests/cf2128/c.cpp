#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(int){
      int n;
      cin >> n;
      vector<int> b(n);
      rep(i,n) cin >> b[i];
      
      int m = 1e9+1;
      rep(i,n){
            if( m+m-1 < b[i] ){
                  cout << "NO\n";
                  return;
            }
            m = min(m,b[i]);
      }
      cout <<"YES\n";

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

