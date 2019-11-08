# coding=utf-8
import numpy as np

if __name__ == '__main__':
    A1 = np.array([[1,2,3],[4,5,6]])
    A2 = np.array([[1, 2],[3, 4], [5, 6]])

    # 利用Numpy进行SVD分解
    # Numpy返回的是特征值向量以及转置后的VT
    u1, sv1, vt1 = np.linalg.svd(A1)
    s1 = np.zeros([2,3])
    s1[0,0] = sv1[0]
    s1[1,1] = sv1[1]
    A1_ = np.matmul(np.matmul(u1,s1),vt1)

    u2, sv2, vt2 = np.linalg.svd(A2)
    s2 = np.zeros([3,2])
    s2[0,0] = sv2[0]
    s2[1,1] = sv2[1]
    A2_ = np.matmul(np.matmul(u2,s2),vt2)

    print A1_
    print A2_