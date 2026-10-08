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
int main() {
    int Kluch;
    int xDonkey;
	int yDonkey;
    int xPlayer;
    int WaitProbel;
    int score;
    int globalscore;
	int high;
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
    printf("|/ \\_/ | | | \\ |-   |    | | \\_/ |\\ |\\  \\_/ |\\ alfa v4.0 \n");
    printf("Dlya Uvorota Ot Osla, ispolzuite PROBEL\n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf("Naberite kluch: ");
    scanf("%d", &Kluch);
    srand(Kluch);
    xPlayer = rand()%2;
    while(1) {
GAME:
    if(yDonkey == 5) {
		++score;
		Beep(600, 100);
        Beep(900, 150);
        if (globalscore < score) { ++globalscore; }
	}
    system("cls");
    printf("                         Score: %d\n", score);
    printf("                   GlobalScore: %d\n", globalscore);
	if (yDonkey == 0) {
        xDonkey = rand()%2;
	}
    printf("%s", yDonkeyPlace[yDonkey]);
	printf("%s", xDonkeyPlace[xDonkey]);
	printf("%s", yDonkeyPlace[high - yDonkey]);
	printf("%s", PlayerPlace[xPlayer]);
	if ((yDonkey == 5) && (xDonkey == xPlayer)) {
        score = 0;
		system("cls");
		Beep(2000, 150);
		system("cls");
        Beep(1000, 100); 
		system("cls");
        Beep(1800, 150); 
		system("cls");
        Beep(400, 300);
		system("cls");
        Beep(150, 600);
        system("cls");
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
				  goto GAME; }
              if (choice == 'n') { goto END; }
                          }
             }
    }
	if (yDonkey == 5) {
		system("cls");
		printf("\n\n(   |   )\n(   |   )\n(   |   )\n(   |   )\n(   |   )\n");
		printf("%s", Donkey_Player[xDonkey]);
		Sleep(30);
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
        Sleep(13);
    }
    }
END:
return(0);
}


