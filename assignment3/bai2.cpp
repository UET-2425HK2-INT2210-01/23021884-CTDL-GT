Function Power_Recursive(n):
    if n = 0 then:
        return 1
    else if n is even then:
        half ? Power_Recursive(n / 2)
        return half * half
    else:
        half ? Power_Recursive((n - 1) / 2)
        return half * half * 2
// do phuc tap O(logn)
Function Power_Iterative(n):
    result <- 1
    for i from 1 to n do:
        result <- result * 2
    return result
// do phuc tap O(n) 
