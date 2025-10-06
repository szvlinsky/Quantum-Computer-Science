def EUC(n, m):
    a = n
    b = m
    while(a != b):
        if(a > b):
            a = a-b
        else:
            b = b-a
    return a

def EUC_MOD(n, m):
    if n > m:
        a = n
        b = m
    else:
         a = m
         b = n
         
    while b != 0:
        a, b = b, a % b
    return a
    
