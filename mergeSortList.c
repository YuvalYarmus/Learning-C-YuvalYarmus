/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *mergeList(struct ListNode *l1, struct ListNode *l2)
{
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->val <= l2->val)
    {
        l1->next = mergeList(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeList(l1, l2->next);
        return l2;
    }
};

struct ListNode* sortList(struct ListNode* head){
    if(head == NULL) 
        return NULL;
    if(head->next == NULL)
        return head;
    struct ListNode *end, *mid, *pre;
    // head will remain the start
    // end will reach the end, mid will reach the middle
    // and pre will be the previous node to mid
    end = mid = head;
    while(end && end->next)
    {
        pre = mid;
        end = end->next->next;
        mid = mid->next;
    }
    pre->next = NULL; // disconnect the 2 halfs from one another
    return mergeList(sortList(head), sortList(mid));
};


// this is a piece of code copied from:
// https://leetcode.com/problems/sort-list/discuss/229687/C-solution(8ms-qsort)
// all right reserved (or something whatever :)
// no idea how this thing works
// TO DO: look at the code and see how it works (obviously)
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
struct ListNode* sortList3(struct ListNode* head) {
    int count = 0;
    struct ListNode* temphead = head;
    while(temphead!=NULL)
    {
        temphead = temphead->next;
        count++;
    }
    int *array = malloc(count*sizeof(int));
    temphead = head;
    count = 0;
    while(temphead!=NULL)
    {
        array[count] = temphead->val;
        temphead = temphead->next;
        count++;
    }
    qsort(array,count,sizeof(int),cmpfunc);
    temphead = head;
    count = 0;
    while(temphead!=NULL)
    {
        temphead->val = array[count];
        temphead = temphead->next;
        count++;
    }
    return head;
};