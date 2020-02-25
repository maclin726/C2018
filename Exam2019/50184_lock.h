#include <stdbool.h>
typedef struct locks {
    int cond[3];
    int mode;
} Locks;
 
Locks* init(int lockSeq[][3], int n);
 
int numUnlocked(Locks *locks, bool lights[], int m);