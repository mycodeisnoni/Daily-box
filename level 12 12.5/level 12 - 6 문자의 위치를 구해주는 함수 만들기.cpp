#include <iostream>
using namespace std;

char vect[9] = "MINQUEST";

int Length(char ch)
{
	int x;
	for (x = 0; x < 8; x++)
	{
		if (vect[x] == ch)
		{
			return x;
		}
	}

	return 0;
}

int main()
{
	char input[3];
	int result;
	int i;

	//�� ���� �Է�
	for (i = 0; i < 3; i++)
	{
		cin >> input[i];
	}

	//for ������ �� ���ھ� ó��
	for (i = 0; i < 3; i++)
	{
		result = Length(input[i]);
		cout << input[i] << "=" << result << endl;
	}

	return 0;
}
