import random as rand
import os

#forms the number array from file
filePath = os.path.dirname(os.getcwd())+"/coords.txt"
coords = []
with open(filePath,'r') as inputData:
    for coord in inputData:
        coordPair = coord.strip().split(',')
        coordPair = (int(coordPair[0]),int(coordPair[1]))
        coords.append(coordPair)
#calculate MST using Prim's Algorithm
connections = [ [float('inf'),False] for index in range(len(coords))]
last = 0
order = [0]
for _ in range(len(coords)-1):
    connections[last]=float('inf'),True
    for index in range(1,len(coords)):
        if connections[index][1] is True: continue
        distance = ((coords[last][0]-coords[index][0])**2 + (coords[last][1]-coords[index][1])**2)**0.5
        if connections[index][0] > distance:
            connections[index][0] = distance
    minDist = float('inf')
    minInd = -1
    for i in range(1,len(connections)):
        if connections[i][0] < minDist: 
            minDist = connections[i][0]
            minInd = i
    last = minInd
    order.append(last)
print(order)



