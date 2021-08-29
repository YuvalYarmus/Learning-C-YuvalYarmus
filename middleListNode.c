/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *middleNode(struct ListNode *head) {
    if (head->next == NULL) {
        return head;
    }
    // we start from h->next so we can return h in the end
    //c = (a < b) ? a : b;
    struct ListNode *two = head->next;
    while (two->next!=NULL){
        if (two->next->next == NULL){
            break;
        }
        two = two->next->next;
        head = head->next;
    }
    return head->next;
}

struct ListNode *middleNode2(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return head;
    int len = 0;
    struct ListNode *end = head, *mid = head;
    while (end->next!=NULL){
        end = end->next;
        len++;
    }
    if (len % 2 != 0) len++;
    len = len / 2;
    while(len > 0) {
        mid = mid->next;
        len--;
    }
    return mid;
}