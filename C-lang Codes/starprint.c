#include<stdio.h>
#include<conio.h>
int main()
{
    int starTot, rowTot, i, j, starInOneRow, rem;
    printf("How many stars you want to print ? ");
    scanf("%d", &starTot);
    printf("Upto how many rows ? ");
    scanf("%d", &rowTot);
    starInOneRow = starTot/rowTot;
    rem = starTot%rowTot;
    printf("\n");
    i=0;
    while(i<rowTot)
    {
        if(i!=0)
            printf("\n");
        for(j=0; j<starInOneRow; j++)
            printf("* ");
        i++;
    }
    if(rem!=0)
    {
        for(i=0; i<rem; i++)
            printf("* ");
    }
    getch();
    return 0;
}
