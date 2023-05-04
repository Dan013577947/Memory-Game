#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define I 4
#define J 4

int i,j,x,y,array[I][J],temp,_temp[I][J],_orig[I][J],end = 0,
_temp_x,_temp_y,couple[I][J],counter = 0,_couple = 0,couple_counter = 0,begin=1,
temp_orig1,temp_orig2,temp_orig3,temp_orig4,
temp_orig5,temp_orig6,temp_orig7,temp_orig8;

void board()
{
    srand(time(NULL));
    for (i = 0;i<I;i++)
    {
        for (j =0;j<J;j++)
        {
            if (i==0) array[i][j] = j+1;
            if (i==1) array[i][j] = j+5;
            if (i==2) array[i][j] = j+1;
            if (i==3) array[i][j] = j+5;
        }
    }

    for (i = 0;i<I;i++)
    {
        for (j = 0;j<J;j++)
        {
            int random_a = rand() %4;
            int random_b = rand() %4;
            temp = array[i][j];
            array[i][j] = array[random_a][random_b];
            array[random_a][random_b] = temp;
        }
    }
    printf("\n\n\n\n\n\n\n\n\n\n");
     for (i = 0;i<I;i++)
    {
        printf("\t\t\t\t\t\t");
        for (j =0;j<J;j++)
        {
            //_orig stores the original shuffled value of each array
            _orig[i][j] = array[i][j];
            printf("    %d", _orig[i][j]);
        }
        printf("\n\n");
    }
    getch();
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n");
     for (i = 0;i<I;i++)
    {
        printf("\t\t\t\t\t\t");
        for (j =0;j<J;j++)
        {
            _temp[i][j] = 0;
            printf("    *");
        }
        printf("\n\n");
    }
    for (i = 0;i<I;i++)
    {
        for (j =0;j<J;j++)
        {
            couple[i][j] = 0;
        }
    }
    getch();
    system("cls");
}

void Input()
{
    printf("What Coodinates Will You Choose? \nEnter Below The X and Y Coordinates\n");
    int *ptr_x = &x;int *ptr_y = &y;
    printf("y: ");scanf("%d", &x);
    printf("x: ");scanf("%d", &y);
    if(counter==0) {_temp_x=x;_temp_y=y;}
    counter+=1;
    getch();system("cls");
}

void Output()
{
    printf("\n\n\n\n\n\n\n\n\n\n");
     for (i = 0;i<I;i++)
    {
        printf("\t\t\t\t\t\t");
        for (j=0;j<J;j++)
        {
            if((i==x)&&(j==y)) _temp[i][j]=1;
            if(couple[i][j]!=0) _temp[i][j]=1;
            if(_temp[i][j] == 0) printf("   *");
            if(_temp[i][j]!=0) printf("   %d", _orig[i][j]);
        }
        printf("\n\n");
    }

    getch();system("cls");

    if ((counter>1)&&(_orig[_temp_x][_temp_y] == _orig[x][y]))
    {
        if((_temp_x==x)&&(_temp_y==y))
        {
            couple_counter+=1;
            _couple=0;
            printf("\n\n\n\n\n\n\n\n\n\n");
            for(i=0;i<I;i++)
            {
                printf("\t\t\t\t\t\t");
                for(j=0;j<J;j++)
                {
                    _temp[x][y]=0;
                    if(_temp[i][j] == 0) printf("   *");
                    if(_temp[i][j]!=0)
                        {

                            if(couple_counter==1) {temp_orig1 = _orig[x][y];couple[_temp_x][_temp_y]=1;
                            couple[x][y]=1;}
                            if(couple_counter==2) {temp_orig2 = _orig[x][y];couple[_temp_x][_temp_y]=2;
                            couple[x][y]=2;}
                            if(couple_counter==3) {temp_orig3 = _orig[x][y];couple[_temp_x][_temp_y]=3;
                            couple[x][y]=3;}
                            if(couple_counter==4) {temp_orig4 = _orig[x][y];couple[_temp_x][_temp_y]=4;
                            couple[x][y]=4;}
                            if(couple_counter==5) {temp_orig5 = _orig[x][y];couple[_temp_x][_temp_y]=5;
                            couple[x][y]=5;}
                            if(couple_counter==6) {temp_orig6 = _orig[x][y];couple[_temp_x][_temp_y]=6;
                            couple[x][y]=6;}
                            if(couple_counter==7) {temp_orig7 = _orig[x][y];couple[_temp_x][_temp_y]=7;
                            couple[x][y]=7;}
                            if(couple_counter==8) {temp_orig8 = _orig[x][y];couple[_temp_x][_temp_y]=8;
                            couple[x][y]=8;}

                            if(couple[i][j]==1) printf("   %d", temp_orig1);
                            if(couple[i][j]==2) printf("   %d", temp_orig2);
                            if(couple[i][j]==3) printf("   %d", temp_orig3);
                            if(couple[i][j]==4) printf("   %d", temp_orig4);
                            if(couple[i][j]==5) printf("   %d", temp_orig5);
                            if(couple[i][j]==6) printf("   %d", temp_orig6);
                            if(couple[i][j]==7) printf("   %d", temp_orig7);
                            if(couple[i][j]==8) printf("   %d", temp_orig8);
                        }
                    couple[x][y]=0;
                }

                printf("\n\n");
            }

            getch();system("cls");

            couple_counter-=1;
        }

        if((_temp_x!=x)||(_temp_y!=y))
        {
            couple_counter+=1;
            _couple=1;
            printf("\n\n\n\n\n\n\n\n\n\n");

            for(i=0;i<I;i++)
            {
                printf("\t\t\t\t\t\t");
                for(j=0;j<J;j++)
                {
                    if(_temp[i][j] == 0) printf("   *");
                    if(_temp[i][j]!=0)
                        {
                            if(couple_counter==1) {temp_orig1 = _orig[x][y];couple[_temp_x][_temp_y]=1;
                            couple[x][y]=1;}
                            if(couple_counter==2) {temp_orig2 = _orig[x][y];couple[_temp_x][_temp_y]=2;
                            couple[x][y]=2;}
                            if(couple_counter==3) {temp_orig3 = _orig[x][y];couple[_temp_x][_temp_y]=3;
                            couple[x][y]=3;}
                            if(couple_counter==4) {temp_orig4 = _orig[x][y];couple[_temp_x][_temp_y]=4;
                            couple[x][y]=4;}
                            if(couple_counter==5) {temp_orig5 = _orig[x][y];couple[_temp_x][_temp_y]=5;
                            couple[x][y]=5;}
                            if(couple_counter==6) {temp_orig6 = _orig[x][y];couple[_temp_x][_temp_y]=6;
                            couple[x][y]=6;}
                            if(couple_counter==7) {temp_orig7 = _orig[x][y];couple[_temp_x][_temp_y]=7;
                            couple[x][y]=7;}
                            if(couple_counter==8) {temp_orig8 = _orig[x][y];couple[_temp_x][_temp_y]=8;
                            couple[x][y]=8;}

                            if(couple[i][j]==1) printf("   %d", temp_orig1);
                            if(couple[i][j]==2) printf("   %d", temp_orig2);
                            if(couple[i][j]==3) printf("   %d", temp_orig3);
                            if(couple[i][j]==4) printf("   %d", temp_orig4);
                            if(couple[i][j]==5) printf("   %d", temp_orig5);
                            if(couple[i][j]==6) printf("   %d", temp_orig6);
                            if(couple[i][j]==7) printf("   %d", temp_orig7);
                            if(couple[i][j]==8) printf("   %d", temp_orig8);
                        }
                }
                printf("\n\n");
            }
        }

        getch();system("cls");
        if(_couple==1) {system("cls");printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");printf("\t\t\t\t\t\t\t");
            printf("GREAT JOB!!");getch();system("cls");}
    }
    for (i = 0;i<I;i++)
    {
        for (j=0;j<J;j++)
        {
            if(couple[i][j]!=0) _temp[i][j]=1;
        }
    }
    if((counter>1)&&(_orig[_temp_x][_temp_y] != _orig[x][y]))
    {
        _couple=0;
        printf("\n\n\n\n\n\n\n\n\n\n");
        for(i=0;i<I;i++)
        {
            printf("\t\t\t\t\t\t");
            for(j=0;j<J;j++)
            {
                if(couple[i][j]==0)
                {_temp[i][j]=0;printf("   *");}

                if(couple[i][j]!=0)
                {printf("   %d", _orig[i][j]);}

            }
            printf("\n\n");
        }
        for(i=0;i<I;i++)
        {
            for(j=0;j<J;j++)
            {
                _temp[_temp_x][_temp_y]=0;
                _temp[x][y]=0;
            }
        }
        getch();system("cls");
    }
    if(counter>1) counter=0;
    for(i=0;i<I;i++)
    {
        for(j=0;j<J;j++)
        {
            if((couple[0][0]!=0)&& (couple[0][1]!=0)&&(couple[0][2]!=0)&&(couple[0][3]!=0)&&
               (couple[1][0]!=0)&& (couple[1][1]!=0)&& (couple[1][2]!=0)&& (couple[1][3]!=0)&&
               (couple[2][0]!=0)&& (couple[2][1]!=0)&& (couple[2][2]!=0)&& (couple[2][3]!=0)&&
               (couple[3][0]!=0)&& (couple[3][1]!=0)&& (couple[3][2]!=0)&& (couple[3][3]!=0)) end=1;
        }
    }
}

int main()
{
    board();
    while(begin==1)
    {
        Input();
        Output();
        if(end==1)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n");printf("\t\t\t\t\t\t");
            printf("!!!! CONGRATULATIONS !!!!\n");
            printf("\n\t\t\t\t\t\t   !!YOU WON THE GAME!!\n");getch();system("cls");
            begin=0;
        }
    }
    return 0;
}
