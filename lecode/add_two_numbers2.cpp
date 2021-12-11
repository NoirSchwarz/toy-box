#include <iostream>
using namespace std;
//注意构造函数
struct ListNode {
    int val;
    ListNode* next;

    ListNode()
    {
        val = 0;
        next = nullptr;
    }

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    //在此处用两个ListNode类型的指针代表两个链表
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            //当head为空时，条件为真，新建新链表的头节点
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
