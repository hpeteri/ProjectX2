#include "src/calculator.h"
#include "src/calculator.h"

#include <assert.h>
#include <limits.h>

void ut_add(void)
{
    int result;

    result = calculator(1, '+', 1);
    assert(result == 2);

    result = calculator(1, '+', -1);
    assert(result == 0);

    result = calculator(-1, '+', -1);
    assert(result == -2);

    result = calculator(INT_MIN, '+', -1);
    assert(result == INT_MAX);

    result = calculator(INT_MAX, '+', 1);
    assert(result == INT_MIN);
}

void ut_subtract(void)
{
    int result;

    result = calculator(1, '-', 1);
    assert(result == 0);

    result = calculator(1, '-', -1);
    assert(result == 2);

    result = calculator(-1, '-', -1);
    assert(result == 0);

    result = calculator(INT_MIN, '-', 1);
    assert(result == INT_MAX);

    result = calculator(INT_MAX, '-', -1);
    assert(result == INT_MIN);
}

void ut_multiply(void)
{
    int result;

    result = calculator(20, '*', -1);
    assert(result == -20);

    result = calculator(20, '*', 0);
    assert(result == 0);

    result = calculator(0, '*', 20);
    assert(result == 0);

    result = calculator(INT_MAX, '*', -1);
    assert(result == INT_MIN + 1);

    result = calculator(INT_MIN, '*', -1);
    assert(result == INT_MAX + 1); //overflow
}

void ut_divide(void)
{
    int result;

    result = calculator(20, '/', -1);
    assert(result == -20);

    result = calculator(20, '/', 0);
    assert(result == 1);

    result = calculator(0, '/', 20);
    assert(result == 0);
}

int main() {

    ut_add();
    ut_subtract();
    ut_multiply();
    ut_divide();

    return 0;
}
