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

    ListNode* makeLL(vector<int>&v){
        ListNode* head = new ListNode(v[0]);
        ListNode* mover = head;
        for(int i=1;i<v.size();i++){
            ListNode* temp = new ListNode(v[i]);
            mover->next=temp;
            mover=mover->next;
        }
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        ListNode* h = makeLL(v);
        return h;
    }
};