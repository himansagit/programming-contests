#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k; cin >> n >> k;
      string s; cin >> s;
      int a = count(s.begin(), s.end(), '0');
      int b = count(s.begin(), s.end(), '1');
      int c = count(s.begin(), s.end(), '2');
      string ans(n,'+');
      for( int i = 0; i< n; i++){
            if( i >= a+c and i < n-b-c){
                  ans[i] = '+';
            }else if( i < a or i >= n-b) ans[i] = '-';
            else{
                  if( n-b-a == c) ans[i] = '-';
                  else ans[i] = '?';
            }
      }
      cout << ans <<'\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

