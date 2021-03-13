if __name__ == '__main__':
  n, k = map(int, input().split())
  s = input()
  nums = []
  prev = s[0]
  count = 0
  for i in range(len(s)):
    if s[i] == prev:
      count += 1
    else:
      nums.append(count)
      count = 1
      prev = s[i]
  nums.append(count)

  a = 1 if s[0] == "0" else 0
  if len(nums) < 2 * k - a:
    print(len(s))
  else:
    max_sum = nums[a]
    for i in range(0 - a, len(nums) - 2 * k, 2):
      sum = 0
      for j in range(i, i + 2 * k + 1):
        if j == -1:
          continue
        sum += nums[j]
      max_sum = max(max_sum, sum)
    print(max_sum)
      