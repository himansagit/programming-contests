#include<bits/stdc++.h>

using namespace std;

void fun() {
	mt19937 mt;
	constexpr int size = 500 << 20;
	char s[size];
	for (int i = 0; i < size; ++i) {
		s[i] = mt();
	}
	for (int i = size - 1; i >= 1; --i) {
		s[0] ^= s[i];
	}
	cout << (int)s[0] << endl;
}
int main()
{ 
      cout << "hello \n";
}

