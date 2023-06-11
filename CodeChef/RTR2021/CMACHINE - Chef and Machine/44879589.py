t = int(input())
for i in range(1,t + 1) :
    num = int(input())
    factorial = 1
    for i in range(1,num + 1):
       factorial = factorial*i
    print(factorial)