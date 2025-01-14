# A-2 Write a Python program to store marks scored in subject “Fundamental of Data Structure”
 #by Nstudents in the class. Write functions to compute following:
 #a) The average score of class
 #b) Highest score and lowest score of class
 #c) Count of students who were absent for the test
 #d) Display mark with highest frequency
def avg(marks):
    total=sum(marks)
    print("Average marks of Students are:")
    avg=total/len(marks)
    print(avg,"/n")
def high(marks):
    highestmarks=max(marks)
    print("Highest marks scored by student is :", highestmarks,"/n")
def minn(marks):
    lowestmarks=min(marks)
    print("Lowest marks scored by student is :", lowestmarks,"/n")

def frequency(marks):
    frequency = {}
    for mark in marks:
        frequency[mark] = frequency.get(mark, 0) + 1
    print("Frequency of marks scored by students is: ", frequency,"/n")
def absent(marks):
    count=0
    for mark in marks:
        if mark==0:
            count=count +1
        else:
            count=count
    print("Number of students Absent for test Was;",count)
marklst=[]
n=int(input("Enter Number of Students of Which you want to know the marks:"))
for i in range(n):
    mark=int(input("Enter marks of Student make sure to add zero for absent Students:"))
    marklst.append(mark)

avg(marklst)
high(marklst)
frequency(marklst)
absent(marklst)

minn(marklst)
        
    



