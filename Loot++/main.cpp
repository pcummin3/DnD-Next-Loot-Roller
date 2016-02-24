#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int mainMenu();
int treasureLevel();
int treasureLevelConversion(int, int);
void lootTableDirectory(int, int, int);
void instructions();

void iOne(int);
void iTwo(int);
void iThree(int);
void iFour(int);

void hOne(int);
void hTwo(int);
void hThree(int);
void hFour(int);

void magicA();
void magicB();
void magicC();
void magicD();
void magicE();
void magicF();
void magicG();
void magicH();
void magicI();

int main()
{
    //Initialize the random seed
    srand (time(NULL));

    //Declare variables
    int mainMenuSelection(0), tLevel(0), iTimes(0);

    //Create Menu Structure
     while (mainMenuSelection !=5)
    {
        mainMenuSelection = mainMenu();

        switch(mainMenuSelection)
        {

            case 1:  //  Individual Treasure
            {
                tLevel = treasureLevel();
                tLevel = treasureLevelConversion(tLevel, mainMenuSelection);
                cout << endl << "Please choose the number of creature loot drops: ";
                cin >> iTimes;

                while (iTimes < 1)
                {
                    cout << endl << endl;
                    cout << "You must enter a value greater than 0: ";
                    cin >> iTimes;
                }

                lootTableDirectory(tLevel, mainMenuSelection, iTimes);

                break;
            }

            case 2:
            {
                tLevel = treasureLevel();
                tLevel = treasureLevelConversion(tLevel, mainMenuSelection);
                lootTableDirectory(tLevel, mainMenuSelection, iTimes);

                break;
            }

            case 3:
            {
                tLevel = treasureLevel();
                tLevel = treasureLevelConversion(tLevel, mainMenuSelection);
                lootTableDirectory(tLevel, mainMenuSelection, iTimes);

                break;
            }

            case 4:
            {
                instructions();
                break;
            }

            case 5:
            {

                break;
            }
        }
    }

    return 0;
}

int mainMenu()
{
    int mainMenuSelection(0);

    while(true)
    {
        cout << endl;
        cout << "        *********************        " << endl;
        cout << "       |     -MAIN MENU-     |       " << endl;
        cout << "   *******************************   " << endl;
        cout << "*************************************" << endl;
        cout << "*  1.  Individual Treasure          *" << endl;
        cout << "*  2.  Treasure Horde               *" << endl;
        cout << "*  3.  Treasure Goblin              *" << endl;
        cout << "*  4.  Instructions                 *" << endl;
        cout << "*  5.  EXIT                         *" << endl;
        cout << "*************************************" << endl;
        cin >> mainMenuSelection;

        if (mainMenuSelection < 6 && mainMenuSelection > 0)
        {
            return mainMenuSelection;
        }
        cout << "Invalid Selection-" << endl << endl;
    }

    //return mainMenuSelection;
}

void instructions()
{
    cout << endl << endl;
    cout << "Welcome to Loot++ !!!" << endl;
    cout << "---------------------" << endl << endl;
    cout << "'Individual Treasure' can roll loot for several individual opponents to the" << endl;
    cout << "PC's.  'Individual Treasure' will display the total value of the encounter's" << endl;
    cout << "varied opponents in coins only.  This is not to say that the treasure" << endl;
    cout << "only comes in coins (gems, art, letters of mark, and other items of value)." << endl;
    cout << "It is simply easier to tabulate totals and display values in 'coin value'" << endl;
    cout << "In addition, it is worth noting that 'Individual Treasure' will never produce" << endl;
    cout << "magic items since they are so value-able and special.  Magic items on" << endl;
    cout << "individual opponents should be hand selected by the DM when appropriate." << endl << endl;

    cout << "'Treasure Hoard' will roll loot for a single Treasure Hoard.  Treasure Hoards" << endl;
    cout << "will include coin value of the treasure as well as the potential for magic" << endl;
    cout << "items; as this represents the loot for a powerful opponents, depository of" << endl;
    cout << "treasure, combined loot for a group, a player reward for a grand quest, or" << endl;
    cout << "anything else of appropriate design.  A DM may choose to roll a Treasure Hoard" << endl;
    cout << "for a group of monsters or a dungeon, and split the treasure up among several" << endl;
    cout << "encounters in place of, or in addition to, individual loot.  The DM may decide" << endl;
    cout << "that they would prefer to hand pick magic items for placement, which is fine." << endl;
    cout << "simply replace magic items rolled for a magic item of relatively comparable" << endl;
    cout << "power (see DMG for page 133 for more about treasure and this sort of thing)." << endl << endl;

    cout << "'Treasure Goblin' (Blizzard all rights reserved) rolls on the 'Treasure" << endl;
    cout << "Hoard' table of a higher level with an elevated chance of rolling magic items." << endl;
    cout << "This is to keep true to the nature of Treasure Goblins within the D3 universe" << endl;
    cout << "(don't want to disappoint our players now).  This is balanced by the fact that" << endl;
    cout << "Treasure Goblins will only have a chance to spawn in any given adventure or" << endl;
    cout << "quest; and even if it does, that's not to say the player's will successfully" << endl;
    cout << "incapacitate it.  Add on the fact that 5e can be deadly.  Sprinkle on the fact" << endl;
    cout << "that this is Gothic horror, and PC deaths are inevitable. Regardless of the" << endl;
    cout << "reason, 'Treasure Goblin' can be ignored when appropriate and they should" << endl;
    cout << "make for a lot of fun." << endl << endl;

    cout << "*************************" << endl;
    cout << "* Scroll up to read all *" << endl;
    cout << "*************************" << endl << endl;
}

int treasureLevel()
{
    int tLevel(0);

    while(true)
    {
        cout << endl << "Please enter the average CR for the encounter: ";
        cin >> tLevel;

        if (tLevel <= 20 && tLevel >= 0)
        {
            return tLevel;
        }
        cout << "Invalid Selection-" << endl << endl;
    }
}

int treasureLevelConversion(int tLevel, int mainMenuSelection)
{
    int modifiedTreasureLevel(0);

    modifiedTreasureLevel = 4;

    if (tLevel >= 11 && tLevel <= 16)
    {
        modifiedTreasureLevel = 3;
    }

    if (tLevel >= 5 && tLevel <= 10)
    {
        modifiedTreasureLevel = 2;
    }

    if (tLevel >= 0 && tLevel <= 4)
    {
        modifiedTreasureLevel = 1;
    }

    if (mainMenuSelection == 3)
    {
        modifiedTreasureLevel++;
    }

    return modifiedTreasureLevel;
}

void lootTableDirectory(int tLevel, int mainMenuSelection, int iTimes)
{
    if (tLevel == 5)
    {
        tLevel--;
        mainMenuSelection++;
    }

    if (mainMenuSelection == 1 && tLevel == 1)
    {
        iOne(iTimes);
    }

    if (mainMenuSelection == 1 && tLevel == 2)
    {
        iTwo(iTimes);
    }

    if (mainMenuSelection == 1 && tLevel == 3)
    {
        iThree(iTimes);
    }

    if (mainMenuSelection == 1 && tLevel == 4)
    {
        iFour(iTimes);
    }

    if (mainMenuSelection != 1 && tLevel == 1)
    {
        mainMenuSelection--;
        hOne(mainMenuSelection);
    }

    if (mainMenuSelection != 1 && tLevel == 2)
    {
        mainMenuSelection--;
        hTwo(mainMenuSelection);
    }

    if (mainMenuSelection != 1 && tLevel == 3)
    {
        mainMenuSelection--;
        hThree(mainMenuSelection);
    }

    if (mainMenuSelection != 1 && tLevel == 4)
    {
        mainMenuSelection--;
        hFour(mainMenuSelection);
    }
}

void iOne(int iTimes)
{
    int coins(0), sP(0), eP(0), gP(0), pP(0), dHundred(0), dSix(0), x(0), y(0);

    coins = 0;

        for(x = 0; x < iTimes; x++)
        {
            dHundred = 1 + rand() % 100;

            if (dHundred <= 3)
            {
                for (y = 0; y < 5; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + dSix;
                }
            }

            if (dHundred >= 31 && dHundred <= 60)
            {
                for (y = 0; y < 4; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 10);
                }
            }

            if (dHundred >= 61 && dHundred <= 70)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }

            }

            if (dHundred >= 71 && dHundred <= 95)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100);
                }

            }

            if (dHundred >= 96)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 1000);
            }
        }

    //  Coin Conversion
        if (coins >= 1000)
        {
            pP = coins / 1000;
            coins = coins % 1000;
        }

        if (coins >= 100)
        {
            gP = coins / 100;
            coins = coins % 100;
        }

        if (coins >= 50)
        {
            eP = coins / 50;
            coins = coins % 50;
        }

        if (coins >= 10)
        {
            sP = coins / 10;
            coins = coins % 10;
        }

    cout << endl << endl;
    cout << "Total Value" << endl;
    cout << "-----------" << endl << endl;
    cout << "CP\t" << coins << endl;
    cout << "SP\t" << sP << endl;
    cout << "EP\t" << eP << endl;
    cout << "GP\t" << gP << endl;
    cout << "PP\t" << pP << endl << endl;
}

void iTwo(int iTimes)
{
    int coins(0), cP(0), sP(0), eP(0), gP(0), pP(0), dHundred(0), dSix(0), x(0), y(0);

    coins = 0;

        for (x = 0; x < iTimes; x++)
        {
            dHundred = 1 + rand() % 100;

            if (dHundred <= 30)
            {
                for (y = 0; y < 4; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1 * 100);
                }

                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 50 * 10);
            }

            if (dHundred >= 31 && dHundred <= 60)
            {
                for(y = 0; y < 6; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 10 * 10);
                }

                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100 * 10);
                }
            }

            if (dHundred >= 61 && dHundred <= 70)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50 * 10);
                }

                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100 * 10);
                }
            }

            if (dHundred >= 71 && dHundred <= 95)
            {
                for (y = 0; y < 4; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100 * 10);
                }
            }

            if (dHundred >= 96)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100 * 10);
                }

                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }
            }
        }

    //  Coin Conversion
        if (coins >= 1000)
        {
            pP = coins / 1000;
            coins = coins % 1000;
        }

        if (coins >= 100)
        {
            gP = coins / 100;
            coins = coins % 100;
        }

        if (coins >= 50)
        {
            eP = coins / 50;
            coins = coins % 50;
        }

        if (coins >= 10)
        {
            sP = coins / 10;
            coins = coins % 10;
        }

    cout << endl << endl;
    cout << "Total Value" << endl;
    cout << "-----------" << endl << endl;
    cout << "CP\t" << coins << endl;
    cout << "SP\t" << sP << endl;
    cout << "EP\t" << eP << endl;
    cout << "GP\t" << gP << endl;
    cout << "PP\t" << pP << endl << endl;
}

void iThree(int iTimes)
{
    int coins(0), cP(0), sP(0), eP(0), gP(0), pP(0), dHundred(0), dSix(0), x(0), y(0);

    coins = 0;

        for(x = 0; x < iTimes; x++)
        {
            dHundred = 1 + rand() % 100;

            if (dHundred <= 20)
            {
                for (y = 0; y < 4; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 10 * 100);
                }

                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 100 * 100);
            }

            if (dHundred >= 21 & dHundred <= 35)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 50 * 100);

                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 100 * 100);
            }

            if (dHundred >= 36 && dHundred <= 75)
            {
                for (y = 0; y < 2; y++)
                {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 100 * 100);
                }

                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 1000 * 10);
            }

            if (dHundred >= 76)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100 * 100);
                }

                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000 * 10);
                }
            }
        }

    //  Coin Conversion
        if (coins >= 1000)
        {
            pP = coins / 1000;
            coins = coins % 1000;
        }

        if (coins >= 100)
        {
            gP = coins / 100;
            coins = coins % 100;
        }

        if (coins >= 50)
        {
            eP = coins / 50;
            coins = coins % 50;
        }

        if (coins >= 10)
        {
            sP = coins / 10;
            coins = coins % 10;
        }

    cout << endl << endl;
    cout << "Total Value" << endl;
    cout << "-----------" << endl << endl;
    cout << "CP\t" << coins << endl;
    cout << "SP\t" << sP << endl;
    cout << "EP\t" << eP << endl;
    cout << "GP\t" << gP << endl;
    cout << "PP\t" << pP << endl << endl;
}

void iFour(int iTimes)
{
    int coins(0), cP(0), sP(0), eP(0), gP(0), pP(0), dHundred(0), dSix(0), x(0), y(0);

    coins = 0;

        for(x = 0; x < iTimes; x++)
        {
            dHundred = 1 + rand() % 100;

            if (dHundred <= 15)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50 * 1000);
                }

                for (y = 0; y < 8; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100 * 100);
                }
            }

            if (dHundred >= 16 && dHundred <= 55)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 100 * 1000);

                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 1000 * 100);
            }

            if (dHundred >= 56)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 100 * 1000);

                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000 * 100);
                }
            }
        }

    //  Coin Conversion
        if (coins >= 1000)
        {
            pP = coins / 1000;
            coins = coins % 1000;
        }

        if (coins >= 100)
        {
            gP = coins / 100;
            coins = coins % 100;
        }

        if (coins >= 50)
        {
            eP = coins / 50;
            coins = coins % 50;
        }

        if (coins >= 10)
        {
            sP = coins / 10;
            coins = coins % 10;
        }

    cout << endl << endl;
    cout << "Total Value" << endl;
    cout << "-----------" << endl << endl;
    cout << "CP\t" << coins << endl;
    cout << "SP\t" << sP << endl;
    cout << "EP\t" << eP << endl;
    cout << "GP\t" << gP << endl;
    cout << "PP\t" << pP << endl << endl;
}

void hOne(int mainMenuSelection)
{
    int coins(0), cP(0), sP(0), eP(0), gP(0), pP(0), dHundred(0), dSix(0), dFour(0), x(0), y(0);

    cout << endl  << endl;
    coins = 0;

        for(x = 0; x < mainMenuSelection; x++)
        {
            dHundred = 1 + rand() % 100;

            if (dHundred <= 6)
            {
                //  This roll nets nothing extra
            }

            if (dHundred >= 7 && dHundred <= 16)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 10);
                }
            }

            if (dHundred >= 17 && dHundred <= 26)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 25);
                }
            }

            if (dHundred >= 27 && dHundred <= 36)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }
            }

            if (dHundred >= 37 && dHundred <= 44)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 10);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicA();
                }
            }

            if (dHundred >= 45 && dHundred <= 52)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 25);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicA();
                }
            }

            if (dHundred >= 53 &&dHundred <= 60)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicA();
                }
            }

            if (dHundred >= 61 && dHundred <= 65)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 10);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicB();
                }
            }

            if (dHundred >= 66 && dHundred <= 70)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() %4;
                    coins = coins + (dFour * 25);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicB();
                }
            }

            if (dHundred >= 71 && dHundred <= 75)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() %6;
                    coins = coins + (dSix * 50);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicB();
                }
            }

            if (dHundred >= 76 && dHundred <= 78)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 10);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicC();
                }

            }

            if (dHundred >= 79 && dHundred <= 80)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 25);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 81 && dHundred <= 85)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 86 && dHundred <= 92)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() %4;
                    coins = coins + (dFour * 25);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicF();
                }
            }

            if (dHundred >= 93 && dHundred <= 97)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicF();
                }
            }

            if (dHundred >= 98 && dHundred <= 99)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 25);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

            if (dHundred >= 100)
            {
                for (y = 0; y < 2; y++)
                {
                    dSix = 1 + rand() %6;
                    coins = coins + (dSix * 50);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

            //  Determine Base Coinage (The other rolls where for art/gems and magic)
            //  Remember, everything is being calculated in GP for hordes, which then get converted into CP later on
            for (y = 0; y < 6; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 1);
            }

            for (y = 0; y < 3; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 10);
            }

            for (y = 0; y < 2; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 10);
            }

            //  Determine Gems with an independent d100 roll (20% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 20)
            {
                dSix = 1 + rand() % 6;

                if (dSix == 1)
                {
                    cout << "Sapphire" << endl;
                }

                if (dSix == 2)
                {
                    cout << "Ruby" << endl;
                }

                if (dSix == 3)
                {
                    cout << "Topaz" << endl;
                }

                if (dSix == 4)
                {
                    cout << "Diamond" << endl;
                }

                if (dSix == 5)
                {
                    cout << "Emerald" << endl;
                }

                if (dSix == 6)
                {
                    cout << "amethyst" << endl;
                }
            }

            //  Determine Cursed items with an independent d100 roll (4% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 4)
            {
                cout << "Cursed Item (DMG P. 138)" << endl;
            }

            //  Determine Intelligent items with an independent d100 roll (4% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 4)
            {
                cout << "Intelligent Item (DMG P. 214)" << endl;
            }

            //  Determine Artifacts with an independent d100 roll (1% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 1)
            {
                dFour = 1 + rand() % 4;

                if (dFour == 1)
                {
                    cout << "[EVIL] ";
                }

                if (dFour == 2 || dFour == 3)
                {
                    cout << "[UNALIGNED] ";
                }

                if (dFour == 4)
                {
                    cout << "[GOOD] ";
                }
                cout << "Artifact (DMG P. 219)" << endl;
            }
        }

    //  Pre Conversion (everything is in gold pieces and needs to be in CP)
        coins = coins * 100;

    //  Goblin Coin Balancer
        coins = coins / mainMenuSelection;

    //  Coin Conversion
        if (coins >= 1000)
        {
            pP = coins / 1000;
            coins = coins % 1000;
        }

        if (coins >= 100)
        {
            gP = coins / 100;
            coins = coins % 100;
        }

        if (coins >= 50)
        {
            eP = coins / 50;
            coins = coins % 50;
        }

        if (coins >= 10)
        {
            sP = coins / 10;
            coins = coins % 10;
        }

    cout << endl << endl;
    cout << "Total Value" << endl;
    cout << "-----------" << endl << endl;
    cout << "CP\t" << coins << endl;
    cout << "SP\t" << sP << endl;
    cout << "EP\t" << eP << endl;
    cout << "GP\t" << gP << endl;
    cout << "PP\t" << pP << endl << endl;
}

void hTwo(int mainMenuSelection)
{
    int coins(0), cP(0), sP(0), eP(0), gP(0), pP(0), dHundred(0), dSix(0), dFour(0), x(0), y(0);

    cout << endl  << endl;
    coins = 0;

        for(x = 0; x < mainMenuSelection; x++)
        {
            dHundred = 1 + rand() % 100;

            if (dHundred <= 4)
            {
                //  This roll nets nothing extra
            }

            if (dHundred >= 5 && dHundred <= 10)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 25);
                }
            }

            if (dHundred >= 11 && dHundred <= 16)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }
            }

            if (dHundred >= 17 && dHundred <= 22)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100);
                }
            }

            if (dHundred >= 23 && dHundred <= 28)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }
            }

            if (dHundred >= 29 && dHundred <= 32)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 25);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicA();
                }
            }

            if (dHundred >= 33 &&dHundred <= 36)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicA();
                }
            }

            if (dHundred >= 37 && dHundred <= 40)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicA();
                }
            }

            if (dHundred >= 41 && dHundred <= 44)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicA();
                }
            }

            if (dHundred >= 45 && dHundred <= 49)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 25);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicB();
                }
            }

            if (dHundred >= 50 && dHundred <= 54)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicB();
                }

            }

            if (dHundred >= 55 && dHundred <= 59)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicB();
                }
            }

            if (dHundred >= 60 && dHundred <= 63)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicB();
                }
            }

            if (dHundred >= 64 && dHundred <= 66)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 25);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 67 && dHundred <= 69)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 70 && dHundred <= 72)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 73 && dHundred <= 74)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 75 && dHundred <= 76)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 25);
                }

                magicD();
            }

            if (dHundred >= 77 && dHundred <= 78)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }

                magicD();
            }

           if (dHundred == 79)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100);
                }

                magicD();
            }

           if (dHundred == 80)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                magicD();
            }

            if (dHundred >= 81 && dHundred <= 84)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 25);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicF();
                }
            }

           if (dHundred >= 85 && dHundred <= 88)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 50);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicF();
                }
            }

           if (dHundred >= 89 && dHundred <= 91)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicF();
                }
            }

            if (dHundred >= 92 && dHundred <= 94)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicF();
                }
            }

            if (dHundred >= 95 && dHundred <= 96)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

            if (dHundred >= 97 && dHundred <= 98)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

            if (dHundred == 99)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100);
                }

                magicH();
            }

            if (dHundred == 100)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                magicH();
            }

            //  Determine Base Coinage (The other rolls where for art/gems and magic)
            //  Remember, everything is being calculated in GP for hordes, which then get converted into CP later on
            for (y = 0; y < 2; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 1);
            }

            for (y = 0; y < 2; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 100);
            }

            for (y = 0; y < 6; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 100);
            }

            for (y = 0; y < 3; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 100);
            }

            //  Determine Gems with an independent d100 roll (25% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 25)
            {
                dSix = 1 + rand() % 6;

                if (dSix == 1)
                {
                    cout << "Sapphire" << endl;
                }

                if (dSix == 2)
                {
                    cout << "Ruby" << endl;
                }

                if (dSix == 3)
                {
                    cout << "Topaz" << endl;
                }

                if (dSix == 4)
                {
                    cout << "Diamond" << endl;
                }

                if (dSix == 5)
                {
                    cout << "Emerald" << endl;
                }

                if (dSix == 6)
                {
                    cout << "amethyst" << endl;
                }
            }

            //  Determine Cursed items with an independent d100 roll (6% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 6)
            {
                cout << "Cursed Item (DMG P. 138)" << endl;
            }

            //  Determine Intelligent items with an independent d100 roll (6% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 6)
            {
                cout << "Intelligent Item (DMG P. 214)" << endl;
            }

            //  Determine Artifacts with an independent d100 roll (2% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 2)
            {
                dFour = 1 + rand() % 4;

                if (dFour == 1)
                {
                    cout << "[EVIL] ";
                }

                if (dFour == 2 || dFour == 3)
                {
                    cout << "[UNALIGNED] ";
                }

                if (dFour == 4)
                {
                    cout << "[GOOD] ";
                }
                cout << "Artifact (DMG P. 219)" << endl;
            }
        }

    //  Pre Conversion (everything is in gold pieces and needs to be in CP)
        coins = coins * 100;

    //  Goblin Coin Balancer
        coins = coins / mainMenuSelection;

    //  Coin Conversion
        if (coins >= 1000)
        {
            pP = coins / 1000;
            coins = coins % 1000;
        }

        if (coins >= 100)
        {
            gP = coins / 100;
            coins = coins % 100;
        }

        if (coins >= 50)
        {
            eP = coins / 50;
            coins = coins % 50;
        }

        if (coins >= 10)
        {
            sP = coins / 10;
            coins = coins % 10;
        }

    cout << endl << endl;
    cout << "Total Value" << endl;
    cout << "-----------" << endl << endl;
    cout << "CP\t" << coins << endl;
    cout << "SP\t" << sP << endl;
    cout << "EP\t" << eP << endl;
    cout << "GP\t" << gP << endl;
    cout << "PP\t" << pP << endl << endl;
}

void hThree(int mainMenuSelection)
{
    int coins(0), cP(0), sP(0), eP(0), gP(0), pP(0), dHundred(0), dSix(0), dFour(0), x(0), y(0);

    cout << endl  << endl;
    coins = 0;

        for(x = 0; x < mainMenuSelection; x++)
        {
            dHundred = 1 + rand() % 100;

            if (dHundred <= 3)
            {
                //  This roll nets nothing extra
            }

            if (dHundred >= 4 && dHundred <= 6)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }
            }

            if (dHundred >= 7 && dHundred <= 9)
            {
                for (y = 0; y < 2 ; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 750);
                }
            }

            if (dHundred >= 10 && dHundred <= 12)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 500);
                }
            }

            if (dHundred >= 13 && dHundred <= 15)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }
            }

            if (dHundred >= 16 && dHundred <= 19)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicA();
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicB();
                }
            }

            if (dHundred >= 20 &&dHundred <= 23)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 750);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicA();
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicB();
                }
            }

            if (dHundred >= 24 && dHundred <= 26)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 100);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicA();
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicB();
                }
            }

            if (dHundred >= 27 && dHundred <= 29)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() %6;
                    coins = coins + (dSix * 1000);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicA();
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicB();
                }
            }

            if (dHundred >= 30 && dHundred <= 35)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 36 && dHundred <= 40)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 750);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 41 && dHundred <= 45)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 500);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 46 && dHundred <= 50)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 51 && dHundred <= 54)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() %4;
                    coins = coins + (dFour * 250);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicD();
                }
            }

            if (dHundred >= 55 && dHundred <= 58)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 750);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicD();
                }
            }

            if (dHundred >= 59 && dHundred <= 62)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 500);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicD();
                }
            }

            if (dHundred >= 63 && dHundred <= 66)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                dFour = 1 + rand() %4;
                for (y = 0; y < dFour; y++)
                {
                    magicD();
                }
            }

            if (dHundred >= 67 && dHundred <= 68)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                magicE();
            }

            if (dHundred >= 69 && dHundred <= 70)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 50);
                }

                magicE();
            }

           if (dHundred >= 71 && dHundred <= 72)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 500);
                }

                magicE();
            }

           if (dHundred >= 73 && dHundred <= 74)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                magicE();
            }

            if (dHundred >= 75 && dHundred <= 76)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                magicF();

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

           if (dHundred >= 77 && dHundred <= 78)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 750);
                }

                magicF();

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

           if (dHundred >= 79 && dHundred <= 80)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 500);
                }

                magicF();

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

            if (dHundred >= 81 && dHundred <= 82)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 250);
                }

                magicF();

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

            if (dHundred >= 83 && dHundred <= 85)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 100);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicH();
                }
            }

            if (dHundred >= 86 && dHundred <= 88)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 750);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicH();
                }
            }

            if (dHundred >= 89 && dHundred <= 90)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 500);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicH();
                }
            }

            if (dHundred >= 91 && dHundred <= 92)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicH();
                }
            }

            if (dHundred >= 93 && dHundred <= 94)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 250);
                }

                magicI();
            }

            if (dHundred >= 95 && dHundred <= 96)
            {
                for (y = 0; y < 2; y++)
                {
                    dFour = 1 + rand() % 4;
                    coins = coins + (dFour * 750);
                }

                magicI();
            }

            if (dHundred >= 97 && dHundred <= 98)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 500);
                }

                magicI();
            }

            if (dHundred >= 99 && dHundred <= 100)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                magicI();
            }

            //  Determine Base Coinage (The other rolls where for art/gems and magic)
            //  Remember, everything is being calculated in GP for hordes, which then get converted into CP later on
            for (y = 0; y < 4; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 1000);
            }

            for (y = 0; y < 5; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 1000);
            }

            //  Determine Gems with an independent d100 roll (30% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 30)
            {
                dSix = 1 + rand() % 6;

                if (dSix == 1)
                {
                    cout << "Sapphire" << endl;
                }

                if (dSix == 2)
                {
                    cout << "Ruby" << endl;
                }

                if (dSix == 3)
                {
                    cout << "Topaz" << endl;
                }

                if (dSix == 4)
                {
                    cout << "Diamond" << endl;
                }

                if (dSix == 5)
                {
                    cout << "Emerald" << endl;
                }

                if (dSix == 6)
                {
                    cout << "amethyst" << endl;
                }
            }

            //  Determine Cursed items with an independent d100 roll (7% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 7)
            {
                cout << "Cursed Item (DMG P. 138)" << endl;
            }

            //  Determine Intelligent items with an independent d100 roll (8% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 8)
            {
                cout << "Intelligent Item (DMG P. 214)" << endl;
            }

            //  Determine Artifacts with an independent d100 roll (3% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 3)
            {
                dFour = 1 + rand() % 4;

                if (dFour == 1)
                {
                    cout << "[EVIL] ";
                }

                if (dFour == 2 || dFour == 3)
                {
                    cout << "[UNALIGNED] ";
                }

                if (dFour == 4)
                {
                    cout << "[GOOD] ";
                }
                cout << "Artifact (DMG P. 219)" << endl;
            }
        }

    //  Pre Conversion (everything is in gold pieces and needs to be in CP)
        coins = coins * 100;

    //  Goblin Coin Balancer
        coins = coins / mainMenuSelection;

    //  Coin Conversion
        if (coins >= 1000)
        {
            pP = coins / 1000;
            coins = coins % 1000;
        }

        if (coins >= 100)
        {
            gP = coins / 100;
            coins = coins % 100;
        }

        if (coins >= 50)
        {
            eP = coins / 50;
            coins = coins % 50;
        }

        if (coins >= 10)
        {
            sP = coins / 10;
            coins = coins % 10;
        }

    cout << endl << endl;
    cout << "Total Value" << endl;
    cout << "-----------" << endl << endl;
    cout << "CP\t" << coins << endl;
    cout << "SP\t" << sP << endl;
    cout << "EP\t" << eP << endl;
    cout << "GP\t" << gP << endl;
    cout << "PP\t" << pP << endl << endl;
}

void hFour(int mainMenuSelection)
{
    int cP(0), sP(0), eP(0), gP(0), pP(0), dHundred(0), dTen(0), dEight(0), dSix(0), dFour(0), x(0), y(0);
    float coins(0);

    cout << endl  << endl;
    coins = 0;

        for(x = 0; x < mainMenuSelection; x++)
        {
            dHundred = 1 + rand() % 100;

            if (dHundred <= 2)
            {
                //  This roll nets nothing extra
            }

            if (dHundred >= 3 && dHundred <= 5)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                dEight = 1 + rand() % 8;
                for (y = 0; y < dEight; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 6 && dHundred <= 8)
            {
                dTen = 1 + rand() % 10;
                coins = coins + (dTen * 2500);

                dEight = 1 + rand() % 8;
                for (y = 0; y < dEight; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 9 && dHundred <= 11)
            {
                dFour = 1 + rand() % 4;
                coins = coins + (dFour * 7500);

                dEight = 1 + rand() % 8;
                for (y = 0; y < dEight; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 12 && dHundred <= 14)
            {
                dEight = 1 + rand() % 8;
                coins = coins + (dEight * 5000);

                dEight = 1 + rand() % 8;
                for (y = 0; y < dEight; y++)
                {
                    magicC();
                }
            }

            if (dHundred >= 15 && dHundred <= 22)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicD();
                }
            }

            if (dHundred >= 23 &&dHundred <= 30)
            {
                dTen = 1 + rand() % 10;
                coins = coins + (dTen * 2500);

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicD();
                }
            }

            if (dHundred >= 31 && dHundred <= 38)
            {
                dFour = 1 + rand() % 4;
                coins = coins + (dFour * 7500);

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicD();
                }
            }

            if (dHundred >= 39 && dHundred <= 46)
            {
                dEight = 1 + rand() % 8;
                coins = coins + (dEight * 5000);

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicD();
                }
            }

            if (dHundred >= 47 && dHundred <= 52)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicE();
                }
            }

            if (dHundred >= 53 && dHundred <= 58)
            {
                dTen = 1 + rand() % 10;
                coins = coins + (dTen * 2500);

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicE();
                }
            }

            if (dHundred >= 59 && dHundred <= 63)
            {
                dFour = 1 + rand() % 4;
                coins = coins + (dFour * 7500);

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicE();
                }
            }

            if (dHundred >= 64 && dHundred <= 68)
            {
                dEight = 1 + rand() % 8;
                coins = coins + (dEight * 5000);

                dSix = 1 + rand() % 6;
                for (y = 0; y < dSix; y++)
                {
                    magicE();
                }
            }

            if (dHundred == 69)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

            if (dHundred == 70)
            {
                dTen = 1 + rand() % 10;
                coins = coins + (dTen * 2500);

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

            if (dHundred == 71)
            {
                dFour = 1 + rand() % 4;
                coins = coins + (dFour * 7500);

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

            if (dHundred == 72)
            {
                dEight = 1 + rand() % 8;
                coins = coins + (dEight * 5000);

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicG();
                }
            }

            if (dHundred >= 73 && dHundred <= 74)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicH();
                }
            }

            if (dHundred >= 75 && dHundred <= 76)
            {
                dTen = 1 + rand() % 10;
                coins = coins + (dTen * 2500);

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicH();
                }
            }

           if (dHundred >= 77 && dHundred <= 78)
            {
                dFour = 1 + rand() % 4;
                coins = coins + (dFour * 7500);

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicH();
                }
            }

           if (dHundred >= 79 && dHundred <= 80)
            {
                dEight = 1 + rand() % 8;
                coins = coins + (dEight * 5000);

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicH();
                }
            }

            if (dHundred >= 81 && dHundred <= 85)
            {
                for (y = 0; y < 3; y++)
                {
                    dSix = 1 + rand() % 6;
                    coins = coins + (dSix * 1000);
                }

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicI();
                }
            }

           if (dHundred >= 86 && dHundred <= 90)
            {
                dTen = 1 + rand() % 10;
                coins = coins + (dTen * 2500);

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicI();
                }
            }

           if (dHundred >= 91 && dHundred <= 95)
            {
                dFour = 1 + rand() % 4;
                coins = coins + (dFour * 7500);

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicI();
                }
            }

            if (dHundred >= 96 && dHundred <= 100)
            {
                dEight = 1 + rand() % 8;
                coins = coins + (dEight * 5000);

                dFour = 1 + rand() % 4;
                for (y = 0; y < dFour; y++)
                {
                    magicI();
                }
            }

            //  Determine Base Coinage (The other rolls where for art/gems and magic)
            //  Remember, everything is being calculated in GP for hordes, which then get converted into CP later on
            for (y = 0; y < 12; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 1000);
            }

            for (y = 0; y < 8; y++)
            {
                dSix = 1 + rand() % 6;
                coins = coins + (dSix * 10000);
            }

            //  Determine Gems with an independent d100 roll (35% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 35)
            {
                dSix = 1 + rand() % 6;

                if (dSix == 1)
                {
                    cout << "Sapphire" << endl;
                }

                if (dSix == 2)
                {
                    cout << "Ruby" << endl;
                }

                if (dSix == 3)
                {
                    cout << "Topaz" << endl;
                }

                if (dSix == 4)
                {
                    cout << "Diamond" << endl;
                }

                if (dSix == 5)
                {
                    cout << "Emerald" << endl;
                }

                if (dSix == 6)
                {
                    cout << "amethyst" << endl;
                }
            }

            //  Determine Cursed items with an independent d100 roll (8% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 8)
            {
                cout << "Cursed Item (DMG P. 138)" << endl;
            }

            //  Determine Intelligent items with an independent d100 roll (10% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 10)
            {
                cout << "Intelligent Item (DMG P. 214)" << endl;
            }

            //  Determine Artifacts with an independent d100 roll (4% chance)
            dHundred = 1 + rand() % 100;

            if (dHundred <= 4)
            {
                dFour = 1 + rand() % 4;

                if (dFour == 1)
                {
                    cout << "[EVIL] ";
                }

                if (dFour == 2 || dFour == 3)
                {
                    cout << "[UNALIGNED] ";
                }

                if (dFour == 4)
                {
                    cout << "[GOOD] ";
                }
                cout << "Artifact (DMG P. 219)" << endl;
            }
        }


    //  Pre Conversion (everything is in gold pieces and needs to be in CP)
        coins = coins * 100;

    //  Goblin Coin Balancer
        coins = coins / mainMenuSelection;

    //  Goblin Coin Balancer continued...
        if (mainMenuSelection == 3)
        {
            coins = coins * 1.5;
        }

    //  Coins conversion (need to use int for % and not float)
        {
            cP = coins;
        }

    //  Coin Conversion
        if (cP >= 1000)
        {
            pP = cP / 1000;
            cP = cP % 1000;
        }

        if (cP >= 100)
        {
            gP = cP / 100;
            cP = cP % 100;
        }

        if (cP >= 50)
        {
            eP = cP / 50;
            cP = cP % 50;
        }

        if (cP >= 10)
        {
            sP = cP / 10;
            cP = cP % 10;
        }

    cout << endl << endl;
    cout << "Total Value" << endl;
    cout << "-----------" << endl << endl;
    cout << "CP\t" << cP << endl;
    cout << "SP\t" << sP << endl;
    cout << "EP\t" << eP << endl;
    cout << "GP\t" << gP << endl;
    cout << "PP\t" << pP << endl << endl;
}

void magicA()
{
    int dHundred(0);

    dHundred = 1 + rand() % 100;

    if (dHundred <= 50)
    {
        cout << "Potion of Healing" << endl;
    }

    if (dHundred >= 51 && dHundred <= 60)
    {
        cout << "Spell Scroll [Cantrip] (+5/DC: 13)" << endl;
    }

    if (dHundred >= 61 && dHundred <= 70)
    {
        cout << "Potion of Climbing" << endl;
    }

    if (dHundred >= 71 && dHundred <= 90)
    {
        cout << "Spell Scroll [1st Level] (+5/DC: 13)" << endl;
    }

    if (dHundred >= 91 && dHundred <= 94)
    {
        cout << "Spell Scroll [2nd Level] (+5/DC: 13)" << endl;
    }

    if (dHundred >= 95 && dHundred <= 98)
    {
        cout << "Potion of Greater Healing" << endl;
    }

    if (dHundred == 99)
    {
        cout << "Bag of Holding" << endl;
    }

    if (dHundred == 100)
    {
        cout << "Driftglobe" << endl;
    }
}

void magicB()
{
    int dHundred(0);

    dHundred = 1 + rand() % 100;

    if (dHundred <= 15)
    {
        cout << "Potion of Greater Healing" << endl;
    }

    if (dHundred >= 16 && dHundred <= 22)
    {
        cout << "Potion of Fire Breath" << endl;
    }

    if (dHundred >= 23 && dHundred <= 29)
    {
        cout << "Potion of Resistance" << endl;
    }

    if (dHundred >= 30 && dHundred <= 34)
    {
        cout << "Ammunition, +1 (x30)" << endl;
    }

    if (dHundred >= 35 && dHundred <= 39)
    {
        cout << "Potion of Animal Friendship" << endl;
    }

    if (dHundred >= 40 && dHundred <= 44)
    {
        cout << "Potion of Hill Giant Strength" << endl;
    }

    if (dHundred >= 45 && dHundred <= 49)
    {
        cout << "Potion of Growth" << endl;
    }

    if (dHundred >= 50 && dHundred <= 54)
    {
        cout << "Potion of Water Breathing" << endl;
    }

    if (dHundred >= 55 && dHundred <= 59)
    {
        cout << "Spell Scroll [2nd Level] (+5/DC: 13)" << endl;
    }

    if (dHundred >= 60 && dHundred <= 64)
    {
        cout << "Spell Scroll [3rd Level] (+7/DC: 15)" << endl;
    }

    if (dHundred >= 65 && dHundred <= 67)
    {
        cout << "Bag of Holding" << endl;
    }

    if (dHundred >= 68 && dHundred <= 70)
    {
        cout << "Keoghtom's Ointment" << endl;
    }

    if (dHundred >= 71 && dHundred <= 73)
    {
        cout << "Oil of Slipperiness" << endl;
    }

    if (dHundred >= 74 && dHundred <= 75)
    {
        cout << "Dust of Disappearance" << endl;
    }

    if (dHundred >= 76 && dHundred <= 77)
    {
        cout << "Dust of Dryness" << endl;
    }

    if (dHundred >= 78 && dHundred <= 79)
    {
        cout << "Dust of Sneezing and Choking" << endl;
    }

    if (dHundred >= 80 && dHundred <= 81)
    {
        cout << "Elemental Gem" << endl;
    }

    if (dHundred >= 82 && dHundred <= 83)
    {
        cout << "Philter of Love" << endl;
    }

    if (dHundred == 84)
    {
        cout << "Alchemy Jug" << endl;
    }

    if (dHundred == 85)
    {
        cout << "Cap of Water Breathing" << endl;
    }

    if (dHundred == 86)
    {
        cout << "Cloak of the Manta Ray" << endl;
    }

    if (dHundred == 87)
    {
        cout << "Driftglobe" << endl;
    }

    if (dHundred == 88)
    {
        cout << "Goggles of Night" << endl;
    }

    if (dHundred == 89)
    {
        cout << "Helm of Comprehending Languages" << endl;
    }

    if (dHundred == 90)
    {
        cout << "Immovable Rod" << endl;
    }

    if (dHundred == 91)
    {
        cout << "Lantern of Revealing" << endl;
    }

    if (dHundred == 92)
    {
        cout << "Mariner's Armor" << endl;
    }

    if (dHundred == 93)
    {
        cout << "Mithral Armor" << endl;
    }

    if (dHundred == 94)
    {
        cout << "Potion of Poison" << endl;
    }

    if (dHundred == 95)
    {
        cout << "Ring of Swimming" << endl;
    }

    if (dHundred == 96)
    {
        cout << "Robe of Useful Items" << endl;
    }

    if (dHundred == 97)
    {
        cout << "Rope of Climbing" << endl;
    }

    if (dHundred == 98)
    {
        cout << "Saddle of tthe Cavalier" << endl;
    }

    if (dHundred == 99)
    {
        cout << "Wand of Magic Detection" << endl;
    }

    if (dHundred == 100)
    {
        cout << "Wand of Secrets" << endl;
    }
}

void magicC()
{
    int dHundred(0);

    dHundred = 1 + rand() % 100;

    if (dHundred <= 15)
    {
        cout << "Potion of Superior Healing" << endl;
    }

    if (dHundred >= 16 && dHundred <= 22)
    {
        cout << "Spell Scroll [4th Level] (+7/DC: 15)" << endl;
    }

    if (dHundred >= 23 && dHundred <= 27)
    {
        cout << "Ammunition, +2 (x30)" << endl;
    }

    if (dHundred >= 28 && dHundred <= 32)
    {
        cout << "Potion of Clairvoyance" << endl;
    }

    if (dHundred >= 33 && dHundred <= 37)
    {
        cout << "Potion of Diminution" << endl;
    }

    if (dHundred >= 38 && dHundred <= 42)
    {
        cout << "Potion of Gaseous Form" << endl;
    }

    if (dHundred >= 43 && dHundred <= 47)
    {
        cout << "Potion of Frost Giant Strength" << endl;
    }

    if (dHundred >= 48 && dHundred <= 52)
    {
        cout << "Potion of Stone Giant Strength" << endl;
    }

    if (dHundred >= 53 && dHundred <= 57)
    {
        cout << "Potion of Heroism" << endl;
    }

    if (dHundred >= 58 && dHundred <= 62)
    {
        cout << "Potion of Invulnerability" << endl;
    }

    if (dHundred >= 63 && dHundred <= 67)
    {
        cout << "Potion of Mind Reading" << endl;
    }

    if (dHundred >= 68 && dHundred <= 72)
    {
        cout << "Spell Scroll [5th Level] (+9/DC: 17)" << endl;
    }

    if (dHundred >= 73 && dHundred <= 75)
    {
        cout << "Elixir of Health" << endl;
    }

    if (dHundred >= 76 && dHundred <= 78)
    {
        cout << "Oil of Etherealness" << endl;
    }

    if (dHundred >= 79 && dHundred <= 81)
    {
        cout << "Potion of Fire Giant Strength" << endl;
    }

    if (dHundred <= 82 && dHundred >= 84)
    {
        cout << "Quaal's Feather Token" << endl;
    }

    if (dHundred <= 85 && dHundred >= 87)
    {
        cout << "Scroll of Protection" << endl;
    }

    if (dHundred <= 88 && dHundred >= 89)
    {
        cout << "Bag of Beans" << endl;
    }

    if (dHundred <= 90 && dHundred >= 91)
    {
        cout << "Bead of Force" << endl;
    }

    if (dHundred == 92)
    {
        cout << "Chime of Opening" << endl;
    }

    if (dHundred == 93)
    {
        cout << "Decanter of Endless Water" << endl;
    }

    if (dHundred == 94)
    {
        cout << "Eyes of Minute Seeing" << endl;
    }

    if (dHundred == 95)
    {
        cout << "Folding Boat" << endl;
    }

    if (dHundred == 96)
    {
        cout << "Heward's Handy Haversack" << endl;
    }

    if (dHundred == 97)
    {
        cout << "Horseshoes of Speed" << endl;
    }

    if (dHundred == 98)
    {
        cout << "Necklace of Fireballs" << endl;
    }

    if (dHundred == 99)
    {
        cout << "Periapt of Health" << endl;
    }

    if (dHundred == 100)
    {
        cout << "Sending Stones" << endl;
    }
}

void magicD()
{
    int dHundred(0);

    dHundred = 1 + rand() % 100;

    if (dHundred <= 20)
    {
        cout << "Potion of Supreme Healing" << endl;
    }

    if (dHundred >= 21 && dHundred <= 30)
    {
        cout << "Potion of Invisibility" << endl;
    }

    if (dHundred >= 31 && dHundred <= 40)
    {
        cout << "Potion of Speed" << endl;
    }

    if (dHundred >= 41 && dHundred <= 50)
    {
        cout << "Spell Scroll [6th Level] (+9/DC: 17)" << endl;
    }

    if (dHundred >= 51 && dHundred <= 57)
    {
        cout << "Spell Scroll [7th Level] (+10/DC: 18)" << endl;
    }

    if (dHundred >= 58 && dHundred <= 62)
    {
        cout << "Ammunition, +3 (x30)" << endl;
    }

    if (dHundred >= 63 && dHundred <= 67)
    {
        cout << "Oil of Sharpness" << endl;
    }

    if (dHundred >= 68 && dHundred <= 72)
    {
        cout << "Potion of Flying" << endl;
    }

    if (dHundred >= 73 && dHundred <= 77)
    {
        cout << "Potion of Cloud Giant Strength" << endl;
    }

    if (dHundred >= 78 && dHundred <= 82)
    {
        cout << "Potion of Longevity" << endl;
    }

    if (dHundred >= 83 && dHundred <= 87)
    {
        cout << "Potion of Vitality" << endl;
    }

    if (dHundred >= 88 && dHundred <= 92)
    {
        cout << "Spell Scroll [8th Level] (+10/DC: 18)" << endl;
    }

    if (dHundred >= 93 && dHundred <= 95)
    {
        cout << "Horseshoes of a Zephyr" << endl;
    }

    if (dHundred >= 96 && dHundred <= 98)
    {
        cout << "Nolzur's Marvelous Pigments" << endl;
    }

    if (dHundred == 99)
    {
        cout << "Bag of Devouring" << endl;
    }

    if (dHundred == 100)
    {
        cout << "Portable Hole" << endl;
    }
}

void magicE()
{
    int dHundred(0);

    dHundred = 1 + rand() % 100;

    if (dHundred <= 30)
    {
        cout << "Spell Scroll [8th Level] (+10/DC: 18)" << endl;
    }

    if (dHundred >= 31 && dHundred <= 55)
    {
        cout << "Potion of Storm Giant Strength" << endl;
    }

    if (dHundred >= 56 && dHundred <= 70)
    {
        cout << "Potion of Supreme Healing" << endl;
    }

    if (dHundred >= 71 && dHundred <= 85)
    {
        cout << "Spell Scroll [9th Level] (+11/DC: 19)" << endl;
    }

    if (dHundred >= 86 && dHundred <= 93)
    {
        cout << "Universal Solvent" << endl;
    }

    if (dHundred >= 94 && dHundred <= 98)
    {
        cout << "Arrow of Slaying" << endl;
    }

    if (dHundred >= 99 && dHundred <= 100)
    {
        cout << "Sovereign Glue" << endl;
    }
}

void magicF()
{
    int dHundred(0);

    dHundred = 1 + rand() % 100;

    if (dHundred <= 15)
    {
        cout << "Weapon, +1" << endl;
    }

    if (dHundred >= 16 && dHundred <= 18)
    {
        cout << "Shield, +1" << endl;
    }

    if (dHundred >= 16 && dHundred <= 18)
    {
        cout << "Shield, +1" << endl;

    }if (dHundred >= 19 && dHundred <= 21)
    {
        cout << "Sentinel Shield" << endl;
    }

    if (dHundred >= 22 && dHundred <= 23)
    {
        cout << "Amulet of Proof Against Detection and Location" << endl;
    }

    if (dHundred >= 24 && dHundred <= 25)
    {
        cout << "Boots of Elvenkind" << endl;
    }

    if (dHundred >= 26 && dHundred <= 27)
    {
        cout << "Boots of Striding and Springing" << endl;
    }

    if (dHundred >= 28 && dHundred <= 29)
    {
        cout << "Bracers of Archery" << endl;
    }

    if (dHundred >= 30 && dHundred <= 31)
    {
        cout << "Brooch of Shielding" << endl;
    }

    if (dHundred >= 32 && dHundred <= 33)
    {
        cout << "Broom of Flying" << endl;
    }

    if (dHundred >= 34 && dHundred <= 35)
    {
        cout << "Cloak of Elvenkind" << endl;
    }

    if (dHundred >= 36 && dHundred <= 37)
    {
        cout << "Cloak of Protection" << endl;
    }

    if (dHundred >= 38 && dHundred <= 39)
    {
        cout << "Gauntlets of Ogre Power" << endl;
    }

    if (dHundred >= 40 && dHundred <= 41)
    {
        cout << "Hat of Disguise" << endl;
    }

    if (dHundred >= 42 && dHundred <= 43)
    {
        cout << "Javelin of Lightning" << endl;
    }

    if (dHundred >= 44 && dHundred <= 45)
    {
        cout << "Pearl of Power" << endl;
    }

    if (dHundred >= 46 && dHundred <= 47)
    {
        cout << "Rod of the Pact Keeper, +1" << endl;
    }

    if (dHundred >= 48 && dHundred <= 49)
    {
        cout << "Slippers of Spider Climbing" << endl;
    }

    if (dHundred >= 50 && dHundred <= 51)
    {
        cout << "Staff of the Adder" << endl;
    }

    if (dHundred >= 52 && dHundred <= 53)
    {
        cout << "Staff of the Python" << endl;
    }

    if (dHundred >= 54 && dHundred <= 55)
    {
        cout << "Sword of Vengeance" << endl;
    }

    if (dHundred >= 56 && dHundred <= 57)
    {
        cout << "Trident of Fish Command" << endl;
    }

    if (dHundred >= 58 && dHundred <= 59)
    {
        cout << "Wand of Magic Missiles" << endl;
    }

    if (dHundred >= 60 && dHundred <= 61)
    {
        cout << "Wand of the War Mage, +1" << endl;
    }

    if (dHundred >= 62 && dHundred <= 63)
    {
        cout << "Wand of Web" << endl;
    }

    if (dHundred >= 64 && dHundred <= 65)
    {
        cout << "Weapon of Warning" << endl;
    }

    if (dHundred == 66)
    {
        cout << "Adamantine Armor (Chain Mail)" << endl;
    }

    if (dHundred == 67)
    {
        cout << "Adamantine Armor (Chain Shirt)" << endl;
    }

    if (dHundred == 68)
    {
        cout << "Adamantine Armor (Scale Mail)" << endl;
    }

    if (dHundred == 69)
    {
        cout << "Bag of Tricks (Gray)" << endl;
    }

    if (dHundred == 70)
    {
        cout << "Bag of Tricks (Rust)" << endl;
    }

    if (dHundred == 71)
    {
        cout << "Bag of Tricks (Tan)" << endl;
    }

    if (dHundred == 72)
    {
        cout << "Boots of the Winterlands" << endl;
    }

    if (dHundred == 73)
    {
        cout << "Circlet of Blasting" << endl;
    }

    if (dHundred == 74)
    {
        cout << "Deck of Illusions" << endl;
    }

    if (dHundred == 75)
    {
        cout << "Eversmoking bottle" << endl;
    }

    if (dHundred == 76)
    {
        cout << "Eyes of Charming" << endl;
    }

    if (dHundred == 77)
    {
        cout << "Eyes of the Eagle" << endl;
    }

    if (dHundred == 78)
    {
        cout << "Figurine of Wondrous Power (Silver Raven" << endl;
    }

    if (dHundred == 79)
    {
        cout << "Gem of Brightness" << endl;
    }

    if (dHundred == 80)
    {
        cout << "Gloves of Missile Snaring" << endl;
    }

    if (dHundred == 81)
    {
        cout << "Gloves of Swimming and Climbing" << endl;
    }

    if (dHundred == 82)
    {
        cout << "Gloves of Thievery" << endl;
    }

    if (dHundred == 83)
    {
        cout << "Headband of Intellect" << endl;
    }

    if (dHundred == 84)
    {
        cout << "Helm of Telepathy" << endl;
    }

    if (dHundred == 85)
    {
        cout << "Instrument of the Bards (Doss Lute)" << endl;
    }

    if (dHundred == 86)
    {
        cout << "Instrument of the Bards (Fochlucan Bandore)" << endl;
    }

    if (dHundred == 87)
    {
        cout << "Instrument of the Bards (Mac-Fuimidh Cittern)" << endl;
    }

    if (dHundred == 88)
    {
        cout << "Medallion of Thoughts" << endl;
    }

    if (dHundred == 89)
    {
        cout << "Necklace of Adaptation" << endl;
    }

    if (dHundred == 90)
    {
        cout << "Periapt of Wound Closure" << endl;
    }

    if (dHundred == 91)
    {
        cout << "Pipes of Haunting" << endl;
    }

    if (dHundred == 92)
    {
        cout << "Pipes of the Sewers" << endl;
    }

    if (dHundred == 93)
    {
        cout << "Ring of Jumping" << endl;
    }

    if (dHundred == 94)
    {
        cout << "Ring of Mind Shielding" << endl;
    }

    if (dHundred == 95)
    {
        cout << "Ring of Warmth" << endl;
    }

    if (dHundred == 96)
    {
        cout << "Ring of Water Walking" << endl;
    }

    if (dHundred == 97)
    {
        cout << "Quiver of Ehlonna" << endl;
    }

    if (dHundred == 98)
    {
        cout << "Stone of Good Luck" << endl;
    }

    if (dHundred == 99)
    {
        cout << "Wind Fan" << endl;
    }

    if (dHundred == 100)
    {
        cout << "Winged Boots" << endl;
    }
}

void magicG()
{
    int dHundred(0), dEight(0);

    dHundred = 1 + rand() % 100;

    if (dHundred <= 11)
    {
        cout << "Weapon, +2" << endl;
    }

    if (dHundred >= 12 && dHundred <= 14)
    {
        cout << "Figurine of Wondrous Power: ";
        dEight = 1 + rand() % 8;

        if (dEight == 1)
        {
            cout << "Bronze Griffon" << endl;
        }

        if (dEight == 2)
        {
            cout << "Ebony Fly" << endl;
        }

        if (dEight == 3)
        {
            cout << "Golden Lions" << endl;
        }

        if (dEight == 4)
        {
            cout << "Ivory Goats" << endl;
        }

        if (dEight == 5)
        {
            cout << "Marble Elephant" << endl;
        }

        if (dEight >= 6 && dEight <= 7)
        {
            cout << "Onyx Dog" << endl;
        }

        if (dEight == 8)
        {
            cout << "Serpentine Owl" << endl;
        }
    }

    if (dHundred == 15)
    {
        cout << "Adamantine Armor (Breastplate)" << endl;
    }

    if (dHundred == 16)
    {
        cout << "Adamantine Armor (Splint)" << endl;
    }

    if (dHundred == 17)
    {
        cout << "Amulet of Health" << endl;
    }

    if (dHundred == 18)
    {
        cout << "Armor of Vulnerability" << endl;
    }

    if (dHundred == 19)
    {
        cout << "Arrow-Catching Shield" << endl;
    }

    if (dHundred == 20)
    {
        cout << "Belt of Dwarvenkind" << endl;
    }

    if (dHundred == 21)
    {
        cout << "Belt of Hill Giant Strength" << endl;
    }

    if (dHundred == 22)
    {
        cout << "Berserker Axe" << endl;
    }

    if (dHundred == 23)
    {
        cout << "Boots of Levitation" << endl;
    }

    if (dHundred == 24)
    {
        cout << "Boots of Speed" << endl;
    }

    if (dHundred == 25)
    {
        cout << "Bowl of Commanding Water Elementals" << endl;
    }

    if (dHundred == 26)
    {
        cout << "Bracers of Defense" << endl;
    }

    if (dHundred == 27)
    {
        cout << "Brazier of Commanding Fire Elementals" << endl;
    }

    if (dHundred == 28)
    {
        cout << "Cape of the Mountebank" << endl;
    }

    if (dHundred == 29)
    {
        cout << "Censure of Controlling Air Elementals" << endl;
    }

    if (dHundred == 30)
    {
        cout << "Armor, +1 Chain Mail" << endl;
    }

    if (dHundred == 31)
    {
        cout << "Armor of Resistance (Chain Mail)" << endl;
    }

    if (dHundred == 32)
    {
        cout << "Armor, +1 Chain Shirt" << endl;
    }

    if (dHundred == 33)
    {
        cout << "Armor of Resistance (Chain Shirt)" << endl;
    }

    if (dHundred == 34)
    {
        cout << "Cloak of Displacement" << endl;
    }

    if (dHundred == 35)
    {
        cout << "Cloak of the Bat" << endl;
    }

    if (dHundred == 36)
    {
        cout << "Cube of Force" << endl;
    }

    if (dHundred == 37)
    {
        cout << "Daern's Instant Fortress" << endl;
    }

    if (dHundred == 38)
    {
        cout << "Dagger of Venom" << endl;
    }

    if (dHundred == 39)
    {
        cout << "Dimensional Shackles" << endl;
    }

    if (dHundred == 40)
    {
        cout << "Dragon Slayer" << endl;
    }

    if (dHundred == 41)
    {
        cout << "Elven Chain" << endl;
    }

    if (dHundred == 42)
    {
        cout << "Flame Tongue" << endl;
    }

    if (dHundred == 43)
    {
        cout << "Gem of Seeing" << endl;
    }

    if (dHundred == 44)
    {
        cout << "Giant Slayer" << endl;
    }

    if (dHundred == 45)
    {
        cout << "Glamoured Studded Leather" << endl;
    }

    if (dHundred == 46)
    {
        cout << "Helm of Teleportation" << endl;
    }

    if (dHundred == 47)
    {
        cout << "Horn of Blasting" << endl;
    }

    if (dHundred == 48)
    {
        cout << "Horn of Valhalla (Silver or Brass)" << endl;
    }

    if (dHundred == 49)
    {
        cout << "Instrument of the Bards (Canaith Mandolin)" << endl;
    }

    if (dHundred == 50)
    {
        cout << "Instrument of the Bards (Cli Lyre)" << endl;
    }

    if (dHundred == 51)
    {
        cout << "Ioun Stone (Awareness)" << endl;
    }

    if (dHundred == 52)
    {
        cout << "Ioun Stone (Protection)" << endl;
    }

    if (dHundred == 53)
    {
        cout << "Ioun Stone (Reserve)" << endl;
    }

    if (dHundred == 54)
    {
        cout << "Ioun Stone (Sustenance)" << endl;
    }

    if (dHundred == 55)
    {
        cout << "Iron Bands of Bilarro" << endl;
    }

    if (dHundred == 56)
    {
        cout << "Armor, +1 Leather" << endl;
    }

    if (dHundred == 57)
    {
        cout << "Armor of Resistance (Leather)" << endl;
    }

    if (dHundred == 58)
    {
        cout << "Mace of Disruption" << endl;
    }

    if (dHundred == 59)
    {
        cout << "Mace of Smiting" << endl;
    }

    if (dHundred == 60)
    {
        cout << "Mace of Terror" << endl;
    }

    if (dHundred == 61)
    {
        cout << "Mantle of Spell Resistance" << endl;
    }

    if (dHundred == 62)
    {
        cout << "Necklace of Prayer Beads" << endl;
    }

    if (dHundred == 63)
    {
        cout << "Periapt of Proof Against Poison" << endl;
    }

    if (dHundred == 64)
    {
        cout << "Ring of Animal Influence" << endl;
    }

    if (dHundred == 65)
    {
        cout << "Ring of Evasion" << endl;
    }

    if (dHundred == 66)
    {
        cout << "Ring of Feather Falling" << endl;
    }

    if (dHundred == 67)
    {
        cout << "Ring of Free Action" << endl;
    }

    if (dHundred == 68)
    {
        cout << "Ring of Protection" << endl;
    }

    if (dHundred == 69)
    {
        cout << "Ring of Resistance" << endl;
    }

    if (dHundred == 70)
    {
        cout << "Ring of Spell Storing" << endl;
    }

    if (dHundred == 71)
    {
        cout << "Ring of the Ram" << endl;
    }

    if (dHundred == 72)
    {
        cout << "Ring of X-ray Vision" << endl;
    }

    if (dHundred == 73)
    {
        cout << "Robe of Eyes" << endl;
    }

    if (dHundred == 74)
    {
        cout << "Rod of Rulership" << endl;
    }

    if (dHundred == 75)
    {
        cout << "Rod of the Pact Keeper, +2" << endl;
    }

    if (dHundred == 76)
    {
        cout << "Rope of Entanglement" << endl;
    }

    if (dHundred == 77)
    {
        cout << "Armor, +1 Scale Mail" << endl;
    }

    if (dHundred == 78)
    {
        cout << "Armor of Resistance (Scale Mail)" << endl;
    }

    if (dHundred == 79)
    {
        cout << "Shield, +2" << endl;
    }

    if (dHundred == 80)
    {
        cout << "Shield of Missile Attraction" << endl;
    }

    if (dHundred == 81)
    {
        cout << "Staff of Charming" << endl;
    }

    if (dHundred == 82)
    {
        cout << "Staff of Healing" << endl;
    }

    if (dHundred == 83)
    {
        cout << "Staff of Swarming Insects" << endl;
    }

    if (dHundred == 84)
    {
        cout << "Staff of the Woodlands" << endl;
    }

    if (dHundred == 85)
    {
        cout << "Staff of Withering" << endl;
    }

    if (dHundred == 86)
    {
        cout << "Stone of Controlling Earth Elementals" << endl;
    }

    if (dHundred == 87)
    {
        cout << "Sun Blade" << endl;
    }

    if (dHundred == 88)
    {
        cout << "Sword of Life Stealing" << endl;
    }

    if (dHundred == 89)
    {
        cout << "Sword of Wounding" << endl;
    }

    if (dHundred == 90)
    {
        cout << "Tentacle Rod" << endl;
    }

    if (dHundred == 91)
    {
        cout << "Vicious Weapon" << endl;
    }

    if (dHundred == 92)
    {
        cout << "Wand of Binding" << endl;
    }

    if (dHundred == 93)
    {
        cout << "Wand of Enemy Detection" << endl;
    }

    if (dHundred == 94)
    {
        cout << "Wand of Fear" << endl;
    }

    if (dHundred == 95)
    {
        cout << "Wand of Fireballs" << endl;
    }

    if (dHundred == 96)
    {
        cout << "Wand of Lightning Bolts" << endl;
    }

    if (dHundred == 97)
    {
        cout << "Wand of Paralysis" << endl;
    }

    if (dHundred == 98)
    {
        cout << "Wand of the War Mage, +2" << endl;
    }

    if (dHundred == 99)
    {
        cout << "Wand of Wonder" << endl;
    }

    if (dHundred == 100)
    {
        cout << "Wings of Flying" << endl;
    }
}

void magicH()
{
    int dHundred(0);

    dHundred = 1 + rand() % 100;

    if (dHundred <= 10)
    {
        cout << "Weapon, +3" << endl;
    }

    if (dHundred >= 11 && dHundred <= 12)
    {
        cout << "Amulet of the Planes" << endl;
    }

    if (dHundred >= 13 && dHundred <= 14)
    {
        cout << "Carpet of Flying" << endl;
    }

    if (dHundred >= 15 && dHundred <= 16)
    {
        cout << "Crystal Ball (Very Rare Version)" << endl;
    }

    if (dHundred >= 17 && dHundred <= 18)
    {
        cout << "Ring of Regeneration" << endl;
    }

    if (dHundred >= 19 && dHundred <= 20)
    {
        cout << "Ring of Shooting Stars" << endl;
    }

    if (dHundred >= 21 && dHundred <= 22)
    {
        cout << "Ring of Telekinesis" << endl;
    }

    if (dHundred >= 23 && dHundred <= 24)
    {
        cout << "Robe of Scintillating Colors" << endl;
    }

    if (dHundred >= 25 && dHundred <= 26)
    {
        cout << "Robe of Stars" << endl;
    }

    if (dHundred >= 27 && dHundred <= 28)
    {
        cout << "Rod of Absorption" << endl;
    }

    if (dHundred >= 29 && dHundred <= 30)
    {
        cout << "Rod of Alertness" << endl;
    }

    if (dHundred >= 31 && dHundred <= 32)
    {
        cout << "Rod of Security" << endl;
    }

    if (dHundred >= 33 && dHundred <= 34)
    {
        cout << "Rod of the Pact Keeper, +3" << endl;
    }

    if (dHundred >= 35 && dHundred <= 36)
    {
        cout << "Scimitar of Speed" << endl;
    }

    if (dHundred >= 37 && dHundred <= 38)
    {
        cout << "Shield, +3" << endl;
    }

    if (dHundred >= 39 && dHundred <= 40)
    {
        cout << "Staff of Fire" << endl;
    }

    if (dHundred >= 41 && dHundred <= 42)
    {
        cout << "Staff of Frost" << endl;
    }

    if (dHundred >= 43 && dHundred <= 44)
    {
        cout << "Staff of Power" << endl;
    }

    if (dHundred >= 45 && dHundred <= 46)
    {
        cout << "Staff of Striking" << endl;
    }

    if (dHundred >= 47 && dHundred <= 48)
    {
        cout << "Staff of Thunder and Lightning" << endl;
    }

    if (dHundred >= 49 && dHundred <= 50)
    {
        cout << "Sword of Sharpness" << endl;
    }

    if (dHundred >= 51 && dHundred <= 52)
    {
        cout << "Wand of Polymorph" << endl;
    }

    if (dHundred >= 53 && dHundred <= 54)
    {
        cout << "Wand of the War Mage, +3" << endl;
    }

    if (dHundred == 55)
    {
        cout << "Adamantine Armor (Half Plate)" << endl;
    }

    if (dHundred == 56)
    {
        cout << "Adamantine Armor (Plate)" << endl;
    }

    if (dHundred == 57)
    {
        cout << "Animated Shield" << endl;
    }

    if (dHundred == 58)
    {
        cout << "Belt of Fire Giant Strength" << endl;
    }

    if (dHundred == 59)
    {
        cout << "Belt of Frost (or Stone) Giant Strength" << endl;
    }

    if (dHundred == 60)
    {
        cout << "Armor, +1 Breastplate" << endl;
    }

    if (dHundred == 61)
    {
        cout << "Armor of Resistance (Breastplate)" << endl;
    }

    if (dHundred == 62)
    {
        cout << "Candle of Invocation" << endl;
    }

    if (dHundred == 63)
    {
        cout << "Armor, +2 Chain Mail" << endl;
    }

    if (dHundred == 64)
    {
        cout << "Armor, +2 Chain Shirt" << endl;
    }

    if (dHundred == 65)
    {
        cout << "Cloak of Arachnida" << endl;
    }

    if (dHundred == 66)
    {
        cout << "Dancing Sword" << endl;
    }

    if (dHundred == 67)
    {
        cout << "Demon Armor" << endl;
    }

    if (dHundred == 68)
    {
        cout << "Dragon Scale Mail" << endl;
    }

    if (dHundred == 69)
    {
        cout << "Dwarven Plate" << endl;
    }

    if (dHundred == 70)
    {
        cout << "Dwarven Thrower" << endl;
    }

    if (dHundred == 71)
    {
        cout << "Efreeti Bottle" << endl;
    }

    if (dHundred == 72)
    {
        cout << "Figurine of Wondrous Power (Obsidian Steed)" << endl;
    }

    if (dHundred == 73)
    {
        cout << "Frost Brand" << endl;
    }

    if (dHundred == 74)
    {
        cout << "Helm of Brilliance" << endl;
    }

    if (dHundred == 75)
    {
        cout << "Horn of Valhalla (Bronze)" << endl;
    }

    if (dHundred == 76)
    {
        cout << "Instrument of the Bards (Anstruth Harp)" << endl;
    }

    if (dHundred == 77)
    {
        cout << "Ioun Stone (Absorption)" << endl;
    }

    if (dHundred == 78)
    {
        cout << "Ioun Stone (Agility)" << endl;
    }

    if (dHundred == 79)
    {
        cout << "Ioun Stone (Fortitude)" << endl;
    }

    if (dHundred == 80)
    {
        cout << "Ioun Stone (Insight)" << endl;
    }

    if (dHundred == 81)
    {
        cout << "Ioun Stone (Intellect)" << endl;
    }

    if (dHundred == 82)
    {
        cout << "Ioun Stone (Leadership)" << endl;
    }

    if (dHundred == 83)
    {
        cout << "Ioun Stone (Strength)" << endl;
    }

    if (dHundred == 84)
    {
        cout << "Armor, +2 Leather" << endl;
    }

    if (dHundred == 85)
    {
        cout << "Manual of Bodily Health" << endl;
    }

    if (dHundred == 86)
    {
        cout << "Manual of Gainful Exercise" << endl;
    }

    if (dHundred == 87)
    {
        cout << "Manual of Golems" << endl;
    }

    if (dHundred == 88)
    {
        cout << "Manual of Quickness of Action" << endl;
    }

    if (dHundred == 89)
    {
        cout << "Mirror of Life Trapping" << endl;
    }

    if (dHundred == 90)
    {
        cout << "Nine Lives Stealer" << endl;
    }

    if (dHundred == 91)
    {
        cout << "Oathbow" << endl;
    }

    if (dHundred == 92)
    {
        cout << "Armor, +2 Scale Mail" << endl;
    }

    if (dHundred == 93)
    {
        cout << "Spellguard Shield" << endl;
    }

    if (dHundred == 94)
    {
        cout << "Armor, +1 Splint" << endl;
    }

    if (dHundred == 95)
    {
        cout << "Armor of Resistance (Splint)" << endl;
    }

    if (dHundred == 96)
    {
        cout << "Armor, +1 Studded Leather" << endl;
    }

    if (dHundred == 97)
    {
        cout << "Armor of Resistance (Studded Leather)" << endl;
    }

    if (dHundred == 98)
    {
        cout << "Tome of Clear Thought" << endl;
    }

    if (dHundred == 99)
    {
        cout << "Tome of Leadership and Influence" << endl;
    }

    if (dHundred == 100)
    {
        cout << "Tome of Understanding" << endl;
    }
}

void magicI()
{
    int dHundred(0), dTwelve(0);

    dHundred = 1 + rand() % 100;

    if (dHundred <= 5)
    {
        cout << "Defender" << endl;
    }

    if (dHundred >= 6 && dHundred <= 10)
    {
        cout << "Hammer of Thunderbolts" << endl;
    }

    if (dHundred >= 11 && dHundred <= 15)
    {
        cout << "Luck Blade" << endl;
    }

    if (dHundred >= 16 && dHundred <= 20)
    {
        cout << "Sword of Answering" << endl;
    }

    if (dHundred >= 21 && dHundred <= 23)
    {
        cout << "Holy Avenger" << endl;
    }

    if (dHundred >= 24 && dHundred <= 26)
    {
        cout << "Ring of Djinni Summoning" << endl;
    }

    if (dHundred >= 27 && dHundred <= 29)
    {
        cout << "Ring of Invisibility" << endl;
    }

    if (dHundred >= 30 && dHundred <= 32)
    {
        cout << "Ring of Spell Turning" << endl;
    }

    if (dHundred >= 33 && dHundred <= 35)
    {
        cout << "Rod of Lordly Might" << endl;
    }

    if (dHundred >= 36 && dHundred <= 38)
    {
        cout << "Staff of the Magi" << endl;
    }

    if (dHundred >= 39 && dHundred <= 41)
    {
        cout << "Vorpal Sword" << endl;
    }

    if (dHundred >= 42 && dHundred <= 43)
    {
        cout << "Belt of Cloud Giant Strength" << endl;
    }

    if (dHundred >= 44 && dHundred <= 45)
    {
        cout << "Armor, +2 Breastplate" << endl;
    }

    if (dHundred >= 46 && dHundred <= 47)
    {
        cout << "Armor, +3 Chain Mail" << endl;
    }

    if (dHundred >= 48 && dHundred <= 49)
    {
        cout << "Armor, +3 Chain Shirt" << endl;
    }

    if (dHundred >= 50 && dHundred <= 51)
    {
        cout << "Cloak of Invisibility" << endl;
    }

    if (dHundred >= 52 && dHundred <= 53)
    {
        cout << "Crystal Ball (Legendary Version)" << endl;
    }

    if (dHundred >= 54 && dHundred <= 55)
    {
        cout << "Armor, +1 Half Plate" << endl;
    }

    if (dHundred >= 56 && dHundred <= 57)
    {
        cout << "Iron Flask" << endl;
    }

    if (dHundred >= 58 && dHundred <= 59)
    {
        cout << "Armor, +3 Leather" << endl;
    }

    if (dHundred >= 60 && dHundred <= 61)
    {
        cout << "Armor, +1 Plate" << endl;
    }

    if (dHundred >= 62 && dHundred <= 63)
    {
        cout << "Robe of the Archmagi" << endl;
    }

    if (dHundred >= 64 && dHundred <= 65)
    {
        cout << "Rod of Resurrection" << endl;
    }

    if (dHundred >= 66 && dHundred <= 67)
    {
        cout << "Armor, +1 Scale Mail" << endl;
    }

    if (dHundred >= 68 && dHundred <= 69)
    {
        cout << "Scarab of Protection" << endl;
    }

    if (dHundred >= 70 && dHundred <= 71)
    {
        cout << "Armor, +2 Splint" << endl;
    }

    if (dHundred >= 72 && dHundred <= 73)
    {
        cout << "Armor, +2 Studded Leather" << endl;
    }

    if (dHundred >= 74 && dHundred <= 75)
    {
        cout << "Well of Many Worlds" << endl;
    }

    if (dHundred == 76)
    {
        dTwelve = 1 + rand() % 12;
        cout << "Magic Armor: ";

        if (dTwelve >= 1 && dTwelve <= 2)
        {
            cout << "Armor, +2 Half Plate" << endl;
        }

        if (dTwelve >= 3 && dTwelve <= 4)
        {
            cout << "Armor, +2 Plate" << endl;
        }

        if (dTwelve >= 5 && dTwelve <= 6)
        {
            cout << "Armor, +3 Studded Leather" << endl;
        }

        if (dTwelve >= 7 && dTwelve <= 8)
        {
            cout << "Armor, +3 Breastplate" << endl;
        }

        if (dTwelve >=9 && dTwelve <= 10)
        {
            cout << "Armor, +3 Splint" << endl;
        }

        if (dTwelve == 11)
        {
            cout << "Armor, +3 Half Plate" << endl;
        }

        if (dTwelve == 12)
        {
            cout << "Armor, +3 Plate" << endl;
        }
    }

    if (dHundred == 77)
    {
        cout << "Apparatus Kwalish" << endl;
    }

    if (dHundred == 78)
    {
        cout << "Armor of Invulnerability" << endl;
    }

    if (dHundred == 79)
    {
        cout << "Belt of Storm Giant Strength" << endl;
    }

    if (dHundred == 80)
    {
        cout << "Cubic Gate" << endl;
    }

    if (dHundred == 81)
    {
        cout << "Deck of Many Things" << endl;
    }

    if (dHundred == 82)
    {
        cout << "Efreeti Chain" << endl;
    }

    if (dHundred == 83)
    {
        cout << "Armor of Resistance (Half Plate)" << endl;
    }

    if (dHundred == 84)
    {
        cout << "Horn of Valhalla (Iron)" << endl;
    }

    if (dHundred == 85)
    {
        cout << "Instrument of the Bards (Ollamh Harp)" << endl;
    }

    if (dHundred == 86)
    {
        cout << "Ioun Stone (Greater Absorption)" << endl;
    }

    if (dHundred == 87)
    {
        cout << "Ioun Stone (Mastery)" << endl;
    }

    if (dHundred == 88)
    {
        cout << "Ioun Stone (Regeneration)" << endl;
    }

    if (dHundred == 89)
    {
        cout << "Plate Armor of Etherealness" << endl;
    }

    if (dHundred == 90)
    {
        cout << "Plate Armor of Resistance" << endl;
    }

    if (dHundred == 91)
    {
        cout << "Ring of Air Elemental Command" << endl;
    }

    if (dHundred == 92)
    {
        cout << "Ring of Earth Elemental Command" << endl;
    }

    if (dHundred == 93)
    {
        cout << "Ring of Fire Elemental Command" << endl;
    }

    if (dHundred == 94)
    {
        cout << "Ring of Three Wishes" << endl;
    }

    if (dHundred == 95)
    {
        cout << "Ring of Water Elemental Command" << endl;
    }

    if (dHundred == 96)
    {
        cout << "Sphere of Annihilation" << endl;
    }

    if (dHundred == 97)
    {
        cout << "Talisman of Pure Good" << endl;
    }

    if (dHundred == 98)
    {
        cout << "Talisman of the Sphere" << endl;
    }

    if (dHundred == 99)
    {
        cout << "Talisman of Ultimate Evil" << endl;
    }

    if (dHundred == 100)
    {
        cout << "Tomb of the Stilled Tongue" << endl;
    }
}
