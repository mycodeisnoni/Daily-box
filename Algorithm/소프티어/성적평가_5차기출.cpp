#include <iostream>
#include <vector>
using namespace std;

struct ans{
	int s1, s2, s3, sA;
};
vector<ans>v;
int N;

int maxscore1, maxscore2, maxscore3, maxscoreAll = 0;
vector<int>test1;
vector<int>test2;
vector<int>test3;
vector<int>testAll;

int score1[1001] = { 0, };
int score2[1001] = { 0, };
int score3[1001] = { 0, };
int scoreAll[3001] = { 0, };

int prefix1[1001] = { 0, };
int prefix2[1001] = { 0, };
int prefix3[1001] = { 0, };
int prefixAll[3001] = { 0, };


void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		score1[a]++;
		test1.push_back(a);
		if (a > maxscore1) maxscore1 = a;
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		score2[a]++;
		test2.push_back(a);
		if (a > maxscore2) maxscore2 = a;
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		score3[a]++;
		test3.push_back(a);
		if (a > maxscore3) maxscore3 = a;
	}
}

void make_test3() {
	for (int i = 0; i < N; i++) {
		int a = test1[i] + test2[i] + test3[i];
		scoreAll[a]++;
		testAll.push_back(a);
		if (a > maxscoreAll) maxscoreAll = a;
	}
}

// prefix = idx 점수보다 점수가 높은 사람의 수
void calc() {

	prefix1[maxscore1] = 0;
	prefix2[maxscore2] = 0;
	prefix3[maxscore3] = 0;
	prefixAll[maxscoreAll] = 0;

	for (int i = maxscore1 - 1; i >= 0; i--) {
		prefix1[i] = prefix1[i + 1] + score1[i + 1];
	}
	for (int i = maxscore2 - 1; i >= 0; i--) {
		prefix2[i] = prefix2[i + 1] + score2[i + 1];
	}
	for (int i = maxscore3 - 1; i >= 0; i--) {
		prefix3[i] = prefix3[i + 1] + score3[i + 1];
	}
	for (int i = maxscoreAll - 1; i >= 0; i--) {
		prefixAll[i] = prefixAll[i + 1] + scoreAll[i + 1];
	}
}

void calc2() {
	for (int i = 0; i < N; i++) {
		int s1 = prefix1[test1[i]] + 1;
		int s2 = prefix2[test2[i]] + 1;
		int s3 = prefix3[test3[i]] + 1;
		int sA = prefixAll[testAll[i]] + 1;
		v.push_back({ s1,s2,s3,sA });
	}
}

// 필요한 것
// 출력의 형태가 각 대회마다의 N번째 사람의 등수를 출력하는 것
// N명의 사람들 자체를 정렬하는 방식은 별로다.
// 그럼 일단 배열로 입력받으면서 점수배열을 만들어서 기록하자.
// 1. 내가 몇번째 사람인지
// 2. 



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();
	make_test3();
	calc();
	calc2();

	for (int i = 0; i < N; i++) {
		cout << v[i].s1 << " ";
	}
	cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << v[i].s2 << " ";
	}
	cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << v[i].s3 << " ";
	}
	cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << v[i].sA << " ";
	}

	return 0;
}