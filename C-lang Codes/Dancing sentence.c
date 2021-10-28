#include<stdio.h>
#include<string.h>
int main(){
char a[100];
char b[28]="abcdefghijklmnopqrstuvwxyz";
char c[28]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int x,i,g;
g=0;
scanf("\n%[^\n]",a);
for(x=0;x<100;x++){
for(i=0;i<27;i++)
if(g%2==0){
if((a[x]==b[i])|| (a[x]==c[i])){
a[x]=c[i];
}
}
else{
if((a[x]==b[i]||(a[x]==c[i])){
a[x]=b[i];
}
}
if(a[x]!=''){
g++;
}
}
printf("%s\n",a);
return 0;
}
