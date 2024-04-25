/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Lee Ho Kong  
 * Student ID    : 1155149106
 * Class/Section : ENGG1110F
 * Date          : 16/12/2020
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2

/* Initialize the game board by setting all nine squares to EMPTY */
void initGameBoard(int gameBoard[3][3]) {

    // TODO: Complete this part
    int i=0,j=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            gameBoard[i][j] = EMPTY;
            
        }
    }

}



/* Display the game board on the screen
   In Part 1, you are required to follow exactly the output format stated in the project specification
   You are welcome to design and implement a better one in Part 2
   IMPORTANT: Using other output format in Part 1 will result in mark deduction
              If you have a better one, please use them in Part 2 instead */

// TODO: Complete the printGameBoard(...) function here
int printGameBoard(int gameBoard[3][3]) {
    int i,j;
    printf("========\n");
    
    for(i=2;i>=0;i--){
        for(j=0;j<3;j++){
        	if(gameBoard[i][j]==0){
        		printf("|%d|",(i*3+j+1));
			} else if (gameBoard[i][j]==1){
				printf("|O|");
			} else if (gameBoard[i][j]==2){
				printf("|X|");
			}
			
        }
        printf("\n");
    }
    printf("========\n");
    
}


/* Ask the human player to place the mark.
   In Part 1, you can assume that the user input must be valid (i.e, an empty space between 1 and 9).
   You are welcome to perform error checking in Part 2. */
void placeMarkByHumanPlayer(int gameBoard[3][3], int mark) {
	int input;
    // TODO: Complete this part
    scanf("%d",&input);
    
    if(input >= 7 && input <= 9){ 
    	if(gameBoard[2][input-7]== CIRCLE || gameBoard[2][input-7]== CROSS ){ //check whether the input place has been used.
    		printf("You cannot place mark in this place. Please input again.\n");
			placeMarkByHumanPlayer(gameBoard,mark); // if not, run the placeMarkbyHumanPlayer again.
		} else {
			gameBoard[2][input-7] = mark;
		}
    				
	} else if (input < 7 && input >=4) {
		if(gameBoard[1][input-4] == CIRCLE || gameBoard[1][input-4] == CROSS ){
			printf("You cannot place mark in this place. Please input again.\n");
			placeMarkByHumanPlayer(gameBoard,mark);		
		} else {
			gameBoard[1][input-4] = mark;
		}
	} else if (input < 4 && input >= 1){
		if(gameBoard[0][input-1]== CIRCLE || gameBoard[0][input-1]== CROSS ){
			printf("You cannot place mark in this place. Please input again.\n");
			placeMarkByHumanPlayer(gameBoard,mark);
			
		} else {
			gameBoard[0][input-1] = mark;
		}
	} else if(input > 9 || input < 1){ // if the input is not correct,
		printf("Please input from 1 to 9. Please input again.\n");
		fflush(stdin); //clear the input
		placeMarkByHumanPlayer(gameBoard,mark);  // let the user to input again
	}
	
}


/* Return 1 if there is a winner in the game, otherwise return 0 */
/* Note: the winner is the current player indicated in main() */
int hasWinner(int gameBoard[3][3]) {
	int haswinner=0;
    // TODO: Complete this part
	if(gameBoard[0][0]!=0){
		if(gameBoard[0][0] == gameBoard[1][0] && gameBoard[0][0] == gameBoard[2][0]){
			haswinner = 1;
		}else if(gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][0] == gameBoard[0][2]){
			haswinner = 1;
		}
	}
	if(gameBoard[1][1]!=0){
		if(gameBoard[1][1] == gameBoard[1][0] && gameBoard[1][1] == gameBoard[1][2]){
			haswinner = 1;
		}else if(gameBoard[1][1] == gameBoard[0][1] && gameBoard[1][1] == gameBoard[2][1]){
			haswinner = 1;
		}else if(gameBoard[1][1] == gameBoard[0][0] && gameBoard[1][1] == gameBoard[2][2]){
			haswinner = 1;
		}else if(gameBoard[1][1] == gameBoard[0][2] && gameBoard[1][1] == gameBoard[2][0]){
			haswinner = 1;
		}
	}
	if(gameBoard[2][2]!=0){
		if(gameBoard[2][2] == gameBoard[0][2] && gameBoard[2][2] == gameBoard[1][2]){
			haswinner = 1;
		}else if(gameBoard[2][2] == gameBoard[2][0] && gameBoard[2][2] == gameBoard[2][1]){
			haswinner = 1;
		}
	}
	return haswinner;
}



/* Return 1 if the game board is full, otherwise return 0 */

// TODO: Complete the isFull(...) function here
int isFull(int gameBoard[3][3]){
	int i,j,count=0,isfull=0;
	for(i=2;i>=0;i--){
        for(j=0;j<3;j++){
        	if(gameBoard[i][j]!=0){
        		count++;
        		
        	}
        }
    }
    if (count==9){
    	isfull=1;
	}
	return isfull;
}



/* Determine the next move of the computer player.
   In Part 1, you are required to implement the following naive strategy:
   place the mark in the first empty space scanning from 1 to 9.
   You are welcome to design and implement better strategies in Part 2.
   IMPORTANT: Using other strategies in Part 1 will result in mark deduction.
              If you have better strategies, please use them in Part 2 instead. */

// TODO: Complete the placeMarkByComputerPlayer(...) function here
void placeMarkByComputerPlayer(int gameBoard[3][3], int mark) {
	int i,j,count=0;
	if(gameBoard[0][0]==CROSS&&count==0){
		if(gameBoard[1][0]==CROSS&&count==0){
			if(gameBoard[2][0]!=CIRCLE){
				gameBoard[2][0]=mark;
				count++;
			}	
		}
		if(gameBoard[2][0]==CROSS&&count==0){
			if(gameBoard[1][0]!=CIRCLE){
				gameBoard[1][0]=mark;
				count++;
			}
		}
		if(gameBoard[0][1]==CROSS&&count==0){
			if(gameBoard[0][2]!=CIRCLE){
				gameBoard[0][2]=mark;
				count++;
			
			}
		} 
		if(gameBoard[0][2]==CROSS&&count==0){
			if(gameBoard[0][1]!=CIRCLE){
				gameBoard[0][1]=mark;
				count++;
			
			}
		}
		if(gameBoard[2][2]==CROSS&&count==0){
			if(gameBoard[1][1]!=CIRCLE){
				gameBoard[1][1]=mark;
				count++;
			
			}
		}
	} 
	if (gameBoard[2][2]==CROSS&&count==0){
		if(gameBoard[2][1]==CROSS&&count==0){
			if(gameBoard[2][0]!=CIRCLE){
				gameBoard[2][0]=mark;
				count++;
			
			}
		} 
		if(gameBoard[2][0]==CROSS&&count==0){
			if(gameBoard[2][1]!=CIRCLE){
				gameBoard[2][1]=mark;
				count++;
			
			}
		} 
		if(gameBoard[1][2]==CROSS&&count==0){
			if(gameBoard[0][2]!=CIRCLE){
				gameBoard[0][2]=mark;
				count++;
		
			}
		} 
		if(gameBoard[0][2]==CROSS&&count==0){
			if(gameBoard[1][2]!=CIRCLE){
				gameBoard[1][2]=mark;
				count++;
			
			}
		}
	} 
	if (gameBoard[1][1]==CROSS&&count==0){
		if(gameBoard[0][0]==CROSS&&count==0){
			if(gameBoard[2][2]!=CIRCLE){
				gameBoard[2][2]=mark;
				count++;
			
			}
		} if (gameBoard[2][2]==CROSS&&count==0){
			if(gameBoard[0][0]!=CIRCLE){
				gameBoard[0][0]=mark;
				count++;
			
			}
		}if (gameBoard[0][2]==CROSS&&count==0){
			if(gameBoard[2][0]!=CIRCLE){
				gameBoard[2][0]=mark;
				count++;
			
			}	
		} if (gameBoard[2][0]==CROSS&&count==0){
			if(gameBoard[0][2]!=CIRCLE){
				gameBoard[0][2]=mark;
				count++;
			
			}
		} if (gameBoard[1][0]==CROSS&&count==0){
			if(gameBoard[1][2]!=CIRCLE){
				gameBoard[1][2]=mark;
				count++;
		
			}
		} if (gameBoard[1][2]==CROSS&&count==0){
			if(gameBoard[1][0]!=CIRCLE){
				gameBoard[1][0]=mark;
				count++;
			
			}
		} if (gameBoard[0][1]==CROSS&&count==0){
			if(gameBoard[2][1]!=CIRCLE){
				gameBoard[2][1]=mark;
				count++;
			
			}
		} if (gameBoard[2][1]==CROSS&&count==0){
			if(gameBoard[0][1]!=CIRCLE){
				gameBoard[0][1]=mark;
				count++;
			
			}
		} 
	} 
	if(gameBoard[0][2]==CROSS&&count==0){
		if(gameBoard[0][1]==CROSS&&count==0){
			if(gameBoard[0][0]!=CIRCLE){
				gameBoard[0][0]=mark;
				count++;
			
			}
		} 
		if (gameBoard[1][2]==CROSS&&count==0){
			if(gameBoard[2][2]!=CIRCLE){
				gameBoard[2][2]=mark;
				count++;
			
			}
		} 
		if (gameBoard[2][0]==CROSS&&count==0){
			if(gameBoard[1][1]!=CIRCLE){
				gameBoard[1][1]=mark;
				count++;

			}	
		}
	} 
	if(gameBoard[1][0]==CROSS&&count==0){
		if(gameBoard[2][0]==CROSS&&count==0){
			if(gameBoard[0][0]!=CIRCLE){
				gameBoard[0][0]=mark;
				count++;
			
			}
		}
		if (gameBoard[1][2]==CROSS&&count==0){
			if(gameBoard[1][1]!=CIRCLE){
				gameBoard[1][1]=mark;
				count++;
			
			}
		} 
	} 
	if(gameBoard[2][1]==CROSS&&count==0){
		if(gameBoard[0][1]==CROSS&&count==0){
			if(gameBoard[1][1]!=CIRCLE){
				gameBoard[1][1]=mark;
				count++;
			
			}
		} 
		if (gameBoard[2][0]==CROSS&&count==0){
			if(gameBoard[2][2]!=CIRCLE){
				gameBoard[2][2]=mark;
				count++;
			
			}
		} 
		if (gameBoard[2][0]==CROSS&&count==0){
			if(gameBoard[1][1]!=CIRCLE){
				gameBoard[1][1]=mark;
				count++;

			}	
		}
	}
	if(gameBoard[0][0]==CIRCLE&&count==0){
		if(gameBoard[1][0]==CIRCLE&&count==0){
			if(gameBoard[2][0]!=CROSS){
				gameBoard[2][0]=mark;
				count++;
			}	
		}
		if(gameBoard[2][0]==CIRCLE&&count==0){
			if(gameBoard[1][0]!=CROSS){
				gameBoard[1][0]=mark;
				count++;
			}
		}
		if(gameBoard[0][1]==CIRCLE&&count==0){
			if(gameBoard[0][2]!=CROSS){
				gameBoard[0][2]=mark;
				count++;
			
			}
		} 
		if(gameBoard[0][2]==CIRCLE&&count==0){
			if(gameBoard[0][1]!=CROSS){
				gameBoard[0][1]=mark;
				count++;
			
			}
		}
		if(gameBoard[2][2]==CIRCLE&&count==0){
			if(gameBoard[1][1]!=CROSS){
				gameBoard[1][1]=mark;
				count++;
			
			}
		}
	} 
	if (gameBoard[2][2]==CIRCLE&&count==0){
		if(gameBoard[2][1]==CIRCLE&&count==0){
			if(gameBoard[2][0]!=CROSS){
				gameBoard[2][0]=mark;
				count++;
			
			}
		} 
		if(gameBoard[2][0]==CIRCLE&&count==0){
			if(gameBoard[2][1]!=CROSS){
				gameBoard[2][1]=mark;
				count++;
			
			}
		} 
		if(gameBoard[1][2]==CIRCLE&&count==0){
			if(gameBoard[0][2]!=CROSS){
				gameBoard[0][2]=mark;
				count++;
		
			}
		} 
		if(gameBoard[0][2]==CIRCLE&&count==0){
			if(gameBoard[1][2]!=CROSS){
				gameBoard[1][2]=mark;
				count++;
			
			}
		}
	} 
	if (gameBoard[1][1]==CIRCLE&&count==0){
		if(gameBoard[0][0]==CIRCLE&&count==0){
			if(gameBoard[2][2]!=CROSS){
				gameBoard[2][2]=mark;
				count++;
			
			}
		} if (gameBoard[2][2]==CIRCLE&&count==0){
			if(gameBoard[0][0]!=CROSS){
				gameBoard[0][0]=mark;
				count++;
			
			}
		}if (gameBoard[0][2]==CIRCLE&&count==0){
			if(gameBoard[2][0]!=CROSS){
				gameBoard[2][0]=mark;
				count++;
			
			}	
		} if (gameBoard[2][0]==CIRCLE&&count==0){
			if(gameBoard[0][2]!=CROSS){
				gameBoard[0][2]=mark;
				count++;
			
			}
		} if (gameBoard[1][0]==CIRCLE&&count==0){
			if(gameBoard[1][2]!=CROSS){
				gameBoard[1][2]=mark;
				count++;
		
			}
		} if (gameBoard[1][2]==CIRCLE&&count==0){
			if(gameBoard[1][0]!=CROSS){
				gameBoard[1][0]=mark;
				count++;
			
			}
		} if (gameBoard[0][1]==CIRCLE&&count==0){
			if(gameBoard[2][1]!=CROSS){
				gameBoard[2][1]=mark;
				count++;
			
			}
		} if (gameBoard[2][1]==CIRCLE&&count==0){
			if(gameBoard[0][1]!=CROSS){
				gameBoard[0][1]=mark;
				count++;
			
			}
		} 
	} 
	if(gameBoard[0][2]==CIRCLE&&count==0){
		if(gameBoard[0][1]==CIRCLE&&count==0){
			if(gameBoard[0][0]!=CROSS){
				gameBoard[0][0]=mark;
				count++;
			
			}
		} 
		if (gameBoard[1][2]==CIRCLE&&count==0){
			if(gameBoard[2][2]!=CROSS){
				gameBoard[2][2]=mark;
				count++;
			
			}
		} 
		if (gameBoard[2][0]==CIRCLE&&count==0){
			if(gameBoard[1][1]!=CROSS){
				gameBoard[1][1]=mark;
				count++;

			}	
		}
	} 
	if(gameBoard[1][0]==CIRCLE&&count==0){
		if(gameBoard[2][0]==CIRCLE&&count==0){
			if(gameBoard[0][0]!=CROSS){
				gameBoard[0][0]=mark;
				count++;
			
			}
		}
		if (gameBoard[1][2]==CIRCLE&&count==0){
			if(gameBoard[1][1]!=CROSS){
				gameBoard[1][1]=mark;
				count++;
			
			}
		} 
	} 
	if(gameBoard[2][1]==CIRCLE&&count==0){
		if(gameBoard[0][1]==CIRCLE&&count==0){
			if(gameBoard[1][1]!=CROSS){
				gameBoard[1][1]=mark;
				count++;
			
			}
		} 
		if (gameBoard[2][0]==CIRCLE&&count==0){
			if(gameBoard[2][2]!=CROSS){
				gameBoard[2][2]=mark;
				count++;
			
			}
		} 
		if (gameBoard[2][0]==CIRCLE&&count==0){
			if(gameBoard[1][1]!=CROSS){
				gameBoard[1][1]=mark;
				count++;

			}	
		}
	}
	if(count==0 && gameBoard[1][1]==EMPTY){//if the player does not place the centre.
		gameBoard[1][1]=mark; // the computer AI will place the centre.
		count++;
	}
	if(count==0){
		for(i=0;i<3;i++){
        	for(j=0;j<3;j++){
        		if(gameBoard[i][j]==0&&count==0){
        			gameBoard[i][j] = mark;
       				count++;
				}
			}
		}
	}
	printf("Computer places the mark:\n");
	printGameBoard(gameBoard);
}


/* The main function */
int main() {
    /* Local variables */
    int gameBoard[3][3];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1 (Human)   2: Player 2 (Human) or Computer Player
    int gameEnds;           // 0: The game continues   1: The game ends
    int numOfHumanPlayers;  // 1 or 2

    /* Initialize the local variables by invoking a function, using assignment statements, and reading the user input */
    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameEnds = 0;
    printf("How many human players [1-2]?\n");
    scanf("%d", &numOfHumanPlayers);    // In Part 1, you can assume that the user input must be valid
    
    

    // TODO: Complete this part
    
	
		if (numOfHumanPlayers==1){
			printGameBoard(gameBoard);
			do{
				printf("Player 1, please place your mark [1-9]:\n");
    			placeMarkByHumanPlayer(gameBoard, CIRCLE);
    			printGameBoard(gameBoard);
    			if(hasWinner(gameBoard)){
    				printf("Player 1 wins! Congratulations!");
					break;
				}
				if(isFull(gameBoard)){
					printf("Draw game!");
					break;
				}
				
				placeMarkByComputerPlayer(gameBoard, CROSS);
				
				if(hasWinner(gameBoard)){
    				printf("Computer wins!");
					break;
				}
			
			}while(!isFull(gameBoard));
	
			
		} else if (numOfHumanPlayers==2){
			printGameBoard(gameBoard);
			do{
		
				printf("Player 1, please place your mark [1-9]:\n");
    			placeMarkByHumanPlayer(gameBoard, CIRCLE);
    			printGameBoard(gameBoard);
    			if(hasWinner(gameBoard)){
    				printf("Player 1 wins! Congratulations!");
					break;
				}
				if(isFull(gameBoard)){
					printf("Draw game!");
					break;
				}
				
			
    			printf("Player 2, please place your mark [1-9]:\n");
    			placeMarkByHumanPlayer(gameBoard, CROSS);
    			printGameBoard(gameBoard);
    			if(hasWinner(gameBoard)){
    				printf("Player 2 wins! Congratulations!");
					break;
				}
   			}while(!isFull(gameBoard));
			
		} else { //if the user input is not 1 or 2
			printf("\nInvalid input, please input again.\n\n");
			fflush(stdin);//clear the input of numOfHumanPlayers
			main(); // restart the main function again
		}
	
    return 0;
}
