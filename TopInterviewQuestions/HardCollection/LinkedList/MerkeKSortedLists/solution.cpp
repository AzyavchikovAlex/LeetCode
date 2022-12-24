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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        }
        return MergeAll(lists, 0 , lists.size() - 1);
    }
    
    ListNode* MergeAll(vector<ListNode*>& lists, int L, int R) {
        if (L == R) {
            return lists[L];
        }
        if (L + 1 == R) {
            return Merge(lists[L], lists[R]);
        }
        int mid = (L + R) / 2;
        return Merge(MergeAll(lists, L, mid), MergeAll(lists, mid + 1, R));
    }
    
    ListNode* Merge(ListNode* list1, ListNode* list2) {
        ListNode* result = nullptr;
        ListNode* pos = nullptr;
        while (list1 != nullptr || list2 != nullptr) {
            ListNode* new_element = new ListNode();
            if (list2 == nullptr || (list1 != nullptr && list1->val < list2->val)) {
                new_element->val = list1->val;
                list1 = list1->next;
            } else {
                new_element->val = list2->val;
                list2 = list2->next;
            }
            if (result == nullptr) {
                result = new_element;
                pos = result;
            } else {
                pos->next = new_element;
                pos = new_element;
            }
        }
        return result;
    }
};
