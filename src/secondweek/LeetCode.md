## 1. 二叉树的直径
####  给定一棵二叉树，计算它的直径长度。一棵二叉树的直径长度时任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
* 思想：
1. 最长路径经过根结点，则最长路径为左子树深度加右子树深度。
2. 最长路径不经过根节点，将左子树和右子树分别设为根节点。
```
iint Max(int p, int q)   //比较大小，返回两数中大的一个
{
	return p > q ? p : q;
}
int depth(struct BinTree * root) {  //求树的深度
	if (root == NULL)
		return 0;
	return 1 + Max(depth(root->left), depth(root)->right);  //若根非空 ，递归求左右子树的深度，最后加1为树的深度
}
int diameter(struct BinTree * root)
{
	if (root == NULL)
		return 0;
	int res = depth(root->left) + depth(root->right);  //包含根节点的直径
	return Max(res, Max(diamerter(root->left), diameter(root->right)));//求最大直径
}
```
##  2. 二叉搜索树的公共祖先
#### 给定一颗二叉搜索树，找到该树中两个指定结点的最近公共祖先
（最近公共祖先：对于树T中的两个结点pq，最近公共祖先X满足X时pq的祖先且X的深度足够大）
* 思想
由二叉搜索树的特性，公共祖先一定满足左子树<公共祖先<右子树
```
BinTree * LowestComminAncester(BinTree * root, BinTree * p, BinTree * q)
{
	if ((root->data > p->data) && (root->data > q->data))   //pq均小于根时，将根的左孩子变成根
		return LowestComminAncester(root->left, p, q);
	if ((root->data < p->data) && (root->data < q->data))  //pq均大于根时，将根的右孩子变成根
		return LowestComminAncester(root->right, p, q);
	return root;  //pq在根的两边时，返回根结点
}
```
## 3. 二叉树剪枝
#### 给定二叉树的根节点root，此外树的每个结点的值要么是0要么是1。返回移除了所有不包含1的子树的原二叉树。
（结点x的子树为x本身以及所有x的后代）
* 思想
递归遍历，根为1时不做处理，根为0时检查左右子树是否存在，不存在则剪去，（后序遍历由下往上剪）
```
BinTree * PruneTree(BinTree * root)
{
	if (root == NULL)//若树空
		return root;
	//后序递归左右子树
	root->left = PruneTree(root->left);
	root->right = PruneTree(root->right);
	if (root->left != NULL || root->right != NULL || root->data == 1)//左子树不为空或右子树不为空或根节点不为1时，不做改变返回根
		return root;
	return NULL;//否则返回空

}
```
## 4. 二叉树的坡度
#### 给定一颗二叉树，计算整个树的坡度。
一个结点的坡度：该结点左子树的结点之和和右子树结点之和的**差的绝对值**。空结点的坡度为0。
整个树的坡度是所有结点坡度之和
* 思想
递归遍历，一个函数计算单个结点及其子结点之和，一个函数计算所有结点的坡度并累加。
```
int treesum(BinTree * root) {//计算二叉树的所有结点之和
	if (root == NULL)
		return 0;
	else return root->data + treesum(root->left) + treesum(root->right);
}
int slope(BinTree * root) {//求整个树坡度
	if (root == 0)//根空时取0
		return 0;
	else//abs函数是取绝对值，根不为空时返回各个结点的坡度之和
		return abs(treesum(root->left) - treesum(root->right)) + slope(root->left) + slope(root->right);
}
```
## 5. 包含min函数的栈
#### 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
* 思路
栈中加入一个指针记录栈中最小元素，加入一个数组记录曾经所有被栈标记过最小元素的下标，每次入栈出栈更新最小指针以及数组。
```
typedef struct {
    int capacity;
    int topofstack;
    int min;
    int *array;
} MinStack;

/** initialize your data structure here. */
#define EMPTYTOS        (-1)
#define MAX_SIZE        (200001)
MinStack* minStackCreate() {
   MinStack *S;
    S = malloc(sizeof(MinStack));
    if(S == NULL)
        return NULL;
    
    S->array = malloc(sizeof(int)*MAX_SIZE);
    if(S->array == NULL)
        return NULL;
    S->topofstack = EMPTYTOS;
    S->capacity = MAX_SIZE;
    return S;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->topofstack == obj->capacity)
      return;
    obj->array[++obj->topofstack] = x;

    if(obj->topofstack == (EMPTYTOS + 1)){
        obj->min = x;
    }
    else{
        if(obj->min > x)
          obj->min = x;
    }
    return; 
}

void minStackPop(MinStack* obj) {
    if(obj->topofstack == EMPTYTOS)
      return;
    if(obj->array[obj->topofstack] > obj->min){
      obj->topofstack--;
      return;
    }
    else{
      obj->topofstack--;
      if(obj->topofstack == EMPTYTOS)
        return;
      int min = obj->array[obj->topofstack];
      for(int i=obj->topofstack;i>EMPTYTOS;i--){   
        if( obj->array[i] < min)
           min = obj->array[i];    
      }
      obj->min = min;
    }
}

int minStackTop(MinStack* obj) {
    if(obj->topofstack == EMPTYTOS)
      return EMPTYTOS;
    return obj->array[obj->topofstack];
}

int minStackMin(MinStack* obj) {
    return obj->min;    
}

void minStackFree(MinStack* obj) {
    free(obj);
}
```


