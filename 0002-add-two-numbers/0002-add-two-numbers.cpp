/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummyHead=new ListNode(0);
        ListNode*curr=dummyHead;
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        //ListNode*temp1=data;
        int carry=0;
        while(temp1!=NULL||temp2!=NULL||carry!=0){
            int sum=carry;
            if(temp1) sum+=temp1->val;
            if(temp2) sum+=temp2->val;
            //ListNode*newListNode=new ListNode(sum%10);
            //curr->next = new ListNode(sum % 10);
            //curr = curr->next;

            carry=sum/10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
            

        }
        //delete dummyHead;
        return dummyHead->next;
        
    }
};