import random as rand
import os

#forms the number array from file
filePath = os.path.dirname(os.getcwd())+"/testinput.txt"
inputData = open(filePath,'r').read()
nums = inputData.strip().split()
nums = [int(num) for num in nums]

#heapifies partial array assuming the rest is sorted
def heapify(nums,s,root):
    left = 2*root+1
    right = 2*root+2
    maxI = root
    #corrects maxI if heap is invalidated
    if left < s and nums[root] < nums[left]:
        maxI = left
    if right < s and nums[maxI] < nums[right]:
        maxI = right
    #swaps if heap was invalidated and recursively fixes
    if maxI != root:
        nums[maxI],nums[root]=nums[root],nums[maxI]
        heapify(nums,s,maxI)

#sorts using max heap
def heapsort(nums):
    #Builds the initial max heap
    for root in range(len(nums)//2-1,-1,-1):
        heapify(nums,len(nums),root)
    #partitions elements and performs partial heapifies for correction
    for ind in range(len(nums)-1,0,-1):
        nums[0],nums[ind]=nums[ind],nums[0]
        heapify(nums,ind,0)

#sorts using heapsort
heapsort(nums)

print(nums)