class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode current = head;
        ListNode prev = null;

        while(current!=null){
            ListNode front = current.next;
            current.next = prev;
            prev = current;
            current = front;
        }
        return prev;
    }
}