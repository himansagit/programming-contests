#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define sz(x)	(int)(x).size() 
#define pb push_back
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG
vector<vector<i64>> f(4);
i64 getn(i64 n){
      i64 res = n;
     for( int i = 0; i < 4; i++)
     {
           for(int c:f[i])
           {
             if(i%2 == 0){
                   res -= n/c;
             }else{
                   res += n/c;
             }
           }
     } 
     return res;
}

void solve(int){
      i64 l,r;
      cin >> l >> r;
      i64 L = getn(l-1);
      i64 R = getn(r);
      debug(L,R);
      cout << R-L <<"\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);

      vector<i64> a = {2,3,5,7};
      f[0] = a;
      rep(i,0,4) rep(j,i+1,4) f[1].pb(a[i]*a[j]);
      rep(i,0,4) rep(j,i+1,4) rep(k,j+1,4) f[2].pb(a[i]*a[j]*a[k]);
      rep(i,0,4) rep(j,i+1,4) rep(k,j+1,4) rep(l,k+1,4) f[3].pb(a[i]*a[j]*a[k]*a[l]);
      debug(f);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

