import random as rand
import os

#forms the number array from file
filePath = os.path.dirname(os.getcwd())+"/testinput.txt"
inputData = open(filePath,'r').read()
nums = inputData.strip().split()
nums = [int(num) for num in nums]

#sorts using bubble sort
numSwaps = -1
while numSwaps!=0:
    numSwaps=0
    for i in range(len(nums)-1):
        if nums[i] > nums[i+1]:
            nums[i],nums[i+1] = nums[i+1],nums[i]
            numSwaps+=1
        
        
print(nums)