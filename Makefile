all:
	gcc lemon.bro.c -o lemonbro -DMAIN
	gcc lemon.bro.c -o lemonbro2 -DSECONDARY
main:
	gcc lemon.bro.c -o lemonbro -DMAIN
secondary:
	gcc lemon.bro.c -o lemonbro2 -DSECONDARY
one:
	gcc lemon.bro.c -o lemonbro  -DONE
	rm ./lemonbro2
clean:
	rm ./lemonbro
	rm ./lemonbro2
