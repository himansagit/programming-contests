#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,m;
      cin >> n >> m;
      vector<int> a(n),b(m);
      map<int,int> M;
      rep(i,n){
            int x;
            cin >> x;
            M[x] += 1;
      }
      rep(i,m){
            int x;
            cin >> x;
            M[x]--;
      }
      for(auto p:M){
            if( p.second > 0){
                  int c = p.second;
                  int d = p.first;
                  rep(i,c){
                        cout << d << " " ;
                  }
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

