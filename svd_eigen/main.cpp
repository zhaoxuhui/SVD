# include<iostream>
#include <Eigen/Dense>
// 对于Windows下的VS注意在导入Eigen库之前需要先在项目的“属性-C/C++-常规-附加包含目录”里添加Eigen库所在目录
// 对于Linux下的CMake，在CMakeLists.txt文件里find_package(Eigen3 REQUIRED)再包含目录即可

using namespace std;
using namespace Eigen;

int main() {
    // 测试矩阵，分别为2×3和3×2
    Matrix<float, 2, 3> A1;
    A1 << 1, 2, 3, 4, 5, 6;
    Matrix<float, 3, 2> A2;
    A2 << 1, 2, 3, 4, 5, 6;

    // 构造SVD对象，除了BDC还有Jacobian等方法
    BDCSVD<Eigen::MatrixXf> svd1(A1, ComputeThinU | ComputeThinV);
    BDCSVD<Eigen::MatrixXf> svd2(A2, ComputeThinU | ComputeThinV);

    // Eigen得到的是奇异值向量以及V，所以需要构造对角阵并对V转置
    cout << svd1.matrixU() * svd1.singularValues().asDiagonal() * svd1.matrixV().transpose() << endl;
    cout << svd2.matrixU() * svd2.singularValues().asDiagonal() * svd2.matrixV().transpose() << endl;
    return 0;
}