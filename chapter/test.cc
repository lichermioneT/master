#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;

void test()
{
    // 定义一个 3×3 的 double 矩阵
    Matrix3d A;
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    cout << "A =\n" << A << "\n\n";

    // 1. 转置
    cout << "A.transpose() =\n" << A.transpose() << "\n\n";

    // 2. 元素求和
    cout << "sum(A) = " << A.sum() << "\n\n";

    // 3. 迹（主对角线之和）
    cout << "trace(A) = " << A.trace() << "\n\n";

    // 4. 数乘
    cout << "2 * A =\n" << 2 * A << "\n\n";

    // 5. 行列式
    cout << "det(A) = " << A.determinant() << "\n\n";

    // 6. 逆矩阵（注意：此矩阵不可逆，仅示例）
    // A 的行列式为 0，所以不能求逆；我们改用一个可逆矩阵
    Matrix3d B;
    B << 1, 2, 3,
         0, 1, 4,
         5, 6, 0;

    cout << "B =\n" << B << "\n\n";
    cout << "B.inverse() =\n" << B.inverse() << "\n\n";
    cout << "det(B) = " << B.determinant() << "\n\n";
}


int main() 
{

    Matrix<double, 3, 3> R; // 模板。可以定义自己想要的矩阵

// 基本的矩阵，已经存在了的
    // Matrix2d A;
    // A << 1, 2,
    //      3, 4;
    // std::cout << "Matrix A:\n" << A << std::endl;
    // cout<<endl;
    // Matrix3f aa;
    // for(int i = 0; i < 2; i++)
    // {
    //     for(int j = 0; j < 2; j++)
    //     {
    //         cout<< A(i, j) <<endl;
    //     }
    // }

// 初始化为零
    Matrix3d matrix_33 = Matrix3d::Zero();   

// 动态的矩阵
    Matrix<double, Dynamic, Dynamic> Matrix_dynamic; // Dynamic -1

// 类型不确定
    MatrixXd Matrix_x;




    // for(int i = 0; i < A.rows(); i++)
    // {
    //     for(int j = 0; j < A.cols(); j++)
    //     {
    //         cout << A(i, j) << " ";
    //     }
    //     cout << endl;
    // }


// 矩阵相乘
// 类型和对齐 才能相乘



// A 是 2×3 矩阵
    // Matrix<double, 2, 3> A2;
    // A2 << 1, 2, 3,
    //      4, 5, 6;

    // // B 是 3×2 矩阵
    // Matrix<double, 3, 2> B2;
    // B2 << 1, 2,
    //      3, 4,
    //      5, 6;

    // // C = A * B 将得到 2×2 矩阵
    // Matrix<double, 2, 2> C = A2 * B2;

    // cout << "A:\n" << A2 << endl << endl;
    // cout << "B:\n" << B2 << endl << endl;
    // cout << "C = A * B:\n" << C << endl;



    // test();

// 矩阵的求解











    return 0;
}

