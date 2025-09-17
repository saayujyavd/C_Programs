//
// calculator.h
//
//      Copyright (c) K&R Corporation. All rights reserved.
//
// The reverse Polish (postfix) calculator(integer only) <calc.h> header.
// 
// Developed by: Saayujya Vishwakumar Deshpande
//

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100		/* max size of expression */
#define NUMBER 1	/* signal that a number was found */

double calculate(void);
