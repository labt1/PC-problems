import sys

def factorial(n):
    fact = 1
    for i in range(1, n + 1):
        fact = fact * i
    return fact

count = 1
fact = 1
penalty = 1
temp = 1

for cad in sys.stdin:
    cad = cad.rstrip()
    cad = sorted(cad)
    c = cad[0]

    for i in range (1, len(cad)):
        if c!=cad[i]:
            count = count+1
            c = cad[i]
            temp = 1
        else:
            temp = temp + 1
            penalty = penalty * temp
    fact = factorial(len(cad))
    if count < len(cad):
        fact = fact // penalty
    print(fact)
    count = 1
    fact = 1
    temp = 1
    penalty = 1