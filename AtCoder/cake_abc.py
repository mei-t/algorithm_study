import heapq

if __name__ == '__main__':
  x, y, z, k = map(int, input().split())
  A = sorted(list(map(int, input().split())), reverse=True)
  B = sorted(list(map(int, input().split())), reverse=True)
  C = sorted(list(map(int, input().split())), reverse=True)

  ABC = []
  for a in range(len(A)):
    for b in range(len(B)):
      if (a + 1) * (b + 1) > k:
        break
      for c in range(len(C)):
        if (a + 1) * (b + 1) * (c + 1) > k:
          break
        ABC.append(A[a] + B[b] + C[c])
  ABC.sort(reverse=True)
  for i in range(k):
    print(ABC[i])