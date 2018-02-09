#include <iostream>
using namespace std;

#include "LCL/LCL.h"

#include <cstdlib>

int main(int argc, char** argv) {

    F7Mat<10,10> A(2,2), B(2,1);

    A(0,0) = 5;
    A(1,1) = 3;
    B(0,0) = 8;
    B(1,0) = 1;

    cout << A << endl;

    F7Mat<10,10> C = A/2;

    cout << C << endl;

    /*
        TODO:
            - Declare and implement the rest of LCL_Matrix class
            - Document LCL_Field, LCL_OrderedField, LCL_FiniteField
            - Document LCL_Matrix
            - Input for matrix from file:
                - implement >> overrides for fields
                - Put each line of file into stringstream
                - Try Get matrix elements using >> operator until stringstream is eof
                - If successful, increment row number
                - Otherwise exit
                - If this row has more elements than the current number of output columns then set to number of elements in this row.
                - If either row or col exceed max rows or cols exit and report an error
                - Otherwise output the populate matrix

    */

    return 0;
}
