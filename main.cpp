/**************************************************************************
 *   Author    :  John Chen
 *   Assn #7   :  Text Adventure Specification
 *   CLASS     :  CS 002
 *   SECTION   :  MTRF: 7a - 12p
 *   Due Date  :  7/10/19
 *************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
/**************************************************************************
 *
 * TEXT ADVENTURE SPECIFICATION
 * ________________________________________________________________________
 * This program is a text adventure where the adventurer starts off with
 * some bananas and oranges and is faced with the choice of going through
 * one of the four doors in every room. Each room has a different action.
 * ________________________________________________________________________
 * INPUT:
 *   name: Name of the user -> input from user
 *   monsterName: Name of the user's scariest monster -> input from user
 *   direction: Direction taken within a room -> input from user
 *
 * OUTPUT:
 *   Outputs the state of the game
 *************************************************************************/
/**************************************************************************
* monsterRoom
*  This function resets the scores of the oranges and bananas to zero and
*  also tells the user that he has been attacked.
*   - returns nothing -> All changes are passed by reference and cout
* ***********************************************************************/
void monsterRoom(int& bananas,    //OUT - linked to the bananas
                 int& oranges,    //OUT - linked to the orange count
                 string monName); //IN - the name of the monster

/**************************************************************************
* genieRoom
*  This function gives the user two bananas and one orange as well as
*  telling him that a genie had appeared.
*   - returns nothing -> All changes are passed by reference and cout
* ***********************************************************************/
void genieRoom(int& bananas,  //OUT - linked to the banana count
              int& oranges);  //OUT - linked to the orange count

/**************************************************************************
* drawPicture
*  This function draws a picture of a robot.
*   - returns nothing -> All changes through cout
* ***********************************************************************/
void drawPicture();

/**************************************************************************
* pictureRoom
*  This function calls the drawPicture function to draw a picture of a
*  robot for the room.
*   - returns nothing -> All changes through cout
* ***********************************************************************/
void pictureRoom();

/**************************************************************************
* isValid
*  This function checks to see whether the inputted direction is a valid
*  one and will return true or false.
*   - returns boolean -> This tells whether the direction is a valid one
* ***********************************************************************/
bool isValid(char direction); //IN - this is the direction inputted

int main()
{
    //constants
    int bananas;         //CALC - The current count of bananas
    int oranges;         //CALC - The current count of oranges
    string name;         //INPUT - The name of the player
    string monsterName;  //INPUT - The name of the monster
    char direction;      //INPUT - The direction taken in the room
    bool val;            //CALC - The state of the game

    //Initializing the variables and seeding the rng engine
    bananas = 5;
    oranges = 3;
    val = true;
    srand(500);

    //INPUT & OUTPUT: Prompt the user for his name and the name of his
    //                scariest monster and store them
    cout << "Please enter your name: ";
    cin >> name;
    cout << endl;
    cout << "Name your scariest monster: ";
    cin >> monsterName;
    cout << endl;

    //PROCESSING: Game will run as long as the state of the game is true
    while(val)
    {
        //OUTPUT: Display the user their location and stats
        cout << name << ", you are in a room with 4 doors." << endl << endl
             << "You are carrying " << bananas << " bananas and "
             << oranges << " oranges." << endl;

        //INPUT & OUTPUT: Prompt the user to pick a direction
        cout << "Pick a door to enter by typing the direction it is "
                "in (N/E/S/W): ";
        cin >> direction;
        cout << endl;

        //PROCESSING: Will continually prompt the user for a direction if
        //            the one given is not valid
        //isValid - checks to see if a direction is a valid input
        if(!isValid(direction))
        {
            while(!isValid(direction))
            {
                //INPUT & OUTPUT: Same as above - keep prompting
                cout << "Pick a door to enter by typing the direction "
                        "it is in (N/E/S/W): ";
                cin >> direction;
                cout << endl;
            }
        }
        else {
            cout << endl;
        }

        //Create the rng for the rooms by creating the variable and
        //intializing it either 1 or 0
        int rng;
        rng = rand() % 2;

        //PROCESSING: Based on random selection, user has two possible
        //            room alignments to traverse
        if(rng) // ALignment 1
        {
            //PROCESSING: Different directions lead to different rooms
            if(direction == 'N') //Exit
            {
                //OUTPUT: Display to the user that they have completed the
                //        game and their scores along with a congratulation
                cout << "You found the exit!" << endl
                     << "Your score is " << bananas + oranges
                     << "(" << bananas << " bananas and " << oranges
                     << " oranges)." << endl
                     << "Bye bye!!!" << endl;

                //PROCESSING: Change the state of the game to end
                val = false;
            }
            else if(direction == 'S') //Monster
                //monsterRoom - Display the name of the monster and reset
                //              bananas and oranges to zero
                monsterRoom(bananas, oranges, monsterName);
            else if(direction == 'E') //Genie
                //genieRoom - Give the user two bananas and one orange
                genieRoom(bananas, oranges);
            else
                //pictureRoom - Display to the user a picture
                pictureRoom();
        }
        //Same as the alignment above but with different rooms linked to
        //different directions
        else //Alignmnet 2
        {
            if(direction == 'W') //Exit
            {
                cout << "You found the exit!" << endl
                     << "Your score is " << bananas + oranges
                     << "(" << bananas << " bananas and " << oranges
                     << " oranges)." << endl
                     << "Bye bye!!!" << endl;

                val = false;
            }
            else if(direction == 'N') //Monster
                monsterRoom(bananas, oranges, monsterName);
            else if(direction == 'S') //Genie
                genieRoom(bananas, oranges);
            else
                pictureRoom();
        }
    }
}

bool isValid(char direction)
{
    //PROCESSING: Test if the inputted direction matches any one of the
    //            four possible directions and return true or false
    if(direction == 'N' || direction == 'S' || direction == 'W'
            || direction == 'E')
        return true;
    else
        return false;
}

void monsterRoom(int& bananas, int& oranges, string monName)
{
    //PROCESSING: Reset bananas and oranges scores to zero through pass
    //            by reference
    bananas = 0;
    oranges = 0;

    //OUTPUT: Display that the user has been attacked by the scary monster
    //        and that their oranges and bananas have been stolen
    cout << "WATCH OUT!!!" << endl << monName
         << " attacks you and steals all of your bananas and oranges."
         << endl;
}

void genieRoom(int& bananas, int& oranges)
{
    //PROCESSING: Two bananas will be added to the banana count and one
    //            orange to the orange count
    bananas += 2;
    oranges += 1;

    //OUTPUT: Display to user that a genie has appeared to give them
    //        two bananas and one orange
    cout << "!!Poof!! "
         << "A Genie pops out and grants you 2 bananas and 1 orange."
         << endl;

}

void drawPicture()
{
    //OUTPUT: Display a picture of a robot
    cout << "        _--~~--_" << endl;
    cout << "      /~/_|  |_\\~\\" << endl;
    cout << "     |____________|" << endl;
    cout << "     |[][][][][][]|" << endl;
    cout << "   __| __         |__" << endl;
    cout << "  |  ||. |   ==   |  |" << endl;
    cout << " (|  ||__|   ==   |  |)" << endl;
    cout << "  |  |[] []  ==   |  |" << endl;
    cout << "  |  |____________|  |" << endl;
    cout << "  /__\\            /__\\" << endl;
    cout << "   ~~              ~~ " << endl;
    cout << endl;
}

void pictureRoom()
{
    //PROCESSING: Call the drawPicture function for the room
    //OUTPUT: Display to user that he has found a picture
    cout << endl;
    cout << "You found a picture!" << endl;

    //drawPicture - Will draw a picture of a robot
    drawPicture();
}
