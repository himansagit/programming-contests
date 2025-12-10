#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
const int N = 1e6+5;
int rmq[N][25];
int A[N];
int L;
void build(int n){
      for( int i = 0; i < n; i++){
            rmq[i][0] = A[i];
      }
      for( int k = 0; k < L; k++){
            for( int i = 0; i < n; i++){
                  rmq[i][k+1] = gcd( rmq[i][k], rmq[i+(1 <<k)][k]);
            }
      }
}

int get(int l,int r){
     int k = 31 - __builtin_clz(r-l+1); 
     return gcd(rmq[l][k], rmq[r - (1<<k)+1][k]);
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      memset(rmq,0,sizeof(rmq)); 
      
      int n; cin >> n;
      L = 32 - __builtin_clz(n);
      for( int i = 0 ;i < n;i++) cin >> A[i];
      build(n);
      map<int,long long> cnt;
      for( int i = 0; i < n; i++){
            int s = i;
            // this step should take atmost logn steps
            while(s < n){
                  int l = s, r = n-1, cur = get(i,s);
                  while(l < r){
                        int m = (l+r+1)/2;
                        if( get(i,m) == cur){
                              l = m;
                        }else{
                              r = m-1;
                        }
                  }
                  cnt[cur] += l-s+1;
                  s = l+1;
            }
      }

      int q; cin >> q;
      while(q--){
            int x; cin >> x;            
            cout << cnt[x] << '\n';
      }
}

