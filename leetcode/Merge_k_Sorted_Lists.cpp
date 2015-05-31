/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists.back();
        
        vector<ListNode *> l;
        while(!lists.empty()){
            if(lists.size()==1){
                l.push_back(lists.back());
                lists.pop_back();
            }else{
                ListNode *p = lists.back();
                lists.pop_back();
                ListNode *q = lists.back();
                lists.pop_back();
                
                l.push_back(mergeTwoLists(p, q));
            }
        }
        return mergeKLists(l);
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode dummy(-1);
        for(ListNode *p=&dummy; l1!=nullptr || l2!=nullptr; p=p->next){
            int val1 = l1==nullptr?INT_MAX:l1->val;
            int val2 = l2==nullptr?INT_MAX:l2->val;
            if(val1 <= val2){
                p->next=l1;
                l1=l1->next;
            }else{
                p->next=l2;
                l2=l2->next;
            }
        }
        return dummy.next;
    }
};
