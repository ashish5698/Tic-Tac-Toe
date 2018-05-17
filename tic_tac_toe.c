#include <stdio.h>
#include "rlutil.h"//downloaded header file for colors,etc
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define space "\t\t\t"

char square[10]= {'0','1','2','3','4','5','6','7','8','9'};
void rules();
int checkwin();
void board();
void animation();
void choice();
void game(char *player1,char *player2);
void details();

void menu()//main menu
{
    char a = 219;
    int i, j;
    char str[7][50] 
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,a,a,a,a,a,0,0,a,0,0,a,a,a,a,0,0,a,a,a,a,a,0,0,a,a,a,a,0,0,a,a,a,a},
        {0,0,0,a,0,0,0,0,a,0,0,a,0,0,0,0,0,0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0},
        {0,0,0,a,0,0,0,0,a,0,0,a,0,0,0,a,a,0,0,a,0,0,0,0,a,a,a,a,0,0,a,0,0,0},
        {0,0,0,a,0,0,0,0,a,0,0,a,0,0,0,0,0,0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0},
        {0,0,0,a,0,0,0,0,a,0,0,a,a,a,a,0,0,0,0,a,0,0,0,0,a,0,0,a,0,0,a,a,a,a},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    char str2[5][20] =
    {
        {a,a,a,a,a,0,0,a,a,a,a,0,0,a,a,a,a,a},
        {0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0,0},
        {0,0,a,0,0,0,0,a,0,0,a,0,0,a,a,a,a,0},
        {0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0,0},
        {0,0,a,0,0,0,0,a,a,a,a,0,0,a,a,a,a,a},
    };//These above two 2d Arrays are for creating the logo
    while(1)
    {
        system("cls");
        setColor(BLUE);
        for(i = 0; i < 7; i++)
        {
            printf(space "\t\t");
            for(j = 0; j < 34; j++)
            {
                printf("%c",str[i][j]);
            }
            printf("\n");
        }
        for(i = 0; i < 5; i++)
        {
            printf(space "\t\t\t");
            for(j = 0; j < 18; j++)
            {
                printf("%c",str2[i][j]);
            }
            printf("\n");
        }
        printf("\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n");
        printf(space"1---->Start Game\n\n");
        printf(space"2---->Rules\n\n");
        printf(space"3---->Exit");
        printf("\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        char ch;
        int count;
        printf(space"enter your choice: ");
        ch = _getch();
        if(ch == '1')
        {
            count = 49;
            for(i = 1; i < 10; i++)
            {
                square[i] = count;
                count++;
            }
            details();
        }
        else if(ch == '2')
        {
            rules();
            menu();
        }
        else if(ch == '3')
        {
            exit(0);
        }
        else
        {
         printf("\n"space"Invalid choice");
         Sleep(150);
        }
    }
}

void details()//input players details
{
    system("cls");
    int i, j;
    char *player1 = (char*)malloc(sizeof(char)*20);
    char *player2 = (char*)malloc(sizeof(char)*20);
    printf("\n\n\n\n\n\n\n"space space"Enter your names");
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n");
    printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n"space"\t\t Player1 : %c            %c\n",179,179);
    printf(space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy(53,14);
    scanf("%s",player1);
    printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n"space"\t\t Player2 : %c            %c\n",179,179);
    printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy(53,17);
    scanf("%s",player2);
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    Sleep(1000);
    game(player1,player2);
}

void game(char *player1, char *player2)//Start game
{
    system("cls");
    int i, j, choice, chance = 1;
    char player[20];
    char mark;
    char a = 219;
    char welc[5][50] =
    {
        {a,0,0,0,a,0,0,a,a,a,a,0,0,a,0,0,a,a,a,a,0,0,a,a,a,a,0,0,a,0,0,0,a,0,0,a,a,a,a},
        {a,0,0,0,a,0,0,a,0,0,0,0,0,a,0,0,a,0,0,0,0,0,a,0,0,a,0,0,a,a,0,a,a,0,0,a,0,0,0},
        {a,0,a,0,a,0,0,a,a,a,0,0,0,a,0,0,a,0,0,0,0,0,a,0,0,a,0,0,a,0,a,0,a,0,0,a,a,a,0},
        {a,a,0,a,a,0,0,a,0,0,0,0,0,a,0,0,a,0,0,0,0,0,a,0,0,a,0,0,a,0,0,0,a,0,0,a,0,0,0},
        {a,0,0,0,a,0,0,a,a,a,a,0,0,a,0,0,a,a,a,a,0,0,a,a,a,a,0,0,a,0,0,0,a,0,0,a,a,a,a},
    };//this 2d array id for welcome logo
    for(i = 0; i < 10; i++)
    {
        printf("\n");
    }
    setColor(BLUE);
    for(i = 0; i < 5; i++)
    {
        printf(space "\t\t");
        for(j = 0; j < 39; j++)
        {
            printf("%c",welc[i][j]);
        }
        printf("\n");
    }
    Sleep(1000);
    setColor(BLACK);
    do
    {
        system("cls");
        printf("\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n\n");
        board();
        chance = chance % 2 ? 1 : 2;//changing the chance between 1 and 2 alternatively
        if(chance == 1)
        {
            strcpy(player,player1);
        }
        else
            strcpy(player,player2);
        printf("\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n");
        printf(space"enter your number %s: ", player);
        scanf("%d", &choice);
        mark = (chance == 1)? 'X' :'O';
        if(choice == 1 && square[1] == '1')
            square[1] = mark;
        else if(choice == 2 && square[2] == '2')
            square[2] = mark;
        else if(choice == 3 && square[3] == '3')
            square[3] = mark;
        else if(choice == 4 && square[4] == '4')
            square[4] = mark;
        else if(choice == 5 && square[5] == '5')
            square[5] = mark;
        else if(choice == 6 && square[6] == '6')
            square[6] = mark;
        else if(choice ==7 && square[7] == '7')
            square[7] = mark;
        else if(choice == 8 && square[8] == '8')
            square[8] = mark;
        else if(choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            printf(space"Invalid entry");
            Sleep(200);
            fflush(stdin);
            chance--;
        }
        i = checkwin();
        chance++;
    }
    while(i == -1);
    system("cls");
    for(j = 0; j < 10; j++)
    {
        printf("\n");
    }
    board();
    if(i == 1)
    {
        system("cls");
        int trigger = 0;
        if(strcmp(player,player1) == 0)
        {
            trigger = 1;
        }
        else
            trigger = 2;
        char anm1[5][50] =
        {
            {a,a,0,0,0,a,0,0,a,a,a,a,0,0,a,0,0,0,a,0,0,a,a,a,a,0,0,a,a,0,0},
            {a,0,a,0,0,a,0,0,a,0,0,a,0,0,0,a,0,a,0,0,0,a,0,0,0,0,0,a,0,a,0},
            {a,a,0,0,0,a,0,0,a,a,a,a,0,0,0,0,a,0,0,0,0,a,a,a,0,0,0,a,a,0,0},
            {a,0,0,0,0,a,0,0,a,0,0,a,0,0,0,0,a,0,0,0,0,a,0,0,0,0,0,a,a,0,0},
            {a,0,0,0,0,a,0,0,a,0,0,a,0,0,0,0,a,0,0,0,0,a,a,a,a,0,0,a,0,a,0},
        };//For 'Player' logo
        char anm2[6][30] =
        {
            {a,0,0,0,a,0,0,a,0,0,a,0,0,0,a,0,0,0,a,a,0},
            {a,0,0,0,a,0,0,a,0,0,a,a,0,0,a,0,0,a,0,0,a},
            {a,0,0,0,a,0,0,a,0,0,a,a,a,0,a,0,0,0,a,0,0},
            {a,0,a,0,a,0,0,a,0,0,a,0,a,a,a,0,0,0,0,a,0},
            {a,a,0,a,a,0,0,a,0,0,a,0,0,a,a,0,0,a,0,0,a},
            {a,0,0,0,a,0,0,a,0,0,a,0,0,0,a,0,0,0,a,a,0}
        };//For 'Wins'Logo
        char one[7][4] =
        {
            {0,a,0},
            {a,a,0},
            {0,a,0},
            {0,a,0},
            {a,a,a},
        };//If First player wins then this blove 2d array is used to print '1'
        char two[5][4] =
        {
            {0,a,a,0},
            {a,0,0,a},
            {0,0,a,0},
            {0,a,0,0},
            {a,a,a,a},
        };//If second player wins then this blove 2d array is used to print '2'
        setColor(RED);
        for(i = 0; i < 10; i++)
        {
            printf("\n");
        }
        for(i = 0; i < 5; i++)
        {
            printf(space );
            for(j = 0; j < 31; j++)
            {
                printf("%c",anm1[i][j]);
            }
            printf("\n");
        }
        setColor(GREEN);
        switch(trigger)
        {
        case 1:
            printf("\n");
            for(i = 0; i < 5; i++)
            {
                printf(space "\t\t\t\t");
                for(j = 0; j < 3; j++)
                {
                    printf("%c",one[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            printf("\n");
            for(i = 0; i < 5; i++)
            {
                printf(space "\t\t\t\t");
                for(j = 0; j < 4; j++)
                {
                    printf("%c",two[i][j]);
                }
                printf("\n");
            }
            break;
        }
        printf("\n");
        setColor(BLUE);
        for(i = 0; i < 6; i++)
        {
            printf(space "\t\t\t\t\t");
            for(j = 0; j < 21; j++)
            {
                printf("%c",anm2[i][j]);
            }
            printf("\n");
        }
        setColor(BLACK);
        _getch();
    }
    else
    {
        char draw[5][50] =
        {
            {a,a,0,0,0,a,a,a,0,0,0,a,a,a,a,0,0,a,0,0,0,a},
            {a,0,a,0,0,a,0,0,a,0,0,a,0,0,a,0,0,a,0,0,0,a},
            {a,0,a,0,0,a,a,a,0,0,0,a,a,a,a,0,0,a,0,a,0,a},
            {a,0,a,0,0,a,0,a,0,0,0,a,0,0,a,0,0,a,a,0,a,a},
            {a,a,0,0,0,a,0,0,a,0,0,a,0,0,a,0,0,a,0,0,0,a},
        };//If no one wins then this 2d array is used to print 'Draw'
        system("cls");
        for(i = 0; i < 10; i++)
        {
            printf("\n");
        }
        setColor(RED);
        for(i = 0; i < 5; i++)
        {
            printf(space "\t\t");
            for(j = 0; j < 22; j++)
            {
                printf("%c",draw[i][j]);
            }
            printf("\n");
        }
        _getch();
        setColor(BLACK);
    }
}
int checkwin()//check if there is a three row combination or column or diagonal combinations
{
   if(square[1]==square[2] && square[2]==square[3])
        return 1;
   else if(square[4]==square[5] && square[5]==square[6])
        return 1;
   else if(square[7]==square[8] && square[8]==square[9])
        return 1;
   else if(square[1]==square[5] && square[5]==square[9])
        return 1;
   else if(square[3]==square[5] && square[5]==square[7])
        return 1;
   else if(square[1]==square[4] && square[4]==square[7])
        return 1;
   else if(square[2]==square[5] && square[5]==square[8])
        return 1;
   else if(square[3]==square[6] && square[6]==square[9])
        return 1;
   else if(square[1]!= '1' && square[2]!= '2'&&square[3]!='3'&&square[4]!='4'&&square[5]!='5'&&square[6]!='6'&&square[7]!='7'&&square[8]!='8'&&square[9]!='9')
         return 0;
    else
        return -1;
}

void board()//board structure
{
    char a = 219, b = 220;
    printf("\t\t\t"space"    %c   %c   \n", a, a);
    printf("\t\t\t"space"  %c %c %c %c %c\n", square[1], a, square[2], a, square[3]);
    printf("\t\t\t"space" %c%c%c%c%c%c%c%c%c%c%c\n", b, b, b, a, b, b, b, a, b, b, b);
    printf("\t\t\t"space"    %c   %c   \n", a, a);
    printf("\t\t\t"space"  %c %c %c %c %c\n", square[4], a, square[5], a, square[6]);
    printf("\t\t\t"space" %c%c%c%c%c%c%c%c%c%c%c\n", b, b, b, a, b, b, b, a, b, b, b);
    printf("\t\t\t"space"    %c   %c   \n", a, a);
    printf("\t\t\t"space"  %c %c %c %c %c\n", square[7], a, square[8], a, square[9]);
    printf("\t\t\t"space"    %c   %c   \n", a, a);
}



void animation()//starting page
{
    char a = 219;
    char str[7][50] =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,a,a,a,a,a,0,0,a,0,0,a,a,a,a,0,0,a,a,a,a,a,0,0,a,a,a,a,0,0,a,a,a,a},
        {0,0,0,a,0,0,0,0,a,0,0,a,0,0,0,0,0,0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0},
        {0,0,0,a,0,0,0,0,a,0,0,a,0,0,0,a,a,0,0,a,0,0,0,0,a,a,a,a,0,0,a,0,0,0},
        {0,0,0,a,0,0,0,0,a,0,0,a,0,0,0,0,0,0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0},
        {0,0,0,a,0,0,0,0,a,0,0,a,a,a,a,0,0,0,0,a,0,0,0,0,a,0,0,a,0,0,a,a,a,a},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    char str2[5][20] =
    {
        {a,a,a,a,a,0,0,a,a,a,a,0,0,a,a,a,a,a},
        {0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0,0},
        {0,0,a,0,0,0,0,a,0,0,a,0,0,a,a,a,a,0},
        {0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0,0},
        {0,0,a,0,0,0,0,a,a,a,a,0,0,a,a,a,a,a},
    };//The above 2d arrays are used for printing 'TIC-TAC-TOE'
    int i, j, k = 0, count = 0;
    while(k != 15)
    {
        choice(k);
        k++;
        system("cls");
        for(i = 0; i < 10; i++)
        {
            printf("\n");
        }
        for(i = 0; i < 7; i++)
        {
            printf(space "\t\t");
            for(j = 0; j < 34; j++)
            {
                printf("%c",str[i][j]);
            }
            printf("\n");
        }
        for(i = 0; i < 5; i++)
        {
            printf(space "\t\t\t");
            for(j = 0; j < 18; j++)
            {
                printf("%c",str2[i][j]);
            }
            printf("\n");
        }
        setColor(BLACK);
        printf("\n"space"\tLoading...");
        for(i = 0; i < count; i++)
        {
            printf("%c%c", 177, 177);
        }
        count++;
        Sleep(200);
    }

}

void choice(int ch)//color choice for startup animation
{
    if(ch == 1)
        setColor(BLUE);
    if(ch == 2)
        setColor(GREEN);
    if(ch == 3)
        setColor(CYAN);
    if(ch == 4)
        setColor(MAGENTA);
    if(ch == 5)
        setColor(RED);
    if(ch == 6)
        setColor(YELLOW);
    if(ch == 7)
        setColor(BROWN);
    if(ch == 8)
        setColor(DARKGREY);
    if(ch == 9)
        setColor(LIGHTBLUE);
    if(ch == 10)
        setColor(LIGHTGREEN);
    if(ch == 11)
        setColor(LIGHTCYAN);
    if(ch == 12)
        setColor(LIGHTRED);
    if(ch == 13)
        setColor(LIGHTMAGENTA);
    if(ch == 14)
        setColor(BLUE);
}

void rules()
{
    system("cls");
    char a = 219;
    int i, j;
    char str[7][50] =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,a,a,a,a,a,0,0,a,0,0,a,a,a,a,0,0,a,a,a,a,a,0,0,a,a,a,a,0,0,a,a,a,a},
        {0,0,0,a,0,0,0,0,a,0,0,a,0,0,0,0,0,0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0},
        {0,0,0,a,0,0,0,0,a,0,0,a,0,0,0,a,a,0,0,a,0,0,0,0,a,a,a,a,0,0,a,0,0,0},
        {0,0,0,a,0,0,0,0,a,0,0,a,0,0,0,0,0,0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0},
        {0,0,0,a,0,0,0,0,a,0,0,a,a,a,a,0,0,0,0,a,0,0,0,0,a,0,0,a,0,0,a,a,a,a},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    char str2[5][20] =
    {
        {a,a,a,a,a,0,0,a,a,a,a,0,0,a,a,a,a,a},
        {0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0,0},
        {0,0,a,0,0,0,0,a,0,0,a,0,0,a,a,a,a,0},
        {0,0,a,0,0,0,0,a,0,0,a,0,0,a,0,0,0,0},
        {0,0,a,0,0,0,0,a,a,a,a,0,0,a,a,a,a,a},
    };//the above 2d arrays are used to print 'TIC-TAC-T0E' in rules page
    setColor(BLUE);
    printf("\n");
    for(i = 0; i < 7; i++)
    {
        printf(space "\t\t");
        for(j = 0; j < 34; j++)
        {
            printf("%c",str[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < 5; i++)
    {
        printf(space "\t\t\t");
        for(j = 0; j < 18; j++)
        {
            printf("%c",str2[i][j]);
        }
        printf("\n");
    }
    setColor(BLACK);
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n\n"space"1) The Object of Tic-Tac-Toe is to get three in a row.\n\n");
    printf(space"2) You play on a three by three game board.\n\n");
    printf(space"3) The first player is known as X and the second player is known as O.\n\n");
    printf(space"4) Players are given chance alternately to place X's and O's.\n\n");
    printf(space"5) You need to play until you get three in a row or all squares are filled\n\n");
    printf(space"6) X always goes First followed by O.\n\n");
    printf(space"7) If in the event that no one has three in a row then it is Draw.\n");
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    _getch();
}

int main()
{
    system("color 76");
    animation();
    system("cls");
    menu();
    return(0);
}
