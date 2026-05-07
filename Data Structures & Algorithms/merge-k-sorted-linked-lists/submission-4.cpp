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
    ListNode* mergeList (ListNode* m, ListNode* n) {
        ListNode* head = new ListNode (-1);
        ListNode* tmp = head;

        while (m && n) {
            if (m->val < n->val) {
                tmp->next = m;
                m = m->next;
            }
            else {
                tmp->next = n;
                n = n->next;
            }
            tmp = tmp->next;
        }

        while (m) {
            tmp->next = m;
            m = m->next;
            tmp = tmp->next;
        }

        while (n) {
            tmp->next = n;
            n = n->next;
            tmp = tmp->next;
        }

        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return nullptr;
        }

        int jump = 1;
        while (jump < k) {
            for (int i = 0; i + jump < k; i += (jump*2)) {
                lists [i] = mergeList (lists [i], lists [i+jump]);
            }
            jump *= 2;
        }
        return lists [0];
    }

};
