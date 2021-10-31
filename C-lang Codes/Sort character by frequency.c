#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 256
int cmpfunc(const char a[], cost char b[]);
void frequencysort(char s[]);
struct freq{
int val;
  char c;
  
};
int main(){
char s[30];
  scanf("%s",&s);
  frequencysort(s);
  printf("%s",s);
  return 0;
}
int cmpfunc(const char a[], const char b[]){
int l=((struct freq*)a->)val;
  int r=((struct freq*)b->)val;
return r-l;
}
void frequencysort(char s[]){
struct freq res[MAX]={0};
  int len=strlen(s);
  for(int i=0;i<len;i++){
  if(res[s[i]].c!=s[i]){
  res[s[i]].c=s[i];
    res[s[i]].val++;
  }
    else
      res[s[i]].val++;
  }
  qsort(res,MAX,sizeof(struct freq),cmpfunc);
  int index=0;
  for(int i=0;i<MAX;i++){
  while(res[i].val!=0){
  s[index]=res[i].c;
    res[i].val--;
    index++;
  }
  }
}
