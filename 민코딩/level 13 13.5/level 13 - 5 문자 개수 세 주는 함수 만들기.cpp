#include<iostream>
#include <cstring>
using namespace std;


void KFC(char x[10], int* cntA, int* cnta) {
	//char x 라고만 썼을 때 에러
	cin >> x;
	for (int i = 0; i < 10; i++) {
		if (x[i] == '\0') break;
		else {

		if (x[i] >= 'A' && x[i] <= 'Z') {
			*cntA += 1;
		}
		else { *cnta +=1; }
	}
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char x[10];
	int cntA = 0;
	int cnta = 0;

	KFC(x[10], &cntA, &cnta);
	//KFC(x[10], ~~ 할 경우 에러

	cout << "대문자" << cntA << "개\n";
	cout << "소문자" << cnta << "개";

	return 0;
}
