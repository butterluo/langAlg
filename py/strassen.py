# coding=utf-8
# copyright@zhangwenchi at 2019/9/21
import numpy as np


num_addorsub=0
num_mul=0
num_assign=0

def matrix_add(matrix_a, matrix_b):
    '''
    :param matrix_a:
    :param matrix_b:
    :return:matrix_c=matrix_a+matrix_b
    '''
    rows = len(matrix_a) # get numbers of rows
    columns = len(matrix_a[0]) # get numbers of cols
    matrix_c = [list() for i in range(rows)] # build matrix 2d list
    for i in range(rows):
        for j in range(columns):
            matrix_c_temp = matrix_a[i][j] + matrix_b[i][j]
            global num_addorsub,num_assign
            num_addorsub=num_addorsub+1
            num_assign = num_assign+1
            matrix_c[i].append(matrix_c_temp)
    return matrix_c


def matrix_minus(matrix_a, matrix_b):
    '''
    :param matrix_a:
    :param matrix_b:
    :return:matrix_c=matrix_a-matrix_b
    '''
    rows = len(matrix_a)
    columns = len(matrix_a[0])
    matrix_c = [list() for i in range(rows)]
    for i in range(rows):
        for j in range(columns):
            matrix_c_temp = matrix_a[i][j] - matrix_b[i][j]
            global num_addorsub,num_assign
            num_addorsub = num_addorsub + 1
            num_assign=num_assign+1
            matrix_c[i].append(matrix_c_temp)
    return matrix_c


def matrix_divide(matrix_a, row, column):
    '''
    :param matrix_a:
    :param row:
    :param column:
    :return: matrix_b=matrix_a(row,column) to divide matrix_a
    '''
    length = len(matrix_a)
    matrix_b = [list() for i in range(length // 2)]
    k = 0
    for i in range((row - 1) * length // 2, row * length // 2):
        for j in range((column - 1) * length // 2, column * length // 2):
            matrix_c_temp = matrix_a[i][j]
            matrix_b[k].append(matrix_c_temp)
        k += 1
    return matrix_b


def matrix_merge(matrix_11, matrix_12, matrix_21, matrix_22):
    '''
    :param matrix_11:
    :param matrix_12:
    :param matrix_21:
    :param matrix_22:
    :return:mariix merged by 4 parts above
    '''
    length = len(matrix_11)
    matrix_all = [list() for i in range(length * 2)]  # build a matrix of double rows
    for i in range(length):
        # for each row. matrix_all list contain row of matrix_11 and matrix_12
        matrix_all[i] = matrix_11[i] + matrix_12[i]
    for j in range(length):
        # for each row. matrix_all list contain row of matrix_21 and matrix_22
        matrix_all[length + j] = matrix_21[j] + matrix_22[j]
    return matrix_all


def strassen(matrix_a, matrix_b):
    '''
    :param matrix_a:
    :param matrix_b:
    :return:matrix_a * matrix_b
    '''
    rows = len(matrix_a)
    if rows == 1:
        matrix_all = [list() for i in range(rows)]
        matrix_all[0].append(matrix_a[0][0] * matrix_b[0][0])
    elif(rows % 2 ==1):   #不能被2整除无法用 strassen,一直递归到无法被2整除,或者只剩一个元素(如上面),就用NumPy做正常的MatMul
        # 但实际用的时候应该分解到能较快计算矩阵时,矩阵能更好的利用硬件时,就可以停止,或者可以搜索得到应该停止的规模,而不一定非得是奇数或1,这又和原矩阵的形状相关的,看最终矩阵取什么值可以更少地乘2^k次方得到原矩阵
        """ 正常MatMul如下:
        C11 = A11 • B11 + A12 • B21
        C12 = A11 • B12 + A12 • B22
        C21= A21 • B11 + A22 • B21
        C22 = A21 • B12 + A22 • B22 
        """
        matrix_a_np = np.array(matrix_a)
        matrix_b_np = np.array(matrix_b)
        matrix_all = np.dot(matrix_a_np,matrix_b_np)
        global num_mul,num_addorsub
        num_mul = num_mul + 27
        num_addorsub=num_addorsub + 18
    else:
        # 10 first parts of computing. 由于不涉及乘法,可以直接计算
        # S1 = B12 - B22
        # S2 = A11 + A12
        # S3 = A21 + A22
        # S4 = B21 - B11
        # S5 = A11 + A22
        # S6 = B11 + B22
        # S7 = A12 - A22
        # S8 = B21 + B22
        # S9 = A11 - A21
        # S10 = B11 + B12
        s1 = matrix_minus((matrix_divide(matrix_b, 1, 2)), (matrix_divide(matrix_b, 2, 2)))
        s2 = matrix_add((matrix_divide(matrix_a, 1, 1)), (matrix_divide(matrix_a, 1, 2)))
        s3 = matrix_add((matrix_divide(matrix_a, 2, 1)), (matrix_divide(matrix_a, 2, 2)))
        s4 = matrix_minus((matrix_divide(matrix_b, 2, 1)), (matrix_divide(matrix_b, 1, 1)))
        s5 = matrix_add((matrix_divide(matrix_a, 1, 1)), (matrix_divide(matrix_a, 2, 2)))
        s6 = matrix_add((matrix_divide(matrix_b, 1, 1)), (matrix_divide(matrix_b, 2, 2)))
        s7 = matrix_minus((matrix_divide(matrix_a, 1, 2)), (matrix_divide(matrix_a, 2, 2)))
        s8 = matrix_add((matrix_divide(matrix_b, 2, 1)), (matrix_divide(matrix_b, 2, 2)))
        s9 = matrix_minus((matrix_divide(matrix_a, 1, 1)), (matrix_divide(matrix_a, 2, 1)))
        s10 = matrix_add((matrix_divide(matrix_b, 1, 1)), (matrix_divide(matrix_b, 1, 2)))
        # 7 second parts of computing. 由于涉及乘法,而S系列又是在上面直接计算得到,所以A和B系列需要递归用strassen计算. log_2(7) 就是由P系列的递归计算而来
        # P1 = A11 • S1
        # P2 = S2 • B22
        # P3 = S3 • B11
        # P4 = A22 • S4
        # P5 = S5 • S6
        # P6 = S7 • S8
        # P7 = S9 • S10
        p1 = strassen(matrix_divide(matrix_a, 1, 1), s1)
        p2 = strassen(s2, matrix_divide(matrix_b, 2, 2))
        p3 = strassen(s3, matrix_divide(matrix_b, 1, 1))
        p4 = strassen(matrix_divide(matrix_a, 2, 2), s4)
        p5 = strassen(s5, s6)
        p6 = strassen(s7, s8)
        p7 = strassen(s9, s10)
        # 4 final parts of result
        # C11 = P5 + P4 - P2 + P6
        # C12 = P1 + P2
        # C21 = P3 + P4
        # C22 = P5 + P1 - P3 - P7
        c11 = matrix_add(matrix_add(p5, p4), matrix_minus(p6, p2))
        c12 = matrix_add(p1, p2)
        c21 = matrix_add(p3, p4)
        c22 = matrix_minus(matrix_add(p5, p1), matrix_add(p3, p7))
        matrix_all = matrix_merge(c11, c12, c21, c22)
        global num_assign
        num_assign =num_assign+22
    return matrix_all


def main():
    # read data
    # A = read_matrix('matrixA.txt')
    # B = read_matrix('matrixB.txt')
    
    A_arr = np.random.rand(6, 6)
    B_arr = np.random.rand(6, 6)
    print("Rand Matrix A:")
    print(A_arr)
    print("Rand Matrix B:")
    print(B_arr)
    A = A_arr.tolist()
    B = B_arr.tolist()

    # compute A*B
    C = strassen(A,B)
    print("\nResult of matrix given\n",np.array(C))

    # verificate A*B
    C_verification=np.dot(A,B)
    print("\n Result of NumPy:")
    print(C_verification)
    print("\nSubtract from standard results\n",np.array((C-C_verification),dtype=int))

    # statistical data
    print("\nfrequency of add/sub",num_addorsub)
    print("frequency of assign", num_assign)
    print("frequency of mul", num_mul)
    
    # 下面是整数矩阵
    # new_matrixA = np.random.random_integers(-5,5,size=(8, 8))
    # print("\nRandom Matrix A:\n", new_matrixA)
    # new_matrixB = np.random.random_integers(-5,5,size=(8, 8))
    # print("\nRandom Matrix B:\n", new_matrixB)

    # AdotB=strassen(new_matrixA, new_matrixB)
    # print("\n A*B Result of matrixs by generate randomly\n",np.array(AdotB))

    # BdotA = strassen(new_matrixB, new_matrixA)
    # print("\n B*A Result of matrixs by generate randomly\n", np.array(BdotA))

    # result=new_matrixA
    # for i in range(0,2019):
    #     result=strassen(result,new_matrixA)
    # print("\n A^2019 Result of matrixs by generate randomly\n",np.array(result))
if __name__ == '__main__':
    main()