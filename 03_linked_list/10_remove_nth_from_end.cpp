//c语言写法 删除倒数第n个节点
#include <stdio.h>
#include <stdlib.h>
// 定义链表节点结构体
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeNothFromEnd(struct ListNode* head,int n)
{
    //在函数内部给链表增加一个头节点(一般题目里面头节点就是数字，需要自己定义一个虚拟头节点)
    struct ListNode head_;
    head_.next=head;
    struct ListNode *p=&head_;
    struct ListNode *q=&head_;
    //p->n
    for(int i=0;i<n;i++) {
        if(p==NULL) {
            return head;
        }
        p=p->next;
    }
    //q->head p->正数n
    while(p->next!=NULL) {
        q=q->next;
        p=p->next;
    }
    struct ListNode *del=q->next;
    q->next=q->next->next;
    free(del);
    return head_.next;
    
};

