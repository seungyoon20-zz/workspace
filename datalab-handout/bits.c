/* 
 * CS:APP Data Lab 
 * 
 * <Yixue Wang, ywang20>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
  return ((0xaa << 24) | (0xaa << 16) | (0xaa << 8) | 0xaa);//use shift to get 0xaaaaaaaa
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
	return (!(x+x))&(!!x);//tmin is 0x10000000, tmin+tmin equals 0 and tmin is not 0
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	int a = ~(x&y);
	int b = ~(~x&~y);
	return a&b;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int helperNum = !!x << 31 >> 31;//if x is true, helperNum will be 0x11111111, otherwise 0x00000000
  return (y&helperNum) + (z&(~helperNum));//helperNum determines y or z to be cleaned
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
	int helperNum;
	x = x | x >> 1;
	x = x | x >> 2;
	x = x | x >> 4;
	x = x | x >> 8;
	x = x | x >> 16;
	//currently x becomes a 32-bits number with all position in the left of greatestBitPos set to 1
	helperNum = (~x >> 1) | (1 << 31);
	return x & helperNum;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	int helperNum = (1 << n) + (1 << 31 >> 31);//in case of overflow
	x = (x + (helperNum & (x >> 31))) >> n;
	//if x is positive then no bias, other wise add the bias then right shift
	return x;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  return !(x >> 31);//if x is negative, x >> 31 is 0x11111111, otherwise 0x00000000
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
	int tmin = 1 << 31;//0x10000000
	int sign = x >> 31;
	int overflow;
	int helperNum;
	int twicex = x+ x;
	overflow = ((twicex ^ x) >> 31);
	//check if the sign has changed, if changed overflow equals 0x11111111, otherwise 0
	helperNum = overflow & (sign ^ (~tmin));
	//if overflow, saturating to tmin or tmax depending on sign
	return ((twicex & (~overflow)) | helperNum);
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
	int signx = (x >> 31) & 1;
	int signy = (y >> 31) & 1;
	int sign = x + (~y + 1);
	sign = sign >> 31;
	sign  = sign & 1;
	//since simply compute x-y may lead to overflow, need to check the sign first
	return (signx & (!signy)) | ((!(signx ^ signy)) & sign);
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	int sign30 = ((x + (~0x30 + 1)) >> 31 ) & 1;
	int sign39 = ((0x39 + (~x + 1)) >> 31) & 1;
	//check if x is between 30 and 39
	return !(sign30 | sign39);
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
	int helperNumber = x & 3;
	//3/4 = 1/4 + (1/4)*2
	int result = (x >> 2 << 1) + (x >> 2);
	//take care of the possible overflow
	result = result + ((helperNumber + helperNumber + helperNumber) >> 2);
	result = result + ((!!helperNumber) & (x >> 31));
	return result;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	int result = 0;
	int sign = x >> 31;
	int helper1 = 0x55;
	int helper2 = 0x33;
	int helper4 = 0x0f;
	int helper8 = 0xff;
	int helper16 = 0xff;

	x = x | x >> 1;
	x = x | x >> 2;
	x = x | x >> 4;
	x = x | x >> 8;
	x = x | x >> 16;
	x = (x & (~sign)) >> 1;
	//similar to greatestBitPos, set all bits left to the largest 1

	//count how many 1s in the 32-bits integer
	helper1 = helper1 | (helper1 << 8);
	helper1 = helper1 | (helper1 << 16);

	helper2 = helper2 | (helper2 << 8);
	helper2 = helper2 | (helper2 << 16);

	helper4 = helper4 | (helper4 << 8);
	helper4 = helper4 | (helper4 << 16);

	helper8 = helper8 | (helper8 << 16);
	helper16 = helper16 | (helper16 << 8);

	result = ((x & helper1) + ((x >> 1) & helper1));
	result = ((result & helper2) + ((result >> 2) & helper2));
	result = (result + (result >> 4)) & helper4;
	result = (result + (result >> 8)) & helper8;
	result = (result + (result >> 16)) & helper16;

	//the count is right ilog2
	return result;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	int sexp = (uf & (0xff << 23));//isolate expr part
	int f = uf << 9;//shift until only fraction part left
	sexp = sexp << 1 >> 24;
	if(!(~sexp) && f){//if x is NaN
		return uf;
	}
	return uf ^ (1 << 31);//if not just reverse the sign
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	int tmin = 0x1 << 31;
	unsigned sign = x & tmin;
	unsigned expr = 0x9e;
	unsigned frac;
	if(!(x ^ tmin)){ //if the given integer is right tmin, return the floating number equals to tmin
		return (0xcf << 24);
	}
	if(!x){ // if the give interger is right 0, return flaot 0
		return 0;
	}
	if(sign){//cast signed integer to unsigned integer
		x = (~x)+ 1;
	}
	while(!(x & tmin)){//shift until the greatest bit is 1
		x = x << 1;
		expr = expr + (tmin >> 31);//each time shift expr minus 1
	}

	//fraction
	frac = (x &(~tmin)) >> 8;
	//take care of the possible overflow
	if((x & 0x80) && ((x & 0x7f) || (frac & 0x1))){
		frac = frac + 1;
	}
	return (sign + (expr << 23) + frac);
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	int exp = uf & (0xff << 23);//isolating expr part
	int helper = exp << 1 >> 24;//shift expr to right most positions
	int a = ((0x7f << 16)| (0xff << 8) | 0xff);//a is all-1 frac part
	int b = (1 << 23);//a helper number for normalized floating
	int frac = uf & a;//isolate frac part
	int sign = uf & (1 << 31);//isolate the sign
	if(!(~helper) || !(helper || frac)){//if x is NaN, return itself remained unchanged
		return uf;
	}
	if(exp){//if normalized float
		exp = exp + b;
	}
	else if(!(frac ^ a)){//if the largest denormalized float
		frac = frac + (1 << 31 >> 31);//frac minus 1
		exp = exp + b;
	}
	else{//little denormalized number
		frac = frac << 1;
	}
	return (sign | exp | frac);//combine the sign, expr and frac parts together
}
