#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define I 4
#define J 4

int i, j, x, y;
int array[I][J], temp, _temp[I][J], _orig[I][J], end = 0;
int _temp_x, _temp_y, couple[I][J], counter = 0, _couple = 0, couple_counter = 0, begin = 1;
int temp_orig1, temp_orig2, temp_orig3, temp_orig4, temp_orig5, temp_orig6, temp_orig7, temp_orig8;

void board(void)
{
    srand((unsigned)time(NULL));

    // Fill pairs (1..8 twice)
    for (i = 0; i < I; i++) {
        for (j = 0; j < J; j++) {
            if (i == 0) array[i][j] = j + 1;
            if (i == 1) array[i][j] = j + 5;
            if (i == 2) array[i][j] = j + 1;
            if (i == 3) array[i][j] = j + 5;
        }
    }

    // Shuffle
    for (i = 0; i < I; i++) {
        for (j = 0; j < J; j++) {
            int ra = rand() % 4;
            int rb = rand() % 4;
            temp = array[i][j];
            array[i][j] = array[ra][rb];
            array[ra][rb] = temp;
        }
    }

    // Show shuffled board briefly
    printf("\n\n\n\n\n\n\n\n\n\n");
    for (i = 0; i < I; i++) {
        printf("\t\t\t\t\t\t");
        for (j = 0; j < J; j++) {
            _orig[i][j] = array[i][j];
            printf("    %d", _orig[i][j]);
        }
        printf("\n\n");
    }
    Sleep(15000);
    system("cls");

    // Hide board
    printf("\n\n\n\n\n\n\n\n\n\n");
    for (i = 0; i < I; i++) {
        printf("\t\t\t\t\t\t");
        for (j = 0; j < J; j++) {
            _temp[i][j] = 0;
            printf("    *");
        }
        printf("\n\n");
    }
    for (i = 0; i < I; i++) {
        for (j = 0; j < J; j++) {
            couple[i][j] = 0;
        }
    }
    getch();
    system("cls");
}

static int read_coord(const char *label)
{
    int v;
    while (1) {
        printf("%s (0-3): ", label);
        if (scanf("%d", &v) == 1 && v >= 0 && v < 4) {
            return v;
        }
        // clear invalid input
        while (getchar() != '\n') {}
        printf("Invalid input. Please enter a number 0, 1, 2, or 3.\n");
    }
}

void Input(void)
{
    printf("Choose coordinates (row and column, both 0-3)\n");
    x = read_coord("row");
    y = read_coord("col");

    if (counter == 0) { _temp_x = x; _temp_y = y; }
    counter += 1;
    system("cls");
}

void Output(void)
{
    printf("\n\n\n\n\n\n\n\n\n\n");
    for (i = 0; i < I; i++) {
        printf("\t\t\t\t\t\t");
        for (j = 0; j < J; j++) {
            if ((i == x) && (j == y)) _temp[i][j] = 1;
            if (couple[i][j] != 0) _temp[i][j] = 1;
            if (_temp[i][j] == 0) printf("   *");
            else printf("   %d", _orig[i][j]);
        }
        printf("\n\n");
    }

    getch(); system("cls");

    if ((counter > 1) && (_orig[_temp_x][_temp_y] == _orig[x][y])) {
        if ((_temp_x == x) && (_temp_y == y)) {
            // Same tile picked twice: treat as revealed (kept face down)
            couple_counter += 1;
            _couple = 0;
            printf("\n\n\n\n\n\n\n\n\n\n");
            for (i = 0; i < I; i++) {
                printf("\t\t\t\t\t\t");
                for (j = 0; j < J; j++) {
                    _temp[x][y] = 0;
                    if (_temp[i][j] == 0) printf("   *");
                    else {
                        if (couple_counter == 1) { temp_orig1 = _orig[x][y]; couple[_temp_x][_temp_y] = 1; couple[x][y] = 1; }
                        if (couple_counter == 2) { temp_orig2 = _orig[x][y]; couple[_temp_x][_temp_y] = 2; couple[x][y] = 2; }
                        if (couple_counter == 3) { temp_orig3 = _orig[x][y]; couple[_temp_x][_temp_y] = 3; couple[x][y] = 3; }
                        if (couple_counter == 4) { temp_orig4 = _orig[x][y]; couple[_temp_x][_temp_y] = 4; couple[x][y] = 4; }
                        if (couple_counter == 5) { temp_orig5 = _orig[x][y]; couple[_temp_x][_temp_y] = 5; couple[x][y] = 5; }
                        if (couple_counter == 6) { temp_orig6 = _orig[x][y]; couple[_temp_x][_temp_y] = 6; couple[x][y] = 6; }
                        if (couple_counter == 7) { temp_orig7 = _orig[x][y]; couple[_temp_x][_temp_y] = 7; couple[x][y] = 7; }
                        if (couple_counter == 8) { temp_orig8 = _orig[x][y]; couple[_temp_x][_temp_y] = 8; couple[x][y] = 8; }

                        if (couple[i][j] == 1) printf("   %d", temp_orig1);
                        if (couple[i][j] == 2) printf("   %d", temp_orig2);
                        if (couple[i][j] == 3) printf("   %d", temp_orig3);
                        if (couple[i][j] == 4) printf("   %d", temp_orig4);
                        if (couple[i][j] == 5) printf("   %d", temp_orig5);
                        if (couple[i][j] == 6) printf("   %d", temp_orig6);
                        if (couple[i][j] == 7) printf("   %d", temp_orig7);
                        if (couple[i][j] == 8) printf("   %d", temp_orig8);
                    }
                    couple[x][y] = 0;
                }
                printf("\n\n");
            }
            getch(); system("cls");
            couple_counter -= 1;
        }

        if ((_temp_x != x) || (_temp_y != y)) {
            couple_counter += 1;
            _couple = 1;
            printf("\n\n\n\n\n\n\n\n\n\n");
            for (i = 0; i < I; i++) {
                printf("\t\t\t\t\t\t");
                for (j = 0; j < J; j++) {
                    if (_temp[i][j] == 0) printf("   *");
                    else {
                        if (couple_counter == 1) { temp_orig1 = _orig[x][y]; couple[_temp_x][_temp_y] = 1; couple[x][y] = 1; }
                        if (couple_counter == 2) { temp_orig2 = _orig[x][y]; couple[_temp_x][_temp_y] = 2; couple[x][y] = 2; }
                        if (couple_counter == 3) { temp_orig3 = _orig[x][y]; couple[_temp_x][_temp_y] = 3; couple[x][y] = 3; }
                        if (couple_counter == 4) { temp_orig4 = _orig[x][y]; couple[_temp_x][_temp_y] = 4; couple[x][y] = 4; }
                        if (couple_counter == 5) { temp_orig5 = _orig[x][y]; couple[_temp_x][_temp_y] = 5; couple[x][y] = 5; }
                        if (couple_counter == 6) { temp_orig6 = _orig[x][y]; couple[_temp_x][_temp_y] = 6; couple[x][y] = 6; }
                        if (couple_counter == 7) { temp_orig7 = _orig[x][y]; couple[_temp_x][_temp_y] = 7; couple[x][y] = 7; }
                        if (couple_counter == 8) { temp_orig8 = _orig[x][y]; couple[_temp_x][_temp_y] = 8; couple[x][y] = 8; }

                        if (couple[i][j] == 1) printf("   %d", temp_orig1);
                        if (couple[i][j] == 2) printf("   %d", temp_orig2);
                        if (couple[i][j] == 3) printf("   %d", temp_orig3);
                        if (couple[i][j] == 4) printf("   %d", temp_orig4);
                        if (couple[i][j] == 5) printf("   %d", temp_orig5);
                        if (couple[i][j] == 6) printf("   %d", temp_orig6);
                        if (couple[i][j] == 7) printf("   %d", temp_orig7);
                        if (couple[i][j] == 8) printf("   %d", temp_orig8);
                    }
                }
                printf("\n\n");
            }
        }


        if (_couple == 1) {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("\t\t\t\t\t\t\tGREAT JOB!!");
            Sleep(1000);system("cls");
        } else {getch(); system("cls");}
    }

    // keep matched ones visible
    for (i = 0; i < I; i++) {
        for (j = 0; j < J; j++) {
            if (couple[i][j] != 0) _temp[i][j] = 1;
        }
    }

    // If mismatch, flip back
    if ((counter > 1) && (_orig[_temp_x][_temp_y] != _orig[x][y])) {
        _couple = 0;
        printf("\n\n\n\n\n\n\n\n\n\n");
        for (i = 0; i < I; i++) {
            printf("\t\t\t\t\t\t");
            for (j = 0; j < J; j++) {
                if (couple[i][j] == 0) { _temp[i][j] = 0; printf("   *"); }
                else { printf("   %d", _orig[i][j]); }
            }
            printf("\n\n");
        }
        _temp[_temp_x][_temp_y] = 0;
        _temp[x][y] = 0;
        getch(); system("cls");
    }

    if (counter > 1) counter = 0;

    // Check win
    end = 1;
    for (i = 0; i < I; i++) {
        for (j = 0; j < J; j++) {
            if (couple[i][j] == 0) { end = 0; break; }
        }
        if (!end) break;
    }
}

int main(void)
{
    board();
    while (begin == 1) {
        Input();
        Output();
        if (end == 1) {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("\t\t\t\t\t\t!!!! CONGRATULATIONS !!!!\n");
            printf("\n\t\t\t\t\t\t   !!YOU WON THE GAME!!\n");
            getch(); system("cls");
            begin = 0;
        }
    }
    return 0;
}

