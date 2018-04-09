# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        head = swaphead(head)
        switchBody(head.next)
        return head

    def swaphead(self, head):
        next1 = head.next
        rest = next1.next
        next1.next = head
        head.next = rest
        return next1

    def switchBody(self, head):
        while head.next is not None and head.next.next is not None:
            next1 = head.next
            next2 = head.next.next
            rest = next2.next
            head.next = next2
            next2.next = next1
            next1.next = rest
            head = next1
