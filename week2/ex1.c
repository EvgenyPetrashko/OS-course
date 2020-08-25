#include <stdio.h>
#include <float.h>
#include <limits.h>


int main() {


    int int_var = INT_MAX;
    float float_var = FLT_MAX;
    double double_var = DBL_MAX;
    printf("INT_SIZE: %ld\n", sizeof(int_var));
    printf("FLOAT_SIZE: %ld\n", sizeof(float_var));
    printf("DOUBLE_SIZE %ld\n", sizeof(double_var));
    printf("INTEGER_MAX_VALUE: %ld\n", int_var);
    printf("FLOAT_MAX_VALUE: %f\n", float_var);
    printf("DOUBLE_MAX_VALUE: %lf\n", double_var);
    return 0;
}
