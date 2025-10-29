#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 6, M = 7;
bool outside(int i, int j){
      if( min(i,j) < 0 or i >= N or j >= M) return true;
      else return false;
}
void solve(){
      vector<string> s(N);
      rep(i,N) cin >> s[i];
      reverse(s.begin(), s.end());
      map<string,int> mark;
      string cur(42,'#');
      vector<string> tmp(N,string(M,'#'));

      //bool connie = false, forrest = false;
      map<char,bool> ok;
      ok['C'] = false;
      ok['F'] = false;
      vector<int> h(M);
      int x;
      int y;
      auto check = [&](char ch)->bool{
            rep(i,N){
                  rep(j,M){
                        if( j <= 3 and tmp[i][j] == ch and tmp[i][j+1] == ch and tmp[i][j+2] == ch and tmp[i][j+3] == ch ){
                              x = i, y = j;
                              return true;
                        }
                        if( i <= 2 and tmp[i][j] == ch and tmp[i+1][j] == ch and tmp[i+2][j] == ch and tmp[i+3][j] == ch){
                              x = i, y = j;
                              return true;
                        }
                        if( i <= 2 and j <= 3 and tmp[i][j] == ch and tmp[i+1][j+1] == ch and tmp[i+2][j+2] == ch and tmp[i+3][j+3] == ch){
                              x = i, y = j;
                              return true;
                        }
                        if( i <= 2 and j >= 3 and tmp[i][j] == ch and tmp[i+1][j-1] == ch and tmp[i+2][j-2] == ch and tmp[i+3][j-3] == ch){
                              x = i, y = j;
                              return true;
                        }
                  }
            }
            return false;
      };
      // check if anyone wins already
      rep(i,N){
            rep(j,M) tmp[i][j] = s[i][j];
      }
      if( check('C') == false and check('F') == false){
            // no one winds
            cout << "0\n";
            return;
      }
      rep(i,N){
            rep(j,M) tmp[i][j] = '.';
      }
      
      auto dfs = [&](auto self, char ch)->void{
            //if( ok['C'] == true and ok['F'] == true) return;
            //rep(i,N) cout << tmp[i] << endl;
            //cout << endl;
            for( int j = 0; j < M; j++){
                  int i = h[j];
                  if( i >= N) continue;
                  if( s[i][j] == ch){
                        tmp[i][j] = ch;
                        cur[M*i + j] = ch;
                        h[j]++;
                        if( mark[cur] == 0){
                              mark[cur] = 1;
                              if( check(ch)){
                                   // if( ch == 'F'){
                                   //      debug(i,j, ch);
                                   //      debug(x,y);
                                   //      rep(i,N) cout << tmp[i] << endl;
                                   //       assert(0);
                                   // }
                                    ok[ch] = true;
                                    //return;
                              }else{
                                    if( ch == 'C') self(self,'F');
                                    else self(self,'C');
                              }
                        }
                        h[j]--;
                        tmp[i][j] = '.';
                        cur[M*i + j] = '#';
                  }
            }
      };
      dfs(dfs,'C');
      if( ok['C']  == true and ok['F'] == true){
            cout << "?\n";
      }else if( ok['C']  == true and ok['F'] == false){
            cout << "C\n";
      }else if(  ok['C']  == false and ok['F'] == true){
            cout << "F\n";
      }else{
            cout << "0\n";
      }
}


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      for( int i = 1; i <= tc; i++){
            cout << "Case #" << i << ": ";
            solve();
      }
}

