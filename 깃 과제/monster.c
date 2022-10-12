#include<stdio.h>
#include<ncurses.h>
#include<locale.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include<time.h>
#include<stdlib.h>
#define N 7

pthread_mutex_t mlock;
pthread_t tid;

char map[N][N+1] = {
    "#######",
    "## a# #",
    "#x    #",
    "##xx  #",
    "#  x ##",
    "# x  Y#",
    "#######",
};
int ny = 1;
int nx = 1;
int hp = 100;
int ok = 0;

void print()
{
    clear();
    for(int y = 0; y<N;y++){
        for(int x = 0; x<N; x++){
            if(y == ny && x == nx)
                printw("⍤");
            else
                printw("%c", map[y][x]);
        }
        printw("\n");
    }
    printw("HP : %d\n", hp);
    refresh();
}
void* moveMonster()
{
//  initscr();
    pthread_mutex_lock(&mlock);
    srand(time(NULL));
	char remember;
    while(1)
    {
		if(ok == 1)
			break;
        int my = rand()%(N-2) +1;
        int mx = rand()%(N-2) +1;
        if(map[my][mx]=='#') continue;
		remember = map[my][mx];
	 	map[my][mx]='M';
        refresh();

		usleep(200*1000);
		map[statey][statex]=remember;
    }

    pthread_mutex_unlock(&mlock);
}

int main()
{
    setlocale(LC_CTYPE, "ko_KR.utf8");
    initscr();
    pthread_mutex_init(&mlock, NULL);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    int flag = 0;
    pthread_create(&tid, NULL, moveMonster, NULL);
    while(1)
    {
        print();
        int ch = getch();
        if(ch == ERR) ch = 0;
        if(ch == KEY_LEFT){
            flag = 0;
            if(map[ny][nx-1]!='#')nx--;
        }
        if(ch == KEY_RIGHT){
            flag = 0;
            if(map[ny][nx+1]!='#')nx++;
        }
        if(ch == KEY_UP){
            flag = 0;
            if(map[ny-1][nx]!='#')ny--;
        }
        if(ch == KEY_DOWN){
            flag = 0;
            if(map[ny+1][nx]!='#')ny++;
        }
        if(map[ny][nx]=='M' || hp == 0)
        {
			print();
			ok = 1;
			usleep(500*1000);
            clear();
            mvprintw(10, 30, "GAME OVER");
            refresh();
            break;
        }
        if(map[ny][nx]=='Y')
        {
			print();
            usleep(500*1000);
            clear();
            mvprintw(10, 30, "WIN (HP : %d)", hp);
            refresh();
            break;
        }
        if(map[ny][nx]=='x'&& !flag)
        {
            hp-=10;
            flag = 1;
        }
        if(map[ny][nx]=='a')
        {
            hp = 100;
            map[ny][nx]=' ';
        }
    }

    pthread_join(tid, NULL);
    sleep(1);
    getch();
    endwin();
    return 0;
}

