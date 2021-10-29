#include<stdio.h>
int main(){
char str[100];
  int arr[100],i,j,min,t,len,k,count,x;
  scanf("%d"'&t);
        while(t--){
        scanf("%s",&str);
          len=strlen(str);
          min=1;
          k=0;
          for(i=0;i<=len;i++)
            arr[i]=0;
          count=0;
          for(i=0;i<len;i++){
          if(str[i]=='I'){
          for(j=i;j>=k;j--){
          arr[j]=min;
            min++;
            count++;
          }
            k=i+1;
          }
          }
          count=min+len-count;
          for(i=0;i<=len;i++){
          if(arr[i]==0){
          arr[i]=count;
            count--;
          }
          }
          for(i=0;i<=len;i++)
            printf("%d",arr[i]);
          printf("\n");
        }
        return 0;
}
