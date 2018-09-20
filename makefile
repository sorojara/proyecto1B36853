
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

run_unittest:
	echo Pruebas positivas
	./build/positive
	echo Pruebas negativas
	./build/negative

define make-repo
	mkdir -p $(OBJDIR)
	for dir in $(SRCDIRS); \
	do \
		mkdir -p $(OBJDIR)/$$dir; \
	done
endef
