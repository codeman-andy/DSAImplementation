#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"
#include "queue.h"


BSTreeNode* createBSTreeNode(void* data) {
  BSTreeNode* node = (BSTreeNode*) calloc(1, sizeof(BSTreeNode));
  node->data = data;
  return node;
}

bool __isEqual(void* data, void* node_data) {
  return *((int*) data) == *((int*) node_data);
}

bool __isGreater(void* data, void* node_data) {
  return *((int*) data) > *((int*) node_data);
}

bool __isLesser(void* data, void* node_data) {
  return *((int*) data) < *((int*) node_data);
}

void insertBSTreeNode(BSTreeNode** node, void* data) {
  if (*node == NULL) {
    *node = createBSTreeNode(data);
  } else if (__isGreater(data, (*node)->data)) {
    insertBSTreeNode(&(*node)->right, data);
  } else {
    insertBSTreeNode(&(*node)->left, data);
  }
}

BSTreeNode* searchBSTree(BSTreeNode* node, void* data) {
  if (node == NULL) {
    return NULL;
  } else if (__isEqual(data, node->data)) {
    return node;
  } else if (__isGreater(data, node->data)) {
    return searchBSTree(node->right, data);
  } else {
    return searchBSTree(node->left, data);
  }
}

// Function to find minimum in a tree
BSTreeNode* FindMin(BSTreeNode* node) {
	while (node->left != NULL) {
	  node = node->left;
	}
	return node;
}

// Function to find maximum in a tree
BSTreeNode* FindMax(BSTreeNode* node) {
	while (node->right != NULL) {
	  node = node->right;
	}
	return node;
}

// Function to search a delete a value from tree
int deleteBSTNode(BSTreeNode** root, void* data) {
	if (*root == NULL) {
	  return 0;
	}
	else if (__isLesser(data, (*root)->data)) {
	  deleteBSTNode(&(*root)->left, data);
	}
	else if (__isGreater(data, (*root)->data)) {
	  deleteBSTNode(&(*root)->right, data);
	}
	else {
		// Case 1:  No child
		if ((*root)->left == NULL && (*root)->right == NULL) { 
			free(*root);
      *root = NULL;
		}
		// Case 2: One child 
		else if ((*root)->left == NULL) {
			BSTreeNode* temp = (*root);
			(*root) = (*root)->right;
			free(temp);
		}
		else if((*root)->right == NULL) {
			BSTreeNode* temp = (*root);
			(*root) = (*root)->left;
			free(temp);
		}
		// Case 3: 2 children
		else {
			BSTreeNode* temp = FindMin((*root)->right);
			(*root)->data = temp->data;
			deleteBSTNode(&(*root)->right, temp->data);
		}
	}
	return 1;
}

int FindHeight(BSTreeNode* root) {
  if (root == NULL) {
    return -1;
  }
  else {
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
  }
}

int killBSTree(BSTreeNode** node) {
  if (*node == NULL) return 0;

  if ((*node)->left != NULL) {
    killBSTree(&(*node)->left);
  }
  if ((*node)->right != NULL) {
    killBSTree(&(*node)->right);
  }
  free(*node);
  *node = NULL;

  return 1;
}

// Function to print Nodes in a Binary Search Tree in Level-Order
void printLevelOrder(BSTreeNode* rootNode) {
	if (rootNode == NULL) return;
	Queue *queue = (Queue*) malloc(sizeof(Queue));
	queue->front = -1;
	queue->rear = -1;
	Enqueue(queue, rootNode);
	// While there is at least one discovered Node
	while(queue->rear > -1) {
		BSTreeNode* current = queue->items[queue->front];
		printf("%d\n", *((int*) current->data));
		if (current->left != NULL) {
		  Enqueue(queue, current->left);
		}
		if (current->right != NULL) {
		  Enqueue(queue, current->right);
		}
		Dequeue(queue); // Removing the element at the front of the Queue
	}
}

BSTreeNode* GetSuccessor(BSTreeNode* rootNode, void* queriedValue) {
  // Checks if the queriedValue exists in the Tree
  BSTreeNode *current = searchBSTree(rootNode, queriedValue);
  if (current == NULL) {
    // If the queriedValue does not exist in the Tree
    return NULL;
  } else if (current->right != NULL) {
    // If the queriedValue has a right sub-tree then its successor will naturally be the minimum value in it
    return FindMin(current->right);
  } else {
    // A BTreeNode ptr to store our result in
    BSTreeNode* successor = NULL;
    while (rootNode != current) {
      if (__isGreater(queriedValue, rootNode->data)) {
        // If the current value we are examining is lesser than the queriedValue then we should look for a bigger one
        rootNode = rootNode->right;
      } else {
        // The current value is a good candidate for the successor
        successor = rootNode;
        rootNode = rootNode->left;
      }
    }
    return successor;
  }
}

BSTreeNode* GetPredecessor(BSTreeNode* rootNode, void* queriedValue) {
  // Checks if the queriedValue exists in the Tree
  BSTreeNode* current = searchBSTree(rootNode, queriedValue);
  if (current == NULL) {
    // If the queriedValue does not exist in the Tree
    return NULL;
  } else if (current->right != NULL) {
    // If the queriedValue has a left sub-tree then its successor will naturally be the maximum value in it
    return FindMax(current->left);
  } else {
    // A BTreeNode ptr to store our result in
    BSTreeNode* predecessor = NULL;
    while (rootNode != current) {
      if (__isLesser(queriedValue, rootNode->data)) {
        // If the current value we are examining is greater than the queriedValue then we should look for a smaller one
        rootNode = rootNode->left;
      } else {
        // The current value is a good candidate for the predecessor
        predecessor = rootNode;
        rootNode = rootNode->right;
      }
    }
    return predecessor;
  }
}

/*int main() {
  BSTreeNode *root = NULL;
  root = insertBSTreeNode(root, 3);
  root = insertBSTreeNode(root, 11);
	root = insertBSTreeNode(root, 6);
	root = insertBSTreeNode(root, 1);
	root = insertBSTreeNode(root, 9);
	root = insertBSTreeNode(root, 8);
	root = insertBSTreeNode(root, 10);
	root = insertBSTreeNode(root, 19);
	root = insertBSTreeNode(root, 5);
	LevelOrder(root);
	killBSTree(root);
}*/