#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,s;
      cin >> n >> s;
      vector<int> v(n);
      int sum = 0;
      int a = 0, b = 0, c= 0;
      rep(i,n){
            int x;
            cin >> x;
            v[i] = x;
            sum += x;
            if( x == 0) a++;
            else if( x == 1) b++;
            else c++;
      }
      if(sum > s ){
      
            rep(i,n) cout << v[i] << " ";
            cout << "\n";
            return;
      }
      if( sum == s or s - sum > 1){
            cout << "-1\n";
            return;
      }
      assert(s-sum == 1);
      rep(i,a) cout << 0 << " ";
      rep(i,c) cout << 2 << " ";
      rep(i,b) cout << 1 << " ";
      cout << "\n";

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

