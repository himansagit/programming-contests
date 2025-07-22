#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define sz(x)	(int)(x).size() 
#define pb push_back
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG

void solve(int){
  int n;
  cin >> n;
  vector<i64> a(n);
  rep(i,0,n) cin >> a[i];
  i64 sum = 0, o = 0, e = 0, omin = 1e15, emin = 1e15;
  rep(i,0,n){
    if( i%2 == 1){
      o += a[i];
      e -= a[i];
      
    }else{
      o -= a[i];
      e += a[i];
    }
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

