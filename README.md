# LemonBro
## A suckless-inspired bar utility

## Overview ##

LemonBro is a piper program for lemonbar. What this means is that without [`lemonbar`](https://github.com/LemonBoy/bar) or one of its forks, this program just prints to stdout. To use the program, see [usage](#usage). By making this piping process into a C program rather than a shell script, it makes it easier to make efficient, minimalist bars that don't reinvent the wheel or use unnessecary compute cycle finding the current user every second.

# Purpose
Honestly, this is just a project I whipped up for fun thinking that it would prove helpful for people wanting to take a more UNIXy or suckless approach to doing theirbars while still being to setup and not being overly specific. If you are interested in the suckless approach (modifying source code as config), you can [click here](https://suckless.org) to view their website. I am not affiliated with them in anyway.

## Configuration
Modifying this program to fit your needs is a fairly straightforward process and only requires your favorite text editor and a C compiler (tested with GNU make). In order to do so, you have to modify the source code and recompile. However, for simplicities sake, most the of the configuration needed is done in the appropriate `config.h` file.
<br/>
The first thing to be aware of is the script variables present in the following image:
<img align='center' alt="variables with hardcoded paths to user's home" src='images/script_variables.png'/><br/>
The value of the following variables is useful because they set pre-set paths. `HOME` is used exclusively for the following two variables. `LEMON` is a shortcut to the directory where you have your scripts.
<br/>
The second step is choosing which delimiters you want.
<img align='center' alt="variables controlling the delimiters." src='images/delimiters.png'/><br/>
By changing either the `LEFT_DELIM`,`CENTER_DELIM`, or `RIGHT_DELIM` variables you can choose delimiters for each section of the bar. `DELIM` is simply a default you can use by setting the other variables with `#define x DELIM`.
<br/>
The next step is to define which scripts to use as modules. The following image shows an example array (it's mine :D)
<img align='center' alt="my configuration of scripts" src='images/modules_array.png'/><br/>
For a more in-depth explanation of each field, please see [modules](#Modules)
After adding these modules to the array, you have to modify the number of modules to the appropriate value (the number of rows in your modules array)
<img align='center' alt="Variable representing the number of modules" src='images/num_mods.png'/><br/>
Finally, to start up the program you do the following shell commands: `./lemonbro | lemonbar` and/or `./lemonbrosecondary | lemonbar` depending on the whether it is a single bar or you are using both bars. 

## Compiling
The program comes with a make file for use with GNU make utility. The following options are supported:

- [`all`](#all)
- [`main`](#main)
- [`secondary`](#secondary)
- [`one`](#one)
- [`clean`](#clean)
### all
Using all compiles both the main binary and secondary binaries. This allows running both binaries, say for a bar on the top and bottom of the screen.
### main
Just compiles the primary binary. Mostly an auxilary switch to be used for small performance improvements.
### secondary
Just compiles the secondary binary. Maybe useful if you haven't changed the primary binary
### one
Removes the secondary binary and compiles the main binary. This could be useful if you launch lemonbar with a script that detects binaries inside the lemonbar folder.
### clean
Removes both binaries.

## Usage
Running the program is as simple as doing `./lemonbro | lemonbar`. Although, you should probably configure lemonbar, also. Doing this depends on your specific fork, but generally it will be in the form `lemonbar -option value`.<br/>
You will likely want to put this command into a shell script and run it on startup.

## Modules

For your convience, the following sections will have the portion of the area the section is referring to circled in red. The following image is the entire array.
<img align='center' alt='full array' src='images/modules_array[0].png'><br/>

### Command
`modules[x][0]` is the command for the module. This can either be a shell script or can be direct commands. If properly configured, the `LEMON` variable when used as shown serves to eliminate the need for a path.
<img align='center' alt='full array' src='images/modules_array[0][0].png'><br/>

### Alignment
`modules[x][1]` places the widget onto a side of the bar. The values `LEFT`,`RIGHT`,`CENTER` refer to variables defined at the top of the `lemon.bro.c` file. These *do not* need to be changed.
<img align='center' alt='full array' src='images/modules_array[0][1].png'><br/>

### Order
`modules[x][2]` defines the order of the modules on its side. *This is 1 indexed and goes left to right*. Adding gaps in this order or starting at 0 <em>will</em> lead to undefined behavior.
<img align='center' alt='full array' src='images/modules_array[0][2].png'><br/>

### Prefix and Postfix
`modules[x][3]` gives a prefix for the command output (output of `modules[x][0]`). Useful for adding underlines or other lemonbar commands. 
`modules[x][4]` is the same as the prefix, just in post.
The first image is the prefix, and the second the postfix.
<img align='center' alt='full array' src='images/modules_array[0][3].png'><br/>
<img align='center' alt='full array' src='images/modules_array[0][4].png'><br/>

### Timer
`modules[x][5]` is the amount of time before the module updates. `-1` indicates the module will not auto-update.
<img align='center' alt='full array' src='images/modules_array[0][5].png'><br/>

### Signal
`modules[x][6]` provides an alternate method for updating a module. By sending a posix signal, with the signal number + the `SIG_START` (see 2nd picture below) variable as defined in `config.h`, the module will update. 
<img align='center' alt='full array' src='images/modules_array[0][6].png'><br/>
<img align='center' alt="Starting signal value so it doesn't overlap with SIGKILL or SIGTERM" src='images/signals_start.png'/>
