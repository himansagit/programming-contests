#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

//RNG

void solve(){
      string s;
      cin >> s;
      string t = s;
      int n = s.length();
      bool ok = true;
      rep(i,n){
            if( t[i] == '#') ok = true;
            else{
                  if(ok){
                        ok = false;
                        t[i] = 'o';
                  }
            }
      }

      cout << t;


}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

