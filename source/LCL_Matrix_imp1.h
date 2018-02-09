#include "LCL/Maths/LCL_Matrix.h"

template<class T, int N, int M>
T LCL_Matrix<T,N,M>::LCL_MatrixBadVal;

#include "LCL/Core/LCL_ConsoleOut.h"
using namespace LCL_ConsoleOut;

#include <iostream>
using namespace std;

template <class T, int N, int M>
LCL_Matrix<T,N,M>::LCL_Matrix() {
    _r(0,N-1);
    _c(0,M-1);
    _r = 0;
    _c = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            _e[i][j] = 0;
        }
    }
}

template <class T, int N, int M>
LCL_Matrix<T,N,M>::LCL_Matrix(const LCL_Matrix& in) {
    _r(0,N-1);
    _c(0,M-1);
    _r = in._r;
    _c = in._c;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            _e[i][j] = in._e[i][j];
        }
    }
}

template <class T, int N, int M>
LCL_Matrix<T,N,M>::LCL_Matrix(int in_r, int in_c) {
    _r(0,N-1);
    _c(0,M-1);
    _r = in_r;
    _c = in_c;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            _e[i][j] = 0;
        }
    }
}

template <class T, int N, int M>
const T& LCL_Matrix<T,N,M>::operator()(int i, int j) const {
    if((i>=0)&&(i<_r)&&(j>=0)&&(j<_c)) {
        return _e[i][j];
    } else {
        error("Index out of bounds.", "operator()", "LCL_Matrix");
        return LCL_MatrixBadVal;
    }
}

template <class T, int N, int M>
T& LCL_Matrix<T,N,M>::operator()(int i, int j) {
    if((i>=0)&&(i<_r)&&(j>=0)&&(j<_c)) {
        return _e[i][j];
    } else {
        error("Index out of bounds.", "operator()", "LCL_Matrix");
        return LCL_MatrixBadVal;
    }
}

template <class T, int N, int M>
LCL_Matrix<T,N,M>& LCL_Matrix<T,N,M>::operator=(const LCL_Matrix& in) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            _e[i][j] = in._e[i][j];
        }
    }
    return (*this);
}

template <class T, int N, int M>
int LCL_Matrix<T,N,M>::r() const {
    return _r;
}

template <class T, int N, int M>
int& LCL_Matrix<T,N,M>::r() {
    return _r;
}

template <class T, int N, int M>
int LCL_Matrix<T,N,M>::c() const {
    return _c;
}

template <class T, int N, int M>
int& LCL_Matrix<T,N,M>::c() {
    return _c;
}

template <class T, int N, int M>
LCL_Array<int,2> LCL_Matrix<T,N,M>::dims() const {
    LCL_Array<int,2> out(2);
    out[0] = _r;
    out[1] = _c;
    return out;
}

template <class T, int N, int M>
void LCL_Matrix<T,N,M>::dims(int in_r, int in_c) {
    _r = in_r;
    _c = in_c;
}

template <class T, int N, int M>
LCL_Matrix<T,N,M> LCL_Matrix<T,N,M>::operator+(const LCL_Matrix& b) const {
    LCL_Matrix<T,N,M> out;

    if((_r==b._r)&&(_c==b._c)) {
        out.dims(_r,_c);
        for(int i = 0; i < _r; i++) {
            for(int j = 0; j < _c; j++) {
                out(i,j) = (operator()(i,j) + b(i,j));
            }
        }
    } else {
        error("Operand dimensions must match.", "operator+", "LCL_Matrix");
    }

    return out;
}

template <class T, int N, int M>
LCL_Matrix<T,N,M> LCL_Matrix<T,N,M>::operator*(const LCL_Matrix& b) const {
    LCL_Matrix<T,N,M> out;

    if(_c==b._r) {
        out.dims(_r,b._c);
        for(int i = 0; i < _r; i++) {
            for(int j = 0; j < b._c; j++) {
                for(int k = 0; k < _c; k++) {
                    out(i,j) += operator()(i,k)*b(k,j);
                }
            }
        }
    } else {
        error("Inner dimensions must match.", "operator*", "LCL_Matrix");
    }

    return out;
}

template <class T, int N, int M>
LCL_Matrix<T,N,M> LCL_Matrix<T,N,M>::operator-() const {
    LCL_Matrix<T,N,M> out(_r,_c);

    for(int i = 0; i < _r; i++) {
        for(int j = 0; j < _c; j++) {
            out(i,j) = (-out(i,j));
        }
    }

    return out;
}

template <class T, int N, int M>
LCL_Matrix<T,N,M> LCL_Matrix<T,N,M>::operator-(const LCL_Matrix& b) const {
    return operator+(-b);
}

template <class T, int N, int M>
LCL_Matrix<T,N,M> LCL_Matrix<T,N,M>::operator*(const T& b) const {
    LCL_Matrix<T,N,M> out(_r,_c);

    for(int i = 0; i < _r; i++) {
        for(int j = 0; j < _c; j++) {
            out(i,j) = (operator()(i,j)*b);
        }
    }

    return out;
}

template <class T, int N, int M>
LCL_Matrix<T,N,M> LCL_Matrix<T,N,M>::operator/(const T& b) const {
    LCL_Matrix<T,N,M> out(_r,_c);

    for(int i = 0; i < _r; i++) {
        for(int j = 0; j < _c; j++) {
            out(i,j) = (operator()(i,j)/b);
        }
    }

    return out;
}

template <class T, int N, int M>
ostream& operator<<(ostream& os, const LCL_Matrix<T,N,M>& in) {
    for(int i = 0; i < in._r; i++) {
        for(int j = 0; j < in._c; j++) {
            os << in._e[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
