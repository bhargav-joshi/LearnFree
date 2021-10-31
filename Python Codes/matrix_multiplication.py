''' Python program to multiply
    two matrices'''
def matrix_multiplication(A,B):
    result=[]
    for i in range(len(A)):
        result.append([0]*len(B[0]))
    for i in range(len(A)):
         for j in range(len(B[0])):
            for k in range(len(B)):
                result[i][j] += A[i][k] * B[k][j]
    for row in result:
        print(row)
matrix_multiplication([[12, 7, 3],[4, 5, 6],[7, 8, 9]],
                      [[5, 8, 1, 2],[6, 7, 3, 0],[4, 5, 9, 1]])
