#!/usr/local/bin/python3

# filter from stdin to stdout
# with no arguments print everything
# with one or more integer arguments print only the corresponding text columns 
# 
# c 1 3 prints the first and third column of text to output

import sys

# get integer arguments from sys.argv
# outputcols = sys.argv[1:]
# outputcols = [ int(x)-1 for x in sys.argv[1:] ]

outputcols = []

for x in sys.argv[1:]:
	try:
		outputcols.append(int(x)-1)
		# Subtract 1 from each argument - humans will call the first column 1,
		# while Python will start with 0
	except ValueError:
		print("Error:  " + x + " is not an integer")
		print("Usage: c  [int] [int] [int]")
		sys.exit(1)

# outputcols now looks like [1, 2, 11, 4]
# take 'line' from sys.stdin and split it on whitespace, into a list
# print the list, separated by whitespace, according to the output cols

for line in sys.stdin:
	print(''.join([ line.split()[x] + ' ' for x in outputcols ]))

sys.exit(0)
