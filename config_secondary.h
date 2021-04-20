/***************************************************\
 * Author:   Jonesad@etsu.edu			    *
 * Date l.m: 1/26/21				    *
 * Purpose:  Pipes output of scripts into lemonbar. *   		
\***************************************************/

/* Modify these to change default file locations */
#define HOME "/home/jonesad"
#define LEMON HOME"/.scripts/lemon"
#define FIFO HOME"/.lemonbar_bottom.fifo"

/* This variable controls the amount of spaces on each side of the bar. */
#define SIDE_BUFFER 0

/* This HAS to be changed when you add or delete modules  */
#define NUM_MODS 7

/* Modify these to modify the delimeters between modules in each section */
#define DELIM "  "
#define LEFT_DELIM " "
#define CENTER_DELIM DELIM
#define RIGHT_DELIM DELIM

/* Modify this to change the base for signals */
#define SIGS_START 60

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct message {
	  char text[BUFFER_SIZE];
	  int order, align;
} message;

typedef struct module {
	  char cmd[BUFFER_SIZE];
	  int align;
	  int order;
	  char pre[BUFFER_SIZE];
	  char post[BUFFER_SIZE];
	  int timer;
	  int signal;
} module;

/* MODIFY THIS TO ADD MODULES. MAKE SURE TO INCREMENT NUM_MODS */
struct module modules[NUM_MODS] = {
		  /*  COMMAND                       ALIGN    ORDER  PRE     POST    TIMER	SIGNAL   */
		    { LEMON"/lemon-temp.sh",        RIGHT,   1,    "",     "",     3,	5  },
		    { LEMON"/lemon-mem.sh",         RIGHT,   2,    "",     "",     2,	6  },
		    { LEMON"/lemon-home.sh",        RIGHT,   3,    "",     "",     120,	6  },
		    { LEMON"/lemon-root.sh",        RIGHT,   4,    "",     "",     120,	6  },
		    { LEMON"/lemon-weather.sh",     RIGHT,   5,    "",     "",     900,	6  },
		    { LEMON"/lemon-mpd.sh",	    CENTER,  1,	   "",	   "",	   1,	9  },
		    { LEMON"/lemon-tasks.sh",	    LEFT,    1,	   "",	   "",     30,	10 },
};

/* Method Declaration - ignore me*/
void reader  (  );
void handler (  );
void catcher ( int );
void send    ( char*, int, int, int );
void setup   ( module );
void exec    ( module, char*, int );
int  capture ( char*, char* );
void format  ( char*, char*, char*, char* );
