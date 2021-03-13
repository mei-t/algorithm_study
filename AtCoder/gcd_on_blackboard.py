import math

if __name__ == '__main__':
  n = int(input())
  nums = list(map(int, input().split()))
  
  L = [0] * n
  for i in range(0, n - 1):
    L[i + 1] = math.gcd(L[i], nums[i])
  
  R = [0] * n
  for i in range(n - 1, 0, -1):
    R[i - 1] = math.gcd(R[i], nums[i])
  
  max_gcd = 0
  for i in range(n):
    gcd = math.gcd(L[i], R[i])
    max_gcd = max(max_gcd, gcd)
  print(max_gcd)
  