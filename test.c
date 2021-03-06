#include <stdio.h>
#include <stdlib.h>
#include "hashset.h"

void main()
{
   void *map;

   map = HashSetCreate( 10 );

   if ( HashSetContains( map, "Violet" ) ) exit( -1 );

   HashSetAdd( map, "Albert" );
   HashSetAdd( map, "Violet" );
   HashSetAdd( map, "Josh" );

   if (  HashSetContains( map, "Mangum" ) ) exit( -1 );
   if ( !HashSetContains( map, "Albert" ) ) exit( -1 );
   if ( !HashSetContains( map, "Violet" ) ) exit( -1 );
   if ( !HashSetContains( map, "Josh" ) ) exit( -1 );

   HashSetAdd( map, "Mangum" );
   if ( !HashSetContains( map, "Mangum" ) ) exit( -1 );

   HashSetAdd( map, "Kai" );
   if ( !HashSetContains( map, "Kai" ) ) exit( -1 );

   HashSetAdd( map, "Chris" );
   HashSetAdd( map, "Lost" );
   HashSetAdd( map, "Hilton" );
   HashSetAdd( map, "Broken" );

   printf( "Passed.\n" );

   HashSetPrint( map );

   HashSetDestroy( map );

   return;
}
