#### 1.反转一个单链表（用递归和迭代）
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*struct ListNode* reverseList(struct ListNode* head){//迭代，不建立头节点。此时只能反转整个链表
    struct ListNode *pre,*p=head->next,*r=p->next;
    p->next=NULL; 
    head->next=NULL;
    while (r!=NULL)
    {
       pre=p;
       p=r;
       r=r->next;
       p->next=pre;
    } 
    head->next=p;
    
    return head;
}*/

struct ListNode* reverseList(struct ListNode* head)//迭代
{
     struct ListNode*temp,*new1;
     struct ListNode* phead=(struct ListNode*)malloc(sizeof(struct ListNode));/*建立一个头节点，建立头节点，链表可以部分反转*/
     phead->next=head;
     new1=NULL;
     temp=NULL;
     while(head)
     {
         temp=head->next;
         head->next=new1;
         new1=head;
         head=temp;
     }
     phead->next=new1;
     return phead->next;

     
}

/*struct ListNode* reverseList(struct ListNode* head)//递归，只要做最后两部，剩下的递归实现
{
    if(!head||!head->next)
        return head;
    struct ListNode* r=reverseList(head->next);//r用来储存逆转代码，r指向当head->next=NULL时返回的head值
    head->next->next=head;
    head->next=NULL;//逆转
    return r;
}*/
/*链表反转的递归思想与栈类似，先将所有结点储存，再从最后一个结点开始反转*/
```
#### 2. 合并两个有序链表
* 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
* 递归的难点在于找出两个链表结点的较大的一个赋予新链表
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* a, struct ListNode* b)
{
    if(!a)
        return b;
    if(!b)
        return a;
    if(a->val<b->val)
    {
        a->next=mergeTwoLists(a->next,b);//a>b，a作为头结点向下递归
        return a;
    }
    else 
    {
        b->next=mergeTwoLists(a,b->next);//b>a，b作为头结点向下递归
        return b;
    }
} 
```
#### 3. 反转链表II（92）
反转从位置m到n的链表，请使用一次扫描完成反转
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    难点，逆置函数不包括头节点，假如逆置区间在中间，逆置函数要设置一个头节点用来连接逆置链表
*/

struct ListNode* Rev(struct ListNode* head, int n)
{
    struct ListNode*newnode=NULL,*oldnode=head->next,*temp;//new指向已逆转链表的第一个结点，old指向下一个将逆转的结点。
    for(int i=0;i<=n;i++)
    {
        temp=oldnode->next;
        oldnode->next=newnode;
        newnode=oldnode;
        oldnode=temp;
    }
    head->next->next=oldnode;
    head->next=newnode;
    return head->next;

}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if (!head)
        return head;
    struct ListNode *pre;//需要逆转结点的头节点
    struct ListNode *phead=(struct ListNode*)malloc(sizeof(struct ListNode));//Phead为链表的头结点
    phead->next=head;//连接头节点
    pre=phead;//表示m=1，从第一个结点逆转，
    for(int i=1;i<m;i++)
    {
        pre=pre->next;
    }            
    pre->next=Rev(pre,n-m);
    return phead->next;
}
```

