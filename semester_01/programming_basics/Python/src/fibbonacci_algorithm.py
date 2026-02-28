def FIB(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return FIB(n-1) + FIB(n-2)
