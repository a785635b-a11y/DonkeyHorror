#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int osel(void) {
	printf("   (..)   (..)\n");
    printf("    ||     ||\n");
    printf("  .-''-----''-.\n");
    printf(" /  *       *  \\\n");
    printf("\n");
    printf("|       _       |\n");
    printf(" \\   (  _  )   /\n");
    printf("  '--._____.--'\n");
    printf("    ( O O O )\n");
	return(0);
    }
int clear(void) { // Единственное что я здесь из нейросети копировал именно с нуля. Ибо без этого обычный system(cls); будет и так лагать.
	 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO c;
    COORD start;
    DWORD written;
    DWORD cells;
    start.X = 0;
    start.Y = 0;
    GetConsoleScreenBufferInfo(h, &c);
    cells = c.dwSize.X * c.dwSize.Y;
    FillConsoleOutputCharacter(h, ' ', cells, start, &written);
    SetConsoleCursorPosition(h, start);
    return 0;
}		
int main() {
    int Kluch;
    int xDonkey;
	int yDonkey;
    int xPlayer;
    int WaitProbel;
    int score;
    int globalscore;
	int high;
	int speeDonkey;
	int speeStart;
	char xDonkeyPlace[2][15] = {
		"(#M#|   )\n",
		"(   |#M#)\n"
	};
	char yDonkeyPlace[6][50] = {
		"",
		"(   |   )\n",
		"(   |   )\n(   |   )\n",
		"(   |   )\n(   |   )\n(   |   )\n",
		"(   |   )\n(   |   )\n(   |   )\n(   |   )\n",
	};
	char PlayerPlace[2][15] = {
		"( ^ |   )\n",
		"(   | ^ )\n"
	};
	char Donkey_Player[2][15] = {
		"(#M#| ^ )\n",
		"( ^ |#M#)\n"
	};
	WaitProbel = 0;
    score = 0;
    globalscore = 0;
	yDonkey = 0;
	high = 4;
    osel();
    printf(" \n");
    printf("|\\ /-\\ | | | / |- \\   /  | | /-\\ |) |)  /-\\ |) \n");
    printf("|| | | |\\| |<  |-  \\_/   |-| | | |/ |)  | | |) \n");
    printf("|/ \\_/ | | | \\ |-   |    | | \\_/ |\\ |\\  \\_/ |\\ beta v1.0 \n");
    printf("Dlya Uvorota Ot Osla, ispolzuite PROBEL\n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf("Naberite kluch: ");
    scanf("%d", &Kluch);
    srand(Kluch);
    xPlayer = rand()%2;
	speeDonkey = 13 + rand()%9;
	speeStart = speeDonkey;
    while(1) {
GAME:
    if(yDonkey == 5) {
		++score;
		clear();
		if (globalscore < score) { ++globalscore; }
		printf("                         Score: %d\n", score);
        printf("                   GlobalScore: %d\n", globalscore);
		printf("                         Kluch: %d\n", Kluch);
		printf("                 DonkeyLagging: %d\n", speeDonkey);
		printf("%s", yDonkeyPlace[4]);
		printf("%s", yDonkeyPlace[1]);
	    printf("%s", Donkey_Player[xDonkey]);
		Beep(600, 100);
        Beep(900, 150);
	}
    clear();
    printf("                         Score: %d\n", score);
    printf("                   GlobalScore: %d\n", globalscore);
	printf("                         Kluch: %d\n", Kluch);
	printf("                 DonkeyLagging: %d\n", speeDonkey);
	if (yDonkey == 0) {
        xDonkey = rand()%2;
	}
    printf("%s", yDonkeyPlace[yDonkey]);
	printf("%s", xDonkeyPlace[xDonkey]);
	printf("%s", yDonkeyPlace[high - yDonkey]);
	printf("%s", PlayerPlace[xPlayer]);
	if ((yDonkey == 5) && (xDonkey == xPlayer)) {
        score = 0;
		clear();
		Beep(2000, 150);
		clear();
        Beep(1000, 100); 
		clear();
        Beep(1800, 150); 
		clear();
        Beep(400, 300);
		clear();
        Beep(150, 600);
        clear();
        printf("TI PROIGRAL!!! OSEL VAS SOZHRAL!!!\n");
        printf(" \n");
        osel();
        Sleep(1400);
        printf(" \n");
        printf("Esli xotite Prodolzhit Nazhmite Y, esli net, Nazhmite N.\n");
        while(1) {
            if (_kbhit()) {
                char choice = _getch();
              if (choice == 'y') {
				  yDonkey = 0;
				  speeDonkey = speeStart;
				  goto GAME; }
              if (choice == 'n') { goto END; }
                          }
             }
    }
	if (yDonkey == 5) {
		if (speeDonkey > 2){
		speeDonkey = speeDonkey - rand()%3;
	    }
		clear();
		yDonkey = 0;
	    goto GAME;
	} else {
		++yDonkey;
	}
    for(WaitProbel = 0; WaitProbel<10; ++WaitProbel) { 
        if (_kbhit()) { 
            char probel = _getch(); 
              if (probel == ' ' && xPlayer == 0) {
                xPlayer = 1;
            } else if (probel == ' ' && xPlayer == 1) { 
            xPlayer = 0;
            }
        }
		    Sleep(speeDonkey);
		}
	}
END:
return(0);
}
