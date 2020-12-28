import random as rand
import os
filePath = os.path.dirname(os.getcwd())+"/testinput.txt"
inputData = open(filePath,'r').read()
nums = inputData.strip().split()
nums = [int(num) for num in nums]
for i in range(len(nums)):
    minInd = i
    for j in range(i+1,len(nums)):
        if nums[minInd] > nums[j]:
            minInd = j
    nums[i],nums[minInd] = nums[minInd],nums[i]
print(nums)