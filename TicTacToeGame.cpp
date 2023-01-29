// C++ program on tick cross game using
// AI minimax algorithm

#include<bits/stdc++.h>
using namespace std;
char board[3][3] =
	{
		{ '_', '_', '_' },
		{ '_', '_', '_' },
		{ '_', '_', '_' }
	};
int row,column,i,j;
char turn;
bool draw = false;
struct Move
{
	int row, col;
};

char player = 'X', opponent = 'O';

// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.
bool isMovesLeft(char board[3][3])
{
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			if (board[i][j]=='_')
				return true;
	return false;
}

// This is the evaluation function 
int evaluate(char b[3][3])
{
	// Checking for Rows for X or O victory.
	for (int row = 0; row<3; row++)
	{
		if (b[row][0]==b[row][1] &&
			b[row][1]==b[row][2])
		{
			if (b[row][0]==player)
				return +10;
			else if (b[row][0]==opponent)
				return -10;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col<3; col++)
	{
		if (b[0][col]==b[1][col] &&
			b[1][col]==b[2][col])
		{
			if (b[0][col]==player)
				return +10;

			else if (b[0][col]==opponent)
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
	{
		if (b[0][0]==player)
			return +10;
		else if (b[0][0]==opponent)
			return -10;
	}

	if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
	{
		if (b[0][2]==player)
			return +10;
		else if (b[0][2]==opponent)
			return -10;
	}

	// Else if none of them have won then return 0
	return 0;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);

	// If Maximizer has won the game return his/her
	// evaluated score
	if (score == 10)
		return score;

	// If Minimizer has won the game return his/her
	// evaluated score
	if (score == -10)
		return score;

	// If there are no more moves and no winner then
	// it is a tie
	if (isMovesLeft(board)==false)
		return 0;

	// If this maximizer's move
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty
				if (board[i][j]=='_')
				{
					// Make the move
					board[i][j] = player;

					// Call minimax recursively and choose
					// the maximum value
					best = max( best,
						minimax(board, depth+1, !isMax) );

					// Undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}

	// If this minimizer's move
	else
	{
		int best = 1000;

		// Traverse all cells
		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{
				// Check if cell is empty
				if (board[i][j]=='_')
				{
					// Make the move
					board[i][j] = opponent;

					// Call minimax recursively and choose
					// the minimum value
					best = min(best,
						minimax(board, depth+1, !isMax));

					// Undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
}

// This will return the best possible move for the player
Move findBestMove(char board[3][3])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	// Traverse all cells, evaluate minimax function for
	// all empty cells. And return the cell with optimal
	// value.
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			// Check if cell is empty
			if (board[i][j]=='_')
			{
				// Make the move
				board[i][j] = player;

				// compute evaluation function for this
				// move.
				int moveVal = minimax(board, 0, false);

				// Undo the move
				board[i][j] = '_';

				// If the value of the current move is
				// more than the best value, then update
				// best/
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}

//	printf("The value of the best Move is : %d\n\n",
//			bestVal);

	return bestMove;
}
void display_board()
{
    system("CLS");
    cout<<"\n\n    TICK CROSS GWME    "<<endl;
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<< board[0][0]<<"  |  "<< board[0][1]<<"  |  "<< board[0][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";     
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<< board[1][0]<<"  |  "<< board[1][1]<<"  |  "<< board[1][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";   
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<< board[2][0]<<"  |  "<< board[2][1]<<"  |  "<< board[2][2]<<"  \n";
    cout<<"\t\t     |     |     \n";
}
void player_turn()
{
    int choice;
    if (turn=='O'){
    	cout<<"\n\t player1[O] turn :";
    	cin>>choice;
    	switch(choice){
	    case 1: row=0; column=0; break;
	    case 2: row=0; column=1; break;
	    case 3: row=0; column=2; break;
	    case 4: row=1; column=0; break;
	    case 5: row=1; column=1; break;
	    case 6: row=1; column=2; break;
	    case 7: row=2; column=0; break;
	    case 8: row=2; column=1; break;
	    case 9: row=2; column=2; break;
	    default:
	    cout<<" invalid choice\n";
	    break;
		}
}
    if(turn=='X'){
    cout<<"\n\t player2[X] turn :";
    Move bestMove = findBestMove(board);
    	printf("ROW: %d COL: %d\n\n", bestMove.row,
								bestMove.col );
    row=bestMove.row;
    column=bestMove.col;
    }
if (turn=='X' && board[row][column]!='X' && board[row][column]!='O')
{
    board[row][column] = 'X';
    turn='O';
}
else if (turn=='O' && board[row][column]!='X' && board[row][column]!='O')
{
    board[row][column] = 'O';
    turn='X';
}
else
{
    cout<<" BOX ALREADY FILLED ! \n PLEACE TRY AGAIN !! \n\n";
    player_turn();
}
    
}
bool gameover()
{
    //check win
    for(int i=0;i<3;i++)
    if(board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]=='X' ||  board[0][i]==board[1][i] && board[0][i]==board[2][i]&&board[0][i]=='X') 
    return false;
    if(board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]=='O' ||  board[0][i]==board[1][i] && board[0][i]==board[2][i]&&board[0][i]=='O') 
    return false;
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]=='X' || board[0][2]==board[1][1] && board[0][2]==board[2][0]&&board[0][2]=='X')
    return false;
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]=='O' || board[0][2]==board[1][1] && board[0][2]==board[2][0]&&board[0][2]=='O')
    return false;
    // if there is any box not FILLED
    
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    if( board[i][j]!='X' && board[i][j]!='O')
    return true;
    // draw 
    draw= true;
    return false;
}
// Driver code
int main()
{
	int ch;
	printf("Choose Your turn: \n1. First Player [O]\n2. Second Player [X]\n");
	cin>>ch;
	if(ch==1){
		turn='O';
	}else{
		turn='X';
	}
while(gameover())
    {
        display_board();
        player_turn();
        gameover();
    }
    display_board();
    if(turn=='X'&& draw == false)
    cout<<"player1[O] wins!! congrats!!!\n";
    else if (turn=='O'&& draw==false)
    cout<<"player2[X] wins!! congrats!!!\n";
    else
    cout<<"  game draw !!\n";
							
	return 0;
}
