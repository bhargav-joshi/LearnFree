''' Program to perform
    addition of two matrices'''
def matrix_addition(X,Y):
    result = [[X[i][j] + Y[i][j]  for j in range
    (len(X[0]))] for i in range(len(X))]
  
    for row in result:
        print(row)
        
#Driver Code
matrix_addition([[1,2,3],[4 ,5,6],[7 ,8,9]],
                [[9,8,7],[6,5,4],[3,2,1]])
