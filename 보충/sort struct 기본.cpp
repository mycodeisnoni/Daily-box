#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int n;
	char ch;
};

bool cmp(Node a, Node b) {
	// 숫자는 작을수록 앞으로
	if (a.n < b.n) return true;
	if (a.n > b.n) return false;
	// 문자는 클수록 앞으로
	if (a.ch < b.ch) return false;
	if (a.ch > b.ch) return true;
	return false;
}

vector<Node> arr = { {3, 'A'}, {7, 'B'}, {7, 'Q'}, {7, 'C'}, {4, 'Q'}, {5, '3'} };
int main()
{
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].n << " " << arr[i].ch << "\n";
	}
	return 0;
}