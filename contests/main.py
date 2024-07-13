class FenwickTree:
    def __init__(self, n_or_a):
        if isinstance(n_or_a, int):
            self.n = n_or_a
            self.bit = [0] * n_or_a
        elif isinstance(n_or_a, list):
            self.n = len(n_or_a)
            self.bit = [0] * self.n
            for i, val in enumerate(n_or_a):
                self.add(i, val)

    def sum(self, r):
        ret = 0
        while r >= 0:
            ret += self.bit[r]
            r = (r & (r + 1)) - 1
        return ret

    def range_sum(self, l, r):
        return self.sum(r) - self.sum(l - 1)

    def add(self, idx, delta):
        while idx < self.n:
            self.bit[idx] += delta
            idx = idx | (idx + 1)

def mex(A):
    b = set(A)
    result = 0
    while result in b:
        result += 1
    return result

def exgcd(a, b):
    if b == 0:
        return a, 1, 0
    d, x1, y1 = exgcd(b, a % b)
    x = y1
    y = x1 - y1 * (a // b)
    return d, x, y

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b

def solve(num):
    if num % 2:
        print(num, end=' ')
        num -= 1
    for i in range(1, num // 2 + 1):
        print(num - i + 1, i, end=' ')
    print()

def main():
    t = int(input().strip())
    for _ in range(t):
        n = int(input().strip())
        solve(n)

if __name__ == "__main__":
    main()


