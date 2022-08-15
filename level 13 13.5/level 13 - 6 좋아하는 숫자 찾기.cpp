#include <iostream>
#include <cstring>
using namespace std;


int arr[2][6] = {
	4,5,6,1,3,1,
	2,1,3,6,3,6
};


void input(int* a, int*b, int*c) {
	cin >> *a >> *b >> *c;
}

void process(int a,int b,int c, int*r1, int*r2, int*r3) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if (a == arr[i][j]) (*r1)++;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if (b == arr[i][j]) (*r2)++;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if (c == arr[i][j]) (*r3)++;
		}
	}
}

void output(int a, int b, int c, int r1, int r2, int r3) {
	cout << a << "=" << r1 << "°³" << "\n";
	cout << b << "=" << r2 << "°³" << "\n";
	cout << c << "=" << r3 << "°³" << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a, b, c;
	int r1 = 0;
	int r2 = 0;
	int r3 = 0;
	input(&a, &b, &c);
	process(a, b, c, &r1, &r2, &r3);
	output(a, b, c, r1, r2, r3);

	return 0;
}