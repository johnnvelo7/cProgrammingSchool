libpgdebug.a: pgdbglog.o
	ar rcs $@ $<

pgdebug.o: pgdbglog.c pgdbglog.h
	gcc -c $< -o $@

