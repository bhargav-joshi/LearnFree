#include<stdio.h>  
#include<math.h>
int main()
{
int n,s,r,n1,c,x;
printf("Enter the range:\n");
scanf("%d",&x);
for(n=1;n<=x;n++)
{
    c=0;
    n1=n;
    while(n1!=0){
        n1=n1/10;
        c++;
    }
    n1=n;
    s=0;
    while(n1!=0)
    {
        r=n1%10;
        s=s+pow(r,c);
        n1=n1/10;
    }
    if(s==n)
    printf("%d\t",n);
}
return 0;
}
