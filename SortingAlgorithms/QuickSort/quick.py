import random as rand
import os

def increment(nums,incleft,incright,left,right):
    while incleft<right and nums[incleft] < nums[right]: incleft+=1
    while incright>left and nums[incright] > nums[right]: incright-=1
    return incleft,incright

def partition(nums,left,right):
    pI = rand.randint(left,right)
    nums[pI],nums[right] = nums[right],nums[pI]
    incLeft,incRight = increment(nums,left,right-1,left,right)
    while incLeft < incRight:
        nums[incLeft],nums[incRight] = nums[incRight],nums[incLeft]
        incLeft,incRight = increment(nums,incLeft,incRight,left,right)
    nums[right],nums[incLeft] = nums[incLeft],nums[right]
    return incLeft


def quick(nums,left,right):
    if(left<right):
        pI = partition(nums,left,right)
        quick(nums,left,pI-1)
        quick(nums,pI+1,right)

filePath = os.path.dirname(os.getcwd())+"/testinput.txt"
inputData = open(filePath,'r').read()
nums = inputData.strip().split()
nums = [int(num) for num in nums]

quick(nums,0,len(nums)-1)
print(nums)