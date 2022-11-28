#define DEER 0
#define RABBIT 1
#define SNAKE 2

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <time.h>
using namespace std;

// ※ 전역변수 및 함수 사용 가능합니다.
// ※ 단, 팀명을 앞에 prefix로 붙여주세요.
//     ex) int seoul12_2_sum = 0;
//     ex) int seoul12_2() { } 
// ※ 현재 상태에서 빌드 시 사용할 수 있는 API는 사용 가능합니다.
// ※ 제출방법 : Me 함수와 사용한 전역변수 또는 전역함수를 포함하여 txt 파일로 만들어서 제출

int seoul22_3_cnt0 = 0;
int seoul22_3_cnt1 = 0;
int seoul22_3_cnt2 = 0;

int seoul22_3_array1[10] = { 2,2,2,2,0,2,2,2,2,0 };
int seoul22_3_array2[10] = { 2,2,2,2,1,2,2,2,2,1 };
int seoul22_3_array3[10] = { 2,2,2,2,1,2,2,2,2,2 };



int Me(int opp, int turn, int opp_prev, int opp_last_pattern[][10])
{
	for (int i = 0; i < 10; i++) {
		if (opp_last_pattern[opp][i] == 0) seoul22_3_cnt0++;
		if (opp_last_pattern[opp][i] == 1) seoul22_3_cnt1++;
		if (opp_last_pattern[opp][i] == 2) seoul22_3_cnt2++;
	}

	// 상대가 뱀4 토끼1
	if (seoul22_3_cnt2 == 8) {
		// 뱀4 사슴1
		if (seoul22_3_cnt0 == 2) {
			return seoul22_3_array2[turn];
		}

		// 뱀4 토끼1
		if (seoul22_3_cnt0 == 2) {
			return seoul22_3_array3[turn];
		}


	}

	else if (seoul22_3_cnt2 == 9) {

	}
	// 아무것도 아님
	return seoul22_3_array1[turn];
	
}

// 아래 Opponent1~3은 테스트용 상대 사냥꾼입니다.
// 기본 제공 코드는 임의 수정해도 관계 없습니다.
// 상대방 추가 시, Register 함수를 통해 상대방을 등록합니다. ex) Register("Opp1", Opponent1); 
int Opponent1(int opp, int turn, int opp_prev, int opp_last_pattern[][10])
{
	return DEER;
}

int Opponent2(int opp, int turn, int opp_prev, int opp_last_pattern[][10])
{
	return RABBIT;
}

int Opponent3(int opp, int turn, int opp_prev, int opp_last_pattern[][10])
{
	return SNAKE;
}

typedef int EntryFunction(int opp, int turn, int opp_prev, int opp_last_pattern[][10]);

EntryFunction* f[150] = { 0 };
const char* names[100];
int f_inx = 0;
int total_score[150];
int last_pattern[150][150][10]; // [팀][대전][패턴]
int pattern_count[150];

void Register(const char* name, EntryFunction func)
{
	names[f_inx] = name;
	f[f_inx++] = func;
}


int main() {
	srand((unsigned int)time(NULL));

	Register("Me", Me);
	Register("Opp1", Opponent1);
	//Register("Opp2", Opponent2);
	//Register("Opp3", Opponent3);

	for (int i = 0; i < 140; i++)
		for (int j = 0; j < 140; j++)
			for (int k = 0; k < 10; k++)
				last_pattern[i][j][k] = -1;


	for (int i = 1; i < f_inx; i++) {
		for (int j = 0; j < f_inx; j++) {

			int team_a = j % f_inx;
			int team_b = (j + i) % f_inx;

			printf("[%s] vs [%s]\n", names[team_a], names[team_b]);

			int a_game_score = 0;
			int b_game_score = 0;

			int prev_a = -1;
			int prev_b = -1;

			int team_a_count = 0;
			int team_b_count = 0;

			int a_pattern[10];
			int b_pattern[10];

			for (int k = 0; k < 10; k++) {

				int a = f[team_a](team_b, k, prev_b, last_pattern[team_b]);
				int b = f[team_b](team_a, k, prev_a, last_pattern[team_a]);

				a_pattern[k] = a;
				b_pattern[k] = b;

				if (a == prev_a) team_a_count += a + 1; else team_a_count = 0;
				if (b == prev_b) team_b_count += b + 1; else team_b_count = 0;

				if (a != 0 && a != 1 && a != 2) team_a_count = 100;
				if (b != 0 && b != 1 && b != 2) team_b_count = 100;

				prev_a = a;
				prev_b = b;

				int a_score = 0;
				int b_score = 0;
				int a_bonus = 0;
				int b_bonus = 0;

				if (a == DEER && b == DEER) { a_score = 50; b_score = 50; }
				else if (a == DEER && b == RABBIT) { a_score = 0; b_score = 20; }
				else if (a == DEER && b == SNAKE) { a_score = 0; b_score = 10; }
				else if (a == RABBIT && b == DEER) { a_score = 20; b_score = 0; }
				else if (a == RABBIT && b == RABBIT) { a_score = 20; b_score = 20; }
				else if (a == RABBIT && b == SNAKE) { a_score = 0; b_score = 30; }
				else if (a == SNAKE && b == DEER) { a_score = 10; b_score = 0; }
				else if (a == SNAKE && b == RABBIT) { a_score = 30; b_score = 0; }
				else if (a == SNAKE && b == SNAKE) { a_score = 10; b_score = 10; }

				a_score -= team_a_count;
				b_score -= team_b_count;

				a_bonus = rand() % 3;
				b_bonus = rand() % 3;
				a_score += a_bonus;
				b_score += b_bonus;

				a_game_score += a_score;
				b_game_score += b_score;

				printf("Turn [%d] [%s:(%s)] vs [%s:(%s)] ---> score [%d] / [%d] \n",
					k + 1, names[team_a], a ? (a == 2 ? "SNAKE" : "RABBIT") : "DEER",
					names[team_b], b ? (b == 2 ? "SNAKE" : "RABBIT") : "DEER", a_game_score, b_game_score);

			}

			for (int z = 0; z < 10; z++) {
				last_pattern[team_a][pattern_count[team_a]][z] = a_pattern[z];
			}
			for (int z = 0; z < 10; z++) {
				last_pattern[team_b][pattern_count[team_b]][z] = b_pattern[z];
			}

			pattern_count[team_a]++;
			pattern_count[team_b]++;

			total_score[team_a] += a_game_score;
			total_score[team_b] += b_game_score;

			printf("<Game Result>\n");
			if (a_game_score == b_game_score) printf("Draw\n");
			else printf("Win: [%4s]!\n", a_game_score > b_game_score ? names[team_a] : names[team_b]);
			printf("\n");
		}
	}

	printf("<Final score>\n");

	int max_inx = 0;
	int max_score = 0;

	for (int i = 0; i < f_inx; i++) {

		printf("[%4s] Total Score: %d\n", names[i], total_score[i]);

		if (max_score < total_score[i]) {
			max_inx = i;
			max_score = total_score[i];
		}
	}

	printf("<Winner:[%4s]!!!>\n", names[max_inx]);
	printf("%d\n", max_score);

	return 0;

}