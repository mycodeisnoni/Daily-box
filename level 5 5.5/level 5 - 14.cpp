#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[6] = { 0 };
	int a, b, t, i;

	cin >> a >> b;
	t = a;

	for (i = 0; i <= b - t; i++) {
		arr[i] = a++;
	}

	for (i = 0; i <= b - t; i++) {
		cout << arr[i];
	}

	//¼Ö·ç¼Ç
//#include <iostream>
//	using namespace std;
//
//	int main()
//	{
//		int arr[6] = { 0 };
//		int a, b, x;
//		cin >> a >> b;
//
//		int t = 0;
//
//		for (x = a; x <= b; x++)
//		{
//			arr[t] = x;
//			t++;
//		}
//		for (x = 0; x < t; x++)
//		{
//			cout << arr[x];
//		}
//
//		return 0;
//	}



	return 0;
}