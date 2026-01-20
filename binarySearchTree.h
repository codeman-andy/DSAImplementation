#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#define __cmp_op_min <
#define __cmp_op_max >

#define __cmp(op, x, y)	((x) __cmp_op_##op (y) ? (x) : (y))

#define min(x, y)	__cmp(min, x, y)
#define max(x, y)	__cmp(max, x, y)


typedef struct BSTreeNode {
  void* data;
  struct BSTreeNode *left;
  struct BSTreeNode *right;
} BSTreeNode;

/*
*data: Pointer to be stored in the dode

Returns a pointer to the newly-created BSTree Node.
*/
extern BSTreeNode* createBSTreeNode(void* data);

/*
**node: Address of the root-node of a BSTree
*data: Pointer to be stored in the dode

Initializes a new BSTree Node on the heap to store the *data in, and adds it to the BSTree.
The address of the root-node is passed in case the BSTree is empty.
*/
extern void insertBSTreeNode(BSTreeNode** node, void* data);

/*
*node: Pointer to the root-node of a BSTree
*data: Pointer stored at the node

Looks for the node storing the *data requested in the BSTree until it finds it.
*/
extern BSTreeNode* searchBSTree(BSTreeNode* node, void* data);

/*
*node: Pointer to the root-node of a BSTree

Looks for the minimum value stored in the BSTree.
*/
extern BSTreeNode* FindMin(BSTreeNode* node);

/*
*node: Pointer to the root-node of a BSTree

Looks for the maximum value stored in the BSTree.
*/
extern BSTreeNode* FindMax(BSTreeNode* node);

/*
*node: Pointer to the root-node of a BSTree
*data: Pointer stored at the node

Looks for the node storing the *data requested in the BSTree and then removes it from the tree if it finds it.
*/
extern int deleteBSTNode(BSTreeNode** node, void* data);

/*
*node: Pointer to the root-node of a BSTree

Returns the height of the BSTree.
*/
extern int FindHeight(BSTreeNode* root);

/*
**root: Address of the root-node of a BSTree

Wipes out the BSTree from memory.
*/
extern int killBSTree(BSTreeNode** root);

/*
*node: Pointer to the root-node of a BSTree

Goes level-by-level on a tree and prints the values on the nodes from leftmost to rightmost node.
*/
extern void printLevelOrder(BSTreeNode* rootNode);

/*
*node: Pointer to the root-node of a BSTree
*queriedValue: Valid value in the tree

Returns a pointer to the node containing the closest greater value of the queriedValue.
*/
extern BSTreeNode* GetSuccessor(BSTreeNode* rootNode, void* queriedValue);

/*
*node: Pointer to the root-node of a BSTree
*queriedValue: Valid value in the tree

Returns a pointer to the node containing the closest lesser value of the queriedValue.
*/
extern BSTreeNode* GetPredecessor(BSTreeNode* rootNode, void* queriedValue);

#endif