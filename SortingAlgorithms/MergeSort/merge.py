import random as rand
import os
def rotate(nums,start,end):
    val = nums[end]
    for ind in range(end,start,-1):
        nums[ind] = nums[ind-1]
    nums[start]=val

def merge(nums,left,middle,right):
    #merges 2 sorted ranges in place
    p2 = middle+1
    while left<=middle and p2<=right:
        if nums[left] < nums[p2]:
            left+=1
        else:
            rotate(nums,left,p2)
            left+=1
            p2+=1
            middle+=1

def mergeSort(nums,left=0,right=None):
    if right is None: right = len(nums)-1
    if left<right:
        split = (left+right)//2
        mergeSort(nums,left,split)
        mergeSort(nums,split+1,right)
        merge(nums,left,split,right)

filePath = os.path.dirname(os.getcwd())+"/testinput.txt"
inputData = open(filePath,'r').read()
nums = inputData.strip().split()
nums = [int(num) for num in nums]

mergeSort(nums)

print(nums)