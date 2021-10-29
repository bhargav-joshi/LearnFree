#include<stdio.h>
int main(){
int t;
scanf("%d",&t);
  while(t--){
  int n,k;
    scanf("%d%d",&k,&n);
    int a[n];
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
      
    }
    int min=a[0],max=a[0];
    for(int i=0;i<n;i++){
    if(min>a[i])
      min=a[i];
      if(max<a[i])
        max=a[i];
    }
    if(max-min>=k){
    int avg=(min+max)/2;
      for(int i=0;i<n;i++){
      if(a[i]<=avg)
        a[i]+=k;
        else
          a[i]-=k;
      }
      min=a[0];
      max=a[0];
      for(int i=0;i<n;i++){
      if(min>a[i])
        min=a[i];
      if(max<a[i])
        max=a[i];
    }
    }
    printf("%d\n",max-min);
  }
  return 0;
  }
