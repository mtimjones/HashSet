// hashset.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashset.h"

// Private Structures and types

struct HashSetNode;

struct HashSetNode {
   char *String;
   struct HashSetNode *Next;
};

typedef struct {
   struct HashSetNode *HashSetStart;
   struct HashSetNode *HashSetEnd;
} HashSetList;

typedef struct {
   unsigned int Signature;
   HashSetList *Set;
   unsigned int NumEntries;
} HashSet_t;

#define SIGNATURE   0xFAF32000

#define MAX( a, b )    ( ( a ) > ( b ) ? a : b )

void *HashSetCreate( unsigned int NumEntries )
{
   HashSet_t *HashSet;

   if ( NumEntries != 0 )
   {
      HashSet = ( HashSet_t * )calloc( sizeof( HashSet_t ), 1 );

      if ( HashSet != ( HashSet_t *) 0 )
      {
         HashSet->Signature = SIGNATURE;
         HashSet->NumEntries = NumEntries;
         HashSet->Set = 
            ( HashSetList * ) calloc( sizeof( HashSetList ), NumEntries );

         return ( void * ) HashSet;
      }
   }

   return ( void * ) 0;
}


unsigned char CreateHash( const char *string )
{
   unsigned char hash = 0;

   for ( int i = 0 ; i < strlen( string ) ; i++ )
   {
      hash += string[ i ];
   }

   return hash;
}

struct HashSetNode *HashSetNodeCreate( const char *string )
{
   struct HashSetNode *HashNode;

   HashNode = ( struct HashSetNode * )calloc( sizeof( struct HashSetNode ), 1 );
   HashNode->String = calloc( strlen( string ), 1 );
   strncpy( HashNode->String, string, strlen( string ) );
   HashNode->Next = ( struct HashSetNode * ) 0;

   return HashNode;
}

void HashSetAdd( void *HashSet, const char *string )
{
   if ( HashSet != ( void * ) 0 )
   {
      HashSet_t *set = ( HashSet_t * ) HashSet;

      if ( set->Signature == SIGNATURE )
      {
         unsigned char hash = CreateHash( string ) % set->NumEntries;

         if ( set->Set[ hash ].HashSetStart == ( struct HashSetNode * ) 0 )
         {
            // List is empty, create a list and node.
            set->Set[ hash ].HashSetStart = 
               set->Set[ hash ].HashSetEnd = HashSetNodeCreate( string );
         }
         else
         {
            set->Set[ hash ].HashSetEnd->Next = HashSetNodeCreate( string );
            set->Set[ hash ].HashSetEnd = set->Set[ hash ].HashSetEnd->Next;
         }

      }

   }

   return;
}

bool HashSetContains( void *HashSet, const char *string )
{
   if ( HashSet != ( void * ) 0 )
   {
      HashSet_t *set = ( HashSet_t * ) HashSet;

      if ( set->Signature == SIGNATURE )
      {
         unsigned char hash = CreateHash( string ) % set->NumEntries;

         if ( set->Set[ hash ].HashSetStart == ( struct HashSetNode * ) 0 )
         {
            return false;
         }
         else
         {
            struct HashSetNode *Node = set->Set[ hash ].HashSetStart;
            int source_length = strlen( string );

            while ( Node != ( struct HashSetNode * ) 0 )
            {
               int length = MAX( source_length, strlen( Node->String ) );
               if ( !strncmp( Node->String, string, length ) )
               {
                  return true;
               }

               Node = Node->Next;
            }
         }
      }
   }

   return false;
}

void  HashSetPrint( void *HashSet )
{
   if ( HashSet != ( void * ) 0 )
   {
      HashSet_t *set = ( HashSet_t * ) HashSet;

      if ( set->Signature == SIGNATURE )
      {
         for ( int i = 0 ; i < set->NumEntries ; i++ )
         {
            printf("[ %3d ] ", i );
            
            struct HashSetNode *Node = set->Set[ i ].HashSetStart;

            while ( Node != ( struct HashSetNode * ) 0 )
            {
               printf( "%s ", Node->String );
               Node = Node->Next;
            }

            printf( "\n" );
         }
      }
   }

   return;
}

void DestroyEntries( struct HashSetNode *HashNode )
{
   struct HashSetNode *Node;

   while ( HashNode )
   {
      free( HashNode->String );
      Node = HashNode;
      HashNode = HashNode->Next;
      free( Node );
   }

   return;
}

void  HashSetDestroy( void *HashSet )
{
   if ( HashSet != ( void * ) 0 )
   {
      HashSet_t *set = ( HashSet_t * ) HashSet;

      if ( set->Signature == SIGNATURE )
      {
         for ( int i = 0 ; i < set->NumEntries ; i++ )
         {
            DestroyEntries( set->Set[ i ].HashSetStart );
         }
         free( set->Set );
         free( set );
      }
   }

   return;
}


