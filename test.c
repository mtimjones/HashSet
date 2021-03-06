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
   HashSetAdd( map, "Anne" );

   if (  HashSetContains( map, "Jeff" ) ) exit( -1 );
   if ( !HashSetContains( map, "Albert" ) ) exit( -1 );
   if ( !HashSetContains( map, "Violet" ) ) exit( -1 );
   if ( !HashSetContains( map, "Anne" ) ) exit( -1 );

   HashSetAdd( map, "Jeff" );
   if ( !HashSetContains( map, "Jeff" ) ) exit( -1 );

   HashSetAdd( map, "Kai" );
   if ( !HashSetContains( map, "Kai" ) ) exit( -1 );

   printf( "Passed.\n" );

   HashSetPrint( map );

   return;
}
