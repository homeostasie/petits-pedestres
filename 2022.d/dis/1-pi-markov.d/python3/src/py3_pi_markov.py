#!/usr/bin/env python

# import module
import random

def fpimarkov(nDisk, nPoint):
    "Compute Pi"

    # Initialize the basic random number generator
    random.seed()

    # Pi comput per Disk
    pPidisk = []

    for count in range (0, nDisk):
        # Number of point in the disk
        pIndisk = 0

        # Throw pDisk points in the disk
        for count in range (0, nPoint):
            # aCoor is a point with random coordonate in [-1,1]x[-1,1].
            aCoor = [random.uniform(-1,1), random.uniform(-1,1)]
            # if the point belong to the disk
            if aCoor[0]*aCoor[0] + aCoor[1]*aCoor[1] < 1:
                pIndisk += 1

        # Disk area = Pi and Square area = 4
        pPidisk.append(4*pIndisk/nPoint)

    return(pPidisk)


