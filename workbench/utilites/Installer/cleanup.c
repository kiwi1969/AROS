/* cleanup.c -- here are all functions used before exiting program */

#include "Installer.h"

/* External variables */
extern ScriptArg script;
extern InstallerPrefs preferences;
extern int error;

/* External function prototypes */
extern void free_varlist();
extern void execute_script( ScriptArg *, int );
#ifndef LINUX
extern void deinit_gui();
#endif /* !LINUX */
extern void traperr( char *, char * );

/* Internal function prototypes */
void free_script( ScriptArg * );
void cleanup();
void end_malloc();
void outofmem( void * );

void free_script( ScriptArg *first )
{
  if( first != NULL )
  {
    free_script( first->cmd );
    free_script( first->next );
    free( first->arg );
    free( first );
  }
}

void cleanup( )
{
  if( preferences.transcriptstream != NULL )
  {
    fclose( preferences.transcriptstream );
  }

  free_script( script.cmd );
  free_varlist();
#ifndef LINUX
  deinit_gui();
#endif /* !LINUX */
}

void end_malloc( )
{
#ifdef DEBUG
  printf("Couldn't malloc memory!\n");
#endif /* DEBUG */
  cleanup();
  exit(-1);
}

void outofmem( void * ptr )
{
  if( ptr == NULL )
  {
    error = OUTOFMEMORY;
    traperr( "Out of memory!\n", NULL );
  }
}

