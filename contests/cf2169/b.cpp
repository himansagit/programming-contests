#include<bits/stdc++.h>

using namespace std;

void solve(){
      string s; cin >> s;
      int n = s.length();
      int a = 0, b = 0, c= 0;
      bool inf = false;
      for( int i = 0; i < n; i++){
            if( s[i] == '<'){
                  a++;
                  if( b or c){
                        inf = true;
                  }
            }else if( s[i] == '*'){
                  if( b or c) inf = true;
                  b++;
            }else{
                  c++;
            }
      }
      if( inf) cout << "-1\n";
      else cout << max({a+b,b+c}) << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

