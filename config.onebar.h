/***************************************************\
* Author:   Jonesad@etsu.edu			    *
* Date l.m: 1/26/21				    *
* Purpose:  Pipes output of scripts into lemonbar. *   		
* \***************************************************/

/* Modify these to change default file locations */
#define HOME "/home/jonesad"
#define LEMON HOME"/.scripts/lemon"
#define FIFO HOME"/.lemonbar_top.fifo"

/* This variable controls the amount of spaces on each side of the bar. */
#define SIDE_BUFFER 10

/* This HAS to be changed when you add or delete modules  */
#define NUM_MODS 9
/* Modify these to modify the delimeters between modules in each section */
#define DELIM "  "
#define LEFT_DELIM " "
#define CENTER_DELIM DELIM
#define RIGHT_DELIM DELIM
/* Modify this to change the base for signals */
#define SIGS_START 40

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
	  /*  COMMAND                       ALIGN    ORDER  P
	   *  	   *  RE     POST    TIMER	SIGNAL   */
	    { LEMON"/lemon-edge.sh "LEMON"/lemon-power.sh",      RIGHT,   5,     "",     "",     -1,	1  },
	    { LEMON"/lemon-battery.sh",     CENTER,  1,     "",     "",     30,	2    },
	    { LEMON"/lemon-time.sh",        RIGHT,   4,     "",     "",     30,	3    },
	    { LEMON"/lemon-brightness.sh",  RIGHT,   3,     "",     "",     10,	4    },
	//  { LEMON"/lemon-cpu.sh",         RIGHT,   3,  "",     "",     3, 5   },
	//  { LEMON"/lemon-mem.sh",         RIGHT,   2,    "",     "",     4,	6     },
	    { LEMON"/lemon-ewmh.sh",        LEFT,    3,     "",     "",     1,	7    },
	    { LEMON"/lemon-edge.sh "LEMON"/lemon-launcher.sh",	    LEFT,      1,	    "",	    "",	    -1,	8    },
	    { LEMON"/lemon-mpd.sh",	LEFT,		2,	"",	"",	1,	9	},
	    { LEMON"/lemon-connected.sh",	RIGHT,	2,	"",	"",	-1,	10 },
	    { LEMON"/lemon-volume.sh",		RIGHT,	1,	"",	"",	-1,	11 },
	//  { LEMON"/lemon-kernel.sh",	RIGHT,		1,	"",	"",	-1,	11 },
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
