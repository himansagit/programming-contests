#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      string left, mid, right;
      if( n == 1){
            mid = "a";
      }else if( n == 2){
            mid = "ab";
      }else{
            if( n%2 == 0){
                  mid = "z";
                  n--;
            }else{
                  mid = "yz";
                  n -= 2;
            }
            for( int i = 0; i < n/2; i++){
                  left += 'a';
                  right += 'a';
            }
            right += 'a';
      }
      string res = left + mid + right;
      cout << res << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

