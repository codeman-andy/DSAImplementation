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

extern BSTreeNode* createBSTreeNode(void* data);
extern void insertBSTreeNode(BSTreeNode** node, void* data);
extern BSTreeNode* searchBSTree(BSTreeNode* node, void* data);
extern BSTreeNode* FindMin(BSTreeNode* node);
extern BSTreeNode* FindMax(BSTreeNode* node);
extern int deleteBSTNode(BSTreeNode** node, void* data);
extern int FindHeight(BSTreeNode* root);
extern int killBSTree(BSTreeNode** root);
extern void printLevelOrder(BSTreeNode* rootNode);
extern BSTreeNode* GetSuccessor(BSTreeNode* rootNode, void* queriedValue);
extern BSTreeNode* GetPredecessor(BSTreeNode* rootNode, void* queriedValue);