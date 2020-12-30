import random as rand
import os

#increments the incleft and incright values until it finds a value greater than and
#less than the partition respectively
def increment(nums,incleft,incright,left,right):
    while incleft<right and nums[incleft] < nums[right]: incleft+=1
    while incright>left and nums[incright] > nums[right]: incright-=1
    return incleft,incright

#partitions the array between the ranges such everything left of the partition is less
#and everything greater than the partition is greater than it
def partition(nums,left,right):
    pI = rand.randint(left,right) #chooses random partition
    nums[pI],nums[right] = nums[right],nums[pI] #move partition to the back
    incLeft,incRight = increment(nums,left,right-1,left,right) #increment to find first inc values
    #iterates until the inc values cross each other which indicates that the partition can be put back
    while incLeft < incRight:
        nums[incLeft],nums[incRight] = nums[incRight],nums[incLeft]
        incLeft,incRight = increment(nums,incLeft,incRight,left,right)
    #puts the partition back in its spot
    nums[right],nums[incLeft] = nums[incLeft],nums[right]
    return incLeft #returns new position of the partition

#quick sorts nums
def quick(nums,left=0,right=None):
    if(right is None): right = len(nums-1)
    if(left<right): #until the partition is 1 long
        pI = partition(nums,left,right) #partitions and gets index of partiton
        quick(nums,left,pI-1) #divide and conquers recursively
        quick(nums,pI+1,right)

#forms the number array from file
filePath = os.path.dirname(os.getcwd())+"/testinput.txt"
inputData = open(filePath,'r').read()
nums = inputData.strip().split()
nums = [int(num) for num in nums]

#sorts
quick(nums)
print(nums)