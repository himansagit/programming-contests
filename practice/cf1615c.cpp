#include<bits/stdc++.h>

using namespace std;

using i64 = long long;
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG

const int inf = 1e9;
int find(array<int,4> a,int t){
      if(a[1] == 0 and a[2] == 0)
            return 0;
      swap(a[0],a[2]);
      swap(a[1],a[3]);
      if( t == 0){
            if(a[1] == 0)
                  return inf;
            a[1]--;
            a[3]++;
            return find(a,1)+1;
      }else{
            if( a[0] == 0)
                  return inf;
            a[0]--;
            a[2]++;
            return find(a,0)+1;
      }
}

void solve(int){
     int n; 
     cin >> n;
     string a, b;
     cin >> a >> b;
     array<int,4> cnt = {0,0,0,0};
     rep(i,0,n){
           if( a[i] == '0' and b[i] == '0') cnt[0]++;
           if( a[i] == '0' and b[i] == '1') cnt[1]++;
           if( a[i] == '1' and b[i] == '0') cnt[2]++;
           if( a[i] == '1' and b[i] == '1') cnt[3]++;
     }
     int res = min( find(cnt,0), find(cnt,1));
     if( res >= inf) cout<< "-1\n";
     else cout << res << "\n";
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
// two type of oeprations 0 : 10 or 1 : 11
// two consecutive op of same type cancel out
// so any succesfull sequence of op must be
// 1010101.. or 01010101...
