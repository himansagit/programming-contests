#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
const int N = 1e7+10;
int score[N];

void solve(){
      int n,m; cin >> n >> m;
      memset( score,0,sizeof(score));      
      for( int i = 0; i < n; i++){
            int s; cin >> s;
            score[s]++;
      }
      vector<int> t(m);
      for( int i = 0; i < m; i++){
            cin >> t[i];
      }
      vector<int> sc;
      for( int i = 0; i < N ; i++){
            if( score[i] > 0){
                  sc.push_back(score[i]);
            }
      }
      reverse(sc.begin(), sc.end());
      sort( t.rbegin(), t.rend());
      int l = 0, r = min(m, (int)sc.size());
      //debug(sc);
      //debug(t);
      while( l < r){
            int mid = (l+r+1)/2;
            //debug(l,r, mid);
           i64 sum = 0, pre = 0;
           //for( int j = m-1; j >= mid; j--) sum += t[j];
           bool ok = true;
           //debug(sum);
          // for( int j = mid-1; j >= 0; j--){
          //        pre += sc[j]; 
          //        sum += t[j];
          //        debug(mid,pre,sum);
          //        if( pre > sum){
          //              debug(pre,sum);
          //             ok = false; 
          //        }
          //        else sum -= 
          //        debug(mid,pre,sum);

          // }
           int e = m - mid;
           for( int j = 0; j < e; j++){
                 sum += t[j];
           }
           for( int j = 0; j < mid; j++){
                 pre += sc[j];
                 sum += t[j+e];
                 if( pre > sum){
                       ok = false;
                 }else{
                       sum -= pre;
                 }
           }

            if( ok){
                  l = mid;
            }else{
                  r = mid-1;
            }
      }
      //debug(l);
      i64 sum = 0;
      for( int i = 0; i < l; i++) sum += sc[i];
      cout << sum << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      for( int i = 1; i <= tc; i++){
            cout << "Case #" << i << ": ";
            solve();
      }
}

