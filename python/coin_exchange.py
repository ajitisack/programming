#!/usr/bin/python3
import sys
l = []

#with open("a.txt") as f:
#	f.readline()
#	for line in f:
#		arr = [int(i) for i in line.strip().split()]
#		l.append(arr)

with sys.stdin as f:
	f.readline()
	for line in f:
		arr = [int(i) for i in line.strip().split()]
		l.append(arr)

for i in range(0,len(l), 2):
	x = l[i][1]
	y = sum(l[i+1])
	z = abs(y - x) % 2
	if (z==0):
		print(1)
	else:
		print(0)

		
