/*
 * initial.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: Yan
 */

#include "initial.h"

void hit_check(struct sudo box[][10]){
	//also able to check the solution at last
	for(int y=1;y<10;y++){
		for(int x=1;x<10;x++){
			cout << box[x][y].hit;
		}
		cout << endl;
	}
	/*
	for(int y=1;y<10;y++){
			for(int x=1;x<10;x++){
				cout << box[x][y].Decline[1];
			}
			cout << endl;
		}
	*/
}

//initialize the parameters inside the box, for further solving
void initial_matrix (struct sudo box[][10], int * Num_of_empty){

	int x_col;
	int y_row;

	//using raw_data to save the original sudo question
	string line;
	ifstream file("raw_data.txt");
	int convert_line;

	for(y_row=1; y_row<10; y_row++){
		getline(file, line);
		istringstream ss(line);
		for(x_col=1; x_col<10; x_col++){
			box[x_col][y_row].x = x_col;
			box[x_col][y_row].y = y_row;

			//dum way to set section numb
			initial_sec(x_col, y_row, &(box[x_col][y_row].sec_x), &(box[x_col][y_row].sec_y));

			//store the number for compare
			ss >> convert_line;

			//check hit and update hit, number_left
			if (convert_line == 0){
				box[x_col][y_row].hit = 0;
			}else{
				box[x_col][y_row].hit = convert_line; //store the provided number
				(*Num_of_empty) --; 	//update the empty boxes left number here
			}

			//initial array inside the box
			initial_array(box[x_col][y_row].Reserve,box[x_col][y_row].Decline);
		}
	}
	return;
}

//initialize the section value of box
void initial_sec(int x_col, int y_row, int * sec_x, int * sec_y){
	if (x_col < 4){
		*sec_x = 1;
	}else if( x_col >= 4 &&x_col < 7){
		*sec_x = 4;
	}else{
		*sec_x = 7;
	}
	if (y_row < 4){
		*sec_y = 1;
	}else if( y_row >= 4 &&y_row < 7){
		*sec_y = 4;
	}else{
		*sec_y = 7;
	}
}

//initial the reserve list for the matrix, should include in the matrix, or
//the function should be replaced by update_reserve_list sth
void initial_array(int r_array[], int d_array[]){
	//failed to use the copy function, retry it later !!!!!
	//int all_reserved[10] = {0,1,2,3,4,5,6,7,8,9};
	//copy(all_reserved, all_reserved+2, x);
	for (int index= 1; index <10; index ++){
		r_array[index]=1;
		d_array[index]=0;
	}
	return;
}

