import random as rand
import os

#forms the number array from file
filePath = os.path.dirname(os.getcwd())+"/testinput.txt"
inputData = open(filePath,'r').read()
nums = inputData.strip().split()
nums = [int(num) for num in nums]

#sorts using selection sort
for i in range(len(nums)):
    minInd = i #initializes minimum to start of iteration
    #finds minimum after i
    for j in range(i+1,len(nums)):
        if nums[minInd] > nums[j]:
            minInd = j
    #swaps minimum to the beginning
    nums[i],nums[minInd] = nums[minInd],nums[i]
print(nums)