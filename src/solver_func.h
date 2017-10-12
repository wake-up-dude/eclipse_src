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

void checking(struct sudo box[][10]);

void update_sec(struct sudo box[][10], int sec_x, int sec_y, int hit);

void check_33_sec(struct sudo box[][10],int sec_x, int sec_y, int hit);

void update_res(struct sudo box[][10], int x, int y, int x_y, int hit);

int return_hit(int *Reserve_array, int number_left);

void update_hit(int idx, int idy, int xory, int num);

void hit_check_xy(struct sudo box[][10]);

void x_solving(int num, int xory, struct sudo box[][10]);

void y_solving(int num, int xory, struct sudo box[][10]);

void sect_solving(int sec_x, int sec_y,int num, struct sudo box[][10]);

void update_hit(int idx, int idy, int xory, int num, struct sudo box[][10]);

void update_hit_sec(int x, int y, int num, struct sudo box[][10]);

void update_Num_empty();

#endif /* SOLVER_FUNC_H_ */
