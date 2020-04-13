#include "TowerHanoi.h"
#include "LStack.h"
#include <cstdlib>
#include <string>

TowerHanoi::TowerHanoi(const int discs)
{
    discCount = discs;

    for (int i = discs; i > 0; i--)
    {
        string content = std::string("");
        //All strings should be same length
        content.append(discs-i, ' ');
        content.append(i*2-1, 'x');
        content.append(discs-i, ' ');
        rods[0].push(content);
    }
}

TowerHanoi::~TowerHanoi()
{
    //Nothing deleted as rods and discCount are both local to the class
}

void TowerHanoi::move(const int rod_from, const int rod_to)
{
    //decrease rod_from and rod_to in order to use them as indexes for rods
    int from_index = rod_from - 1;
    int to_index = rod_to - 1;
    if (from_index == to_index) return;

    //ensure the indexs are valid
    if (from_index < 0 || from_index > 2) return;
    if (to_index < 0 || to_index > 2) return;

    //ensure the rod being taken from actually has a disc
    if (rods[from_index].isEmpty()) return;

    //Ensure toRod has a value before accessing it's 'top'
    if (rods[to_index].size() > 0)
    {
        //ensure the disc being moved is only placed on a larger disc
        if (count_val(rods[from_index].peek()) < count_val(rods[to_index].peek()))
        {
            rods[to_index].push(rods[from_index].pop());
        }       
    }
    else
    {
        rods[to_index].push(rods[from_index].pop());
    }    
}

const int TowerHanoi::count_val(string s) const
{
    int count = 0;
    
    //iterate through each character in the string
    //use of size_t to avoid comparison between signed and unsigned int
    for (size_t i = 0; i < s.size(); i++)
    {
        //if the character is x then increment counter
        if (s[i] == 'x') count++;
    }

    return count;
}

const bool TowerHanoi::checkWin() const
{
    return rods[2].size() == discCount;
}

const int TowerHanoi::discs() const
{
    return discCount;
}

const string TowerHanoi::print()
{
    LStack<string> rodBackups[3];

    //create blank string the width of other discs to be used to pad space where there isn't a disc
    string tempPad = string();
    tempPad.append(discCount*2-1, ' ');

    string outval = string();
    //iterate through each 'layer' of discs
    for (int di = discCount; di > 0; di--)
    {        
        outval.append("  ");

        //iterate through each rod
        for (int rod_index = 0; rod_index <= 2; rod_index++)
        {            
            //Pad space if there is no disc at the current level.
            if (di > rods[rod_index].size() || rods[rod_index].size() == 0)
            {                
                outval.append(tempPad);
            }
            else
            {
                //append the disc's value to the string and push it to a temporary stack
                outval.append(rods[rod_index].peek());
                rodBackups[rod_index].push(rods[rod_index].pop());
            }
            outval.append(" ");
        }

        outval.append("\n");
    }

    //append a line of dashes to separate the rod numbers from the disc text
    outval.append(6+(discCount*2-1)*3, '-');
    outval.append("\n");

    //append rod numbers and separate them with dashes
    //note this is dynamically sized depending on the amount of discs in the game
    outval.append(discCount-1 + 2, ' ');
    outval.append("1");
    outval.append((discCount-1)*2 + 1, ' ');
    outval.append("2");
    outval.append((discCount-1)*2 + 1, ' ');
    outval.append("3\n");

    //restore stacks
    for (int r = 0; r <= 2; r++)
    {
        while (!rodBackups[r].isEmpty())
        {
            rods[r].push(rodBackups[r].pop());
        }
    }

    return outval;
}

ostream& operator<< (ostream& out, TowerHanoi& tower)
{
    out << tower.print();
    return out;
}