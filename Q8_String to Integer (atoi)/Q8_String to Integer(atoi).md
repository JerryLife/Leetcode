# Q8 String to Integer(atoi)

This is based on the function in C/C++ ____atoi__

## Main idea:
Use java.math.BigInteger to solve overflow problem, use String.trim() to deal with space, and use BigInteger's constructor to convey a string to an integer.


## The following cases should be considered:
| Case | Example | Tips |
| :--: | :-----: | :---: |
| Empty string | "" | return 0 |
| Overflow | "2147483648" | return the maximum Int |
| Illegal token | "aaad" | return 0 |
| Space and zero | "    0033  " | strip before |
| Partually illegal token | "023a5656" | split from the illegal token and choose the left part |
