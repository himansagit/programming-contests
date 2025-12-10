#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

const int N = 2e5+5;
int rmq[N][5][20];

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      memset(rmq,0,sizeof(rmq));
      int n,m,k; cin >> n >> m >> k;
      vector<vector<int>> A(n, vector<int>(m));
      for(int i = 0; i < n; i++){
            for( int j = 0; j < m; j++){
                  cin >> rmq[i][j][0];
            }
      }

      int L = 32 - __builtin_clz(n);
      for( int k = 0; k < L; k++){
            for( int i = 0; i < n; i++){
                  for( int j = 0; j < m; j++){
                        if( i + (1<<k) < n){
                              rmq[i][j][k+1] = max( rmq[i][j][k], rmq[i + (1<<k)][j][k]);
                        }
                  }
            }
      }
      auto get = [&](int l, int r, int j)->int{
            int k = 31 - __builtin_clz(r-l+1);      
            return max( rmq[l][j][k], rmq[r-(1<<k)+1][j][k]);
      };
      int l = 0, r = n;
      while( l < r){
            int mid = (l+r+1)/2;
            if( mid == 0) break;
            bool ok = false;
            for( int i = 0; i < n-mid+1; i++){
                  int sum = 0;
                  for( int j = 0; j < m; j++){
                        sum += get(i,i+mid-1,j);
                  }
                  if(sum <= k){
                        ok = true; 
                        break;
                  }
            }
            if( ok) l = mid;
            else r = mid-1;
      }
      vector<int> ans(m);
      if( l > 0){
            for( int i = 0; i < n-l+1; i++){
                  int sum = 0;
                  for( int j = 0; j < m; j++){
                        ans[j] = get(i,i+l-1,j);
                        sum += ans[j];
                  }
                  if(sum <= k) break;
            }
      }
      for(int i = 0; i < m; i++) cout << ans[i] << ' ';
      cout << '\n';
}

