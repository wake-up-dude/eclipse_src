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

void check_x(struct sudo box[][10]);

void check_y(struct sudo box[][10]);

void check_sec(struct sudo box[][10]);

void update_res(struct sudo box[][10], int x, int y, int x_y, int hit);

void update_del();

int return_hit(int *Reserve_array, int number_left);

#endif /* SOLVER_FUNC_H_ */
