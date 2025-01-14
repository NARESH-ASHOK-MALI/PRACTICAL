'''Write a Python program to compute following computation on matrix:
 Addition of two matrices B) Subtraction of two matrices
 c) Multiplication of two matrices d) Transpose of a matrix'''
print("Matrics A")
A=[[1,2,3],[4,5,6],[7,8,9]]
Rows=len(A)
Column=len(A[0])
#printing Matrics A
for i in range (Rows):
    print(A[i])
print("Matrics B")
B=[[10,20,30],[40,50,60],[70,80,90]]
rows=len(B)
column=len(B[0])
#printing Matrics B
for i in range (Rows):
    print(B[i])
print("Addition of these two Matrics")
Result=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(Rows):
    for j in range(Column):
        Result[i][j]=A[i][j]
for i in range(rows):
    for j in range(column):
        Result[i][j]=B[i][j]+Result[i][j]
for i in range(len(Result)):
    print(Result[i])
print("Subtractrion of this of these two Matrics")
Result=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(Rows):
    for j in range(Column):
        Result[i][j]=A[i][j]
for i in range(rows):
    for j in range(column):
        Result[i][j]=Result[i][j]-B[i][j]
for i in range(len(Result)):
    print(Result[i])
print("Transpose of Matrix A")
Result=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(Rows):
    for j in range(Column):
        Result[i][j]=A[j][i]
for i in range(len(Result)):
    print(Result[i])
print("Transpose of Matrix B")
Result=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(rows):
    for j in range(column):
        Result[i][j]=B[j][i]
for i in range(len(Result)):
    print(Result[i])
print("Multiplication  of Matricess")
Result=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(len(Result)):
    for j in range(len(Result[0])):
        for k in range(len(Result[0])):
            Result[i][j]+=A[i][k]*B[k][j]
for i in range(len(Result)):
    print(Result[i])