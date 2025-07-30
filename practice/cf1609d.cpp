#include<bits/stdc++.h>

using namespace std;

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int N = 1005;

int dsu[N];
int Size[N];

int root(int a){
      if( dsu[a] == a)
            return a;
      return dsu[a] = root(dsu[a]);
}

void merge(int a, int b){
      int x = root(a);
      int y = root(b);
      if(x == y)
            return;
      dsu[x] = y;
      Size[y] += Size[x];
      Size[x] = 0;
}
bool same(int a, int b){
      return root(a) == root(b);
}
vector<pair<int,int>> F(N);
void solve(){
      int n,d;
      cin >> n >> d;
      //vector<vector<int>> G(n+1);
      rep(i,d) cin >> F[i].first >> F[i].second;
      for(int i = 0; i < d; i++){
            fill(Size,Size+N,1);
            iota(dsu,dsu+N,0);

            int extra = 0;

            for( int j = 0; j <= i; j++){
                  if( same(F[j].first, F[j].second)) extra++;
                  else{
                        merge(F[j].first, F[j].second);
                  }
            }
            sort(Size,Size+n+1,[](int a,int b){ return a > b;});
            int res = 0;
            for( int j = 0; j <= extra; j++) res += Size[j];
            cout << res -1 << "\n";
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

