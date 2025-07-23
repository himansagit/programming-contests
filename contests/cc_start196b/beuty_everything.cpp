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

int getn(string& s){
      int n = s.length();
      int l = 0, r = 0;
      int cnt = 0;
      int ans = 0;
      while( r < n){
            if( cnt < 2){
                  if( s[r] == '1')
                        cnt++;
                  r++;
            }else{
                  if( s[l] == '1')
                        cnt--;
                  l++;
            }
            if( cnt < 2) ans = max(ans, r-l);
      }
      return ans;
}
void solve(int){
      int n;
      cin >> n;
      string s; 
      cin >> s;
      if( n <= 3){
            cout << n <<"\n";
            return;
      }
      // what is max. substring that conatins only 1 '1' or '0'
      string t = s;
      rep(i,0,n){
            if(t[i] == '1') t[i] = '0';
            else t[i] = '1';
      }
      int m = getn(s);
      m = max( m, getn(t));
      if( m >= 4){
            cout << m <<"\n";
            return;
      }
      //check for length 4
      rep(i,0,n-3){
            if( s.substr(i,4) == "0101" or s.substr(i,4) == "1010"){
                  cout <<"4\n";
                  return;
            }
      }
      cout << "3\n";
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

