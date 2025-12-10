#include<bits/stdc++.h>

using namespace std;

int qry( int a, int b){
      cout << "? " << a << " " << b << endl;
      int r; cin >> r;
      return r;
}
int solve(){
      int n; cin >> n;
      int  c = 2;
      queue<int> prt, chl;
      vector<int> ans(n+1);
      for( ; c <= n; c++){
            int r = qry(1,c);
            if( r == 1){
                  prt.push(c);
            }else if( r == -1){
                  return -1;
            }else{
                  ans[c] = 1;
                  c++;
                  break;
            }
      }
      while( c < n){
            while( c < n and !prt.empty()){
                  int p = prt.front();
                  prt.pop();
                  int r = qry(p,c);
                  if( r == -1) return -1;
                  else if( r == 0){
                        chl.push(c);
                        ans[c] = p;
                        c++;
                  }else{

                  }
            }
            while( !chl.empty()){
                  int t = chl.front();
                  prt.push(t);
                  chl.pop();
            }
      }
      cout << "! ";
      for( int i = 1; i < n; i++) cout << ans[i] << " ";
      cout << endl;
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

