
#ifndef LJ_TOWER
#define LJ_TOWER
#include "LStack.h"
//#include <list>

class TowerHanoi
{
    public:
        //Constructor accepts the amount of discs
        TowerHanoi(const int discs);
        //Destructor
        ~TowerHanoi();
        
        /*
         * Member Function: Moves a disc to another rod containing a larger (or no) disc otherwise nothing is changed.
         */
        void move(const int rod_from, const int rod_to);

        /*
         * Member Function: Checks if the last rod has the same size as total number of discs
         */
        const bool checkWin() const;
    
        /*
         * Member Function: Returns a string with a visual representation of the puzzle
         */
        const string print();

        /*
         * Member Function: Returns the number of discs in the puzzle
         */
        const int discs() const;
    private:
        /*
         * Member Function: returns the amount of x's found in the provided string
         */
        const int count_val(string line) const;
        
        LStack<string> rods [3];
        int discCount;


};

ostream& operator<< (ostream& stream, TowerHanoi& tower);

#endif