/*
 * solver_func.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: Yan
 */

#ifndef SOLVER_FUNC_CPP_
#define SOLVER_FUNC_CPP_

#include "solver_func.h"

void solver(struct sudo box[][10]){
	cout << "solver is working now" << endl;
	int check = box[5][4].hit;
	cout << "if the number is 6666 : ||" << check << endl;
	cout << box[5][4].Reserve[3]<< endl;

	//call three solver functions
	check_x(box);

	//check_y(box);
	cout << "if it is 2, then wow !!: " << box[5][7].hit << endl;
	/*
	check_sec(box);

	*/
}

void check_x(struct sudo box[][10]){
	int hit;

	for(int y=1;y<10;y++){
		for(int x=1;x<10;x++){
			if(box[x][y].hit != 0){
				hit = box[x][y].hit;//the actually number, solved or pre-saved
				update_res(box,x,y,0,hit);//0 for x update, 1 for y
				update_res(box,x,y,1,hit);
			}
		}
	}
}

void check_y(struct sudo box[][10]){
	;
}

void check_sec(struct sudo box[][10]){
	;
}

void update_res(struct sudo box[][10], int x, int y, int x_y, int hit){

	//if x or y =0, then update the other one, vice versa.
	//x=0, update y column
	if (x_y==0){//update along x
		for (int temp=1;temp<10;temp++){
			if(box[temp][y].Reserve[hit]==0){//not yet been updated
				box[temp][y].Reserve[hit] = 1;//set it to 1, indicate this number is occupied
				box[temp][y].Num_R--;// one less number possible to fill
				box[temp][y].hit = return_hit(box[temp][y].Reserve, box[temp][y].Num_R);
			}//else{;}   ..not change the value, cuz its 3 or 6, indicate 3*box is occupied, for other use
		}
	}else{//update along y
		for (int temp=1;temp<10;temp++){
			if(box[x][temp].Reserve[hit]==0){//not yet been updated
				box[x][temp].Reserve[hit] = 1;//set it to 1, indicate this number is occupied
				box[x][temp].Num_R--;// one less number possible to fill
				box[x][temp].hit = return_hit(box[x][temp].Reserve, box[x][temp].Num_R);
			}
		}
	}
}
void update_del(){
	;
}

int return_hit(int *Reserve_array, int number_left){
	if(number_left == 1){
		for(int check =1; check < 10;check ++){
			if(Reserve_array[check] == 0){
				Reserve_array[check] = 1;// hit found, update hit, and return the number to hit.
				return check;
			}
		}
	}else{
		return 0;// don't update, number_left not == 1, still more than one possible hit
	}
	return 0;
}
//////////////////////////////////////////||||||||||||||||
//global function to decrement the Num_empty...ei.. how?....

#endif /* SOLVER_FUNC_CPP_ */
