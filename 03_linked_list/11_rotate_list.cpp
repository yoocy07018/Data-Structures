//旋转链表 向右移动k
#include <iostream>
#include <vector>

using namespace std;

// 补全结构体定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head,int k) {
        ListNode* p=head;
        ListNode* q=head;
        if(head==nullptr||k==0) {
            return head;
        }
        int number=0;
        for(ListNode* i=head;i!=nullptr;i=i->next) {
            number++;
        }
        k=k%number;
        for(int i=0;i<k;i++) {
            p=p->next;
        }
        while(p->next!=nullptr) {
            q=q->next;
            p=p->next;
        }
        p->next=head;
        head=q->next;
        q->next=nullptr;
        return head;
    }
};
