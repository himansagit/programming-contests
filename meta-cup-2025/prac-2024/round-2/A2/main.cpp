#include<bits/stdc++.h>

using i64 = long long;
using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
vector<i64> nums;
void dfs(i64 l, i64 r, i64 n, i64 w){
      //cout << "n = " << n << endl;
      if( w >= 18) return;
      for( int i = l; i >= 1; i--){
            for(int j = r; j >= 1; j--){
                  i64 x = i*pow(10LL,w) + n;
                  x = 10*x + j;
                  nums.push_back(x);
                  //cout << x << endl;
                  dfs(i,j,x,w+2);
            }
      }
}
void solve(){
      i64 a,b,m;
      cin >> a >> b >> m;
      int c = 0;
      for(const i64 &x:nums){
            if( a <= x and x <= b and x%m == 0) c++;
      }
      cout << c << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      for( int i = 1; i <= 9; i++){
            nums.push_back(i);
            dfs(i-1, i-1, i, 1);
      }
      //cout << nums.size() << endl;
      //sort(nums.begin(), nums.end());
      //rep(i,100) cout << nums[i] << endl;
      int tc = 0;
      cin >> tc;
      for( int i = 1; i <= tc; i++){
            cout << "Case #" << i << ": ";
            solve();
      }
}

