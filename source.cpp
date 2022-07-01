#include <iostream>                               //header file for input/output stream
#include <conio.h>                                //header file for input/output functions
#include <windows.h>                              //header file for windows functions
#include <fstream>                                //header file for file input/output stream
#define HEIGHT 23                                 // define height of the game screen on concole
#define WIDTH 60                                  // define width of the game screen on concole
#define key_Left 97                               // define the ascii value of the "a" key
#define key_Right 100                             // define the ascii value of the "d" key
#define key_Space 32                              // define the ascii value of the "space" key
#define key_Escape 27                             // define the ascii value of the "Esc" key
using namespace std;                              // add namespace std
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // handle for colors

int shipX = 20, shipY = 22;                                                                                                                                                                // variables for x,y coodinate of the ship
int fireX = 20, fireY = 21;                                                                                                                                                                // variables for x,y coodinate of the fire
int enemyX[9] = {rand() % 35, rand() % 35, rand() % 35, rand() % 35, rand() % 35, rand() % 35, rand() % 35, rand() % 35, rand() % 35}, enemyY[9] = {2, 0, -2, -4, -7, -10, -13, -16, -19}; // arrays for x,y coodinate of thee enemy positions
int level = 1;                                                                                                                                                                             // variable for count the level of the game
int lives = 3;                                                                                                                                                                             // variable for count the lives of the game
int score = 0;                                                                                                                                                                             // variable for count the score of the game

char wall = 178;                                      // varaible for store the ascii value of the boundary
char bullet = 15;                                     // varaible for store the ascii value of the bullet
char ship = 208;                                      // varaible for store the ascii value of the ship
char enemy[9] = {23, 23, 23, 23, 23, 23, 23, 23, 23}; // array to store the ascii value of each enemy

void inter_Face();          // function to display the main interface of the game
void instruction();         // function to display the instruction of the game
void levelUp();             // function to display the level up screen in the game
void enemyColorChange(int); // function to change the enemy color
void draw1();               // function to draw level 1 of the game
void draw2();               // function to draw level 2 of the game
void draw3();               // function to draw level 3 of the game
void draw4();               // function to draw level 4 of the game
void draw5();               // function to draw level 5 of the game
void fire1();               // function to fire the level 1 action in the level 1 of the game
void fire2();               // function to fire the level 2 action in the level 2 of the game
void fire3();               // function to fire the level 3 action in the level 3 of the game
void fire4();               // function to fire the level 4 action in the level 4 of the game
void fire5();               // function to fire the level 5 action in the level 5 of the game
void moveRight1();          // function to move right in the level 1 of the game
void moveRight2();          // function to move right in the level 2 of the game
void moveRight3();          // function to move right in the level 3 of the game
void moveRight4();          // function to move right in the level 4 of the game
void moveRight5();          // function to move right in the level 5 of the game
void moveLeft1();           // function to move left in the level 1 of the game
void moveLeft2();           // function to move left in the level 2 of the game
void moveLeft3();           // function to move left in the level 3 of the game
void moveLeft4();           // function to move left in the level 4 of the game
void moveLeft5();           // function to move left in the level 5 of the game
void youWin();              // function to display the you win screen at the end of the game
void youLose();             // function to display the you lose screen at the end of the game

int main() // main driver function
{
    ofstream outFile;                                      // it will make a stream with outFile
    outFile.open("highestScore.txt", ios::out | ios::app); // it will open a file highestScore.txt in output or append mode
    char name[20] = {'\0'};                                // this array store the name of the player
    cout << "Enter your name: ";                           // prompt the player to enter your name
    cin.getline(name, 19);                                 // input the name of the player
    for (int i = 0; name[i] != '\0'; i++)                  // it will store the name of the player in highestScore.txt file
        outFile << name[i];
    bool winFlag = false; // varaible for store the bool value true/false of the game win or lose
    char ch;              // varaible to store the value of the input key value
    int countLevelUp = 2; // varaible to count the level up display screen
    inter_Face();         // function display main interface
    instruction();        // function display instruction
    system("cls");        // function for clear screen
    draw1();              // function draw level 1 screen
    while (true)          // infinite loop terminate when player enter "Esc" key
    {
        if (level == 1) // check if level 1 then perform level 1 action for respected key
        {
            if (kbhit)
                ch = getch();
            if (int(ch) == key_Space)
            {
                fire1();
            }
            else if (int(ch) == key_Left)
            {
                moveLeft1();
            }
            else if (int(ch) == key_Right)
            {
                moveRight1();
            }
            else if (int(ch) == key_Escape)
            {
                break;
            }
            system("cls");
            draw1();
            Sleep(50);
            if (score == 20)
                level++;
        }
        else if (level == 2) // check if level 2 then perform level 2 action for respected key
        {
            if (countLevelUp == 2)
            {
                levelUp();
                countLevelUp++;
            }
            if (kbhit)
                ch = getch();
            if (int(ch) == key_Space)
            {
                fire2();
            }
            else if (int(ch) == key_Left)
            {
                moveLeft2();
            }
            else if (int(ch) == key_Right)
            {
                moveRight2();
            }
            else if (int(ch) == key_Escape)
            {
                break;
            }
            system("cls");
            draw2();
            Sleep(50);
            if (score == 40)
                level++;
        }
        else if (level == 3) // check if level 3 then perform level 3 action for respected key
        {
            if (countLevelUp == 3)
            {
                levelUp();
                countLevelUp++;
            }
            if (kbhit)
                ch = getch();
            if (int(ch) == key_Space)
            {
                fire3();
            }
            else if (int(ch) == key_Left)
            {
                moveLeft3();
            }
            else if (int(ch) == key_Right)
            {
                moveRight3();
            }
            else if (int(ch) == key_Escape)
            {
                break;
            }
            system("cls");
            draw3();
            Sleep(50);
            if (score == 60)
                level++;
        }
        else if (level == 4) // check if level 4 then perform level 4 action for respected key
        {
            if (countLevelUp == 4)
            {
                levelUp();
                countLevelUp++;
            }
            if (kbhit)
                ch = getch();
            if (int(ch) == key_Space)
            {
                fire4();
            }
            else if (int(ch) == key_Left)
            {
                moveLeft4();
            }
            else if (int(ch) == key_Right)
            {
                moveRight4();
            }
            else if (int(ch) == key_Escape)
            {
                break;
            }
            system("cls");
            draw4();
            Sleep(50);
            if (score == 80)
                level++;
        }
        else if (level == 5) // check if level 5 then perform level 5 action for respected key
        {
            if (countLevelUp == 5)
            {
                levelUp();
                countLevelUp++;
            }
            if (kbhit)
                ch = getch();
            if (int(ch) == key_Space)
            {
                fire5();
            }
            else if (int(ch) == key_Left)
            {
                moveLeft5();
            }
            else if (int(ch) == key_Right)
            {
                moveRight5();
            }
            else if (int(ch) == key_Escape)
            {
                break;
            }
            system("cls");
            draw5();
            Sleep(50);
            if (score == 100)
            {
                winFlag = true;
                break;
            }
        }
        if (lives == 0) // check if lives are equal to 0 then terminate the loop
            break;
    }
    if (winFlag == true) // if winFlag is true than display you win screen else if display you lose
        youWin();
    else
        youLose();
    outFile << " " << score << "\n"; // it will store the score of the player in the highestScore.txt file
    outFile.close();                 // at this the outFile is closed
    cout << endl;
    system("pause");
    return 0;
}

void inter_Face() // function to display main interface of the gamevoid inter_face()
{
    int count = 2;
    while (count < 8)
    {
        system("cls");
        SetConsoleTextAttribute(hStdOut, count);
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
             << "<< --------------------------------------------------------------- <<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                 S      P     " << char(208) << "       C        E               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|           S      H      O      O      T      E      R         |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                          Loading...                           |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<< --------------------------------------------------------------- <<" << endl
             << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        Sleep(500);
        count++;
    }
}
void instruction() // function to display instruction of the game
{
    int count = 2;
    while (count < 8)
    {
        system("cls");
        SetConsoleTextAttribute(hStdOut, count);
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
             << "<< --------------------------------------------------------------- <<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|       Space shooter is a popular shooting game. In which      |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|      our galaxy is attacked by alien shooters. The aliens     |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|      intend to destroy everything on our planet. Your goal    |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|           is to shoot them all before it is too late.         |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                   Press \"Space\" for shooting                  |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                 Press \"a\" for ship left movement              |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                Press \"d\" for ship right movement              |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                 Press \"Esc\" for exist from game               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                          Loading...                           |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<< --------------------------------------------------------------- <<" << endl
             << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        Sleep(500);
        count++;
    }
}
void levelUp() // function to display level up of the game
{
    int count = 2;
    while (count < 8)
    {
        system("cls");
        SetConsoleTextAttribute(hStdOut, count);
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
             << "<< --------------------------------------------------------------- <<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                 L      E      V      E        L               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                            U      P                           |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<< --------------------------------------------------------------- <<" << endl
             << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        Sleep(500);
        count++;
    }
}
void enemyColorChange(int i) // function display enemy color change
{
    SetConsoleTextAttribute(hStdOut, (i + 3));
    cout << enemy[i];
    SetConsoleTextAttribute(hStdOut, 7);
}
void draw1() // function display the level 1 on screen
{
    for (int i = 1; i <= HEIGHT; i++)
    {
        for (int j = 1; j <= WIDTH; j++)
        {
            if (i == 1)
                cout << wall;
            else if (i == enemyY[0] && j == enemyX[0])
                enemyColorChange(0);
            else if (i == enemyY[1] && j == enemyX[1])
                enemyColorChange(1);
            else if (i == enemyY[2] && j == enemyX[2])
                enemyColorChange(2);
            else if (j == 1)
                cout << wall;
            else if (i == 4 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     S ";
                else if (j == 47)
                    cout << "P ";
                else if (j == 50)
                    cout << ship << " ";
                else if (j == 53)
                    cout << "C ";
                else if (j == 56)
                    cout << "E     " << wall;
            }
            else if (i == 6 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "   S ";
                else if (j == 47)
                    cout << "H ";
                else if (j == 50)
                    cout << "O ";
                else if (j == 53)
                    cout << "O ";
                else if (j == 56)
                    cout << "T E R   " << wall;
            }
            else if (i == 9 && j > WIDTH - 20)
                cout << wall;
            else if (i == 12 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "      L";
                else if (j == 47)
                    cout << "e";
                else if (j == 50)
                    cout << "v";
                else if (j == 53)
                    cout << "e";
                else if (j == 56)
                    cout << "l  " << level << "     " << wall;
            }
            else if (i == 14 && j > WIDTH - 20)
                cout << wall;
            else if (i == 17 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     S";
                else if (j == 47)
                    cout << "c";
                else if (j == 50)
                    cout << "o";
                else if (j == 53)
                    cout << "r";
                else if (j == 56)
                {
                    if (score < 10)
                        cout << "e = " << score << "     " << wall;
                    else if (score > 9 && score < 99)
                        cout << "e = " << score << "    " << wall;
                    else if (score > 99 && score < 999)
                        cout << "e = " << score << "   " << wall;
                }
            }
            else if (i == 19 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     L";
                else if (j == 47)
                    cout << "i";
                else if (j == 50)
                    cout << "v";
                else if (j == 53)
                    cout << "e";
                else if (j == 56)
                    cout << "s = " << lives << "     " << wall;
            }
            else if (i == shipY && j == shipX)
                cout << ship;
            else if (i == fireY && j == fireX)
                cout << bullet;
            else if (i == HEIGHT)
                cout << wall;
            else if (j == WIDTH - 20)
                cout << wall;
            else if (j == WIDTH)
                cout << wall;
            else
                cout << " ";
        }
        cout << endl;
    }
}
void draw2() // function display the level 2 on screen
{
    for (int i = 1; i <= HEIGHT; i++)
    {
        for (int j = 1; j <= WIDTH; j++)
        {
            if (i == 1)
                cout << wall;
            else if (i == enemyY[0] && j == enemyX[0])
                enemyColorChange(0);
            else if (i == enemyY[1] && j == enemyX[1])
                enemyColorChange(1);
            else if (i == enemyY[2] && j == enemyX[2])
                enemyColorChange(2);
            else if (i == enemyY[3] && j == enemyX[3])
                enemyColorChange(3);
            else if (i == enemyY[4] && j == enemyX[4])
                enemyColorChange(4);
            else if (j == 1)
                cout << wall;
            else if (i == 4 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     S ";
                else if (j == 47)
                    cout << "P ";
                else if (j == 50)
                    cout << ship << " ";
                else if (j == 53)
                    cout << "C ";
                else if (j == 56)
                    cout << "E     " << wall;
            }
            else if (i == 6 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "   S ";
                else if (j == 47)
                    cout << "H ";
                else if (j == 50)
                    cout << "O ";
                else if (j == 53)
                    cout << "O ";
                else if (j == 56)
                    cout << "T E R   " << wall;
            }
            else if (i == 9 && j > WIDTH - 20)
                cout << wall;
            else if (i == 12 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "      L";
                else if (j == 47)
                    cout << "e";
                else if (j == 50)
                    cout << "v";
                else if (j == 53)
                    cout << "e";
                else if (j == 56)
                    cout << "l  " << level << "     " << wall;
            }
            else if (i == 14 && j > WIDTH - 20)
                cout << wall;
            else if (i == 17 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     S";
                else if (j == 47)
                    cout << "c";
                else if (j == 50)
                    cout << "o";
                else if (j == 53)
                    cout << "r";
                else if (j == 56)
                {
                    if (score < 10)
                        cout << "e = " << score << "     " << wall;
                    else if (score > 9 && score < 99)
                        cout << "e = " << score << "    " << wall;
                    else if (score > 99 && score < 999)
                        cout << "e = " << score << "   " << wall;
                }
            }
            else if (i == 19 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     L";
                else if (j == 47)
                    cout << "i";
                else if (j == 50)
                    cout << "v";
                else if (j == 53)
                    cout << "e";
                else if (j == 56)
                    cout << "s = " << lives << "     " << wall;
            }
            else if (i == shipY && j == shipX)
                cout << ship;
            else if (i == fireY && j == fireX)
                cout << bullet;
            else if (i == HEIGHT)
                cout << wall;
            else if (j == WIDTH - 20)
                cout << wall;
            else if (j == WIDTH)
                cout << wall;
            else
                cout << " ";
        }
        cout << endl;
    }
}
void draw3() // function display the level 3 on screen
{
    for (int i = 1; i <= HEIGHT; i++)
    {
        for (int j = 1; j <= WIDTH; j++)
        {
            if (i == 1)
                cout << wall;
            else if (i == enemyY[0] && j == enemyX[0])
                enemyColorChange(0);
            else if (i == enemyY[1] && j == enemyX[1])
                enemyColorChange(1);
            else if (i == enemyY[2] && j == enemyX[2])
                enemyColorChange(2);
            else if (i == enemyY[3] && j == enemyX[3])
                enemyColorChange(3);
            else if (i == enemyY[4] && j == enemyX[4])
                enemyColorChange(4);
            else if (i == enemyY[5] && j == enemyX[5])
                enemyColorChange(5);
            else if (i == enemyY[6] && j == enemyX[6])
                enemyColorChange(6);
            else if (j == 1)
                cout << wall;
            else if (i == 4 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     S ";
                else if (j == 47)
                    cout << "P ";
                else if (j == 50)
                    cout << ship << " ";
                else if (j == 53)
                    cout << "C ";
                else if (j == 56)
                    cout << "E     " << wall;
            }
            else if (i == 6 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "   S ";
                else if (j == 47)
                    cout << "H ";
                else if (j == 50)
                    cout << "O ";
                else if (j == 53)
                    cout << "O ";
                else if (j == 56)
                    cout << "T E R   " << wall;
            }
            else if (i == 9 && j > WIDTH - 20)
                cout << wall;
            else if (i == 12 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "      L";
                else if (j == 47)
                    cout << "e";
                else if (j == 50)
                    cout << "v";
                else if (j == 53)
                    cout << "e";
                else if (j == 56)
                    cout << "l  " << level << "     " << wall;
            }
            else if (i == 14 && j > WIDTH - 20)
                cout << wall;
            else if (i == 17 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     S";
                else if (j == 47)
                    cout << "c";
                else if (j == 50)
                    cout << "o";
                else if (j == 53)
                    cout << "r";
                else if (j == 56)
                {
                    if (score < 10)
                        cout << "e = " << score << "     " << wall;
                    else if (score > 9 && score < 99)
                        cout << "e = " << score << "    " << wall;
                    else if (score > 99 && score < 999)
                        cout << "e = " << score << "   " << wall;
                }
            }
            else if (i == 19 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     L";
                else if (j == 47)
                    cout << "i";
                else if (j == 50)
                    cout << "v";
                else if (j == 53)
                    cout << "e";
                else if (j == 56)
                    cout << "s = " << lives << "     " << wall;
            }
            else if (i == shipY && j == shipX)
                cout << ship;
            else if (i == fireY && j == fireX)
                cout << bullet;
            else if (i == HEIGHT)
                cout << wall;
            else if (j == WIDTH - 20)
                cout << wall;
            else if (j == WIDTH)
                cout << wall;
            else
                cout << " ";
        }
        cout << endl;
    }
}
void draw4() // function display the level 4 on screen
{
    for (int i = 1; i <= HEIGHT; i++)
    {
        for (int j = 1; j <= WIDTH; j++)
        {
            if (i == 1)
                cout << wall;
            else if (i == enemyY[0] && j == enemyX[0])
                enemyColorChange(0);
            else if (i == enemyY[1] && j == enemyX[1])
                enemyColorChange(1);
            else if (i == enemyY[2] && j == enemyX[2])
                enemyColorChange(2);
            else if (i == enemyY[3] && j == enemyX[3])
                enemyColorChange(3);
            else if (i == enemyY[4] && j == enemyX[4])
                enemyColorChange(4);
            else if (i == enemyY[5] && j == enemyX[5])
                enemyColorChange(5);
            else if (i == enemyY[6] && j == enemyX[6])
                enemyColorChange(6);
            else if (j == 1)
                cout << wall;
            else if (i == 4 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     S ";
                else if (j == 47)
                    cout << "P ";
                else if (j == 50)
                    cout << ship << " ";
                else if (j == 53)
                    cout << "C ";
                else if (j == 56)
                    cout << "E     " << wall;
            }
            else if (i == 6 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "   S ";
                else if (j == 47)
                    cout << "H ";
                else if (j == 50)
                    cout << "O ";
                else if (j == 53)
                    cout << "O ";
                else if (j == 56)
                    cout << "T E R   " << wall;
            }
            else if (i == 9 && j > WIDTH - 20)
                cout << wall;
            else if (i == 12 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "      L";
                else if (j == 47)
                    cout << "e";
                else if (j == 50)
                    cout << "v";
                else if (j == 53)
                    cout << "e";
                else if (j == 56)
                    cout << "l  " << level << "     " << wall;
            }
            else if (i == 14 && j > WIDTH - 20)
                cout << wall;
            else if (i == 17 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     S";
                else if (j == 47)
                    cout << "c";
                else if (j == 50)
                    cout << "o";
                else if (j == 53)
                    cout << "r";
                else if (j == 56)
                {
                    if (score < 10)
                        cout << "e = " << score << "     " << wall;
                    else if (score > 9 && score < 99)
                        cout << "e = " << score << "    " << wall;
                    else if (score > 99 && score < 999)
                        cout << "e = " << score << "   " << wall;
                }
            }
            else if (i == 19 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     L";
                else if (j == 47)
                    cout << "i";
                else if (j == 50)
                    cout << "v";
                else if (j == 53)
                    cout << "e";
                else if (j == 56)
                    cout << "s = " << lives << "     " << wall;
            }
            else if (i == shipY && j == shipX)
                cout << ship;
            else if (i == fireY && j == fireX)
                cout << bullet;
            else if (i == HEIGHT)
                cout << wall;
            else if (j == WIDTH - 20)
                cout << wall;
            else if (j == WIDTH)
                cout << wall;
            else
                cout << " ";
        }
        cout << endl;
    }
}
void draw5() // function display the level 5 on screen
{
    for (int i = 1; i <= HEIGHT; i++)
    {
        for (int j = 1; j <= WIDTH; j++)
        {
            if (i == 1)
                cout << wall;
            else if (i == enemyY[0] && j == enemyX[0])
                enemyColorChange(0);
            else if (i == enemyY[1] && j == enemyX[1])
                enemyColorChange(1);
            else if (i == enemyY[2] && j == enemyX[2])
                enemyColorChange(2);
            else if (i == enemyY[3] && j == enemyX[3])
                enemyColorChange(3);
            else if (i == enemyY[4] && j == enemyX[4])
                enemyColorChange(4);
            else if (i == enemyY[5] && j == enemyX[5])
                enemyColorChange(5);
            else if (i == enemyY[6] && j == enemyX[6])
                enemyColorChange(6);
            else if (i == enemyY[7] && j == enemyX[7])
                enemyColorChange(7);
            else if (i == enemyY[8] && j == enemyX[8])
                enemyColorChange(8);
            else if (j == 1)
                cout << wall;
            else if (i == 4 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     S ";
                else if (j == 47)
                    cout << "P ";
                else if (j == 50)
                    cout << ship << " ";
                else if (j == 53)
                    cout << "C ";
                else if (j == 56)
                    cout << "E     " << wall;
            }
            else if (i == 6 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "   S ";
                else if (j == 47)
                    cout << "H ";
                else if (j == 50)
                    cout << "O ";
                else if (j == 53)
                    cout << "O ";
                else if (j == 56)
                    cout << "T E R   " << wall;
            }
            else if (i == 9 && j > WIDTH - 20)
                cout << wall;
            else if (i == 12 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "      L";
                else if (j == 47)
                    cout << "e";
                else if (j == 50)
                    cout << "v";
                else if (j == 53)
                    cout << "e";
                else if (j == 56)
                    cout << "l  " << level << "     " << wall;
            }
            else if (i == 14 && j > WIDTH - 20)
                cout << wall;
            else if (i == 17 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     S";
                else if (j == 47)
                    cout << "c";
                else if (j == 50)
                    cout << "o";
                else if (j == 53)
                    cout << "r";
                else if (j == 56)
                {
                    if (score < 10)
                        cout << "e = " << score << "     " << wall;
                    else if (score > 9 && score < 99)
                        cout << "e = " << score << "    " << wall;
                    else if (score > 99 && score < 999)
                        cout << "e = " << score << "   " << wall;
                }
            }
            else if (i == 19 && j > WIDTH - 20)
            {
                if (j == 44)
                    cout << "     L";
                else if (j == 47)
                    cout << "i";
                else if (j == 50)
                    cout << "v";
                else if (j == 53)
                    cout << "e";
                else if (j == 56)
                    cout << "s = " << lives << "     " << wall;
            }
            else if (i == shipY && j == shipX)
                cout << ship;
            else if (i == fireY && j == fireX)
                cout << bullet;
            else if (i == HEIGHT)
                cout << wall;
            else if (j == WIDTH - 20)
                cout << wall;
            else if (j == WIDTH)
                cout << wall;
            else
                cout << " ";
        }
        cout << endl;
    }
}
void fire1() // function to perform action of fire in the level 1 of the game
{
    fireY--;
    enemyY[0]++;
    enemyY[1]++;
    enemyY[2]++;
    if (fireY == 1)
        fireY = 21;
    if ((enemyY[0] == fireY || enemyY[0] == fireY + 1) && enemyX[0] == fireX)
    {
        fireY = 21;
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
        score += 5;
    }
    else if (enemyY[0] == shipY && enemyX[0] == shipX)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
        lives -= 1;
    }
    if ((enemyY[1] == fireY || enemyY[1] == fireY + 1) && enemyX[1] == fireX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        fireY = 21;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        score += 5;
    }
    else if (enemyY[1] == shipY && enemyX[1] == shipX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        lives -= 1;
    }
    if ((enemyY[2] == fireY || enemyY[2] == fireY + 1) && enemyX[2] == fireX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        fireY = 21;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        score += 5;
    }
    else if (enemyY[2] == shipY && enemyX[2] == shipX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        lives -= 1;
    }
    if (enemyY[0] == 23)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
    }
    if (enemyY[1] == 23)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
    }
    if (enemyY[2] == 23)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
    }
}
void fire2() // function to perform action of fire in the level 2 of the game
{
    fireY--;
    enemyY[0]++;
    enemyY[1]++;
    enemyY[2]++;
    enemyY[3]++;
    enemyY[4]++;
    enemyY[5]++;
    enemyY[6]++;
    if (fireY == 1)
        fireY = 21;
    if ((enemyY[0] == fireY || enemyY[0] == fireY + 1) && enemyX[0] == fireX)
    {
        fireY = 21;
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
        score += 5;
    }
    else if (enemyY[0] == shipY && enemyX[0] == shipX)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
        lives -= 1;
    }
    if ((enemyY[1] == fireY || enemyY[1] == fireY + 1) && enemyX[1] == fireX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        fireY = 21;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        score += 5;
    }
    else if (enemyY[1] == shipY && enemyX[1] == shipX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        lives -= 1;
    }
    if ((enemyY[2] == fireY || enemyY[2] == fireY + 1) && enemyX[2] == fireX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        fireY = 21;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        score += 5;
    }
    else if (enemyY[2] == shipY && enemyX[2] == shipX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        lives -= 1;
    }
    if ((enemyY[3] == fireY || enemyY[3] == fireY + 1) && enemyX[3] == fireX)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        fireY = 21;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
        score += 5;
    }
    else if (enemyY[3] == shipY && enemyX[3] == shipX)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
        lives -= 1;
    }
    if ((enemyY[4] == fireY || enemyY[4] == fireY + 1) && enemyX[4] == fireX)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        fireY = 21;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
        score += 5;
    }
    else if (enemyY[4] == shipY && enemyX[4] == shipX)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
        lives -= 1;
    }
    if ((enemyY[5] == fireY || enemyY[5] == fireY + 1) && enemyX[5] == fireX)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        fireY = 21;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
        score += 5;
    }
    else if (enemyY[5] == shipY && enemyX[5] == shipX)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
        lives -= 1;
    }
    if ((enemyY[6] == fireY || enemyY[6] == fireY + 1) && enemyX[6] == fireX)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        fireY = 21;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
        score += 6;
    }
    else if (enemyY[6] == shipY && enemyX[6] == shipX)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
        lives -= 1;
    }
    if (enemyY[0] == 23)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
    }
    if (enemyY[1] == 23)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
    }
    if (enemyY[2] == 23)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
    }
    if (enemyY[3] == 23)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
    }
    if (enemyY[4] == 23)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
    }
    if (enemyY[5] == 23)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
    }
    if (enemyY[6] == 23)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
    }
}
void fire3() // function to perform action of fire in the level 3 of the game
{
    fireY--;
    enemyY[0]++;
    enemyY[1]++;
    enemyY[2]++;
    enemyY[3]++;
    enemyY[4]++;
    enemyY[5]++;
    enemyY[6]++;
    if (fireY == 1)
        fireY = 21;
    if ((enemyY[0] == fireY || enemyY[0] == fireY + 1) && enemyX[0] == fireX)
    {
        fireY = 21;
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
        score += 5;
    }
    else if (enemyY[0] == shipY && enemyX[0] == shipX)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
        lives -= 1;
    }
    if ((enemyY[1] == fireY || enemyY[1] == fireY + 1) && enemyX[1] == fireX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        fireY = 21;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        score += 5;
    }
    else if (enemyY[1] == shipY && enemyX[1] == shipX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        lives -= 1;
    }
    if ((enemyY[2] == fireY || enemyY[2] == fireY + 1) && enemyX[2] == fireX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        fireY = 21;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        score += 5;
    }
    else if (enemyY[2] == shipY && enemyX[2] == shipX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        lives -= 1;
    }
    if ((enemyY[3] == fireY || enemyY[3] == fireY + 1) && enemyX[3] == fireX)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        fireY = 21;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
        score += 5;
    }
    else if (enemyY[3] == shipY && enemyX[3] == shipX)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
        lives -= 1;
    }
    if ((enemyY[4] == fireY || enemyY[4] == fireY + 1) && enemyX[4] == fireX)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        fireY = 21;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
        score += 5;
    }
    else if (enemyY[4] == shipY && enemyX[4] == shipX)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
        lives -= 1;
    }
    if ((enemyY[5] == fireY || enemyY[5] == fireY + 1) && enemyX[5] == fireX)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        fireY = 21;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
        score += 5;
    }
    else if (enemyY[5] == shipY && enemyX[5] == shipX)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
        lives -= 1;
    }
    if ((enemyY[6] == fireY || enemyY[6] == fireY + 1) && enemyX[6] == fireX)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        fireY = 21;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
        score += 6;
    }
    else if (enemyY[6] == shipY && enemyX[6] == shipX)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
        lives -= 1;
    }
    if (enemyY[0] == 23)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
    }
    if (enemyY[1] == 23)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
    }
    if (enemyY[2] == 23)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
    }
    if (enemyY[3] == 23)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
    }
    if (enemyY[4] == 23)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
    }
    if (enemyY[5] == 23)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
    }
    if (enemyY[6] == 23)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
    }
}
void fire4() // function to perform action of fire in the level 4 of the game
{
    fireY--;
    enemyY[0] += 2;
    enemyY[1] += 2;
    enemyY[2] += 2;
    enemyY[3] += 2;
    enemyY[4] += 2;
    enemyY[5] += 2;
    enemyY[6] += 2;
    if (fireY == 1)
        fireY = 21;
    if ((enemyY[0] == fireY || enemyY[0] == fireY + 1 || enemyY[0] == fireY + 2) && enemyX[0] == fireX)
    {
        fireY = 21;
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
        score += 5;
    }
    else if (enemyY[0] == shipY && enemyX[0] == shipX)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
        lives -= 1;
    }
    if ((enemyY[1] == fireY || enemyY[1] == fireY + 1 || enemyY[1] == fireY + 2) && enemyX[1] == fireX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        fireY = 21;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        score += 5;
    }
    else if (enemyY[1] == shipY && enemyX[1] == shipX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        lives -= 1;
    }
    if ((enemyY[2] == fireY || enemyY[2] == fireY + 1 || enemyY[2] == fireY + 2) && enemyX[2] == fireX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        fireY = 21;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        score += 5;
    }
    else if (enemyY[2] == shipY && enemyX[2] == shipX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        lives -= 1;
    }
    if ((enemyY[3] == fireY || enemyY[3] == fireY + 1 || enemyY[3] == fireY + 2) && enemyX[3] == fireX)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        fireY = 21;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
        score += 5;
    }
    else if (enemyY[3] == shipY && enemyX[3] == shipX)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
        lives -= 1;
    }
    if ((enemyY[4] == fireY || enemyY[4] == fireY + 1 || enemyY[4] == fireY + 2) && enemyX[4] == fireX)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        fireY = 21;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
        score += 5;
    }
    else if (enemyY[4] == shipY && enemyX[4] == shipX)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
        lives -= 1;
    }
    if ((enemyY[5] == fireY || enemyY[5] == fireY + 1 || enemyY[5] == fireY + 2) && enemyX[5] == fireX)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        fireY = 21;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
        score += 5;
    }
    else if (enemyY[5] == shipY && enemyX[5] == shipX)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
        lives -= 1;
    }
    if ((enemyY[6] == fireY || enemyY[6] == fireY + 1 || enemyY[6] == fireY + 2) && enemyX[6] == fireX)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        fireY = 21;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
        score += 6;
    }
    else if (enemyY[6] == shipY && enemyX[6] == shipX)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
        lives -= 1;
    }
    if (enemyY[0] >= 23)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
    }
    if (enemyY[1] >= 23)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
    }
    if (enemyY[2] >= 23)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
    }
    if (enemyY[3] >= 23)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
    }
    if (enemyY[4] >= 23)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
    }
    if (enemyY[5] >= 23)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
    }
    if (enemyY[6] >= 23)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
    }
}
void fire5() // function to perform action of fire in the level 5 of the game
{
    fireY--;
    enemyY[0] += 2;
    enemyY[1] += 2;
    enemyY[2] += 2;
    enemyY[3] += 2;
    enemyY[4] += 2;
    enemyY[5] += 2;
    enemyY[6] += 2;
    enemyY[7] += 2;
    enemyY[8] += 2;
    if (fireY == 1)
        fireY = 21;
    if ((enemyY[0] == fireY || enemyY[0] == fireY + 1 || enemyY[0] == fireY + 2) && enemyX[0] == fireX)
    {
        fireY = 21;
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
        score += 5;
    }
    else if (enemyY[0] == shipY && enemyX[0] == shipX)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
        lives -= 1;
    }
    if ((enemyY[1] == fireY || enemyY[1] == fireY + 1 || enemyY[1] == fireY + 2) && enemyX[1] == fireX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        fireY = 21;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        score += 5;
    }
    else if (enemyY[1] == shipY && enemyX[1] == shipX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        lives -= 1;
    }
    if ((enemyY[2] == fireY || enemyY[2] == fireY + 1 || enemyY[2] == fireY + 2) && enemyX[2] == fireX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        fireY = 21;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        score += 5;
    }
    else if (enemyY[2] == shipY && enemyX[2] == shipX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        lives -= 1;
    }
    if ((enemyY[3] == fireY || enemyY[3] == fireY + 1 || enemyY[3] == fireY + 2) && enemyX[3] == fireX)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        fireY = 21;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
        score += 5;
    }
    else if (enemyY[3] == shipY && enemyX[3] == shipX)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
        lives -= 1;
    }
    if ((enemyY[4] == fireY || enemyY[4] == fireY + 1 || enemyY[4] == fireY + 2) && enemyX[4] == fireX)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        fireY = 21;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
        score += 5;
    }
    else if (enemyY[4] == shipY && enemyX[4] == shipX)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
        lives -= 1;
    }
    if ((enemyY[5] == fireY || enemyY[5] == fireY + 1 || enemyY[5] == fireY + 2) && enemyX[5] == fireX)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        fireY = 21;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
        score += 5;
    }
    else if (enemyY[5] == shipY && enemyX[5] == shipX)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
        lives -= 1;
    }
    if ((enemyY[6] == fireY || enemyY[6] == fireY + 1 || enemyY[6] == fireY + 2) && enemyX[6] == fireX)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        fireY = 21;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
        score += 5;
    }
    else if (enemyY[6] == shipY && enemyX[6] == shipX)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
        lives -= 1;
    }
    if ((enemyY[7] == fireY || enemyY[7] == fireY + 1 || enemyY[7] == fireY + 2) && enemyX[7] == fireX)
    {
        enemyX[7] += 3;
        enemyY[7] = 2;
        fireY = 21;
        if (enemyX[7] > 39)
            enemyX[7] = 2;
        score += 5;
    }
    else if (enemyY[7] == shipY && enemyX[7] == shipX)
    {
        enemyX[7] += 3;
        enemyY[7] = 2;
        if (enemyX[7] > 39)
            enemyX[7] = 2;
        lives -= 1;
    }
    if ((enemyY[8] == fireY || enemyY[8] == fireY + 1 || enemyY[8] == fireY + 2) && enemyX[8] == fireX)
    {
        enemyX[8] += 3;
        enemyY[8] = 2;
        fireY = 21;
        if (enemyX[8] > 39)
            enemyX[8] = 2;
        score += 5;
    }
    else if (enemyY[8] == shipY && enemyX[8] == shipX)
    {
        enemyX[8] += 3;
        enemyY[8] = 2;
        if (enemyX[8] > 39)
            enemyX[8] = 2;
        lives -= 1;
    }
    if (enemyY[0] >= 23)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
    }
    if (enemyY[1] >= 23)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
    }
    if (enemyY[2] >= 23)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
    }
    if (enemyY[3] >= 23)
    {
        enemyX[3] += 3;
        enemyY[3] = 2;
        if (enemyX[3] > 39)
            enemyX[3] = 2;
    }
    if (enemyY[4] >= 23)
    {
        enemyX[4] += 3;
        enemyY[4] = 2;
        if (enemyX[4] > 39)
            enemyX[4] = 2;
    }
    if (enemyY[5] >= 23)
    {
        enemyX[5] += 3;
        enemyY[5] = 2;
        if (enemyX[5] > 39)
            enemyX[5] = 2;
    }
    if (enemyY[6] >= 23)
    {
        enemyX[6] += 3;
        enemyY[6] = 2;
        if (enemyX[6] > 39)
            enemyX[6] = 2;
    }
    if (enemyY[7] >= 23)
    {
        enemyX[7] += 3;
        enemyY[7] = 2;
        if (enemyX[7] > 39)
            enemyX[7] = 2;
    }
    if (enemyY[8] >= 23)
    {
        enemyX[8] += 3;
        enemyY[8] = 2;
        if (enemyX[8] > 39)
            enemyX[8] = 2;
    }
}
void moveRight1() // function to perform action of move right in the level 1 of the game
{
    shipX++;
    fireX++;
    fireY = 21;
    enemyY[0]++;
    enemyY[1]++;
    enemyY[2]++;
    if (shipX == 40)
    {
        shipX = 2;
        fireX = 2;
    }
    if (enemyY[0] == 23)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
    }
    if (enemyY[1] == 23)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
    }
    if (enemyY[2] == 23)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
    }
    if ((enemyY[0] == fireY || enemyY[0] == fireY + 1) && enemyX[0] == shipX)
    {
        lives -= 1;
        enemyX[0] += 3;
        enemyY[0] = 2;
        fireY = 21;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
    }
    if ((enemyY[1] == fireY || enemyY[1] == fireY + 1) && enemyX[1] == shipX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        fireY = 21;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        lives -= 1;
    }
    if ((enemyY[2] == fireY || enemyY[2] == fireY + 1) && enemyX[2] == shipX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        fireY = 21;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        lives -= 1;
    }
}
void moveRight2() // function to perform action of move right in the level 2 of the game
{
    if (shipX < 40)
    {
        shipX++;
        fireX++;
        fireY = 21;
        enemyY[0]++;
        enemyY[1]++;
        enemyY[2]++;
        enemyY[3]++;
        enemyY[4]++;
        enemyY[5]++;
        enemyY[6]++;
        if (shipX == 40)
        {
            shipX = 2;
            fireX = 2;
        }
        if (enemyY[0] == 23)
        {
            enemyX[0] += 3;
            enemyY[0] = 2;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if (enemyY[1] == 23)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
        }
        if (enemyY[2] == 23)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
        }
        if (enemyY[3] == 23)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
        }
        if (enemyY[4] == 23)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
        }
        if (enemyY[5] == 23)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
        }
        if (enemyY[6] == 23)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
        }
        if ((enemyY[0] == fireY || enemyY[0] == fireY + 1) && enemyX[0] == shipX)
        {
            lives -= 1;
            enemyX[0] += 3;
            enemyY[0] = 2;
            fireY = 21;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if ((enemyY[1] == fireY || enemyY[1] == fireY + 1) && enemyX[1] == shipX)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            fireY = 21;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
            lives -= 1;
        }
        if ((enemyY[2] == fireY || enemyY[2] == fireY + 1) && enemyX[2] == shipX)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            fireY = 21;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
            lives -= 1;
        }
        if ((enemyY[3] == fireY || enemyY[3] == fireY + 1) && enemyX[3] == shipX)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            fireY = 21;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
            lives -= 1;
        }
        if ((enemyY[4] == fireY || enemyY[4] == fireY + 1) && enemyX[4] == shipX)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
            lives -= 1;
        }
        if ((enemyY[5] == fireY || enemyY[5] == fireY + 1) && enemyX[5] == shipX)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
            lives -= 1;
        }
        if ((enemyY[6] == fireY || enemyY[6] == fireY + 1) && enemyX[6] == shipX)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
            lives -= 1;
        }
    }
}
void moveRight3() // function to perform action of move right in the level 3 of the game
{
    if (shipX < 40)
    {
        shipX++;
        fireX++;
        fireY = 21;
        enemyY[0]++;
        enemyY[1]++;
        enemyY[2]++;
        enemyY[3]++;
        enemyY[4]++;
        enemyY[5]++;
        enemyY[6]++;
        if (shipX == 40)
        {
            shipX = 2;
            fireX = 2;
        }
        if (enemyY[0] == 23)
        {
            enemyX[0] += 3;
            enemyY[0] = 2;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if (enemyY[1] == 23)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
        }
        if (enemyY[2] == 23)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
        }
        if (enemyY[3] == 23)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
        }
        if (enemyY[4] == 23)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
        }
        if (enemyY[5] == 23)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
        }
        if (enemyY[6] == 23)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
        }
        if ((enemyY[0] == fireY || enemyY[0] == fireY + 1) && enemyX[0] == shipX)
        {
            lives -= 1;
            enemyX[0] += 3;
            enemyY[0] = 2;
            fireY = 21;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if ((enemyY[1] == fireY || enemyY[1] == fireY + 1) && enemyX[1] == shipX)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            fireY = 21;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
            lives -= 1;
        }
        if ((enemyY[2] == fireY || enemyY[2] == fireY + 1) && enemyX[2] == shipX)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            fireY = 21;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
            lives -= 1;
        }
        if ((enemyY[3] == fireY || enemyY[3] == fireY + 1) && enemyX[3] == shipX)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            fireY = 21;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
            lives -= 1;
        }
        if ((enemyY[4] == fireY || enemyY[4] == fireY + 1) && enemyX[4] == shipX)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
            lives -= 1;
        }
        if ((enemyY[5] == fireY || enemyY[5] == fireY + 1) && enemyX[5] == shipX)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
            lives -= 1;
        }
        if ((enemyY[6] == fireY || enemyY[6] == fireY + 1) && enemyX[6] == shipX)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
            lives -= 1;
        }
    }
}
void moveRight4() // function to perform action of move right in the level 4 of the game
{
    if (shipX < 40)
    {
        shipX++;
        fireX++;
        fireY = 21;
        enemyY[0] += 2;
        enemyY[1] += 2;
        enemyY[2] += 2;
        enemyY[3] += 2;
        enemyY[4] += 2;
        enemyY[5] += 2;
        enemyY[6] += 2;
        if (shipX == 40)
        {
            shipX = 2;
            fireX = 2;
        }
        if (enemyY[0] >= 23)
        {
            enemyX[0] += 3;
            enemyY[0] = 2;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if (enemyY[1] >= 23)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
        }
        if (enemyY[2] >= 23)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
        }
        if (enemyY[3] >= 23)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
        }
        if (enemyY[4] >= 23)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
        }
        if (enemyY[5] >= 23)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
        }
        if (enemyY[6] >= 23)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
        }
        if ((enemyY[0] == fireY || enemyY[0] == fireY + 1 || enemyY[0] == fireY + 2) && enemyX[0] == shipX)
        {
            lives -= 1;
            enemyX[0] += 3;
            enemyY[0] = 2;
            fireY = 21;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if ((enemyY[1] == fireY || enemyY[1] == fireY + 1 || enemyY[1] == fireY + 2) && enemyX[1] == shipX)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            fireY = 21;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
            lives -= 1;
        }
        if ((enemyY[2] == fireY || enemyY[2] == fireY + 1 || enemyY[2] == fireY + 2) && enemyX[2] == shipX)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            fireY = 21;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
            lives -= 1;
        }
        if ((enemyY[3] == fireY || enemyY[3] == fireY + 1 || enemyY[3] == fireY + 2) && enemyX[3] == shipX)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            fireY = 21;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
            lives -= 1;
        }
        if ((enemyY[4] == fireY || enemyY[4] == fireY + 1 || enemyY[4] == fireY + 2) && enemyX[4] == shipX)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
            lives -= 1;
        }
        if ((enemyY[5] == fireY || enemyY[5] == fireY + 1 || enemyY[5] == fireY + 2) && enemyX[5] == shipX)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
            lives -= 1;
        }
        if ((enemyY[6] == fireY || enemyY[6] == fireY + 1 || enemyY[6] == fireY + 2) && enemyX[6] == shipX)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
            lives -= 1;
        }
    }
}
void moveRight5() // function to perform action of move right in the level 5 of the game
{
    if (shipX < 40)
    {
        shipX++;
        fireX++;
        fireY = 21;
        enemyY[0] += 2;
        enemyY[1] += 2;
        enemyY[2] += 2;
        enemyY[3] += 2;
        enemyY[4] += 2;
        enemyY[5] += 2;
        enemyY[6] += 2;
        enemyY[7] += 2;
        enemyY[8] += 2;
        if (shipX == 40)
        {
            shipX = 2;
            fireX = 2;
        }
        if (enemyY[0] >= 23)
        {
            enemyX[0] += 3;
            enemyY[0] = 2;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if (enemyY[1] >= 23)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
        }
        if (enemyY[2] >= 23)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
        }
        if (enemyY[3] >= 23)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
        }
        if (enemyY[4] >= 23)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
        }
        if (enemyY[5] >= 23)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
        }
        if (enemyY[6] >= 23)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
        }
        if (enemyY[7] >= 23)
        {
            enemyX[7] += 3;
            enemyY[7] = 2;
            if (enemyX[7] > 39)
                enemyX[7] = 2;
        }
        if (enemyY[8] >= 23)
        {
            enemyX[8] += 3;
            enemyY[8] = 2;
            if (enemyX[8] > 39)
                enemyX[8] = 2;
        }
        if ((enemyY[0] == fireY || enemyY[0] == fireY + 1 || enemyY[0] == fireY + 2) && enemyX[0] == shipX)
        {
            lives -= 1;
            enemyX[0] += 3;
            enemyY[0] = 2;
            fireY = 21;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if ((enemyY[1] == fireY || enemyY[1] == fireY + 1 || enemyY[1] == fireY + 2) && enemyX[1] == shipX)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            fireY = 21;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
            lives -= 1;
        }
        if ((enemyY[2] == fireY || enemyY[2] == fireY + 1 || enemyY[2] == fireY + 2) && enemyX[2] == shipX)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            fireY = 21;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
            lives -= 1;
        }
        if ((enemyY[3] == fireY || enemyY[3] == fireY + 1 || enemyY[3] == fireY + 2) && enemyX[3] == shipX)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            fireY = 21;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
            lives -= 1;
        }
        if ((enemyY[4] == fireY || enemyY[4] == fireY + 1 || enemyY[4] == fireY + 2) && enemyX[4] == shipX)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
            lives -= 1;
        }
        if ((enemyY[5] == fireY || enemyY[5] == fireY + 1 || enemyY[5] == fireY + 2) && enemyX[5] == shipX)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
            lives -= 1;
        }
        if ((enemyY[6] == fireY || enemyY[6] == fireY + 1 || enemyY[6] == fireY + 2) && enemyX[6] == shipX)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
            lives -= 1;
        }
        if ((enemyY[7] == fireY || enemyY[7] == fireY + 1 || enemyY[7] == fireY + 2) && enemyX[7] == shipX)
        {
            enemyX[7] += 3;
            enemyY[7] = 2;
            if (enemyX[7] > 39)
                enemyX[7] = 2;
            lives -= 1;
        }
        if ((enemyY[8] == fireY || enemyY[8] == fireY + 1 || enemyY[8] == fireY + 2) && enemyX[8] == shipX)
        {
            enemyX[8] += 3;
            enemyY[8] = 2;
            if (enemyX[8] > 39)
                enemyX[8] = 2;
            lives -= 1;
        }
    }
}
void moveLeft1() // function to perform action of move left in the level 1 of the game
{
    shipX--;
    fireX--;
    fireY = 21;
    enemyY[0]++;
    enemyY[1]++;
    enemyY[2]++;
    if (shipX == 1)
    {
        shipX = 39;
        fireX = 39;
    }
    if (enemyY[0] == 23)
    {
        enemyX[0] += 3;
        enemyY[0] = 2;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
    }
    if (enemyY[1] == 23)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
    }
    if (enemyY[2] == 23)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
    }
    if ((enemyY[0] == fireY || enemyY[0] == fireY + 1) && enemyX[0] == shipX)
    {
        lives -= 1;
        enemyX[0] += 3;
        enemyY[0] = 2;
        fireY = 21;
        if (enemyX[0] > 39)
            enemyX[0] = 2;
    }
    if ((enemyY[1] == fireY || enemyY[1] == fireY + 1) && enemyX[1] == shipX)
    {
        enemyX[1] += 3;
        enemyY[1] = 2;
        fireY = 21;
        if (enemyX[1] > 39)
            enemyX[1] = 2;
        lives -= 1;
    }
    if ((enemyY[2] == fireY || enemyY[2] == fireY + 1) && enemyX[2] == shipX)
    {
        enemyX[2] += 3;
        enemyY[2] = 2;
        fireY = 21;
        if (enemyX[2] > 39)
            enemyX[2] = 2;
        lives -= 1;
    }
}
void moveLeft2() // function to perform action of move left in the level 2 of the game
{
    if (shipX > 0)
    {
        shipX--;
        fireX--;
        fireY = 21;
        enemyY[0]++;
        enemyY[1]++;
        enemyY[2]++;
        enemyY[3]++;
        enemyY[4]++;
        enemyY[5]++;
        enemyY[6]++;
        if (shipX == 1)
        {
            shipX = 39;
            fireX = 39;
        }
        if (enemyY[0] == 23)
        {
            enemyX[0] += 3;
            enemyY[0] = 2;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if (enemyY[1] == 23)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
        }
        if (enemyY[2] == 23)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
        }
        if (enemyY[3] == 23)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
        }
        if (enemyY[4] == 23)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
        }
        if (enemyY[5] == 23)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
        }
        if (enemyY[6] == 23)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
        }
        if ((enemyY[0] == fireY || enemyY[0] == fireY + 1) && enemyX[0] == shipX)
        {
            lives -= 1;
            enemyX[0] += 3;
            enemyY[0] = 2;
            fireY = 21;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if ((enemyY[1] == fireY || enemyY[1] == fireY + 1) && enemyX[1] == shipX)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            fireY = 21;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
            lives -= 1;
        }
        if ((enemyY[2] == fireY || enemyY[2] == fireY + 1) && enemyX[2] == shipX)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            fireY = 21;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
            lives -= 1;
        }
        if ((enemyY[3] == fireY || enemyY[3] == fireY + 1) && enemyX[3] == shipX)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            fireY = 21;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
            lives -= 1;
        }
        if ((enemyY[4] == fireY || enemyY[4] == fireY + 1) && enemyX[4] == shipX)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            fireY = 21;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
            lives -= 1;
        }
        if ((enemyY[5] == fireY || enemyY[5] == fireY + 1) && enemyX[5] == shipX)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            fireY = 21;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
            lives -= 1;
        }
        if ((enemyY[6] == fireY || enemyY[6] == fireY + 1) && enemyX[6] == shipX)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            fireY = 21;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
            lives -= 1;
        }
    }
}
void moveLeft3() // function to perform action of move left in the level 3 of the game
{
    if (shipX > 0)
    {
        shipX--;
        fireX--;
        fireY = 21;
        enemyY[0]++;
        enemyY[1]++;
        enemyY[2]++;
        enemyY[3]++;
        enemyY[4]++;
        enemyY[5]++;
        enemyY[6]++;
        if (shipX == 1)
        {
            shipX = 39;
            fireX = 39;
        }
        if (enemyY[0] == 23)
        {
            enemyX[0] += 3;
            enemyY[0] = 2;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if (enemyY[1] == 23)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
        }
        if (enemyY[2] == 23)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
        }
        if (enemyY[3] == 23)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
        }
        if (enemyY[4] == 23)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
        }
        if (enemyY[5] == 23)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
        }
        if (enemyY[6] == 23)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
        }
        if ((enemyY[0] == fireY || enemyY[0] == fireY + 1) && enemyX[0] == shipX)
        {
            lives -= 1;
            enemyX[0] += 3;
            enemyY[0] = 2;
            fireY = 21;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if ((enemyY[1] == fireY || enemyY[1] == fireY + 1) && enemyX[1] == shipX)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            fireY = 21;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
            lives -= 1;
        }
        if ((enemyY[2] == fireY || enemyY[2] == fireY + 1) && enemyX[2] == shipX)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            fireY = 21;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
            lives -= 1;
        }
        if ((enemyY[3] == fireY || enemyY[3] == fireY + 1) && enemyX[3] == shipX)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            fireY = 21;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
            lives -= 1;
        }
        if ((enemyY[4] == fireY || enemyY[4] == fireY + 1) && enemyX[4] == shipX)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            fireY = 21;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
            lives -= 1;
        }
        if ((enemyY[5] == fireY || enemyY[5] == fireY + 1) && enemyX[5] == shipX)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            fireY = 21;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
            lives -= 1;
        }
        if ((enemyY[6] == fireY || enemyY[6] == fireY + 1) && enemyX[6] == shipX)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            fireY = 21;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
            lives -= 1;
        }
    }
}
void moveLeft4() // function to perform action of move left in the level 4 of the game
{
    if (shipX > 0)
    {
        shipX--;
        fireX--;
        fireY = 21;
        enemyY[0] += 2;
        enemyY[1] += 2;
        enemyY[2] += 2;
        enemyY[3] += 2;
        enemyY[4] += 2;
        enemyY[5] += 2;
        enemyY[6] += 2;
        if (shipX == 1)
        {
            shipX = 39;
            fireX = 39;
        }
        if (enemyY[0] >= 23)
        {
            enemyX[0] += 3;
            enemyY[0] = 2;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if (enemyY[1] >= 23)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
        }
        if (enemyY[2] >= 23)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
        }
        if (enemyY[3] >= 23)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
        }
        if (enemyY[4] >= 23)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
        }
        if (enemyY[5] >= 23)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
        }
        if (enemyY[6] >= 23)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
        }
        if ((enemyY[0] == fireY || enemyY[0] == fireY + 1 || enemyY[0] == fireY + 2) && enemyX[0] == shipX)
        {
            lives -= 1;
            enemyX[0] += 3;
            enemyY[0] = 2;
            fireY = 21;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if ((enemyY[1] == fireY || enemyY[1] == fireY + 1 || enemyY[1] == fireY + 2) && enemyX[1] == shipX)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            fireY = 21;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
            lives -= 1;
        }
        if ((enemyY[2] == fireY || enemyY[2] == fireY + 1 || enemyY[2] == fireY + 2) && enemyX[2] == shipX)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            fireY = 21;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
            lives -= 1;
        }
        if ((enemyY[3] == fireY || enemyY[3] == fireY + 1 || enemyY[3] == fireY + 2) && enemyX[3] == shipX)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            fireY = 21;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
            lives -= 1;
        }
        if ((enemyY[4] == fireY || enemyY[4] == fireY + 1 || enemyY[4] == fireY + 2) && enemyX[4] == shipX)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            fireY = 21;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
            lives -= 1;
        }
        if ((enemyY[5] == fireY || enemyY[5] == fireY + 1 || enemyY[5] == fireY + 2) && enemyX[5] == shipX)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            fireY = 21;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
            lives -= 1;
        }
        if ((enemyY[6] == fireY || enemyY[6] == fireY + 1 || enemyY[6] == fireY + 2) && enemyX[6] == shipX)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            fireY = 21;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
            lives -= 1;
        }
    }
}
void moveLeft5() // function to perform action of move left in the level 5 of the game
{
    if (shipX > 0)
    {
        shipX--;
        fireX--;
        fireY = 21;
        enemyY[0] += 2;
        enemyY[1] += 2;
        enemyY[2] += 2;
        enemyY[3] += 2;
        enemyY[4] += 2;
        enemyY[6] += 2;
        enemyY[7] += 2;
        enemyY[8] += 2;
        if (shipX == 1)
        {
            shipX = 39;
            fireX = 39;
        }
        if (enemyY[0] >= 23)
        {
            enemyX[0] += 3;
            enemyY[0] = 2;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if (enemyY[1] >= 23)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
        }
        if (enemyY[2] >= 23)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
        }
        if (enemyY[3] >= 23)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
        }
        if (enemyY[4] >= 23)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
        }
        if (enemyY[5] >= 23)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
        }
        if (enemyY[6] >= 23)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
        }
        if (enemyY[7] >= 23)
        {
            enemyX[7] += 3;
            enemyY[7] = 2;
            if (enemyX[7] > 39)
                enemyX[7] = 2;
        }
        if (enemyY[8] >= 23)
        {
            enemyX[8] += 3;
            enemyY[8] = 2;
            if (enemyX[8] > 39)
                enemyX[8] = 2;
        }
        if ((enemyY[0] == fireY || enemyY[0] == fireY + 1 || enemyY[0] == fireY + 2) && enemyX[0] == shipX)
        {
            lives -= 1;
            enemyX[0] += 3;
            enemyY[0] = 2;
            fireY = 21;
            if (enemyX[0] > 39)
                enemyX[0] = 2;
        }
        if ((enemyY[1] == fireY || enemyY[1] == fireY + 1 || enemyY[1] == fireY + 2) && enemyX[1] == shipX)
        {
            enemyX[1] += 3;
            enemyY[1] = 2;
            fireY = 21;
            if (enemyX[1] > 39)
                enemyX[1] = 2;
            lives -= 1;
        }
        if ((enemyY[2] == fireY || enemyY[2] == fireY + 1 || enemyY[2] == fireY + 2) && enemyX[2] == shipX)
        {
            enemyX[2] += 3;
            enemyY[2] = 2;
            fireY = 21;
            if (enemyX[2] > 39)
                enemyX[2] = 2;
            lives -= 1;
        }
        if ((enemyY[3] == fireY || enemyY[3] == fireY + 1 || enemyY[3] == fireY + 2) && enemyX[3] == shipX)
        {
            enemyX[3] += 3;
            enemyY[3] = 2;
            fireY = 21;
            if (enemyX[3] > 39)
                enemyX[3] = 2;
            lives -= 1;
        }
        if ((enemyY[4] == fireY || enemyY[4] == fireY + 1 || enemyY[4] == fireY + 2) && enemyX[4] == shipX)
        {
            enemyX[4] += 3;
            enemyY[4] = 2;
            fireY = 21;
            if (enemyX[4] > 39)
                enemyX[4] = 2;
            lives -= 1;
        }
        if ((enemyY[5] == fireY || enemyY[5] == fireY + 1 || enemyY[5] == fireY + 2) && enemyX[5] == shipX)
        {
            enemyX[5] += 3;
            enemyY[5] = 2;
            fireY = 21;
            if (enemyX[5] > 39)
                enemyX[5] = 2;
            lives -= 1;
        }
        if ((enemyY[6] == fireY || enemyY[6] == fireY + 1 || enemyY[6] == fireY + 2) && enemyX[6] == shipX)
        {
            enemyX[6] += 3;
            enemyY[6] = 2;
            fireY = 21;
            if (enemyX[6] > 39)
                enemyX[6] = 2;
            lives -= 1;
        }
        if ((enemyY[7] == fireY || enemyY[7] == fireY + 1 || enemyY[7] == fireY + 2) && enemyX[7] == shipX)
        {
            enemyX[7] += 3;
            enemyY[7] = 2;
            fireY = 21;
            if (enemyX[7] > 39)
                enemyX[7] = 2;
            lives -= 1;
        }
        if ((enemyY[8] == fireY || enemyY[8] == fireY + 1 || enemyY[8] == fireY + 2) && enemyX[8] == shipX)
        {
            enemyX[8] += 3;
            enemyY[8] = 2;
            fireY = 21;
            if (enemyX[8] > 39)
                enemyX[8] = 2;
            lives -= 1;
        }
    }
}
void youWin() // function to display you win screen
{
    int count = 2;
    while (count < 8)
    {
        system("cls");
        SetConsoleTextAttribute(hStdOut, count);
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
             << "<< --------------------------------------------------------------- <<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                 ***** Y ***** O ***** U *****                 |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                 ***** W ***** I ***** N *****                 |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<< --------------------------------------------------------------- <<" << endl
             << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        Sleep(500);
        count++;
    }
}
void youLose() // function to display you lose screen
{
    int count = 2;
    while (count < 8)
    {
        system("cls");
        SetConsoleTextAttribute(hStdOut, count);
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl
             << "<< --------------------------------------------------------------- <<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                 ***** Y ***** O ***** U *****                 |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|             ***** L ***** O ***** S ***** E *****             |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<<|                                                               |<<" << endl
             << "<< --------------------------------------------------------------- <<" << endl
             << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        Sleep(500);
        count++;
    }
}
