#include <iostream>
using namespace std;

int X;

void init() {
	cin >> X;
}

int main() {

	init();

	int now = 1;

	// 홀수는 row 부터 , 짝수는 col 부터
	// now : 현재 몇번째 단계인지
	while ((X - now) > 0) {
		X -= now;
		now++;
	}
	
	bool is2K = false;
	if (now % 2 == 0) is2K = true;

	int fir, sec;
	if (is2K) {
		fir = X;
		sec = now + 1 - X;
	}
	else {
		fir = now + 1 - X;
		sec = X;
	}
	
	cout << fir << '/' << sec;

	return 0;
}