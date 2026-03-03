from itertools import product, permutations

def fun_many(X):
    result = [list(p) for p in product(X, repeat=3)]
    return sorted(result)

def fun_single(X):
    result = [list(p) for p in permutations(X, 3)]
    return sorted(result)

X = [name.strip() for name in input().split(',')]

many = fun_many(X)
single = fun_single(X)

print(many)
print(len(many))
print(single)
print(len(single))