#include <pthread.h>
#ifndef VARS_AND_DEFS
#define VARS_AND_DEFS

#define ROWS 10
#define COLS 10

// Cell Datatype-definition
typedef struct cell
{
    char state;             // state can be one of: F for Fuel, B for Burning, O for Not Fuel, X for Burnt
    int counter_B_to_X;     // Counter used to determine when a Burning cell gets changed to Burnt
} CELL;

extern CELL **current;      // Pointer to the current state of the world
extern CELL **future;       // Pointer to the future state of the world

#define DEBUG_LEVEL 1
#define TOTAL_DAYS 10         // Total simulation days
#define NUMTHREADS 1          // Number of threads (set to 1 for single-threaded execution)

// Probabilities for transition from Fuel to Burning
#define PROB_F_TO_B_1 0.50
#define PROB_F_TO_B_2 0.6
#define PROB_F_TO_B_3 0.7
#define PROB_F_TO_B_4 0.75
#define PROB_F_TO_B_5 0.8
#define PROB_F_TO_B_6 0.85
#define PROB_F_TO_B_7 0.9
#define PROB_F_TO_B_8 1.0

#define MIN_DAYS_B_TO_X 1      // Minimum days for Burning to transition to Burnt
#define MAX_DAYS_B_TO_X 2      // Maximum days for Burning to transition to Burnt

// Mutex and condition variable for thread synchronization
extern pthread_mutex_t mutex;
extern pthread_cond_t cond_var;

// Global Variables for counting cell states
extern unsigned long int numF;  // Number of Fuel cells
extern unsigned long int numB;  // Number of Burning cells
extern unsigned long int numO;  // Number of cells that are Not Fuel
extern unsigned long int numX;  // Number of Burnt cells

// Function Prototypes
void *basicThread(void *param);  // Thread function
void initialiseWorld();           // Initialize the world with cells and their initial states

// Function for deciding the transition from Fuel to Burning based on neighbors
void decide_F_to_B(int row, int col, int num_Burning_Neighbours);

// Function for deciding the transition from Burning to Burnt with varying days
void decide_B_to_X_VaryingDays(int row, int col);

// Function to count Burning neighbors with closed boundaries
int countBurningNeighbours_ClosedBoundaries(int row, int col);

#endif  // VARS_AND_DEFS

