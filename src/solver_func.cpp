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
	//int check = box[5][4].hit;
	//cout << "if the number is 6666 : ||" << check << endl;
	//cout << box[5][4].Reserve[3]<< endl;

	//call three solver functions
	checking(box);

	cout << "if it is 2, then wow !!: " << box[5][7].hit << endl;
	/*
	check_sec(box);

	*/
}

void checking(struct sudo box[][10]){
	int hit;

	for(int y=1;y<10;y++){
		for(int x=1;x<10;x++){
			if(box[x][y].hit != 0){
				hit = box[x][y].hit;//the actually number, solved or pre-saved
				update_res(box,x,y,0,hit);//0 for x update, 1 for y
				update_res(box,x,y,1,hit);//1 for updating along y axis
				update_sec(box,box[x][y].sec_x,box[x][y].sec_y,hit);//updating with the section
				//check_33_sec(box,box[x][y].sec_x,box[x][y].sec_y,hit);
			}
		}
	}
}

void update_sec(struct sudo box[][10],int sec_x, int sec_y, int hit){
	for(int y = sec_y; y < (sec_y + 3); y++){
		for(int x = sec_x; x < (sec_x + 3); x++){
			if( box[x][y].Reserve[hit] == 0){
				box[x][y].Reserve[hit] = 1;
				box[x][y].Num_R--;
				box[x][y].hit = return_hit(box[x][y].Reserve, box[x][y].Num_R);
			}
		}
	}
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

void check_33_sec(struct sudo box[][10],int sec_x, int sec_y, int hit){

////////////checking along x direction
	int count = 0;
	int imhit_3 = 0;

	int survive_index_y;

	for(int y = sec_y; y < (sec_y + 3); y++){
		for(int x = sec_x; x < (sec_x + 3); x++){
			if( box[x][y].Reserve[hit] == 1){
				count++;
			}
		}
		if(count == 3){
			imhit_3++;
		}else{
			survive_index_y = y;
		}
		count = 0;// reset count, to check 3 consecutive impossible to hit
	}

	//update the parallel section's reserve array, if there r 2 consecutive unhit
	if (imhit_3 == 2){// there are 2 consecutive row with imhit, so the left one should be
		for(int temp = 1; temp < 10; temp++){
			if(temp<sec_x || temp >(sec_x+3)){
				box[temp][survive_index_y].Reserve[hit] = 1;
			}
		}
	}
////////////////////////////////////////////////////////////////////
	////checking along y section direction|||
	count = 0;
	imhit_3 = 0;
	int survive_index_x;
	for(int x = sec_x; x < (sec_x + 3); x++){
		for(int y = sec_y; y < (sec_y + 3); y++){
			if( box[x][y].Reserve[hit] == 1){
				count++;
			}
		}
		if(count == 3){
			imhit_3++;
		}else{
			survive_index_x = x;
		}
		count = 0;// reset count, to check 3 consecutive impossible to hit
	}

	if (imhit_3 == 2){// there are 2 consecutive row with imhit, so the left one should be
		for(int temp = 1; temp < 10; temp++){
			if(temp<sec_y || temp >(sec_y+3)){
				box[survive_index_x][temp].Reserve[hit] = 1;
			}
		}
	}


}

int return_hit(int *Reserve_array, int number_left){
	if(number_left == 1){
		for(int check =1; check < 10;check ++){
			if(Reserve_array[check] == 0){
				Reserve_array[check] = 1;// hit found, update hit, and return the number to hit.
				update_Num_empty();
				return check;
			}
		}
	}else{
		return 0;// don't update, number_left not == 1, still more than one possible hit
	}
	return 0;
}
///////////////
void hit_check_xy(struct sudo box[][10]){
	for(int num=1; num < 10; num ++){
		for(int xory=1; xory <10; xory ++){
			x_solving(num, xory, box);
			y_solving(num, xory, box);
		}
		//for for section_solving
		for(int sec_y=1; sec_y < 8; sec_y= sec_y+3){
			for(int sec_x=1; sec_x < 8; sec_x= sec_x+3){
				sect_solving(sec_x, sec_y,num,box);
			}
		}
	}
}

void x_solving(int num, int xory, struct sudo box[][10]){
	int count = 0;
	int idx;
	for (int index=1; index<10; index++){
		if(box[index][xory].Reserve[num]==0){
			count ++;
			idx = index;
		}
	}
	if(count == 1){
		update_hit(idx,0,xory,num,box);
	}
}

void y_solving(int num, int xory, struct sudo box[][10]){
	int count = 0;
	int idy;
	for (int index=1; index<10; index++){
		if(box[num][index].Reserve[num]==0){
			count ++;
			idy = index;
		}
	}
	if(count == 1){
		update_hit(0,idy,xory,num,box);
	}
}

void sect_solving(int sec_x,int sec_y,int num, struct sudo box[][10]){
	int count = 0;
	int r_x;
	int r_y;
	for(int y = 1; y<4; y++){
		for(int x = 1; x<4; x++){
			if(box[x][y].Reserve[num]==0){
				count ++;
				r_x = x;
				r_y = y;
			}
		}
	}
	if(count == 1){
		update_hit_sec(r_x,r_y,num,box);
	}
}
//////////////////////
void update_hit(int idx, int idy, int xory, int num, struct sudo box[][10]){
	if(idx != 0){
		box[idx][xory].Reserve[num] = 1;
		box[idx][xory].hit = num;
		update_Num_empty();
	}
	if(idy != 0){
		box[xory][idy].Reserve[num] = 1;
		box[xory][idy].hit = num;
		update_Num_empty();
	}
}

void update_hit_sec(int x, int y, int num, struct sudo box[][10]){
	box[x][y].Reserve[num] = 1;
	box[x][y].hit = num;
	update_Num_empty();
}

//////////////////////////////////////////||||||||||||||||
//global function to decrement the Num_empty...ei.. how?....
void update_Num_empty(){
	Num_empty--;
}

#endif /* SOLVER_FUNC_CPP_ */
