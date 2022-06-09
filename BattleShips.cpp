#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define DEFAULT 15
#define FOREGROUND_MAGENTA 11
#define FOREGROUND_PINK 13
#define FOREGROUND_GAMEOVR 12
#define FOREGROUND_DETAILS 10

void header();
void members();

void setTextColor(int color) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

class BattleShips // used a class as will have 2 instances, one for computer, one for human
{
private:
    const static int rows = 10;
    const static int columns = 10;
    int coOrd;
    int maximumShips;
    int isUser = false;

    bool checkShipExists(int argMatrix[10][10], int orientation, int initialX, int initialY) {
        if (orientation == 0) {
            for (int y = 0; y < columns; y++)
            {
                if (argMatrix[initialX][y] == 1) {
                    return true;
                }
            }
        }
        else if (orientation == 1) {
            for (int x = 0; x < columns; x++)
            {
                if (argMatrix[x][initialY] == 1) {
                    return true;
                }
            }
        }

        return false;
    }
public:
    int matrix[rows][columns];

    BattleShips()
    { // CLASS CONSTRUCTOR
        coOrd = 0;
        maximumShips = 5;
    }


    void ClearGrid() // simple function to clear the matrix.
    {
        for (int y = 0; y < rows; y++) // loops while y is less than rows, and increments y
        {
            for (int x = 0; x < columns; x++) // loops while x is less than columns and increments x
            {
                matrix[y][x] = 0; // sets each matrix row and column to 0
            }
        }
    }

    void ShowGrid()
    {
        cout << "   0 1 2 3 4 5 6 7 8 9" << endl;
        cout << "-----------------------" << endl;
        for (int x = 0; x < rows; x++)
        {
            cout << coOrd << "| ";
            coOrd++;
            for (int y = 0; y < rows; y++)
            {

                cout << matrix[x][y] << " ";
            }
            cout << endl;
        }
    }

    void setShips()
    {
        int ships = 0;
        int maxIndex = 8;
        int interations = 1;

        while (ships < maximumShips)
        {
            switch (ships) {
            case 0:
                maxIndex = 8;
                break;
            case 1:
                maxIndex = 7;
                break;
            case 2:
                maxIndex = 6;
                break;
            case 3:
                maxIndex = 5;
                break;
            case 4:
                maxIndex = 4;
                break;
            }

            int xPos = rand() % maxIndex + 1; // modulo 10 to make an int between 0 and maxIndex
            int yPos = rand() % maxIndex + 1; // modulo 10 to make an int between 0 and maxIndex

            // Generates ship orientation horizontal(0) or vertical(1)
            // modulo 2 to make an int between 0 and 1
            int orientation = rand() % 2;

            // if (matrix[xPos][yPos] != 1)
            if (!checkShipExists(matrix, orientation, xPos, yPos))
            {
                if (ships == 0) {
                    //horizontal
                    if (orientation == 0) {
                        matrix[xPos][yPos] = 1; // sets position to 1
                        matrix[xPos][yPos + 1] = 1; // sets position to 1
                        matrix[xPos][yPos + 2] = 1; // sets position to 1
                    }
                    //vertical
                    if (orientation == 1) {
                        matrix[xPos][yPos] = 1; // sets position to 1
                        matrix[xPos + 1][yPos] = 1; // sets position to 1
                        matrix[xPos + 2][yPos] = 1; // sets position to 1
                    }
                }
                if (ships == 1) {
                    //horizontal
                    if (orientation == 0) {
                        matrix[xPos][yPos] = 1; // sets position to 1
                        matrix[xPos][yPos + 1] = 1; // sets position to 1
                        matrix[xPos][yPos + 1] = 1; // sets position to 1
                    }
                    //vertical
                    if (orientation == 1) {
                        matrix[xPos][yPos] = 1; // sets position to 1
                        matrix[xPos + 1][yPos] = 1; // sets position to 1
                        matrix[xPos + 1][yPos] = 1; // sets position to 1
                    }
                }
                if (ships == 2) {
                    //horizontal
                    if (orientation == 0) {
                        matrix[xPos][yPos] = 1; // sets position to 1
                        matrix[xPos][yPos + 1] = 1; // sets position to 1
                        matrix[xPos][yPos + 2] = 1; // sets position to 1
                    }
                    //vertical
                    if (orientation == 1) {
                        matrix[xPos][yPos] = 1; // sets position to 1
                        matrix[xPos + 1][yPos] = 1; // sets position to 1
                        matrix[xPos + 2][yPos] = 1; // sets position to 1
                    }
                }
                if (ships == 3) {
                    //horizontal
                    if (orientation == 0) {
                        matrix[xPos][yPos] = 1; // sets position to 1
                        matrix[xPos][yPos + 1] = 1; // sets position to 1
                        matrix[xPos][yPos + 2] = 1; // sets position to 1
                        matrix[xPos][yPos + 3] = 1; // sets position to 1
                    }
                    //vertical
                    if (orientation == 1) {
                        matrix[xPos][yPos] = 1; // sets position to 1
                        matrix[xPos + 1][yPos] = 1; // sets position to 1
                        matrix[xPos + 2][yPos] = 1; // sets position to 1
                        matrix[xPos + 3][yPos] = 1; // sets position to 1
                    }
                }
                if (ships == 4) {
                    //horizontal
                    if (orientation == 0) {
                        matrix[xPos][yPos] = 1; // sets position to 1
                        matrix[xPos][yPos + 1] = 1; // sets position to 1
                        matrix[xPos][yPos + 2] = 1; // sets position to 1
                        matrix[xPos][yPos + 3] = 1; // sets position to 1
                        matrix[xPos][yPos + 4] = 1; // sets position to 1
                    }
                    //vertical
                    if (orientation == 1) {
                        matrix[xPos][yPos] = 1; // sets position to 1
                        matrix[xPos + 1][yPos] = 1; // sets position to 1
                        matrix[xPos + 2][yPos] = 1; // sets position to 1
                        matrix[xPos + 3][yPos] = 1; // sets position to 1
                        matrix[xPos + 4][yPos] = 1; // sets position to 1
                    }
                }

                ships++;
            }

        }

    }

    bool Attack(int _x, int _y) // makes a function with a boolean return type
    {
        if (matrix[_x][_y] == 1) // checks if the given parameters are a 'ship' on the matrix
        {
            matrix[_x][_y] = 2; // sets the position to 2 so the same position can not be re used
            return true; // returns a boolean 'true'
        }
        return false; // returns a boolean 'false'
    }
};

class Boards // makes another class called boards, will be used to initiate the game boards the user can see
{
private:
    const static int rows = 10; // makes constants called rows and columns set to 10; to make the game board matrix
    const static int columns = 10;
    char grid[rows][columns]; // makes an multidimensional array of data type 'char'
    int refMatrix[rows][columns];
    bool isUser = false;

public:
    Boards(bool user, int matrix[][10]) {
        isUser = user;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                refMatrix[i][j] = matrix[i][j];
            }
        }
    }

    //CLASS CONSTRUCTOR NOT NECCESSARY AS ALL VALUES ASSIGNED IN PRIVATE BLOCK
    void MakeBoards() // declares a function to make the game boards
    {
        for (int x = 0; x < rows; x++) // starts a for loop
        {
            for (int y = 0; y < columns; y++) // nested for loop
            {
                if (isUser) {
                    if (refMatrix[x][y] == 1) {
                        grid[x][y] = 'O'; // sets the element in the position to a '-'
                    }
                    else {
                        grid[x][y] = '-'; // sets the element in the position to a '-'
                    }
                }
                else {
                    grid[x][y] = '-'; // sets the element in the position to a '-'
                }
            }
        }
    }

    void updateBoards(bool i, int x, int y) // makes a function to update the game boards, takes 3 paramaters. a boolean, and two integers
    {
        int xPos = x; // sets two variables equal to the int values passed in
        int yPos = y;

        if (i == true) // checks if i is equal to 'true'
        {
            grid[xPos][yPos] = 'X'; // sets the element in the position to 'Y'
        }
        else
        {
            grid[xPos][yPos] = 'M'; // sets the element in the position to 'N'
        }
    }

    void PrintBoards() // makes a function to print the boards
    {
        int amt = 0; // sets an int called amt to 0

        cout << "  0 1 2 3 4 5 6 7 8 9" << endl; // prints the top line of coordinates
        for (int x = 0; x < rows; x++) { // for loop
            cout << amt << " "; // outputs the amount variable to the console + a space
            amt++; // increments amt
            for (int y = 0; y < columns; y++) { // nested for loop
                cout << grid[x][y] << " "; // outputs the element of the grid to the console, plus a space
            }
            cout << endl; // outputs an endline character
        }
    }
};

int main() // this is what is run everytime the program starts
{   
    header();
    members();
    system("CLS");
    char rerun = ' '; // declares a char variable called rerun
    int choice;
    do
    {      
        system("CLS");
        srand((unsigned)time(NULL)); // to prevent sequence repetition between runs

        //The boolean argument passed tells the instance whether the instance is of the user or the CPU
        BattleShips human; // instantiates the two objects
        BattleShips cpu;

        human.ClearGrid(); // clears the existing matrix
        human.setShips(); // sets the position of the ships

        cpu.ClearGrid();  // clears the existing grid
        cpu.setShips();

        Boards humanBoard = Boards(false, human.matrix); // instantiates the Board objects
        Boards cpuBoard = Boards(true, cpu.matrix);

        humanBoard.MakeBoards(); // makes the gameboards
        cpuBoard.MakeBoards();

        setTextColor(FOREGROUND_PINK);
        cout << "CPU's Board: " << endl;

        setTextColor(FOREGROUND_MAGENTA);
        humanBoard.PrintBoards(); // prints the new boards

        setTextColor(FOREGROUND_PINK);
        cout << "\nYour Board: " << endl;

        setTextColor(FOREGROUND_MAGENTA);
        cpuBoard.PrintBoards();

        setTextColor(FOREGROUND_DETAILS);

        int position1, position2; // makes two integers for the positions to be stored inside
        char which; // makes a char variable called which, will be used to store the result of asking the user if they want to forfeit.
        int found = 0; // makes an int called found, initializes it to 0
        int toGo = 17; 

        int cpuFound = 0; // ^ does the same for the cpu counters
        int cpuToGet = 17;

        bool isTrue; // initializes two boolean variables.
        bool isTrueCpu;

        while (found < 10 || cpuFound < 10) // loops while found is less than 10.
        {
            int cpuX = rand() % 10; // makes a random integer between 0 and 9, hence the mod 10.
            int cpuY = rand() % 10;

            if (cpu.Attack(cpuX, cpuY)) // checks the boolean output of the Attack function for the cpu
            {
                isTrueCpu = true; // sets isTrueCpu to true
                cpuFound++; // increments cpuFound
                cpuToGet--; // decrements cpuToGet
                setTextColor(FOREGROUND_GAMEOVR);
                cout << "\nThe Computer has hitted one of your battleships at: " << "(" << cpuX << ", " << cpuY << ")" << endl; // outputs the position that the cpu found a battleship at.
            }
            else // anything else
            {
                isTrueCpu = false; // sets isTrueCpu to false
                setTextColor(FOREGROUND_DETAILS);
                cout << "\nThe Computer just missed its shot at: " << "(" << cpuX << ", " << cpuY << ")" << endl; // outputs that the cpu did not find a battleship this time.
            }

            //------------------------------------------------------------------------------------------------------------

            position1 = 11; // sets position1 and position2 to 11
            position2 = 11; // so that the while loop will initiate below

            while (position1 > 9 || position2 > 9) // loops while position1 is more than 9 OR position 2  is more than 9.
            {
                if (cpuFound == 10 || found == 10)
                {
                    break;
                }
                setTextColor(FOREGROUND_DETAILS);
                cout << "\nEnter Coordinate (Ex: 0 1): "; // prompts the user to enter co-ordinates.

                cin >> position1 >> position2; // takes the keyboard input and stores it in position 

                while (cin.fail()) // this will inintiate if the user enters a non integer input.
                {
                    cin.clear(); // clears the cin.
                    cin.ignore(); // ignores so it does not go in to an infinite loop
                    cout << "not int, try again: "; cin >> position1 >> position2; // re prompts the user to enter their input
                }
            }

            if (human.Attack(position1, position2)) // checks if the boolean value for the Attack function is true
            {
                isTrue = true; // sets isTrue to true
                found++; // increments found
                toGo--; // decrements toGo
                setTextColor(FOREGROUND_DETAILS);
                cout << "\nIt's a hit! " << endl; // alerts the user of how many battleships they have found, and how many more they need to get.
            }
            else // anything else
            {
                isTrue = false; // sets isTrue to false
                setTextColor(FOREGROUND_GAMEOVR);
                cout << "\nYou've missed your shot, the enemy will strike back." << endl; // alerts the user that there is no ship in that position
            }

            cout << "\nWould you like to surrender (y/n)?: "; cin >> which; // asks the user if they want to surrender and stores the input into char.

            system("CLS"); // clears the console to eliminate clutter

            humanBoard.updateBoards(isTrue, position1, position2); // updates the boards
            cpuBoard.updateBoards(isTrueCpu, cpuX, cpuY);

            setTextColor(FOREGROUND_PINK);
            cout << "CPU'S Board: " << endl;

            setTextColor(FOREGROUND_MAGENTA);
            humanBoard.PrintBoards(); // prints the new boards

            setTextColor(FOREGROUND_PINK);
            cout << "\nYour Board: " << endl;

            setTextColor(FOREGROUND_MAGENTA);
            cpuBoard.PrintBoards();

            if (which == 'y' || which == 'Y') // checks if which is equal to y
            {
                break; // breaks from the loop
            }
            else if (found == 10 || cpuFound == 10)
            {
                break;
            }

        }

        // this code is run when the loop is exited.
        system("CLS");

        setTextColor(FOREGROUND_GAMEOVR);
        cout << "\t\tGame Over!" << endl; // outputs game over to the user

        setTextColor(FOREGROUND_DETAILS);
        cout << "\nThe number 2 represents the ships that have been hit or damaged" << endl;

        setTextColor(FOREGROUND_PINK);
        cout << "\nCPU'S Board: " << endl; // outputs the text "your grid" 

        setTextColor(FOREGROUND_MAGENTA);
        human.ShowGrid(); // shows the human objects grid
        cout << "\n----------------------------------------------------" << endl;

        setTextColor(FOREGROUND_PINK);
        cout << "\nYour Board: " << endl; // outputs "CPU's Grid"

        setTextColor(FOREGROUND_MAGENTA);
        cpu.ShowGrid(); // shows the cpu grid to the user

        setTextColor(DEFAULT);

        cout << "\nWould you like to play again or exit the game? (r/e): "; cin >> rerun; // ask the user if they want to rerun, is stored in rerun.*/

    } while (rerun == 'r' || rerun == 'R'); // part of the do while loop, checks if rerun is equal to 'y'

    return 0;
}

void header() 
{
    setTextColor(FOREGROUND_PINK);
    cout << "\n\t\t\t============================";
    cout << "\n\t\t\t|      BATTLESHIP GAME     |";
    cout << "\n\t\t\t============================" << "\n";
}

void members() 
{
    setTextColor(FOREGROUND_MAGENTA);
    cout << "\n\t  Made By : Danielle John P. Cruz              // Lead Programmer" << "\n";
    cout << "\n\t          : Angelynn Francis Almeda            // Programmer" << "\n";
    cout << "\n\t          : Dijon Timothy P. Molina            // Programmer" << "\n";
    cout << "\n\t          : Enrico Carlos Miguel B. Anonuevo   // Programmer" << "\n\n";
    cout << "\n\t\t  Enter any key to continue: ";
    cin.get();
}




