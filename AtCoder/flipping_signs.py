if __name__ == '__main__':
  n = int(input())
  nums = list(map(int, input().split()))
  
  negative_even = True
  min_num = float('inf')
  sum = 0
  for num in nums:
    if num < 0:
      print(num)
      negative_even = not negative_even
      print(negative_even)
    min_num = min(min_num, abs(num))
    sum += abs(num)
    
  if negative_even:
    print(sum)
  else:
    print(sum - min_num * 2)