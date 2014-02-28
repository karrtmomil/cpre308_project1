shell: shell.o initShell.o
	gcc -o shell shell.o initShell.o
initShell.o: initShell.c shell.h
	gcc -c initShell.c	
shell.o: shell.c shell.h
	gcc -c shell.c
clean:
	rm -f *.o 