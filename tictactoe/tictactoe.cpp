#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <windows.h>

using std::cout;
using std::cin;
using namespace std;
char space[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
string player1;
string player2;
bool stop = false;
char restart;
int k = 0,j,i;
int reblink;
int delay = 200;
inline void clrscr() { system("cls"); }
inline void c_out() {                                           //main interface
    cout << endl;
    cout << "\t|\t" << space[0][0] << " \t|" << "\t" << space[0][1] << "\t|\t" << space[0][2] << "\t|" << endl;
    cout << "\t|\t" << "  \t|" << "\t" << " \t|\t" << "\t|" << endl;
    cout << "\t|-----------------------------------------------" << "|" << endl;
    cout << "\t|\t" << space[1][0] << " \t|" << "\t" << space[1][1] << "\t|\t" << space[1][2] << "\t|" << endl;
    cout << "\t|\t" << "  \t|" << "\t" << " \t|\t" << "\t|" << endl;
    cout << "\t|-----------------------------------------------" << "|" << endl;
    cout << "\t|\t" << space[2][0] << " \t|" << "\t" << space[2][1] << "\t|\t" << space[2][2] << "\t|" << endl;
    cout << "\t|\t" << "  \t|" << "\t" << " \t|\t" << "\t|" << endl;
}
inline void blinkrow() {
    for (int n = 0; n < 6; n++) {
        clrscr();
        space[j][0] = ' ';
        space[j][1] = ' ';
        space[j][2] = system("Color 0A");
        space[j][2] = ' ';
        c_out();
        k % 2 == 0 ? cout << "\n--------------------\n" << "  " << player1 << " wins" << "\n--------------------\n" : cout << "\n--------------------\n" << "  " << player2 << " wins" << "\n--------------------\n";       
        Sleep(delay);
        space[j][0] = reblink;
        space[j][1] = reblink;
        space[j][2] = system("Color 0A");
        space[j][2] = reblink;
        
        clrscr();
        c_out();
        k % 2 == 0 ? cout << "\n--------------------\n" << "  " << player1 << " wins" << "\n--------------------\n" : cout << "\n--------------------\n" << "  " << player2 << " wins" << "\n--------------------\n";      
        Sleep(delay);
    }
}
inline void blinkcolumn() {
    for (int n = 0; n < 6; n++) {
        clrscr();
        space[0][i] = ' ';
        space[1][i] = ' ';
        space[2][i] = ' ';
        system("Color 0A");
        c_out();
        k % 2 == 0 ? cout << "\n--------------------\n" << "  " << player1 << " wins" << "\n--------------------\n" : cout << "\n--------------------\n" << "  " << player2 << " wins" << "\n--------------------\n";
        Sleep(delay);
        clrscr();
        space[0][i] = reblink;
        space[1][i] = reblink;
        space[2][i] = reblink;
        c_out();
        k % 2 == 0 ? cout << "\n--------------------\n" << "  " << player1 << " wins" << "\n--------------------\n" : cout << "\n--------------------\n" << "  " << player2 << " wins" << "\n--------------------\n";
        Sleep(delay);
    }
}

inline void check();
inline void ask() {
    if (stop == true) {
        do {
            system("Color 08");
            cout << "\n\nDo you want to Play the Game Again? (y/n)\n\n\nEnter Your Choice: ";
            cin >> restart;
            if (restart == 'y') {
                cin.clear();
                cin.ignore(100, '\n');               
                space[0][0] = '1';
                space[0][1] = '2';
                space[0][2] = '3';
                space[1][0] = '4';
                space[1][1] = '5';
                space[1][2] = '6';
                space[2][0] = '7';
                space[2][1] = '8';
                space[2][2] = '9';
                stop = false;
                k = 9;
            }
            else if (restart == 'n') {
                k = 8;
                clrscr();
                cout << "\n\n\t\t\t\t\t*****************************\n\n\t\t\t\t\t  Thank You For Playing !!!\n\n\t\t\t\t\t*****************************\n\n";
            }
            if(restart != 'y' && restart != 'n'){
                cin.clear();
                cin.ignore(100, '\n');
                clrscr();
                c_out();
                k % 2 == 0 ? cout << "\n--------------------\n" << "  " << player1 << " wins" << "\n--------------------\n" : cout << "\n--------------------\n" << "  " << player2 << " wins" << "\n--------------------\n";
                cout << "\n\t\t\t\t-----(Invalid input)-----\a";
            }
        } while (restart != 'y' && restart != 'n');
    }
}
inline void check() {
    int row = 0, column = 0;
    for (j = 0; j < 3; j++) {
        if (space[j][0] == space[j][1] && space[j][1] == space[j][2]) {
            (/*(space[j][0] == 'X' || space[j][1] == 'X' || space[j][2] == 'X')*/ k % 2 == 0 ? cout << "\n--------------------\n" << "  " << player1 << " wins" << "\n--------------------\n" : cout << "\n--------------------\n" << "  " << player2 << " wins" << "\n--------------------\n");
            reblink = space[j][0];
            stop = true;
            blinkrow();
            
            
        }
        else (row += 1);
    }
    if (row == 3) {
        for (i = 0; i < 3; i++) {
            if (space[0][i] == space[1][i] && space[1][i] == space[2][i]) {
                (/*(space[0][i] == 'X' || space[1][i] == 'X' || space[2][i] == 'X')*/ k % 2 == 0 ? cout << "\n--------------------\n" << "  " << player1 << " wins" << "\n--------------------\n" : cout << "\n--------------------\n" << "  " << player2 << " wins" << "\n--------------------\n");
                reblink = space[0][i];                
                stop = true;
                blinkcolumn();
                
                
                
            }
            else (column += 1);
        }
        if (column == 3) {
            if (((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0]))) {
                (((space[0][0] == 'X' && space[1][1] == 'X') || (space[0][2] == 'X' && space[1][1] == 'X')) ? cout << "\n--------------------\n" << "  " << player1 << " wins" << "\n--------------------\n" : cout << "\n--------------------\n" << "  " << player2 << " wins" << "\n--------------------\n");
                stop = true;
                

            }
        }
    }
    ask();
}

inline void fillerror() {
    c_out();
    cout << "\n\n*****************************\n\nInvalid!! Already Filled\n\n*****************************\n\n\a";
}

int main()
{
    cout << "\n\t----------------------------------( WELCOME TO THE GAME )----------------------------------" << endl << endl << endl;
    /*cout << "\t\t\t\t\t----------------------------------"<<endl;*/
    cout << "\t\t\t\tEnter First Player's Name: ";

    getline(cin, player1);
    cout << "\n\n";
    cout << "\t\t\t-----------------------------------------------------" << endl << endl << endl;
    cout << "\t\t\t\tEnter Second Player's Name: ";
    getline(cin, player2);
    do {
        clrscr();      
        c_out();
        k = 0;
        system("Color 08");

        while (k < 9) {
            int box;
            if (k % 2 == 0) {
                cout << "\n"  << player1 << "'s turn: ";
                cin >> box;
                if (cin.fail() || box <= 0 || box > 9) {
                    clrscr();
                    c_out();
                    cout << "\n\n******************************************\n\nInvalid input. Please enter a number (1-9)\n\n******************************************\n\n\a";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
            }
            else {
                cout << "\n" << player2 << "'s turn: ";
                cin >> box;
                if (cin.fail() || box <= 0 || box > 9) {
                    clrscr();
                    c_out();
                    cout << "\n\n******************************************\n\nInvalid input. Please enter a number (1-9)\n\n******************************************\n\n\a";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                
            }
            if (box == 1 || box == 2 || box == 3 || box == 4 || box == 5 || box == 6 || box == 7 || box == 8 || box == 9) {
                clrscr();
                switch (box) {
                case 1:
                    if (space[0][0] == 'X' || space[0][0] == 'O') {
                        fillerror();
                    }
                    else {
                        k % 2 == 0 ? space[0][0] = 'X' : space[0][0] = 'O';
                        c_out();
                    }
                    check();
                    break;
                case 2:
                    if (space[0][1] == 'X' || space[0][1] == 'O') {
                        fillerror();
                    }
                    else {
                        k % 2 == 0 ? space[0][1] = 'X' : space[0][1] = 'O';
                        c_out();
                    }
                    check();
                    break;
                case 3:
                    if (space[0][2] == 'X' || space[0][2] == 'O') {
                        fillerror();
                    }
                    else {
                        k % 2 == 0 ? space[0][2] = 'X' : space[0][2] = 'O';
                        c_out();
                    }
                    check();
                    break;
                case 4:
                    if (space[1][0] == 'X' || space[1][0] == 'O') {
                        fillerror();
                    }
                    else {
                        k % 2 == 0 ? space[1][0] = 'X' : space[1][0] = 'O';
                        c_out();
                    }
                    check();
                    break;
                case 5:
                    if (space[1][1] == 'X' || space[1][1] == 'O') {
                        fillerror();
                    }
                    else {
                        k % 2 == 0 ? space[1][1] = 'X' : space[1][1] = 'O';
                        c_out();
                    }
                    check();
                    break;
                case 6:
                    if (space[1][2] == 'X' || space[1][2] == 'O') {
                        fillerror();
                    }
                    else {
                        k % 2 == 0 ? space[1][2] = 'X' : space[1][2] = 'O';
                        c_out();
                    }
                    check();
                    break;
                case 7:
                    if (space[2][0] == 'X' || space[2][0] == 'O') {
                        fillerror();
                    }
                    else {
                        k % 2 == 0 ? space[2][0] = 'X' : space[2][0] = 'O';
                        c_out();
                    }
                    check();
                    break;
                case 8:
                    if (space[2][1] == 'X' || space[2][1] == 'O') {
                        fillerror();
                    }
                    else {
                        k % 2 == 0 ? space[2][1] = 'X' : space[2][1] = 'O';
                        c_out();
                    }
                    check();
                    break;
                case 9:
                    if (space[2][2] == 'X' || space[2][2] == 'O') {
                        fillerror();
                    }
                    else {
                        k % 2 == 0 ? space[2][2] = 'X' : space[2][2] = 'O';
                        c_out();
                    }
                    check();
                    break;

                }
            }

            if (k == 8 && stop == false) {
                cout << "\n--------------------\nNo one wins (DRAW)\n--------------------\n";
                stop = true;
                ask();
            }


            
            k++;
        }
        
    } while (restart == 'y');
    return 0;
}



