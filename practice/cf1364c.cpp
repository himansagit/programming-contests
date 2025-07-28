#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      int m = 0;
      rep(i,n){
            if( a[i] > i+1 or a[i] < m){
                  cout << "-1\n";
                  return;
            }
            m = min(m, a[i]);
      }
      vector<int> mark(n+5);
      rep(i,n){
            assert(a[i] < n+4);
            mark[a[i]] = true;

      }
      vector<int> b(n);
      int use = 1;
      int mex = 0;
      rep(i,n){
            if( a[i] == mex){
                  while(mark[use]) use++;
                  b[i] = use;
                  use++;
            }else{
                  b[i] = mex;
                  mex = a[i];
            }
      }
      rep(i,n) cout << b[i] << " ";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

