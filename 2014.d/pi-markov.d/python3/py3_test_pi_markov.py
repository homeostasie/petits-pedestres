#!/usr/bin/env python

# Import modules
import time
import math

# Import files
import src.py3_pi_markov as spy3

# Constant

print("Disks \t Points\t Total Point \t Pi \t Error \t Time")

# Number of point
for nPoint in [10, 100, 1000, 10**4, 10**5, 10**6, 10**7]:
    # Number of disk
    for nDisk in [10, 100, 1000, 10**4, 10**5, 10**6, 10**7]:
        # Time
        aTime = time.clock()
        # Call nDisk with nPoint 
        pPidisk = spy3.fpimarkov(nDisk, nPoint)
        
        # mean of all pi
        aPi = sum(pPidisk)/nDisk
        # Error
        aError = math.fabs(math.pi - aPi)
        # Time
        aTime = time.clock() - aTime

        print(nDisk, '\t', nPoint, '\t', nDisk*nPoint, '\t', aPi, '\t', aError, '\t', aTime)

