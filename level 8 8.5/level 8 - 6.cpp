#include <iostream>
using namespace std;

int arr[3][4] = { 0 };

void input() {
	int a;
	cin >> a;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = a++;
		}
	}
}

void process() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] += 1;
		}
	}
}

void output() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	input();
	process();
	output();

	return 0;
}