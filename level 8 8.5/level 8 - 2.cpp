#include <iostream>
using namespace std;

int a, b;

void input() {
	cin >> a >> b;
}
void output() {
	int i = 5;
}

	while (i <= a + b) 
	{
		cout << i << " ";
		i++;

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	input();
	output();

	return 0;
}