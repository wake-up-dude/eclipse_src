/*
 * solver_func.h
 *
 *  Created on: Oct 7, 2017
 *      Author: Yan
 */

#ifndef SOLVER_FUNC_H_
#define SOLVER_FUNC_H_

#include<iostream>
#include "initial.h"
using namespace std;

void solver(struct sudo box[][10]);

void check_x();

void check_y();

void check_sec();

void update_res();

void update_del();

#endif /* SOLVER_FUNC_H_ */
