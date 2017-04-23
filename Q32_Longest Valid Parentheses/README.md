# Q32_Longest Valid Parentheses

## Substact
My solution on this problem makes use of stack, costing O(n) time.
The stack contains the each unmatched left parameter's index before i, and a _invisible_ left parameter whose index is named as **start**.
