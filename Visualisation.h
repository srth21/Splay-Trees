#include<stdio.h>
#include<stdlib.h>
/*
  Visualisation.h is used to create a PNG Image of the Tree.
  A speacial Library called GraphViz is used for the same.


*/

typedef struct bTree
{
    int dispnum;
    char siteName[120];
    char ipAddress[15];
    struct bTree *left;
    struct bTree *right;
    int noOfVisits;
}treeNode;

typedef struct queueNode
{
    treeNode *data;
    struct queueNode *next;
}queue;

void enqueue(treeNode*, queue**, queue**);
treeNode* dequeue(queue**, queue**);
void displayTree(treeNode *root);
void preorderVisual(FILE *fileOp,treeNode *t);

void displayTree(treeNode *root)
{
    if (root == NULL)
    {
        printf("\nTree Empty !");
        return;
    }

    else
    {
        FILE *fileOp = fopen("temp.dot", "w");

        fprintf(fileOp, "digraph BST\n{\n");
        //Creating the Label at the Bottom
        fprintf(fileOp, "label = \"IP Network\"\n");

        // Format to write to temp.dot file , Writing root with red color
        fprintf(fileOp, "%d [label=\"%s\\n%s\\nVisits=%d\", shape = box, color = \"#ff0000\"];\n", root->dispnum,root->ipAddress,root->siteName,root->noOfVisits);

        int nullCount = 0;

        // Writing all left children of root in Temp.dot file
        preorderVisual(fileOp,root->left);

        // Writing all right children of root in Temp.dot file
        preorderVisual(fileOp,root->right);

        // Creating the pointers to the front and the rear of the Queue
        queue *front, *rear;
        front = rear = NULL;

        //Adding the Root to the Queue
        enqueue(root, &front, &rear);

        while(front != NULL)
        {
            treeNode *current = dequeue(&front, &rear);

            /*
            Writing the Leaf Nodes to the File.
            Checking if there are no children to the node.
            The leaf nodes have a blue border
            */
            if ((!current->left) && (!current->right) && (current!=root))
            {
                fprintf(fileOp, "%d [color = \"blue\"];", current->dispnum);
            }

            /* Checking if the Left Child Exists
               If it exists then we are adding it to the queue
               for further steps
            */
            if (current->left)
            {
                fprintf(fileOp, "%d -> %d;\n", current->dispnum, current->left->dispnum);
                enqueue(current->left, &front, &rear);
            }

            else
            {
                nullCount++;
                fprintf(fileOp, "NULL%d [shape=point];\n %d -> NULL%d;\n", nullCount, current->dispnum , nullCount);
            }

            /* Checking if the Right Child Exists
               If it exists then we are adding it to the queue
               for further steps
            */
            if (current->right)
            {
                fprintf(fileOp, "%d -> %d;\n", current->dispnum, current->right->dispnum);
                enqueue(current->right, &front, &rear);
            }

            else
            {
                nullCount++;
                fprintf(fileOp, "NULL%d [shape=point];\n %d -> NULL%d;\n", nullCount, current->dispnum, nullCount);
            }
        }

        fprintf(fileOp, "\n}");
        fclose(fileOp);

        system("dot -Tpng temp.dot -o BST.png");
        system("BST.png");
    }
}

/* Function to add a node to the Queue */
void enqueue(treeNode *node, queue **first, queue **rear)
{
    queue *link = (queue*)malloc(sizeof(queue));
    link->data = node;
    link->next = NULL;

    if (*first == NULL)
    {
        *first = *rear = link;
    }

    else
    {
        (*rear)->next = link;
        (*rear) = link;
    }
}

/* Function to delete a node from the Queue */

treeNode* dequeue(queue **first, queue **rear)
{
    queue *temp;
    treeNode *retVal;
    temp = *first;

    if (temp == NULL)
    {
        return NULL;
    }

    else
    {
        retVal = temp->data;

        if ((*first) == (*rear))
        {
            (*first) = (*rear) = NULL;
        }

        else
        {
            (*first) = temp->next;
        }

        free(temp);
        return retVal;
    }
}

//preorder traversal
void preorderVisual(FILE *fileOp,treeNode *t)
  {
    if(t!=NULL)
    {
      fprintf(fileOp, "%d [label=\"%s\\n%s\\nVisits=%d\"];\n", t->dispnum,t->ipAddress,t->siteName,t->noOfVisits);
      preorderVisual(fileOp,t->left);
      preorderVisual(fileOp,t->right);
    }
  }
