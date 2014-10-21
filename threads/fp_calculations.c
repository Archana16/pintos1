/*
 * fp_calculations.c

 *
 *  Created on: Oct 20, 2014
 *      Author: archana
 */
#include "fp_calculations.h"

#define f 2**14
#define F (1 << 14)
#define FP_MAX (1 << 17)

int convert_int_to_fp(int n) {
	return n * F;
}
int convert_fp_to_int_round(int x) {
	if (x >= 0) {
		return (x + F / 2) / F;
	} else {
		return (x - F / 2) / F;
	}
}
int convert_fp_to_int(int x){
	return x/F;
}
int add_fp(int x, int y){
	return x + y;
}
int add_mixed(int x, int n){
	return x + convert_int_to_fp(n);
}
int sub_fp(int x, int y){
	return x - y;
}
int sub_mixed(int x, int n){
	return x - convert_int_to_fp(n);
}
int mult_fp(int x, int y){
	return ((int64_t) x) * y / F;
}
int mult_mixed(int x, int n){
	 return x * n;
}
int div_fp(int x, int y){
	return ((int64_t) x) * F / y;
}
int div_mixed(int x, int n){
	return x/n;
}
