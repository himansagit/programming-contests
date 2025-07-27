#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void L(){
      cout << "L";
}
void R(){
      cout<< "R";
}

void solve(int){
      int n; 
      cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      bool f = true;
      cout << "L";
      int l = 1, r= n-1, t = a[0];
      
      while(l <= r){
            if(f){
                  if( a[l] < t ){
                        L();
                        f = !f;
                        t = a[l];
                        l++;
                  }else if( a[r] < t){
                        R();
                        f = !f;
                        t = a[r];
                        r--;
                  }else{
                        if( a[l] > a[r]){
                              L();
                              t = a[l];
                              l++;
                        }else{
                              R();
                              t = a[r];
                              r--;
                        }
                  }
            }else{
                  if( a[l] > t ){
                        L();
                        f = !f;
                        t = a[l];
                        l++;
                  }else if( a[r] > t){
                        R();
                        f = !f;
                        t = a[r];
                        r--;
                  }else{
                        if( a[l] < a[r]){
                              L();
                              t = a[l];
                              l++;
                        }else{
                              R();
                              t = a[r];
                              r--;
                        }
                  }
            
            }
      }
      cout << "\n";
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

