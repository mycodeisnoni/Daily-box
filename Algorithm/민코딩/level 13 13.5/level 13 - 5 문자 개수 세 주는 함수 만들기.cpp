#include<iostream>
#include <cstring>
using namespace std;


void KFC(char x[10], int* cntA, int* cnta) {
	//char x ��� ���� �� ����
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
	//KFC(x[10], ~~ �� ��� ����

	cout << "�빮��" << cntA << "��\n";
	cout << "�ҹ���" << cnta << "��";

	return 0;
}
