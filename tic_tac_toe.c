#include<stdio.h>

char entry[10], one, two, back;
int i=1,j;

void input()                     
{
    //taking choice input for player 1 and assigning opposite to player two
    printf("Player 1 enter your choice 'X' or 'O' : ");
    scanf(" %c",&one);
    
    if(one=='X')
        two='O';
    else
        two='X';
}

void board()                      
{
    //printing the board
    printf("\n");
    printf("\t  %c  |  %c  |  %c \n", entry[1], entry[2], entry[3]);
    printf("\t_____|_____|_____\n");
    printf("\t  %c  |  %c  |  %c \n", entry[4], entry[5], entry[6]);
    printf("\t_____|_____|_____\n");
    printf("\t  %c  |  %c  |  %c \n", entry[7], entry[8], entry[9]);
    printf("\t     |     |     \n");
}

char result()                      
{
    //checking for the winner
    if((entry[1]=='X'&&entry[2]=='X'&&entry[3]=='X')||(entry[4]=='X'&&entry[5]=='X'&&entry[6]=='X')||(entry[7]=='X'&&entry[8]=='X'&&entry[9]=='X')||(entry[1]=='X'&&entry[4]=='X'&&entry[7]=='X')||(entry[2]=='X'&&entry[5]=='X'&&entry[8]=='X')||(entry[3]=='X'&&entry[6]=='X'&&entry[9]=='X')||(entry[1]=='X'&&entry[5]=='X'&&entry[9]=='X')||(entry[3]=='X'&&entry[5]=='X'&&entry[7]=='X'))
    {
        if(j%2 != 0)
            printf("Player 1 is the winner!!\n");
        else
            printf("Player 2 is the winner!!\n");
        
        back='t';
        return back;
    }
    
    else if((entry[1]=='O'&&entry[2]=='O'&&entry[3]=='O')||(entry[4]=='O'&&entry[5]=='O'&&entry[6]=='O')||(entry[7]=='O'&&entry[8]=='O'&&entry[9]=='O')||(entry[1]=='O'&&entry[4]=='O'&&entry[7]=='O')||(entry[2]=='O'&&entry[5]=='O'&&entry[8]=='O')||(entry[3]=='O'&&entry[6]=='O'&&entry[9]=='O')||(entry[1]=='O'&&entry[5]=='O'&&entry[9]=='O')||(entry[3]=='O'&&entry[5]=='O'&&entry[7]=='O'))
    {
        if(j%2 != 0)
            printf("Player 1 is the winner!!\n");
        else
            printf("Player 2 is the winner!!\n");
        
        back='t'; 
        return back;
    }   
}

void main()
{
    int again=1,k,pain=1;

    input();

    printf("Pattern of the board is :-\n");      //printing the slot numbers
    printf("\t  1  |  2  |  3  \n");
    printf("\t_____|_____|_____\n");
    printf("\t  4  |  5  |  6  \n");
    printf("\t_____|_____|_____\n");
    printf("\t  7  |  8  |  9  \n");
    printf("\t     |     |     \n");
    
    do
    {
        back='z';
        for(k=0; k<10; k++)                       //clearing the board 
            entry[k]=' ';
        
        for(j=1; j<10; j++)
        {
            if(j%2!=0)                            //taking input for the game itself
            {
                while(pain==1)
                {
                    printf("Player 1 enter your choice : ");                          //player 1 input
                    scanf("%d",&i);
                    if(entry[i]==' ')
                        {
                            entry[i]=one;
                            break;
                        }
                    else 
                        printf("an entry is already made in the slot, try again \n");   //invalid entry warning
                }

                board();
                result();
                if(back=='t')
                    break;
            }
            if(j%2==0)
            {
                while(pain==1)
                {
                    printf("Player 2 enter your choice : ");                           //player 2 input
                    scanf("%d",&i);
                    if(entry[i]==' ')
                        {
                            entry[i]=two;
                            break;
                        }
                    else 
                        printf("an entry is already made in the slot, try again\n");   //invalid entry warning     
                }
                board();
                result();
                if(back=='t')
                    break;
            }
        }
        if(j==10)
            printf("Its a draw\n");
        
        printf("Press 1 to play again and 0 to stop : ");
        scanf("%d",&again);
    }while(again==1);
}