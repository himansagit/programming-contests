#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      string s; cin >> s;
      int n = s.length();
      double ans = 0;
      rep(i,n){
            rep(j,i-1){
                  double num = 0;
                  if( s[i] == 't' and s[j] == 't'){
                        for( int k = j+1; k < i; k++){
                              if( s[k] == 't') num++;
                        }
                  }
                  double den = (i-j-1);
                  ans = max(ans, num/den); 
            }
      }
      cout << setprecision(10) << ans;
}

