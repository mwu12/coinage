#include <stdio.h>

#define DIME    10
#define QUARTER 25
#define NICKLE  5
#define PENNY   1

int main()
{
    float amount[] = {
        0.49, 1.27, 0.75, 1.31, 0.83
    };
    int x,y,coins=0,quarters=0,dimes=0,nickels=0,pennies=0;
    int chg, pays = 0;

    printf("\t%f , %f , %f , %f , %f \n",
            amount[0], amount[1], amount[2], amount[3], amount[4]
    );

    pays = sizeof(amount) / sizeof(amount[0]);
    for (y = 0; y < pays; y++)
    {
        chg = (int)(amount[y] * 100);
        chg %= 100;
        for (x = 1; x < 5; x++)
            if ( (x*QUARTER) > chg )
                break;
        quarters = x - 1;

        chg -= (quarters*QUARTER);
        for (x = 1; x < 4; x++)
            if ( (x*DIME) > chg )
                break;
        dimes = x - 1;

        chg -= (dimes*DIME);
        for (x = 1; x < 3; x++)
            if ( (x*NICKLE) > chg )
                break;
        nickels = x - 1;

        chg -= (nickels*NICKLE);
        for (x = 1; x < 6; x++)
            if ( (x*PENNY) > chg )
                break;
        pennies = x - 1;

        printf("\t%d chg, %d quarters, %d dimes, %d nickels, %d pennies\n",
            chg,
            quarters,
            dimes,
            nickels,
            pennies
        );
    }
    return(0);
}

