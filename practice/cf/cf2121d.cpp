#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> a(n), b(n);
      for( int i = 0; i < n; i++){
            cin >> a[i];
      }
      for( int i = 0; i < n; i++){
            cin >> b[i];
      }
      vector<int> op1, op2, op3;
      auto srt = [&]( vector<int> &v, vector<int> &op)->void{
            for( int i = 0; i < n-1; i++){
                  for( int j = 0; j < n-1-i; j++){
                        if( v[j] > v[j+1]){
                              op.push_back(j+1);
                              swap(v[j], v[j+1]);
                        }
                  }
            }
      };
      srt(a,op1);
      srt(b,op2);
      for( int i = 0; i < n; i++){
            if( a[i] > b[i]){
                  swap( a[i], b[i]);
                  op3.push_back(i+1);
            }
      }
      int k = op1.size() + op2.size() + op3.size();
      cout <<  k << '\n';
      for( int &x:op1) cout << 1 << " " << x << '\n';
      for( int &x:op2) cout << 2 << " " << x << '\n';
      for( int &x:op3) cout << 3 << " " << x << '\n';

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

