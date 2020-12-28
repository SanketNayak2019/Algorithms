import random as rand
import os
filePath = os.path.dirname(os.getcwd())+"/testinput.txt"
inputData = open(filePath,'r').read()
nums = inputData.strip().split()
nums = [int(num) for num in nums]
while sorted(nums) != nums:
    rand.shuffle(nums)
print(nums)