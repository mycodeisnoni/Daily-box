#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[6] = { 3,4,2,5,7,9 };
	int a, b;
	cin >> a >> b;
	int temp;

	temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;

	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}



	return 0;
}