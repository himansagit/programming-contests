#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,m;
      cin >> n >> m;
      vector<int> exl(n+1);
      vector<vector<int>> days(m+1);
      vector<vector<int>> fr(n+1);

      rep(i,m){
            int k; cin >> k;
            int x;
            rep(j,k){
                   cin >> x;
                  days[i+1].push_back(x);
                  fr[x].push_back(i+1);
            }
            if( k == 1){
                  exl[x]++;
            }
      }
      if( *max_element(exl.begin(),exl.end()) > (m+1)/2){
            cout << "NO\n";
            return;
      }
     int maxi = 0, f= -1;
     rep(i,n){
           if( maxi < fr[i+1].size() ){
                 maxi = fr[i+1].size();
                 f = i+1;
           }
     }
     vector<int> ans(m+1);
     if( maxi >= (m+1)/2){
           // ensure one friend gets picked exactly (m+1)/2 times 
           // first assign exclusive days
           int cnt = (m+1)/2;
           for( int i = 1; i <= m and cnt > 0; i++){
                 if( days[i].size() == 1 and days[i][0] == f){
                       ans[i] = f;
                       cnt--;
                 }
           }
           for( int i = 0; i < fr[f].size() and cnt > 0 ; i++){
                 if( ans[fr[f][i]] != 0) continue;
                 ans[fr[f][i]] = f;
                 cnt--;
           }
           // at this pint friend f should be
           // assigned to exaclty (m+1)/2 days
           // rest of the day can be filled by any friend
           // except f;
           for(int i = 1; i <= m; i++){
                 if( ans[i] != 0) continue;
                 assert( days[i].size() > 0);
                 if( days[i][0] != f){
                       ans[i] = days[i][0];
                 }else{
                       assert( days[i].size() > 1);
                       ans[i] = days[i][1]; // any other friend than f
                 }
           }
            
     }else{
            // no friend is available more 
            // thatn (m+1)/2 time so i can just pick
            // first friend on each day
            rep(i,m){
                  ans[i+1] = days[i+1][0];
            }
     }
     cout << "YES\n";
     rep(i,m) cout << ans[i+1] << " \n"[i == m-1];
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

