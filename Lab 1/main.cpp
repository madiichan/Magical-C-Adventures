#include <iostream>
#include <iomanip> // For output formatting


using namespace std;

const int SIZE = 9;

void showInstructions();
void showBoard(char theBoard[], int SIZE);
void initializeBoard(char theBoard[], int SIZE);
int getMove(char theBoard[], int & MOVE, int player);
int checkGameOver(char theBoard[]);
int checkRepeat(int & player);


int main()
{
    int MOVE;
    int x; // This will hold the place of the value used to determine a win/tie
    int y; // This will hold the place of the value used to determine to repeat
    int player = 1; // Initialize player to 1 to begin
    char MARKER;

    char theBoard[SIZE] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

    showInstructions();


    do // Outer game loop: this one checks if it should repeat the game
    {
        do // Inner game loop: checks to see if game has been won/tie
        {
            player=(player%2)?1:2; // This will switch the player each turn

            showBoard(theBoard, SIZE);
            getMove(theBoard, MOVE, player);

            player++; // Increment the player count

            x = checkGameOver(theBoard);

            if (x == 1)
            {
            showBoard(theBoard, SIZE);
            cout << "The winner is Player: " << (player - 1) << "!" << endl;
            }
            else if (x == 0)
            {
            showBoard(theBoard, SIZE);
            cout << "It was a tie!" << endl;
            }
        } while (x == -1);

        y = checkRepeat(player); // Check to see if repeat & re-initialize players
        initializeBoard(theBoard, SIZE);

    } while (y == 1);
}

// Shows instructions
void showInstructions()
{
    cout << endl;
    cout << endl;
    cout << "------- INSTRUCTIONS --------" << endl;
    cout << "Each square is represented " << endl;
    cout << "by a number from 0 - 8" << endl;
    cout << "Enter the number of the square" << endl;
    cout << "you would like to choose." << endl;
    cout << "------------------------------" << endl << endl << endl;
}

void initializeBoard(char theBoard[], int SIZE)
{
    for(int i = 0; i < SIZE; i++)
        {
            theBoard[i] = i;
        }
}

// Shows board
void showBoard(char theBoard[], int SIZE)
{
    const int LINE = 3;
    cout << "The board looks like this: " << endl;
    cout << " -------------" << endl;

    for(int i = 0; i < SIZE; i++)
        {
        cout << setw(2) << " | " << theBoard[i];
        if ((i+1) % LINE == 0)
        cout << " |" << endl << " -------------" << endl;
        }
 cout << endl;
}


// Gets move, validates & assigns to coordinates
int getMove(char theBoard[], int & MOVE, int player)
{
    bool validate = false;

    cout << "Player " << player << " enter your move: ";

    do
    {
        cin >> MOVE;

        // Assigns marker to player based on player #
        // Switches marker for each player
        char MARKER=(player == 1) ? 'X' : 'O';


        // This validates the integer and gets a new one if invalid
        if (MOVE != 0 && MOVE != 1 && MOVE != 2 && MOVE != 3 && MOVE != 4 && MOVE != 5 && MOVE != 6 && MOVE != 7 && MOVE != 8 || !cin)
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout << "Invalid entry" << endl;
                cin >> MOVE;
            } while (MOVE != 0 && MOVE != 1 && MOVE != 2 && MOVE != 3 && MOVE != 4 && MOVE != 5 && MOVE != 6 && MOVE != 7 && MOVE != 8 || !cin);
        }

        // This validates the position on the board
        // & makes sure the space is not already occupied

        if (MOVE == 0 && theBoard[0] == '0')
        {
            theBoard[0] = MARKER;
            validate = true;
        }
        else if (MOVE == 1 && theBoard[1] == '1')
        {
            theBoard[1] = MARKER;
            validate = true;
        }
        else if (MOVE == 2 && theBoard[2] == '2')
        {
            theBoard[2] = MARKER;
            validate = true;
        }
        else if (MOVE == 3 && theBoard[3] == '3')
        {
            theBoard[3] = MARKER;
            validate = true;
        }
        else if (MOVE == 4 && theBoard[4] == '4')
        {
            theBoard[4] = MARKER;
            validate = true;
        }
        else if (MOVE == 5 && theBoard[5] == '5')
        {
             theBoard[5] = MARKER;
             validate = true;
        }
        else if (MOVE == 6 && theBoard[6] == '6')
        {
             theBoard[6] = MARKER;
             validate = true;
        }
        else if (MOVE == 7 && theBoard[7] == '7')
        {
            theBoard[7] = MARKER;
            validate = true;

        }
        else if (MOVE == 8 && theBoard[8] == '8')
        {
            theBoard[8] = MARKER;
            validate = true;
        }

        // This gets a new move if the space was occupied
        else
        {
                cout<<"Space already occupied. Enter new move: ";
                cin.ignore();
                cin.clear();
                validate = false;
        }

    } while (validate != true);

}



// This checks to see if there has been a win, tie, or neither
// If there is a win, it returns 1
// A tie returns 0
// And neither will return -1 to the main function

int checkGameOver(char theBoard[])
{
    if (theBoard[0] == theBoard[1] && theBoard[1] == theBoard[2])
    {
        return 1;
    }
    else if (theBoard[3] == theBoard[4] && theBoard[4] == theBoard[5])
    {
        return 1;
    }
    else if (theBoard[6] == theBoard[7] && theBoard[7] == theBoard[8])
    {
        return 1;
    }
    else if (theBoard[0] == theBoard[4] && theBoard[4] == theBoard[8])
    {
        return 1;
    }
    else if (theBoard[2] == theBoard[4] && theBoard[4] == theBoard[6])
    {
        return 1;
    }
    else if (theBoard[0] == theBoard [3] && theBoard[3] == theBoard[6])
    {
        return 1;
    }
    else if (theBoard[1] == theBoard[4] && theBoard[4] == theBoard[7])
    {
        return 1;
    }
    else if (theBoard[2] == theBoard[5] && theBoard[5] == theBoard[8])
    {
        return 1;
    }
    else if (theBoard[0] != '0' && theBoard[1] != '1' && theBoard[2] != 2
             && theBoard[3] != '3' && theBoard[4] != '4' && theBoard[5] != '5'
             && theBoard[6] != '6' && theBoard[7] != '7' && theBoard[8] != '8')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int checkRepeat(int & player)
{
    int repeat;

    cout << "Would you like to play again?" << endl;
    do
    {
            cout << "Enter 1 to play again, 0 to quit" << endl;
    cin >> repeat;
    if (repeat == 1)
    {
        cout << "Lets go again!" << endl;
        player--;
        return 1;
    }
    else if (repeat == 0)
    {
        cout << "Thanks for playing!" << endl;
        return 0;
    }
    else
    {
        cout << "Invalid entry. Try again:" << endl;
        cin.clear();
        cin.ignore();
    }

    } while(repeat != 1 && repeat != 0);

    return true;
}
