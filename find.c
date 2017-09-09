#include<stdio.h>
#include<stdlib.h>
#include"splayTree.c"

void find( Node* root, char* ipAddress)
{
  Node* temp;
  temp=root;
  int found=0;

  while(!found)
  {
    int comp=compare(temp->ipAddress,ipAddress);
    if(comp==0)
    {
      printNodeDetails(temp);
      temp->noOfVisits=temp->noOfVisits+1;
      found=1;
    }
    else if(comp>0)
    {
      temp=temp->left;
      //printNodeDetails(temp);
    }
    else
    {
      temp=temp->right;
      //printNodeDetails(temp);
    }
  }
}
