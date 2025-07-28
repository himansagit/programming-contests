#include<bits/stdc++.h>

using namespace std;

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,k;
      cin >> n >> k;
      vector<int> alice,bob,both;
      int t,a,b;
      rep(i,n){
            cin >> t >> a >> b;
            if( a == 0 and b == 0)
                  continue;
            if( a == 1 and b == 0)
                  alice.push_back(t);
            else if( a == 0 and b == 1)
                  bob.push_back(t);
            else
                  both.push_back(t);
      }
      sort( alice.rbegin(), alice.rend());
      sort( bob.rbegin(), bob.rend());
      sort( both.rbegin(), both.rend());

      int res = 0;
      int cnt = 0;
      while( cnt < k){
            int  z = 0;
            if( !alice.empty() ) z += 1;
            if( !bob.empty() ) z += 2;
            if( !both.empty()) z += 4;
            
            if( z <= 2 ) break;
            else if( z == 3 ){
                  res += alice.back();
                  res += bob.back();
                  alice.pop_back();
                  bob.pop_back();
                  cnt++;
            }else if( z <= 6 ){
                  res += both.back();
                  both.pop_back();
                  cnt++;
            }else{
                  if( alice.back() + bob.back() < both.back () ){
                        res += alice.back();
                        res += bob.back();
                        alice.pop_back();
                        bob.pop_back();
                        cnt++;
                  }else{
                        res += both.back();
                        both.pop_back();
                        cnt++;
                  }
            }
      }
      cout << (cnt < k ? -1 : res ) << "\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

