#include<bits/stdc++.h>

using namespace std;

bool getb(int &a, int &i){
      return(a&(1<<i)) > 0;
}
void solve(){
      int n; cin >> n;
      vector<int> a(n), b(n);
      for( int i = 0; i < n; i++) cin >> a[i];
      for( int i = 0; i < n; i++) cin >> b[i];
      for( int p = 25; p >= 0; p--){
            int c = 0;
            for( int i = 0; i < n; i++){
                  if( getb(a[i],p) != getb(b[i],p)){
                        c++;
                  }
            }
            if( c%2 == 0){
                  continue;
            }else{
                  for( int i = n; i >= 1; i--){
                        if( getb(a[i-1],p) != getb(b[i-1],p)){
                              if( i%2 == 1) cout << "Ajisai\n";
                              else cout << "Mai\n";
                              return;
                        }
                  }
            }
      }
      cout << "Tie\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

