/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p, *prev;
        unordered_map<RandomListNode *, RandomListNode * > hash;
        if(head == nullptr) return nullptr;
        RandomListNode *q = head;
        RandomListNode dummy(-1);
        //dummy.next = new RandomListNode(q->label);
        prev = &dummy;
        while(q) {
            p = new RandomListNode(q->label);
            prev->next = p;
            //hash.insert(make_pair<RandomListNode *, RandomListNode *>(q, p) );
            hash.insert({q, p});
            q = q->next;
            prev = p;
        }
        q = head;
        p = dummy.next;
        while(q) {
            if(q->random == nullptr) {
                p->random = nullptr;
            } else {
                auto rd = hash.find(q->random);
                p->random = rd->second;
            }
            q = q->next;
            p = p->next;
        }
        return dummy.next;
        
    }
};
