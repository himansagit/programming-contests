#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<i64>  a(n);
      rep(i,n) cin >> a[i];

      cout << n << " " << n << "\n";
      cout << -a[n-1] << "\n";
      a[n-1] = 0;
      if( n == 1){
            cout <<"1 1\n0\n1 1\n0\n";
            return ;
      }
      cout << 1 << " " << n-1 << "\n";
      rep(i,n-1){
            cout << a[i]*(n-1) << " ";
      }
      cout << "\n";
      cout << 1 << " " << n << "\n";
      rep(i,n){
            cout << -a[i]*n << " ";
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

