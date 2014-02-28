shell: shell.o initShell.o parseOptions.o builtinCom.o
	gcc -o shell shell.o initShell.o parseOptions.o builtinCom.o
builtinCom.o: builtinCom.c shell.h
	gcc -c builtinCom.c
parseOptions.o: parseOptions.c shell.h
	gcc -c parseOptions.c
initShell.o: initShell.c shell.h
	gcc -c initShell.c	
shell.o: shell.c shell.h
	gcc -c shell.c
clean:
	rm -f *.o 