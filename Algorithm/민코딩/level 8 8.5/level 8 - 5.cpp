#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[6] = { 3,4,1,6,7,5 };

	int i = 0;

	while (i < 6) {
		cout << arr[i] << " ";
		i++;
	}


	return 0;
}