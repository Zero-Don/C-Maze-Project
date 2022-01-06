   
/* Name : Daryl Branford
   Student I.d #: 20204896
   Lecturer: Natalie Rose
   Course: ITT200 - Object Oriented Proramming using C++
   

   I CERTIFY THAT I HAVE NOT GIVEN OR RECEIVED ANY UNAUTHORIZED ASSISTANCE ON THIS ASSIGNMENT
*/

#include <iostream>

// for the random functions
#include <cstdlib>
#include <ctime>

using namespace std;

// maze is fixed
// no need to render maze
// place user in random room
// let user move l/r/u/d
// determine if user can move to free space
// user shouldn't be able to revisit path

#define ROWS 15
#define COLS 22

#define R1 0
#define R3 1
#define R5 2
#define R6 3
#define R7 4
#define R8 5
#define NUM_ROOMS 6

#define E2 0
#define E4 1

// this function retruns E2 or E4 if exit is found
// otherwise returns -1
int move(std::string maze[ROWS][COLS], int& row, int& col, string dir) {
	// & <-- it passes the value by reference
    // note: no need for fence post check since maze is surrunded by walls

    int newRow = row;
    int newCol = col;
    // this tests to see if the pathway is clear before moving

    if (dir == "u") newRow -= 1;
    else if (dir == "d") newRow += 1;
    else if (dir == "l") newCol -= 1;
    else if (dir == "r") newCol += 1;
    else {
    	cout<<"invalid input, please enter u , d ,l or r"<<endl;
    	system("pause");
    	return -1;
	}

    string item = maze[newRow][newCol];

    // empty path
    if (item == "0") {
        maze[row][col] = "2";
        row = newRow;
        col = newCol;
    }
    // wall
    else if (item == "1") {
        cout << "You have hit a wall, you cant proceed" << endl;
        system("pause");
    }
    // already visited path
    else if (item == "2") {
        cout << "You cant walk back" << endl;
        system("pause");
    }
    // room
    else if (item[0] == 'R') {
        maze[row][col] = "2";
        row = newRow;
        col = newCol;

        cout << "You've entered a new room" << item << endl;
        system("pause");
    }
    // exit
    else if (item[0] == 'E') {
        cout << "You've reached the exit " << item << "!" << endl;
        system("pause");
        
        if (item == "E2")
        	return E2;
		else return E4;
    }

    return -1;
}


int main()
{
	int numbers[5];
    // player position
    int row = 1;
    int col = 1;
    
    while(true){
    	system("cls");
	   	// seed random function
	    srand(time(NULL));
	    
	     // start with a random room
	    int startingRoom = rand() % NUM_ROOMS;
	    //startingRoom = R6;
		
		// get starting position for room
	    switch (startingRoom) {
	    case R1:
	        row = 1;
	        col = 1;
	        break;
	    case R3:
	        row = 1;
	        col = 8;
	        break;
	    case R5:
	        row = 1;
	        col = 15;
	        break;
	    case R6:
	        row = 9;
	        col = 20;
	        break;
	    case R7:
	        row = 4;
	        col = 20;
	        break;
	    case R8:
	        row = 13;
	        col = 1;
	        break;
	    }
	    
	    string roomNames[6] = {
	        "R1",
	        "R3",
	        "R5",
	        "R6",
	        "R7",
	        "R8"
	    };
	
	    int expectedSteps[8][2] = {
	      // E2  E4
	        {16, 24}, // R1 16 steps to E2 | 24 steps to E4
	        {15, 17}, // R3 15 steps to E2 | 17 steps to E4
	        {22, 16}, // R5 22 steps to E2 | 16 steps to E4
	        {29, 19}, // R6 29 steps to E2 | 19 steps to E4
	        {24, 18}, // R7 24 steps to E2 | 18 steps to E4
	        {32, 30}, // R8 32 steps to E2 | 30 steps to E4
	    };
	
	    string maze[ROWS][COLS] = {
	        {"1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
	        {"1", "R1", "1", "0", "0", "0", "0", "1", "R3", "1", "0", "0", "0", "0", "1", "R5", "1", "0", "0", "0", "0", "1"},
	        {"1", "0", "1", "0", "0", "0", "0", "1", "0", "1", "0", "0", "0", "0", "1", "0", "1", "0", "0", "0", "0", "1"},
	        {"1", "0", "1", "1", "1", "1", "0", "1", "0", "1", "1", "1", "1", "0", "1", "0", "1", "0", "1", "1", "1", "1"},
	        {"1", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "R7", "1"},
	        {"1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "0", "1", "0", "0", "0", "0", "0", "0", "1", "1", "1", "1"},
	        {"1", "0", "0", "0", "0", "0", "1", "0", "0", "0", "0", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0", "1"},
	        {"1", "1", "1", "1", "1", "0", "1", "0", "1", "0", "0", "1", "0", "1", "1", "1", "1", "1", "1", "1", "0", "1"},
	        {"E2", "0", "0", "0", "0", "0", "1", "0", "1", "0", "0", "1", "0", "0", "0", "0", "0", "0", "0", "1", "0", "1"},
	        {"1", "1", "1", "1", "1", "0", "1", "0", "1", "0", "0", "1", "0", "1", "0", "0", "0", "0", "0", "1", "R6", "1"},
	        {"1", "0", "0", "0", "1", "0", "1", "0", "1", "0", "0", "1", "0", "1", "0", "0", "0", "0", "0", "1", "1", "1"},
	        {"1", "0", "0", "0", "0", "0", "1", "0", "1", "0", "0", "1", "0", "1", "0", "0", "0", "0", "0", "0", "0", "1"},
	        {"1", "1", "1", "1", "1", "1", "1", "0", "1", "0", "0", "1", "0", "1", "0", "0", "0", "0", "0", "0", "0", "1"},
	        {"1", "R8", "0", "0", "0", "0", "0", "0", "1", "0", "0", "1", "0", "1", "0", "0", "0", "0", "0", "0", "0", "1"},
	        {"1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "E4", "1", "1", "1", "1", "1", "1", "1", "1", "1"}
	    };
	
	    cout << "+++++++++  Welcome to Daryl's Maze !  +++++++++++" << endl;
	    cout << "The Aim of the game is to reach an exit in the least amount of moves as possible!" << endl;
	    cout << "There are 6 rooms: R1, R3, R5, R6, R7, R8 ... You may start at either one"<< endl;
	    cout << "Follow the path of Zeros to reach an Exit: E2 or E4" << endl;
	    
	    
	    system("pause");
	    
	    cout << " Take a look and Try to remember ... " << endl;
		cout << "    0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21"<< endl;
		cout << " 0  1  1  1  1  1  1  1  1  1  1   1  1   1   1   1   1   1   1   1   1   1   1"<< endl;
		cout << " 1  1 R1  1  0  0  0  0  1 R3  1   0  0   0   0   1   R5  1   0   0   0   0   1"<< endl;
		cout << " 2  1  0  1  0  0  0  0  1  0  1   0  0   0   0   1   0   1   0   0   0   0   1 "<< endl;
		cout << " 3  1  0  1  1  1  1  0  1  0  1   1  1   1   0   1   0   1   0   1   1   1   1"<< endl;
		cout << " 4  1  0  0  0  0  0  0  0  0  0   0  0   0   0   0   0   0   0   0   0  R7   1"<< endl;
		cout << " 5  1  1  1  1  1  0  1  1  1  1   0  1   0   0   0   0   0   0   1   1   1   1"<< endl;
		cout << " 6  1  0  0  0  0  0  1  0  0  0   0  1   0   0   0   0   0   0   0   0   0   1"<< endl;
		cout << " 7  1  1  1  1  1  0  1  0  1  0   0  1   0   1   1   1   1   1   1   1   0   1"<< endl;
		cout << " 8 E2  0  0  0  0  0  1  0  1  0   0  1   0   0   0   0   0   0   0   1   0   1"<< endl;
		cout << " 9  1  1  1  1  1  0  1  0  1  0   0  1   0   1   0   0   0   0   0   1  R6   1"<< endl;
		cout << " 10 1  0  0  0  1  0  1  0  1  0   0  1   0   1   0   0   0   0   0   1   1   1"<< endl;
		cout << " 11 1  0  0  0  0  0  1  0  1  0   0  1   0   1   0   0   0   0   0   0   0   1"<< endl;
		cout << " 12 1  1  1  1  1  1  1  0  1  0   0  1   0   1   0   0   0   0   0   0   0   1"<< endl;
		cout << " 13 1 R8  0  0  0  0  0  0  1  0   0  1   0   1   0   0   0   0   0   0   0   1"<< endl;
		cout << " 14 1  1  1  1  1  1  1  1  1  1   1  1  E4   1   1   1   1   1   1   1   1   1 "<< endl;
	    
	    cout << "Let's Get Started ... "<< endl;
	    cout << "Your starting room is " << roomNames[startingRoom] << endl;
	    cout << "Your starting position is: " << endl
	         << "row: " << row << endl
	         << "col: " << col << endl;
	
	    system("pause");
	
	    string dir;
	    int totalSteps = 0;
	    int foundExit = -1;
	
	    while (true) {
	        totalSteps++;
	        
	        system("cls");
	
	
	        // get direction from user
	        cout << "Enter a direction (u/d/l/r): " << endl;
	        cin >> dir;
	
	        // try move
	        foundExit = move(maze, row, col, dir);
	
	        // if successfully found exit, print congrats
	        if (foundExit != -1) {
	            break;
	        }
	    }
	
	    int expectedStepCount = expectedSteps[startingRoom][foundExit];
	    if (totalSteps > expectedStepCount) {
	        // print total steps
	        cout << "Total steps: " << totalSteps << endl;
	
	        // print expected steps
	        cout << "Expected steps: " << expectedStepCount << endl;
	        
	       cout <<"ooooo Almost ! Try again To get smallest amount of steps? enter 'y' or 'n' \n";
	       string shouldTryAgain;
	       cin>>shouldTryAgain;
	       if (shouldTryAgain != "y") {
	       		cout<<"Goodbye loser"<<endl;
	       		break;
		   }
	       		
	        
	    }
	    else {
	        cout << "Winner, Winner, chicken dinner ! You took the smallest amount of steps!" << endl;
	        break;
	    }

	}
    system("pause");

    return 0;
}


