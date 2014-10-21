/*
 * fp_calculations.h
 *
 *  Created on: Oct 20, 2014
 *      Author: archana
 */

#ifndef SRC_THREADS_FP_CALCULATIONS_H_
#define SRC_THREADS_FP_CALCULATIONS_H_

// x and y denote fixed_point numbers in 17.14 format
// n is an integer




int convert_int_to_fp(int n);
int convert_fp_to_int_round(int x);
int convert_fp_to_int(int x);
int add_fp(int x, int y);
int add_mixed(int x, int n);
int sub_fp(int x, int y);
int sub_mixed(int x, int n);
int mult_fp(int x, int y);
int mult_mixed(int x, int n);
int div_fp(int x, int y);
int div_mixed(int x, int n);



#endif /* SRC_THREADS_FP_CALCULATIONS_H_ */
