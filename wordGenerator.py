# -*- coding: utf-8 -*-
"""
Created on Tue Jun 17 20:27:15 2014

@author: bpstern
"""
import random

numWords = 4
def main():
    words=[]
    selected=[]
    #dictionary = "4000-most-common-english-words-csv.csv"
    dictionary = "words_ospd.txt"
    f=open(dictionary,"r")
    for line in f:
        word=line.strip(" ,\n")
        if len(word)>=0:
            words.append(word.lower())
    for i in range(numWords):
        r=random.randint(0,len(words)-1)
        selected.append(words[r])
    password=""
    for word in selected:
        password+=word[0].upper()
        password+=word[1:]
        password+=" "
    print password
main()
