#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
using i64 = long long;

bool on(i64 a, i64 j){
      return (a&j) > 0;
}
void solve(){
      i64 a, b; cin >> a >> b;
      vector<int> ff,ss;

      for( i64 i = 0; i < 32; i++){
            i64 j = (1LL << i);
            if( (on(a,j)^on(b,j)) ){
                  if( j > a){
                        cout << "-1\n";
                        return;
                  }else{
                        if( on(a,j)) ss.push_back(j);
                        else ff.push_back(j);
                  }
            }
      }
      cout <<ff.size()+ ss.size() << '\n';
      for( int x:ff){
            cout << x << " ";
      }
      for( int x:ss){
            cout << x << " ";
      }
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

