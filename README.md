# Splay-Trees
Implementation and Visaulisation Of Splay Trees using Data Structures.

Need for the Usage of Splay Trees

“80% of the accesses are made to 20% of the data”. This statement depicts how much amount of data is actually referred to in most cases. Given that this is the case, how can the storage of data be changed such that time required to access that 20% of the data is minimized. This is the basis for the usage of Splay Trees.
A Splay Tree is a Binary Search Tree with an addition property such that the last accessed node is made the root of the tree. This happens in case of both insertion and a search operation. In case of an insertion the last inserted node is made the root. In case of a search the most recently searched element is made the root. 
Splay Trees ensure that the 20% of the data that is accessed frequently is stored close to the root of the tree so that the access to these elements is fast. If an element is accessed now it might be accessed again soon. Or if an element is just added, it might be accessed soon. Splay Trees use this as basis and store the nodes helping this cause.
The operation introduced in these trees to perform this operation is called Splaying. Splaying is the process of bringing a node to the root of the tree by performing suitable rotations to the tree. Depending on where the node is located in the tree, a set of rotations are performed to get it to the root for easier access.
 
SPLAYING

As mentioned above the process of Splaying involves making a given node the root. It involves rotating the nodes in the tree until the desired result is achieved.
For the process of Splaying, two Rotation Operations are used as basis:
Left Rotation: Rotating a node in such a way that                   
    its right child becomes the root and the node 
    becomes the left child of the new root.
Right Rotation: Rotating a node in such a way 
    that its left child become the root and the node 
    becomes the right child of the new root.
Performing these two rotations repeatedly over the nodes of a tree in an order dependant on the position of the node in the tree we get the required result.


What are the possible cases?

Whenever we try to splay a tree with respect to a particular node, there are two possible cases : 
1. The node is not present in the tree.
2. The node is present in the tree.
Case 1: The node is not present in the tree
If the node is not present in the tree then that last Non Null Node accessed will become the root of the tree.
Case 2: The node is present in the tree.
If the node is present in the tree, there are three possible cases:
a. The node is present at the root.
b. The node is present in the lest subtree.
c. The node is present in the right subtree.
If the node is present at the root, then the process of splaying is complete.
If the node is present in the left subtree of the root, there are two possible cases again:
The node is present in the left subtree of the left child
The node is present in the right subtree of the left child.
In both these cases, we need to make the node the grandchild of the root, that is to the position root->left->left in the first case and to position root->left->right in the second case. This is done recursively by splaying the corresponding subtree with respect to the node.
When the node is the grandchild of the root, we perform two Rotation Operations. Two Right Rotations in Case1 and A Left Rotation followed by a Right Rotation in Case2.
This will result in the node becoming the Root of the tree.
If the node is present in the right subtree of the root, there are two possible cases again:
The node is present in the left subtree of the right child
The node is present in the right subtree of the right child.
In both these cases, we need to make the node the grandchild of the root, that is to the position root->right->left in the first case and to position root->right->right in the second case. This is done recursively by splaying the corresponding subtree with respect to the node.
When the node is the grandchild of the root, we perform two Rotation Operations. Two Left Rotations in Case2 and A Right Rotation followed by a Left Rotation in Case1.This will result in the node becoming the Root of the tree.
	
Implementation

In the project, each node of the Splay Tree stores the IP Address of a website, the corresponding Website Name and the Number of Visits made to the Website. The number of visits made to the website is incremented each time the search function is called searching for a website with that particular IP Address. 
The storage in the Splay Tree is done based on the IP Address. 
The display Function for the trees is implemented using a Graphics Library called GraphViz. A PNG Image of the tree is created everytime the user wants to check the status of the tree.

