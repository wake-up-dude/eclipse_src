/*
 * initial.h
 *
 *  Created on: Oct 5, 2017
 *      Author: Yan
 */

#ifndef INITIAL_H_
#define INITIAL_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// structure of a box, store info of the box, aid to solve the sudo
struct sudo{

	////////////////////
	//basic infomation//
	int x; //x colume number
	int y; //y colume number
	//sudo divide into 9 big sections, for aid solver
	int sec_x;
	int sec_y;

	////////////////
	//info used aid solving the box
	/////////

	//store the possible numbers of the box
	//each number match its index, 1 means good.
	int Reserve[10];
	//store the declined numbers of the box
	// !!!!!!!!its necessary, solving sudo, 3 dcline in one section can help solving other sect
	int Decline[10];

	//constant update to track how many number alive in reserve list
	int Num_R;
	int Num_D;

	//store the solved number in the it, else it equal to 0
	int hit;

};

//check fucntion, to check the box values
void hit_check(struct sudo box[][10]);


//used for initial the matrix itself
void initial_matrix (struct sudo box[][10], int * Num_of_empty);

//initialize the section number of each box
void initial_sec(int x_col, int y_row, int * sec_x, int * sec_y);

//initial the reserve list for the matrix, should include in the matrix, or
//the function should be replaced by update_reserve_list sth
void initial_array(int r_array[], int d_array[], int q_hit);


#endif /* INITIAL_H_ */
