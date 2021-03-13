if __name__ == '__main__':
  n, k = map(int, input().split())
  s = input()
  nums = [0]
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
  nums.append(0)

  a = 1 if s[0] == '1' else 0
  if len(nums) - 2 < 2 * k - (a^1):
    print(len(s))
  else:
    max_sum = 0
    for i in range(a, 2 * k + a + 1):
      max_sum += nums[i]
    prev_sum = max_sum
    for i in range(a, len(nums) - a - 2 * k - 2, 2):
      cur_sum = prev_sum - nums[i] - nums[i + 1] + nums[2 * k + i + 1] + nums[2 * k + i + 2]
      max_sum = max(cur_sum, max_sum)
      prev_sum = cur_sum
  
    print(max_sum)
      