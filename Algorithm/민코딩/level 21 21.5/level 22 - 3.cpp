#include <iostream>
using namespace std;

char st[5] = "BGTK";
char path[10] = {0};
int a;


void BBQ(int level) {

    if (level == a ) {
        cout << path << endl;  //path[10]�̶�� ���� �ڿ� ����־ �ȳ���
        return;
    }

    for (int i = 0; i < 4; i++) {
        path[level] = st[i];
        BBQ(level + 1);
        path[level] = 0; // ������ ��� �ȳ��� �κ�
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> a;

    BBQ(0);

    return 0;
}