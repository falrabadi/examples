/**
 * @file fib.cc
 * @author Krerkkiat Chusap 
 * @editor: Nathaniel Buchanan
 * @date Last edited: March 15, 2021
 * @brief Two different implementation of the Fibonacci functions.
 * 
 * All of the documentation for these functions are in the header file already.
 */
#include "fib.h"

/**
 *  Calculates the fib sequence in a recursive manner up to the value
 *  that the user enters. 
 * */
int fib_recursive(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    /** <h4>Implementation Note</h4>
     * Instead of saving the values and add them before returning them
     * we saved ourselves from declaring variables by returning
     * the value from the expression directly.
     * */
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

/**
 * Calculates the fib sequence in a non-recursive manner up to
 * the value that the user enters.
 * */
int fib_iterative(int n) {
    int a, b, temp;
    a = 1;
    b = 1;

    /**
     <h4>Implementation Note</h4>
     Instead of using multiple `if` statements, we only
     use one `if` statement with two logical expressions.*/
    if (n == 1 || n == 2) {
        return 1;
    }

    /**
     * This loop is used to go through the entire sequence
     * from each number from 3 and to the value that the
     * user entered.
     */
    for (int i = 3; i <= n; i++) {
        temp = b;
        b = a + b;
        a = temp;
    }

    return b;
}
