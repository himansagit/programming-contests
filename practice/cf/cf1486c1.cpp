#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

//RNG


vector<int> store(3e5+1,-1);

inline void q(int l,int r){
      cout << "? " << l << " " << r <<endl;
}

int checkr(int l,int r){
      if(l >= r)
            return 0;
      if(store[r] != -1)
            return store[r];

      q(l,r);
      int t;
      cin >> t;
      store[r] = t;
      return t;
}
int checkl(int l,int r){
      if(l >= r)
            return 0;
      if(store[l] != -1)
            return store[l];

      q(l,r);
      int t;
      cin >> t;
      store[l] = t;
      return t;
}

int to_right(int m, int r,int n){
     int l = m;

     for(int z = r-m+1; z >0 ; z/=2){
           while( l+z <= n and checkr(m,l+z)!=m)
                 l += z;
     }
     cout << "! " << l+1 <<endl;
     return l+1;
}

int to_left(int l, int m,int n){
     int r = m; 
     for(int z = m-l+1; z > 0; z /=2){
           while( r -z >=1 and checkl(r-z,m) != m)
                 r -= z;
     }
     cout << "! " << r-1 <<endl;
     return r-1;
}
void solve(){
      int n;
      cin >> n;
      int l = 1, r = n;
      q(l,r);
      int s;
      cin >> s;
      if( s == 1) to_right(s,r,n);
      else if( s == n) to_left(1,s,n);
      else{
            q(1,s);
            int t; 
            cin >> t;
            if( t == s) to_left(1,s,n);
            else to_right(s,r,n);
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

