VPATH=re:../colibri

CFLAGS=-O3
#CFLAGS=-g
OBJS = 	coatl.o \
	coatlUcd.o \
	coatlUnicode.o \
	coatlRegexp.o \
	regcomp.o \
	regexec.o \
	regfree.o

libcoatl.so: $(OBJS)
	gcc -pthread -shared -o libcoatl.so ../colibri/libcolibri.so $(OBJS)
	strip libcoatl.so

.c.o: include/coatl.h
	gcc $(CFLAGS) -pthread -DBUILD_coatl -DHAVE_STDINT_H -c -I../colibri/include $<

clean:
	rm -f *.o libcoatl.so
