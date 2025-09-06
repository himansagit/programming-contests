#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int ctn(string s){
      int res = 0;
      for( char c:s){
            res = res * 26 + c - 'A' + 1;
      }
      return res;
}

string ntc(int n){
      // have to implement manually
      vector<int> d;
      int x = n;
      while( x){
            d.push_back(x%26);
            x /= 26;
      }
      assert( d.size() > 0);
      debug(d);
      for( int i = 0; i < d.size()-1; i++){
            if( d[i] == 0){
                  d[i] = 26;
                 d[i+1]--;        
            }else if( d[i] == -1){
                  d[i] = 2;
                  d[i+1]--;
            }
      }
      assert(d.back() >= 0);
      debug(d);
      if( d.back() == 0) d.pop_back();
      reverse(d.begin(), d.end());
      string res;
      for( int &x:d){
            res += (char)'A' + x -1;
      }
      return res;
}
void solve(){
      string s;
      cin >> s;
      debug(s);
      int n = s.length();
      rep(i,n-1){
            if( isalpha(s[i+1]) and isdigit(s[i])){
                  int r = stoi(s.substr(1,i));
                  int c = stoi(s.substr(i+2,n-2-i));
                  debug(r,c);
                  cout << ntc(c) << r << '\n';
                  return;
            }
      }
      rep(i,n){
            if( isdigit( s[i] )){
                  cout << "R" << s.substr(i,n-i) << "C" << ctn(s.substr(0,i)) << '\n';
                  return;
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

