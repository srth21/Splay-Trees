/* Documentation
   Line#00 to Line#00 : Include Statements used for including libraries
   Line#00 to Line#00 : Structure Definition
   Line#00 to Line#00 : Right Rotation Function
   Line#00 to Line#00 : Left Rotation Function
   Line#00 to Line#00 : Splay Function
   Line#00 to Line#00 : Print Node Details Function
   Line#00 to Line#00 : Insert into a Tree Function
   Line#00 to Line#00 : Preorder Function
   Line#00 to Line#00 : Insert into Splay Tree Function
   Line#00 to Line#00 : Search Function
   Line#00 to Line#00 : Main Function
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*
  A structure to store the IP Address of a website, the name of the
  website, two pointers to the left and right nodes in the Tree,
  and the number of visits made to the website durting Search.
*/

struct node
{
  char siteName[120]; // name of the website
  char ipAddress[12]; // ip address of the website
  struct node *left; // left node address
  struct node *right; // right node address
  int noOfVisits; // no of visits to the page
};

typedef struct node Node; // typedefining the struct ipAddress

// Start Of Right Rotate Function

/* Function to perform right rotation about a node x
   Input <- a node about which right rotation has to be performed
   Output <- the root node of the subtree after the right rotation
   has been performed
*/

Node* rightRotation( Node* x)
{
  Node *y;
  y = (x->left);
  (x->left) = (y->right);
  (y->right) = x;
  return y;
}

// End of Right Rotate Function

// Start of Left Rotate Function

/* Function to perform left rotation about a node x
   Input <- a node about which left rotation has to be performed
   Output <- the root node of the subtree after the left rotation
   has been performed  */

Node* leftRotation( Node* x)
{
  Node *y;
  y = (x->right);
  (x->right) = (y->left);
  (y->left) = x;
  return y;
}

// End of Left Rotate Function

// Start of Splay Function

/* The Splay function performs one of the two tasks on the
   Tree and a given key value.
   1. If the key value is present in the tree, then it splays it to
   the root.
   2. If the key value is not present in the tree, then the last
   accessed node is splayed to the root of the tree.
   Input <- A pointer to the Root of the Tree and the Key value
   Output <- The new root after modification
*/

Node* splay( Node* root, char ipAddress[12] )
{
  /*
    There are four cases
    1.The tree is empty
    2.The key is present at the root
    3.The key is present in the left subtree.
    4.The key is present in the right subtree.
  */

  // Case 1 or Case 2 <- Return the root itself

  if(root==NULL || (strcmp(root->ipAddress,ipAddress)==0))

  {

      return root;
  }

  // Case 3 <- the key might be present in the left subtree of the root

  if( strcmp(ipAddress,root->ipAddress)<=0 )
  {

    /* Two cases
       1.The key might not be present <- happens is the left subtree is null
       2.The key might be present
    */

    if( root->left==NULL)
    {
      /* Key not present.
         Thus we must return the last accessed non Null node which is the root
      */

      return root;
    }

    /* When the key is present we have two conditions
       1. Zig Zig Condition : when the parent and the key are both left children
       2. Zig Zag Condition : when the parent is the left child and the key
          is the right child.
    */

    // Start of Zig Zig Condition

    if( strcmp(root->left->ipAddress,ipAddress)>=0 )
    {
      /* Zig Zig Condition
         We need to get the key at root->left->left recursively
      */

      root->left->left=splay(root->left->left,ipAddress);

      /* Now that we have the key as the left grandchild of the root
         we need to get it up to the root by performing two right rotations
      */

      root=rightRotation(root);
      // the key is now the left child of the root

      if(root->left==NULL)
      {
        // the left child is null and right rotation is not possible
        return root;
      }

      root=rightRotation(root);

      // the key is now the root

      return root;
    }
    // End of Zig Zig Condition

    // Start of Zig Zag Condition

    else
    {
      /* Zig Zag Condition
         We need to recursively get the key to root->left->right
      */

      root->left->right=splay(root->left->right,ipAddress);

      /* The key is now at root->left->right
         We ensure that its not null and then rotate it */

      if( root->left->right!=NULL )
      {
        // We need to perform left rotation about root->left
        root->left=leftRotation(root->left);

      }
        /*   key is now the left child of the root
             now we perform right rotation and make it the root
        */
        if(root->left==NULL)
        {
          // the left child is null and right rotation is not possible
          return root;
        }

        root=rightRotation(root);

        return root;
        }
      // End of Zig Zag Condition

    // End of Case 3
  }

    /* Start of Case 4
       Case 4 : The key might be present in the right subtree of the root
    */

    if(strcmp(root->ipAddress,ipAddress) <= 0)
    {
      /* Two cases
         1.The key might not be present <- happens is the right subtree is null
         2.The key might be present
      */

      if( root->right==NULL)
      {
        /* Key not present.
           Thus we must return the last accessed non Null node which is the root
        */

        return root;
      }

      /* When the key is present we have two conditions
         1. Zag Zig Condition : when the parent is the right child and
            the key is the  left child.
         2. Zag Zag Condition : when the parent and the key are right children.
      */

      // Start of Zag Zig Condition

      if( strcmp(root->right->ipAddress,ipAddress)>=0 )
      {
        /* Zag Zig Condition
           We need to get the key at root->right->left recursively
        */

        root->right->left=splay(root->right->left,ipAddress);

        /* Now that we have the key as the grandchild of the root
           we need to get it up to the root by performing two rotate rotations
        */

        // We need to check if it exists or not
        if(root->right->left!=NULL)
        {
          // If exists then perform right rotation

          root->right=rightRotation(root->right);

        }

        // the key is now the right child of the root

        if(root->right==NULL)
        {
          // the right child is null and left rotation is not possible
          return root;
        }

        root=leftRotation(root);

        // the key is now the root

        return root;
      }
      // End of Zag Zig Condition

      // Start of Zag Zag Condition

      else if( strcmp(root->right->ipAddress,ipAddress)<=0)
      {
        /* Zag Zag Condition
           We need to recursively get the key to root->right->right
        */

        root->right->right=splay(root->right->right,ipAddress);

        // The key is now at root->right->right

          root=leftRotation(root);

          /*   key is now the right child of the root
               now we perform left rotation and make it the root
          */
          if(root->right==NULL)
          {
            // the right child is null and left rotation is not possible
            return root;
          }

          root=leftRotation(root);

          return root;
        }

        // End of Zag Zag Condition

    // End of Case 4

  }
}

// End of Splay Function

// Beginning of Print Node Function

void printNodeDetails( Node* temp)
{
  printf("IP Address is : %s\n",temp->ipAddress);
  printf("Website Name is : %s\n",temp->siteName);
  printf("Number of Visits to the Webpage : %d\n",temp->noOfVisits);
}

//End of Print Node Function

//Beginning of Insert into Tree Function

/* A Function to insert a node into a binary search tree.
   Accepts the root and the node to be inserted.
*/

void insertIntoTree( Node** root, Node* temp)
{
  Node* curr=*root; // The Current Node
  Node* prev; // The Previous Node
  prev=NULL;

  //Iterating through the tree to find the position where temp has to be inserted.

  while(curr!=NULL)
  {
      prev=curr;

      //Start of Case 1
      /* Case 1: Need to traverse to the left when the key value is less than
         key value of the root */
      if(strcmp(curr->ipAddress,temp->ipAddress)>0)
      {
        curr=curr->left;
      }
      //End of Case 1

      // Start of Case 2
      /* Case 2: Need to traverse to the right when the key value is greater than
         key value of the root */
      else if(strcmp(curr->ipAddress,temp->ipAddress)<0)
      {
        curr=curr->right;
      }
      //End of Case 2
  }

  // prev now stores the parent node of temp
  // we need to now find its position

  if(strcmp(temp->ipAddress,prev->ipAddress)>0)
  {
    prev->right=temp;
  }
  else
  {
    prev->left=temp;
  }

}
//End of Insert into Tree Function

//Start of Preorder Function

void preorder(Node* root)
{
   if(root!=NULL)
  {
    printf("IP Address :  %s\n",root->ipAddress);
    printf("WebSite Name :  %s\n",root->siteName);
    printf("Number Of Visits : %d\n",root->noOfVisits);
    printf("\n");
    preorder(root->left);
    preorder(root->right);
  }

}

//End of Preorder Function

// Beginning of Insert into Splay Tree Function

/* A Function to add a new node to the Splay Tree.
   IF the node is already present then it is not added.
   Else it is made the root.
*/

void insertIntoSplayTree( Node** mainRoot, char ipAddress[12], char siteName[120])
{
    /*
      Case 1: Tree is empty -> we just have to allocate memory and attach it
              to the root pointer.
      If tree is not empty we splay the tree with the node to be inserted.
      Case 2 : If not is already present then it becomes the root.
               In this case we dont do anything as it is already present.
      Case 3 : The node is not present and the root is different.
               We insert the new node into the search tree and then splay the tree
               with respect to that node
   */

   // Create a new node to be inserted
    Node* temp;
    //Allot memory
    temp=(Node*)malloc(sizeof(Node));

    //Adding values to the node.
    temp->noOfVisits=0;
    strcpy(temp->ipAddress,ipAddress);
    strcpy(temp->siteName,siteName);
    temp->left=NULL;
    temp->right=NULL;

    Node* root;
    root=(*mainRoot);
   // Start of Case 1
   if(root==NULL)
   {
      // Attach temp to the root
      root=temp;
      //make mainRoot point to root
      *mainRoot=root;
   }
   //End of Case 1
   else
   {
   //splaying the tree with temp
    root=splay(root,ipAddress);

   // Start of Case 2
   if(strcmp(root->ipAddress,ipAddress)==0)
   {
     *mainRoot=root;
   }
   //End of Case 2

   //Start of Case 3
    else
    {
      insertIntoTree(&root,temp);
      root=splay(root,temp->ipAddress);
      *mainRoot=root;
    }
  }
   //End of Case 3
}

// End of Insert Into Splay Tree Function

// Beginning of Search Function

/*
  Search Function searches for the website name and the number of visits
  everytime we call it.
*/

void search( Node** root, char ipAddress[])
{
    /* If we splay the particular ipAddress, then it will be the root if
       the ipAddress is valid */

    Node* pos= *root;
    pos=splay(pos, ipAddress);

    /* pos contains the root of the new tree after splay
       We compare the ipAddress stored in pos with the key
       If they match then the key is present and we display the details
       ELse the key is not valid
    */

    int match=strcmp(pos->ipAddress,ipAddress);
    *root=pos;
    if(match==0)
    {
      //Key Matched, Printing the ddata

      // Increasing the number of Visits for the page
      pos->noOfVisits= pos->noOfVisits + 1;

      printNodeDetails(pos);

    }
    else
    {
         printf("Match Not Found. \n");

    }
}

//End of Search Function

//Start of main Function

int main()
{
  //Creating the Root
  Node *root;
  root=(Node*)malloc(sizeof(Node));
  root=NULL;

  char ipAddress[12];
  char siteName[120];

  int choice;

  while(1)
  {
    printf("1.Insert into Splay Tree.\n");
    printf("2.Search In the Splay Tree.\n");
    printf("3.Exit.\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
              printf("Enter the IP Address: ");
              scanf(" %s",ipAddress);
              printf("Enter the Website Name: ");
              scanf(" %s",siteName);
              insertIntoSplayTree(&root,ipAddress,siteName);
              preorder(root);
              break;
      case 2:
              printf("Enter the Ip Address: ");
              scanf(" %s",ipAddress);
              search(&root,ipAddress);
              preorder(root);
              break;
      case 3: exit(0);
    }

  }

  return 0;
}

//End of Main function
