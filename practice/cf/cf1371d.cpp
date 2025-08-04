#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(int){
     int n, k;
     cin >> n >> k;
     vector<vector<int>> a(n, vector<int> (n));
     int q = k/n, r = k%n;
     rep(i,n){
            int e = i + q;
            if(i < r) e++;
            for(int j = i; j  < e; j++) a[i][j%n] = 1;
     }
     cout << (r == 0 ? 0 : 2) << "\n";
     rep(i,n){
           rep(j,n){
                 cout << a[i][j] ;
           }
           cout << "\n";
     }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

