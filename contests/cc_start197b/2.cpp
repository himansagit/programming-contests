#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >>n;
      cout << "2\n";
      rep(i,n) cout << i+1 << " ";
      cout << "\n";
      for( int i = n; i >0 ; i--){
            cout << i <<" ";
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

