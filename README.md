# HashSet
Building a hash set implementation in C

This simple hashset implementation supports a minimal API to create and destroy
a hashset structure as well as add a key, check whether the set contains a key
and finally to print out the hashset contents

```
void *HashSetCreate( unsigned int NumEntries );
void  HashSetAdd( void *HashMap, const char *string );
bool  HashSetContains( void *HashMap, const char *string );
void  HashSetPrint( void *HashMap );
void  HashSetDestroy( void *HashMap );
```

A sample usage is shown below:

```
void *map;

map = HashSetCreate( 10 );

HashSetAdd( map, "Violet" );

if ( HashSetContains( map, "Violet" ) )
{
   printf( "Violet is present.\n" );
}

HashSetPrint( map );

HashSetDestroy( map );
```
