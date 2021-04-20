all:
	gcc lemon.bro.c -o lemonmainc -DMAIN
	gcc lemon.bro.c -o lemonsecondaryc -DSECONDARY
	rm -rf ./mainonly
main:
	gcc lemon.bro.c -o lemonmainc -DMAIN
	rm -rf ./mainonly
secondary:
	gcc lemon.bro.c -o lemonsecondaryc -DSECONDARY
	rm -rf ./mainonly
one:
	gcc lemon.bro.c -o lemonmainc  -DONE
	touch ./mainonly
	rm -rf ./lemonsecondaryc
