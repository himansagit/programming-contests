#include<bits/stdc++.h>

using namespace std;

int qry(int a, int b){
      cout << "? " << a << " " << b << endl;
      int r; cin >> r;
      return r;
}

int solve(){
      int n; cin >> n;
      int c = n-1, p = n-2;
      vector<int> ans(n+1);
      while( p > 0){
            int r = qry(p,c);
            if( r == -1) return -1;
            else if( r == 0){
                  ans[c] = p;
                  p--;
                  c--;
            }else{
                  p--;
            }
      }
      cout << "! ";
      for( int i = 1; i < n; i++){
            cout << ans[i] << ' ';
      }
      cout <<endl;
      return 0;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--){
            int r = solve();
            if( r == -1) return 0;
      }
}

