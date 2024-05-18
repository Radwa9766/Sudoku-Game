#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <MMsystem.h>

void loadingBar()
{
    // 0 - black background,
    // A - Green Foreground
    system("color 0A");

    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;

    printf("\n\n\n\n");
    printf("\n\n\n\n\n\n\t\t\t\t\t"
            "\t\tLoading...\n\n");
    printf("\t\t\t\t\t\t");

    // Print initial loading bar
    for (int i = 0; i < 26; i++)
        printf("%c", a);

    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t\t");

    // Print loading bar progress
    for (int i = 0; i < 26; i++) {
        printf("%c", b);
        Sleep(150);
    }
}

void introductiontogame(void)
{
    system("cls");
    printf("\n\n\n");
    printf("\033[31m");
    printf("\t\t\t\t\t\tHELLO IN SODUKO GAME\n\n\n");
    printf("\033[0m");
    printf("\033[32m let me show you the Rules of the game Before you start\n\n");
    printf("\033[35m 1- the game consists of 9 cells in each row and column\n");
    printf("\033[35m 2- You must enter a number that does not exist in the same row and column from 1 to 9\n");
    printf("\033[35m 3- Each row and col is from 0 to 8\n\n");
    printf("\033[0m");
    PlaySound(TEXT("E:\\EMBEDDED FILES\\soduko Project\\Sudoku game 2\\Soduku Game\\music.wav"),NULL,SND_SYNC);
    system("pause");
}
void Print_soduko(int orig[][9],int s1,int user[][9],int s2)
{
    system("cls");
    int i,j;
    for(i=0; i<s1; i++)
    {
        printf(" ");
        for(j=0; j<s1; j++)
        {
            if(i==0)
            {
                if(i==0 && j==0)
                {
                    printf("\033[34m    0 1 2   3 4 5   6 7 8\n");
                    printf("\033[32m  -------------------------\n");
                    printf("\033[0m");
                    printf(" ");
                }
            }

            if((i==3 || i==6) && j==0 )
            {
                printf("\033[33m  -------------------------\n");
                printf("\033[0m");
                printf(" ");
            }
            if(j==0)
            {
                printf("\033[34m%d ",i);
                printf("\033[0m");
                printf("\033[32m| ");
                printf("\033[0m");
            }
            if(orig[i][j]==0 && user[i][j]==0)
            {
                printf("  ");
                if(j==2 || j==5 )
                {
                    printf("\033[33m| ");
                    printf("\033[0m");
                }
            }
            else if (orig[i][j]==0 && user[i][j]!=0)
            {
                printf("\033[36m%d ",user[i][j]);
                printf("\033[0m");
                if(j==2 || j==5 )
                {
                    printf("\033[33m| ");
                    printf("\033[0m");
                }
            }
            else if(orig[i][j]!=0)
            {


                printf("\033[31m%d ",user[i][j]);
                printf("\033[0m");
                if(j==2 || j==5 )
                {
                    printf("\033[33m| ");
                    printf("\033[0m");
                }
            }
        }
        printf("\033[32m|");
        printf("\033[0m");
        printf("\n");

    }
    printf(" ");
    printf("\033[32m  -------------------------\n");
    printf("\033[0m");

}

int take_number(int *pnum)
{
    int flag=0;
    {
        while(flag==0)
        {
            printf("\033[36mNumber-->");
            printf("\033[0m");
            fflush(stdin);
            scanf("%d",pnum);
            if(*pnum>9 || *pnum <1 )
            {
                printf("\033[31munvalid number, please enter a number from 1 to 9\n");
                printf("\033[0m");

            }
            else
            {
                flag=1;
            }
        }
    }
    return 1;
}
int take_Row(int*pn)
{
    int flag=0;


    while(flag==0)
    {
        printf("\033[36mthe row location-->");
        printf("\033[0m");
        fflush(stdin);
        scanf("%d",pn);
        if(*pn>8 || *pn <0 )
        {
            printf("\033[31munvalid location, please enter a valid row number from 0 to 8\n");
            printf("\033[0m");
        }
        else
        {
            flag=1;
        }
    }
    return 1;
}
int take_col(int*pn)
{
    int flag=0;
    while(flag==0)
    {
        printf("\033[36mThe Column location-->");
        printf("\033[0m");
        fflush(stdin);
        scanf("%d",pn);
        if(*pn>8 || *pn <0 )
        {
            printf("\033[31munvalid location, please enter a valid column number from 0 to 8\n");
            printf("\033[0m");

        }
        else
        {
            flag=1;
        }
    }
    return 1;
}
int set_number(int orig[][9],int s1,int user[][9],int s2,int row,int col,int n)
{
    int i,j,flag=0,f1;
    if(orig[row][col]!=0)
    {
        return 0;
    }
    for(i=0; i<s1; i++)
    {
        for (j=0; j<s1; j++)
        {
            if(i==row && n==user[i][j])
            {
                flag++;
            }
            if(j==col && n==user[i][j])
            {
                flag++;
            }
        }
    }
    if(flag==0)
    {
        user[row][col]=n;
        return 1;
    }
    else
    {
        return 2;
    }
}
int check_soduko(int user[][9],int sol[][9],int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for (j=0; j<size; j++)
        {
            if(user[i][j]!=sol[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}
void soduko_game(int orig[][9],int s1,int user[][9],int s2,int sol[][9])
{
    int flag=0,f1=0,r=-1,r2=0;
    int n,row,col;
    loadingBar();
    introductiontogame();
    while(r2!=1)
    {
        Print_soduko(orig,9,user,9);
        take_number(&n);
        take_Row(&row);
        take_col(&col);
        r=set_number(orig,s1,user,s2,row,col,n);
        if(r==0)
        {
            printf("\033[31mUnvalid location,please press Enter to try again\n");
            printf("\033[0m");
            fflush(stdin);
            scanf("%c",&f1);
        }
        else if(r==2)
        {
            printf("\033[31mThere is a same number in the same row or column\n");
            printf("\033[31mplease press Enter to try again\n");
            printf("\033[0m");
            fflush(stdin);
            scanf("%c",&f1);
        }
        r2= check_soduko( user,sol,9);
    }
    Print_soduko(orig,9,user,9);
    printf("\n\n");
    printf("\033[33m\t\t\tCONGRATULATIONS");
    printf("\033[0m");
    printf("\n\n");

}



