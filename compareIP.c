#include<stdio.h>
#include<stdlib.h>

int len(char* a)
{
  int i=0;
  while(a[i]!='\0')
  {
    i++;
  }

  return i;

}

void ipPartition( char* ip1, int len, int*ip )
{
  int i=0;
  int j=0;
  int ipPart=0;
  while(i<len)
  {
      if(ip1[i]!='.')
      {
        ipPart=ipPart*10 + (ip1[i]-'0');
      }
      else
      {
        ip[j++]=ipPart;
        ipPart=0;
      }
      i++;
  }
  ip[j++]=ipPart;

}
int compare( char* ip1, char* ip2)
{
  int len1=len(ip1);
  int len2=len(ip2);

  int i1[4];
  int i2[4];

  ipPartition(ip1,len1,i1);
  ipPartition(ip2,len2,i2);


  int done=0;
  int flag;
  int i=0;
  while(i<4 && !done)
  {
    if(i1[i]==i2[i])
    {
      i++;
      flag=0;
    }
    else if(i1[i]>i2[i])
    {
      done=1;
      flag= 1;
    }
    else
    {
      done=1;
      flag= -1;
    }
  }
  return flag;
}

int main()
{
  char* ip1;
  char* ip2;
  ip1=(char *)malloc(sizeof(char)*15);
  ip2=(char *)malloc(sizeof(char)*15);

  printf("Enter the first IP Address: ");
  scanf(" %s",ip1);
  printf("Enter the second IP Address: ");
  scanf(" %s",ip2);

  int flag=compare(ip1,ip2);

  printf("%d \n",flag);
  return 0;
}
