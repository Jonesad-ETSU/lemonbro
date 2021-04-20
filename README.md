# LemonBro #
## A suckless lemonbar helper client with support for ipc. ##

## Overview ##

	LemonBro is a piper program for lemonbar. Meaning- to use this program you need to pipe it into lemonbar for it to really be of any value. To do this in most shells, all you need to do is 'sh lemonx | lemonbar'. By making this piping step into a C program, efficiency and control of the bar can be given to anyone willing to modify the source code. 

## Configuration ##
	Speaking of source code, that is actually how you modify the configuration for this program. To do this, modify the appropiate config.h file. More details about which config file to use are listed below, in the compiling section. When adding a new module, you must first increment the NUM_MODS variable as defined in the line ` #define NUM_MODS x `. After doing that, you may now add a new entry to the modules array. The entries support the following options:

		1. Command/Script to execute
		2. Alignment (LEFT/RIGHT/CENTER)
		3. Order in that alignment (starting at 1 with 1 being the leftmost entry)
		4. Prefix
		5. Postfix
		6. Update Timer
		7. Update Signal

	When doing this, is it important to keep in mind that this software is designed to be suckless. You can go out of bounds and cause memory issues or dramatically slow down the bar by saying there are more modules than there actually is or other, similar issues.

## Compilation ##

	To compile this tool, it is recommended to use GCC and the GNU/make utility. There are three options to give the make command: 'one', 'main', and 'secondary'. The 'one' parameter uses the 'config.onebar.h' file; 'main' uses the 'config.h' file, and it does not delete the secondary executable; lastly, 'secondary' creates the secondary bar and uses the 'config_secondary.h' file.  

## Usage ##

	Once the tool is runnning, you can use any standard method of sending a signal to update a module. As an example, you can use 'pkill -X lemonmain' or 'kill -X $(pidof lemonmain)' to update the module with signal number X. Otherwise, the modules will update based on their timer. 
	
