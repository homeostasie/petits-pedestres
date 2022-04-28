#!/usr/bin/env python3

"""
-----------------------------------------------------------------
Contributeur :
- Thomas LAFOND
-----------------------------------------------------------------
PROJECT EULER
-----------------------------------------------------------------
Problème 4 :
- Le plus grand produit de deux facteurs entre 100 et 999 qui
soit un palindrome.
-----------------------------------------------------------------
- boolean fonction to check if palindrome
- unique and sorted list of 3-digits factors (thanks python do not let me code this myself) with a started a set in order to have unique entry and a lst = sorted(list(from_set))
- Found the biggest one by pop.
-----------------------------------------------------------------
"""


# True if aNombre is a palindrome
def EstPalindrome(aNombre):
    strNombre = str(aNombre)
    digit = len(strNombre)
    idigit = 0
    
    isPal = True

    while isPal and idigit < digit//2:
        if strNombre[idigit] != strNombre[digit - idigit -1]:
            isPal = False
        idigit += 1
    return isPal

# A list of unique and sorted integer as factor of aNombre-digits number
def lstFactor(aNombre):
    aMax1 = aNombre
    aMax2 = aNombre
    setfact = set()

    while (aMax1 > 0):
        aMax2 = aNombre
        while (aMax2 > 0):
            setfact.add(aMax1 * aMax2)
            aMax2 -= 1          
        aMax1 -=1

    lstfact= sorted(list(setfact))
    return lstfact

# Biggest palindrome
def maxPalindrome(aNombre):
    lstfact = lstFactor(aNombre)
    pal = lstfact.pop()
    while not EstPalindrome(pal):
        pal = lstfact.pop()
    return pal


# Main
print("lst facteur",maxPalindrome(999))

