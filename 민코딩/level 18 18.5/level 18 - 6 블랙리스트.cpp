#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char town[3][3] = {
	{'C', 'D', 'A'},
	{'B', 'M', 'Z'},
	{'Q', 'P', 'O'}
	};

	char black[4];

	for (int i = 0; i < 4; i++)
		cin >> black[i];

	int bucket[100] = { 0 };

	//town을 bucket에 담기
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			bucket[town[y][x]] = 1;

	int count = 0;
	for (int i = 0; i < 4; i++)
		if (bucket[black[i]] == 1)
			count++;

	cout << count << "명";

	return 0;
}