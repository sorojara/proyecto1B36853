
CC = g++
OPTS = -std=c++14 -Iinclude/




PROJECT = soremesis420


OBJDIR = build
SRCDIR = src
TESTDIR = test/


LIBS =


SRCS    = $(shell find $(SRCDIR) -name '*.cpp')
SRCDIRS = $(shell find . -name '*.cpp' | dirname {} | sort | uniq | sed 's/\/$(SRCDIR)//g' )
OBJS    = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))


$(PROJECT): buildrepo $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm $(PROJECT) $(OBJDIR) -Rf
	mkdir $(OBJDIR)

buildrepo:
	@$(call make-repo)

git:
	make clean
	git add *
	read mensaje
	git commit -m mensaje
	git push

run:
	./soremesis420

unittest:
	$(CC) $(OPTS) src/AVL.cpp $(TESTDIR)positive.cpp -o build/positive
	$(CC) $(OPTS) src/AVL.cpp $(TESTDIR)negative.cpp -o build/negative
	$(CC) $(OPTS) src/AVL.cpp $(TESTDIR)pruebaMemoria.cpp -o build/pruebaMemoria

run_unittest:
	echo Pruebas positivas
	./build/positive
	echo Pruebas negativas
	./build/negative

times:
	$(CC) $(OPTS) src/AVL.cpp $(TESTDIR)tiempos.cpp -o build/tiempos
	./build/tiempos

help:
	cat README.md

define make-repo
	mkdir -p $(OBJDIR)
	for dir in $(SRCDIRS); \
	do \
		mkdir -p $(OBJDIR)/$$dir; \
	done
endef
