n = int(input())
mod = 1000000007
fib = {}
fib[0] = 0
fib[1] = 1
fib[2] = 1
def fibf(n):
    if n not in fib:
        if n%2==0:
            fib[n] = (fibf(n//2)**2 + 2*fibf(n//2)*fibf(n//2-1))%mod
        else:
            fib[n] = (2*fibf(n-1)-fibf(n-3))%mod
                #fibf(n//2)**2 + fibf(n//2+1)**2
    return fib[n]
print(fibf(n)%mod)