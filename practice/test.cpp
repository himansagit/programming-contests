#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(string &s, vector<int> &a){
      int  n = s.length();
      int sum = a[0] + a[1] + a[2];
      rep(i,3){
            if( a[i] > 0){
                  if(  n <= 1 or s[n-1] -'a' != i or s[n-2] -'a' != i){
                       a[i]--;
                       int m = max( { a[0], a[1], a[2]});
                        if( 2*(sum - m)>= m){
                              s += (char)'a' + i;
                              solve(s,a);
                              return;
                        }
                        a[i]++;
                  }
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);

      int a,b,c;
      cin >> a >> b >> c;
      string ans;
      vector<int> v = {a,b,c};
      solve(ans,v);
      cout << ans << '\n'; 
}

