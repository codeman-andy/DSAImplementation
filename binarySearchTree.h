#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#define __cmp_op_min <
#define __cmp_op_max >

#define __cmp(op, x, y)	((x) __cmp_op_##op (y) ? (x) : (y))

#define min(x, y)	__cmp(min, x, y)
#define max(x, y)	__cmp(max, x, y)


typedef struct BSTreeNode {
  void* data;
  struct BSTreeNode* left;
  struct BSTreeNode* right;
} BSTreeNode;

/*
*data: Data to be stored in the node

Returns a pointer to the newly-created BSTree Node.
*/
extern BSTreeNode* createBSTreeNode(void* data);

/*
**node: Address of the root-node of a BSTree
*data: Data to be stored in the node

Initializes a new BSTree Node on the heap to store the *data in, and adds it to the BSTree.
The address of the root-node is passed in case the BSTree is initially empty.
*/
extern void insertBSTreeNode(BSTreeNode** node, void* data);

/*
*node: Root-node of a BSTree
*data: Data stored at the node

Recursively looks for the node storing the *data requested.
*/
extern BSTreeNode* searchBSTree(BSTreeNode* node, void* data);

/*
*node: Root-node of a BSTree

Recursively looks for the minimum value stored in a BSTree.
*/
extern BSTreeNode* FindMin(BSTreeNode* node);

/*
*node: Root-node of a BSTree

Recursively looks for the maximum value stored in a BSTree.
*/
extern BSTreeNode* FindMax(BSTreeNode* node);

/*
*node: Root-node of a BSTree
*data: Data stored at the node to be deleted

Looks for the node in a BSTree storing the *data requested.
If it finds it, it then removes it, adequately replacing its place on the tree with one of its neighbouring nodes in case it is not a leaf.
*/
extern int deleteBSTNode(BSTreeNode** node, void* data);

/*
*node: Root-node of a BSTree

Returns the height of the BSTree.
*/
extern int FindHeight(BSTreeNode* root);

/*
**root: Address of the root-node of a BSTree

Wipes out a BSTree from memory.
*/
extern int killBSTree(BSTreeNode** root);

/*
*node: Root-node of a BSTree

Goes level-by-level on a BSTree and prints the values on the nodes, from leftmost to rightmost node.
*/
extern void printLevelOrder(BSTreeNode* rootNode);

/*
*node: Root-node of a BSTree
*queriedValue: Valid value in a BSTree

Returns the node containing the closest greater value.
*/
extern BSTreeNode* GetSuccessor(BSTreeNode* rootNode, void* queriedValue);

/*
*node: Root-node of a BSTree
*queriedValue: Valid value in the BSTree

Returns the node containing the closest lesser value.
*/
extern BSTreeNode* GetPredecessor(BSTreeNode* rootNode, void* queriedValue);

#endif