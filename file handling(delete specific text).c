#include <stdio.h>
#include<string.h>
int countLines(FILE *fp)
{
  int c=0;
  char buf[100];
  while(!feof(fp))
  {
    fgets(buf,60,fp);
    c++;
  }
return c;
}
void print(FILE *fp,int l)
{
  int c=0;
  char buf[100];
  while(!feof(fp))
  {
    fgets(buf,60,fp);
    c++;
    if(c!=l)
    printf("%s",buf);
  }
}
int main()
{	
  	FILE *fp,*fp1;
  	char x[100];
   	scanf("%s",x);
    fp=fopen(x,"r");
  	fp1=fopen(x,"r");
    int tc,l,fc=countLines(fp1),c=0;
    scanf("%d",&tc);
    while(tc--)
    {
      	scanf("%d",&l);
      	c++;
      	if(l>=fc)
        {
          printf("\n-1\n");
          print(fp,c);
        }
      else
		print(fp,l);    
    }
    return 0;
}
