import random as rand
import os
filePath = os.path.dirname(os.getcwd())+"/testinput.txt"
inputData = open(filePath,'r').read()
nums = inputData.strip().split()
nums = [int(num) for num in nums]
for i in range(1,len(nums)):
    for j in reversed(range(0,i)):
        if nums[j] > nums[j+1]:
            nums[j],nums[j+1] = nums[j+1],nums[j]
        else: break
print(nums)