import random as rand

inputData = open('testinput','r').read()
nums = inputData.strip().split()
nums = [int(num) for num in nums]
while sorted(nums) != nums:
    rand.shuffle(nums)
print(nums)