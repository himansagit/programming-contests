#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,a,b;
      cin >> n >> a >> b;
      string s;
      cin >> s;
      for( int i = a; i < n-b; i++){
            cout << s[i];
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

