#include<stdio.h>
int main(){
int n;
scanf("%d",&n);
while(n--){
int k;
scanf("%d",&k);
int a[k],i,j,t,c=0,m=0;
for(i=0;i<k;i++){
scanf("%d",&a[i]);
}
i=0,j=k-1;
while(i<j){
if(a[i]<=a[j]){
t=a[i];
i++;
while(a[i]<a[j]&&a[i]<t){
c+=t-a[i];
i++;
}
}
else{
t=a[j];
j--;
while(a[j]<a[i] && a[j]<t){
c+=t-a[j];
j--;
}
}
if(c>m)
m=c;
}
printf("%d\n",m);
}
return 0;
}
