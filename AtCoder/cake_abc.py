import heapq

if __name__ == '__main__':
  x, y, z, k = map(int, input().split())
  A = sorted(list(map(int, input().split())), reverse=True)
  B = sorted(list(map(int, input().split())), reverse=True)
  C = sorted(list(map(int, input().split())), reverse=True)

  AB = []
  for i in range(len(A)):
    for j in range(len(B)):
      AB.append(A[i] + B[j])
  AB.sort(reverse=True)

  ABC = []
  for i in range(min(len(AB), k)):
    for j in range(len(C)):
      ABC.append(AB[i] + C[j])
  ABC.sort(reverse=True)
  for i in range(k):
    print(ABC[i])