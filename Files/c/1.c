#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int main() {
    int x;
    int xDonkey;
    int yDonkey;
    int PlayerPosition;
    int Vihod_iz_igri;
    int Probel;
    int i;
    int score;
    int scorenew;
    int globalscore;
    i = 0;
    score = 0;
    scorenew = 0;
    globalscore = 0;
    printf("   (..)   (..)\n");
    printf("    ||     ||\n");
    printf("  .-''-----''-.\n");
    printf(" /  *       *  \\\n");
    printf("\n");
    printf("|       _       |\n");
    printf(" \\   (  _  )   /\n");
    printf("  '--._____.--'\n");
    printf("    ( O O O )\n");
    printf(" \n");
    printf("|\\ /-\\ | | | / |- \\   /  | | /-\\ |) |)  /-\\ |) \n");
    printf("|| | | |\\| |<  |-  \\_/   |-| | | |/ |)  | | |) \n");
    printf("|/ \\_/ | | | \\ |-   |    | | \\_/ |\\ |\\  \\_/ |\\ alfa v3.1 \n");

    printf("Dlya Uvorota Ot Osla, ispolzuite PROBEL\n");
    printf(" \n");
    printf(" \n");
    printf(" \n");
    printf("Naberite kluch: ");
    scanf("%d", &x);
    srand(x);
    PlayerPosition = rand()%2;
    while(1) {
GAME:
    scorenew = ++score;
    if (globalscore < scorenew) { ++globalscore; }
    system("cls");
    printf("                         Score: %d\n", score);
    printf("                   GlobalScore: %d", globalscore);
    xDonkey = rand()%2;
    if (xDonkey == 0 && PlayerPosition == 0) {
        printf("\n(#M#|   )\n");
        printf("(# #|   )\n");
        printf("(   |   )\n");
        printf("(   |   )\n");
        printf("(   |   )\n");        
        printf("(   |   )\n");
        printf("(   |   )\n");
        printf("( ^ |   )\n");
        Beep(600, 100);
        Beep(900, 150);
    } else if (xDonkey == 1 && PlayerPosition == 1) {
        printf("\n(   |#M#)\n");
        printf("(   |# #)\n");
        printf("(   |   )\n");
        printf("(   |   )\n");
        printf("(   |   )\n");        
        printf("(   |   )\n");
        printf("(   |   )\n");
        printf("(   | ^ )\n");
        Beep(600, 100);
        Beep(900, 150);
    } else if (xDonkey == 0 && PlayerPosition == 1) {
        printf("\n(#M#|   )\n");
        printf("(# #|   )\n");
        printf("(   |   )\n");
        printf("(   |   )\n");
        printf("(   |   )\n");        
        printf("(   |   )\n");
        printf("(   |   )\n");
        printf("(   | ^ )\n");
        Beep(600, 100);
        Beep(900, 150);
    } else if (xDonkey == 1 && PlayerPosition == 0) { 
        printf("\n(   |#M#)\n");
        printf("(   |# #)\n");
        printf("(   |   )\n");
        printf("(   |   )\n");
        printf("(   |   )\n");        
        printf("(   |   )\n");
        printf("(   |   )\n");
        printf("( ^ |   )\n");
        Beep(600, 100);
        Beep(900, 150); 
    }
    for(i = 0; i<10; ++i) { 
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
        printf("   (..)   (..)\n");
        printf("    ||     ||\n");
        printf("  .-''-----''-.\n");
        printf(" /  *       *  \\\n");
        printf("\n");
        printf("|       _       |\n");
        printf(" \\   (  _  )   /\n");
        printf("  '--._____.--'\n");
        printf("    ( O O O )\n");
        Beep(2000, 150);
        Beep(1000, 100); 
        Beep(1800, 150); 
        Beep(400, 300);
        Beep(150, 600);
        Sleep(1500);
        printf(" \n");
        printf("Esli xotite Prodolzhit Nazhmite Y, esli net, Nazhmite N.\n");
        while(1) { // aaaa wot shto propustil
            if (_kbhit()) {
                char choice = _getch();
              if (choice == 'y') { goto GAME; } // vozrashaet k igre
              if (choice == 'n') { goto END; } // Vikluchaet igru
                          } // closed while s klavoi
        
             }//zakritie if s porazheniem

          }
     
    } // First while
END:
return(0);
} // int main //chitaite readme i probyte vse versii isxodniki starix versi udaleni potome sto kazhdi raz nastraivat kompilator pod novoe ima faila v directorii


