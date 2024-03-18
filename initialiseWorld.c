#include <stdio.h>
#include <stdlib.h>
#include "vars_defs_functions.h"

// Function to initialize the world with cells and their initial states
void initialiseWorld(CELL current[ROWS][COLS],
                     CELL future[ROWS][COLS]){

    int i, j, randRow, randCol;

    // Loopin rows and columns
    for(i=0; i<ROWS; i++)
        for(j=0; j<COLS; j++){

            // Setting the initial state of the cell to 'F'
            current[i][j].state = 'F';

            // Length of burn for the current cell
            current[i][j].counter_B_to_X = rand() % (MAX_DAYS_B_TO_X - MIN_DAYS_B_TO_X + 1) + MIN_DAYS_B_TO_X;

            // Initializing the future state to the current state
            future[i][j] = current[i][j];

            // Incrementing the counter for Fuel cells
            numF++;
        }

    // Randomly selecting a cell to be in the Burning state
    randRow = rand() % ROWS;
    randCol = rand() % COLS;

    // Setting the state of the randomly selected cell to 'B' (Burning)
    current[randRow][randCol].state = 'B';

    // Initializing the future state to the current state
    future[randRow][randCol] = current[randRow][randCol];

    // everythime fuel decreases burning increases
    numF--;
    numB++;
}

