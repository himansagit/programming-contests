#include<iostream>
int main()
{ 
      int res = 1;
      int n;
      scanf("%d",&n);
      for( int i = 1; i <= n; i++){
            res = res * i;
      }
      printf("%d",res);
}

