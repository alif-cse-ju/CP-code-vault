import collections
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    freq = collections.Counter(a)
    big = n - freq[0] - freq[1] - freq[-1]
    if big > 1:
        print(0)
        continue
    if big == 1 and freq[-1] > 0:
        print(0)
        continue
    if freq[-1] > 1 and freq[1] == 0:
        print(0)
        continue
    print(1)