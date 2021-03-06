// hashset.h

#include <stdbool.h>

void *HashSetCreate( unsigned int NumEntries );
void  HashSetAdd( void *HashMap, const char *string );
bool  HashSetContains( void *HashMap, const char *string );
void  HashSetPrint( void *HashMap );
void  HashSetDestroy( void *HashMap );

