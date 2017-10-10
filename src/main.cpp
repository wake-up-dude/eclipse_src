#include <iostream>
#include "initial.h"
#include "solver_func.h"
using namespace std;

int main(){
	//welcome message
	cout << "I am in main now, first row running" << endl;

/////////////////////////////////////////////////////////////////////////
/////////////////////Code start here/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

	// declare the sudo box
	sudo box[10][10];
	int Num_empty = 81; //9*9 matrix boxes, unsolved

	// initial the sudo box
	initial_matrix(box,(&Num_empty));

	//using check func, also able to check the final result
	//hit_check(box);

	// outer do while looping until solved
	do{
		solver(box);
		/*
		for(int y_row=0;y_row < 10; y_row++){
			for(int x_row=0; x_row<10; x_row++){
				;
			}
		}
		*/
	}while(0);//(Num_empty = 0);


	/*test section begin
	cout << box[5][4].x << endl;
	cout << box[5][4].y << endl;
	cout << box[5][4].hit << endl;
	cout << box[4][5].Num_D << endl;
	cout << box[4][5].Reserve[9]<< endl;
	cout << box[4][5].Decline[2]<< endl;
	//test section end
	*/
	cout << "check check: Hello it is the end of the Project :D" << endl;
	return 0;
}
