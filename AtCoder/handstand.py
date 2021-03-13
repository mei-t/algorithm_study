if __name__ == '__main__':
  n, k = map(int, input().split())
  s = input()
  nums = []
  prev = '1'
  count = 0
  for i in range(len(s)):
    if s[i] == prev:
      count += 1
    else:
      nums.append(count)
      count = 1
      prev = s[i]
  nums.append(count)
  if len(nums) % 2 == 0:
    nums.append(0)

  add = 2 * k + 1
  left = 0
  right = 0
  max_sum = 0
  cur_sum = 0
  for i in range(0, len(nums), 2):
    next_left = i
    next_right = min(len(nums), i + add)
    
    while left < next_left:
      cur_sum -= nums[left]
      left += 1

    while right < next_right:
      cur_sum += nums[right]
      right += 1
    max_sum = max(max_sum, cur_sum)
    
  print(max_sum)
      