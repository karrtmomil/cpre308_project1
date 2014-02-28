shell: shell.o initShell.o parseOptions.o builtinCom.o exec.o
	gcc -o shell shell.o initShell.o parseOptions.o builtinCom.o exec.o
exec.o: exec.c shell.h
	gcc -c exec.c
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