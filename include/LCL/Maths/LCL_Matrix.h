#ifndef LCL_MATRIX_HEADER
#define LCL_MATRIX_HEADER

/// A class that represents the mathematical objects commonly known as matrices.
/**
    The template parameter T MUST be a class derived from LCL_Field. The ensures operators +,-,*,/ are well defined.
*/

#include "LCL/Core/LCL_Array.h"

template<class T, int N, int M>
class LCL_Matrix {
    private:
        T _e[N][M];
        LCL_BoundedInt _r;
        LCL_BoundedInt _c;
    public:
        LCL_Matrix();
        LCL_Matrix(const LCL_Matrix& in);
        LCL_Matrix(int in_r, int in_c);

        // Accessors
        const T& operator()(int i, int j) const;
        T& operator()(int i, int j);

        // Assignment
        LCL_Matrix& operator=(const LCL_Matrix& in);
        int r() const;
        int c() const;
        int& r();
        int& c();
        LCL_Array<int,2> dims() const;
        void dims(int in_r, int in_c);

        // Input/Output

        // Arithmetic operators
        LCL_Matrix operator+(const LCL_Matrix& b) const;
        LCL_Matrix operator-() const;
        LCL_Matrix operator-(const LCL_Matrix& b) const;
        LCL_Matrix operator*(const T& b) const;
        LCL_Matrix operator/(const T& b) const;
        LCL_Matrix operator*(const LCL_Matrix& b) const;

        // Composition operators

        // Row/column operators

        // Assignment operators

        // Static functions

        // stdout
        template <class Y, int J, int K>
        friend ostream& operator<<(ostream&, const LCL_Matrix<Y,J,K>& in);

        // Badval
        static T LCL_MatrixBadVal;
};

#endif // LCL_MATRIX_HEADER
