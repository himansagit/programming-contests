#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

using node = array<int,9>;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      string start,end;
     //rep(i,3){
     //      rep(j,3){
     //            cin >> end[i][j];
     //            start[i][j] = 3*i + j + 1;
     //      }
     //}
     rep(i,9){
           char x; cin >> x;
           end += x;
           start += '1' + i;
     }
      unordered_map<string,int> mark; // might have large constant factor
      mark[start] = 1;
      queue<pair<string,int>> q;
      q.push({start,0});
      while( !q.empty()){
           auto [u,d] = q.front();
           q.pop();
           if( u == end){
                 cout << d << '\n';
                 return 0;
           }
           rep(i,3){
                 string v1 = u;
                 string v2 = u;
                 //swap(v1[i][0],v1[i][1]);
                 swap(v1[3*i],v1[3*i+1]);
                 //swap(v2[i][1],v2[i][2]);
                 swap(v2[3*i+1],v2[3*i+2]);
                 if( mark[v1] != 1){
                       mark[v1] = 1;
                       q.push({v1,d+1});
                 }
                 if( mark[v2] != 1){
                       mark[v2] = 1;
                       q.push({v2,d+1});
                 }
           }
           rep(i,3){
                 string v1 = u;
                 string v2 = u;
                 //swap(v1[0][i],v1[1][i]);
                  swap(v1[3+i],v1[i]);
                 //swap(v2[1][i],v2[2][i]);
                  swap(v2[3+i],v2[6+i]);
                 if( mark[v1] != 1){
                       mark[v1] = 1;
                       q.push({v1,d+1});
                 }
                 if( mark[v2] != 1){
                       mark[v2] = 1;
                       q.push({v2,d+1});
                 }
           }
      }
      return 0;
}

