#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      string s,t; cin >> s >> t;
      if( s  < t){
            cout << s << '\n';
            return;
      }
      int n = min( s.length(), t.length());
      rep(i,n){
            assert( s[i] >= t[i]);
            for(int j = i+1; j < s.length(); j++){
                  if( s[j] < t[i]){
                        swap(s[i],s[j]);
                        cout << s << '\n';
                        return;
                  }
            }
            if( s[i] > t[i]){
                  for(int j = i+1; j < s.length(); j++){
                        swap(s[i],s[j]);
                        if(s < t){
                              cout << s << '\n';
                              return;
                        }
                        swap(s[i],s[j]);
                  }
                  break;
            }
      }

      cout << "---" << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

