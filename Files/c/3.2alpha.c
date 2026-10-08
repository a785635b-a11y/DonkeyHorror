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
	int road(void) {
	printf("(   |   )\n");
    printf("(   |   )\n");
    printf("(   |   )\n");
    printf("(   |   )\n");        
    printf("(   |   )\n");
    printf("(   |   )\n");
	return(0);
    }
int main() {
    int Kluch;
    int xDonkey;
    int PlayerPosition;
    int WaitProbel;
    int score;
    int globalscore;
	char DonkeyPlace[2][15] = {
		"\n(#M#|   )\n",
		"\n(   |#M#)\n"
	};
	char PlayerPlace[2][15] = {
		"( ^ |   )\n",
		"(   | ^ )\n"
	};
	WaitProbel = 0;
    score = 0;
    globalscore = 0;
    osel();
    printf(" \n");
    printf("|\\ /-\\ | | | / |- \\   /  | | /-\\ |) |)  /-\\ |) \n");
    printf("|| | | |\\| |<  |-  \\_/   |-| | | |/ |)  | | |) \n");
    printf("|/ \\_/ | | | \\ |-   |    | | \\_/ |\\ |\\  \\_/ |\\ alfa v3.2 \n");
    printf("Dlya Uvorota Ot Osla, ispolzuite PROBEL\n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf("Naberite kluch: ");
    scanf("%d", &Kluch);
    srand(Kluch);
    PlayerPosition = rand()%2;
    while(1) {
GAME:
    ++score;
    if (globalscore < score) { ++globalscore; }
    system("cls");
    printf("                         Score: %d\n", score);
    printf("                   GlobalScore: %d", globalscore);
    xDonkey = rand()%2;
    if (xDonkey == 0 && PlayerPosition == 0) {
        printf("%s", DonkeyPlace[0]);
		road();
        printf("%s", PlayerPlace[0]);
        Beep(600, 100);
        Beep(900, 150);
    } else if (xDonkey == 1 && PlayerPosition == 1) {
        printf("%s", DonkeyPlace[1]);
        road();
        printf("%s", PlayerPlace[1]);
        Beep(600, 100);
        Beep(900, 150);
    } else if (xDonkey == 0 && PlayerPosition == 1) {
        printf("%s", DonkeyPlace[0]);
		road();
        printf("%s", PlayerPlace[1]);
        Beep(600, 100);
        Beep(900, 150);
    } else if (xDonkey == 1 && PlayerPosition == 0) { 
        printf("%s", DonkeyPlace[1]);
		road();
        printf("%s", PlayerPlace[0]);
        Beep(600, 100);
        Beep(900, 150); 
    }
    for(WaitProbel = 0; WaitProbel<10; ++WaitProbel) { 
        if (_kbhit()) { 
            char probel = _getch(); 
              if (probel == ' ' && PlayerPosition == 0) {
                PlayerPosition = 1;
            } else if (probel == ' ' && PlayerPosition == 1) { 
            PlayerPosition = 0;
            }
        }
        Sleep(100);
    }  
    if (xDonkey == PlayerPosition) {
        score = 0;
        system("cls");
        printf("TI PROIGRAL!!! OSEL VAS SOZHRAL!!!\n");
 
        printf(" \n");
        osel();
        Beep(2000, 150);
        Beep(1000, 100); 
        Beep(1800, 150); 
        Beep(400, 300);
        Beep(150, 600);
        Sleep(1500);
        printf(" \n");
        printf("Esli xotite Prodolzhit Nazhmite Y, esli net, Nazhmite N.\n");
        while(1) {
            if (_kbhit()) {
                char choice = _getch();
              if (choice == 'y') { goto GAME; }
              if (choice == 'n') { goto END; }
                          }
        
             }

          }
     
    }
END:
return(0);
}


