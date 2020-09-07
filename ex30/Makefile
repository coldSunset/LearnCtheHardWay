# # define OPTLIBS and OPTFLAGS as needed; in particular, add
# # -I flags to OPTCFLAGS, -L flags to OPTLDFLAGS, and -l flags
# # to OPTLDIBS.
# #
# # The CC, CFLAGS, LDFLAGS, and LDLIBS are all called "implicit variables"
# CC=gcc
# CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTCFLAGS)
# LDFLAGS=$(OPTLDFLAGS)
# LDLIBS=-ldl $(OPTLDLIB)
# PREFIX?=/usr/local

# SOURCES=$(wildcard src/*.c src/**/*.c)
# OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

# TEST_SRC=$(wildcard tests/*_tests.c)
# TESTS=$(patsubst %.c,%,$(TEST_SRC))

# TARGET=build/libex29.a
# SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# # the target build
# all: clean check $(TARGET) $(SO_TARGET) tests

# # this looks weird, but I guess if you want to redefine a variable in a make
# # target, then you do it by just adding an extra line(?)
# dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
# dev: all

# # -fPIC makes 'position independent code', which affects linkage somehow.
# # In a makefile, the $@ refers to the make target (so in this case, $(TARGET))
# # ar is the archive command, rcs are options. You can grep for them in the man.
# # the ranlib is supposedly no longer necessary, but it finalizes some stuff.
# #
# # Note that it appears you don't need library flags to create a static library
# # that depends on other static libraries. A .a file doesn't involve linking,
# # it's actually just a thin wrapper around a bunch of .o files. If you have
# # any dependencies on other static libraries, it appears that they simply
# # need to be documented, and then your end users need to make sure to include
# # all the dependencies when they link their executables ('users' here includes
# # us in testing!)
# $(TARGET): CFLAGS += -fPIC
# $(TARGET): build $(OBJECTS)
	# ar rcs $@ $(OBJECTS)
	# ranlib $@

# $(SO_TARGET): $(TARGET) $(OBJECTS)
	# $(CC) -shared -o $@ $(OBJECTS)

# # I *think* that @mkdir is a platform-independent mkdir -p
# build: 
	# @mkdir -p build
	# @mkdir -p bin

# .PHONY: tests
# tests:
# tests: $(TESTS)
	# sh ./tests/runtests.sh


# valgrind:
	# VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# # The Cleaner
# clean:
	# rm -rf build $(OBJECTS) $(TESTS)
	# rm -f tests/tests.log
	# find . -name "*.gc*" -exec rm {} \;
	# rm -rf `find . -name "*.dSYM" -print`

# # The Install
# install:
	# install -d $(DESTDIR)/$(PREFIX)/lib/
	# install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# # The Checker
# BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
# check:
	# @echo Files with potentially dangerous functions.
	# @egrep $(BADFUNCS) $(SOURCES) || true



# ---------------------------------------------------------------------------
# CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS) -ldl
# LIBS=-ldl $(OPTLIBS)
# PREFIX?=/usr/local

# SOURCES=$(wildcard src/**/*.c src/*.c)
# OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

# TEST_SRC=$(wildcard tests/*_tests.c)
# TESTS=$(patsubst %.c,%,$(TEST_SRC))

# TARGET=build/libex29.a 
# SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# # The Target Build 
# all: $(TARGET) $(SO_TARGET) tests

# dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
# dev: all 

# $(TARGET): CFLAGS += -fPIC 
# $(TARGET): build $(OBJECTS)
	# ar rcs $@ $(OBJECTS)
	# ranlib $@
# $(SO_TARGET): $(TARGET) $(OBJECTS)
	# $(CC) -shared -o $@ $(OBJECTS) 

# build: 
	# @mkdir -p build 
	# @mkdir -p bin 

# # The Unit Tests 
# .PHONY: tests 
# tests: CFLAGS += $(TARGET)
# tests: $(TESTS)
	# sh ./tests/runtests.sh

# # The Cleaner 
# clean: 
	# rm -rf build $(OBJECTS) $(TESTS)
	# rm -f tests/tests.log 
	# find . -name "*.gc*" -exec rm {} \; 
	# rm -rf 'find . -name "*.dSYM" -print'

# # The Install 
# install: all 
	# install -d $(DESTDIR)/$(PREFIX)/lib/
	# install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/ 

# # The Checker 
# check: 
	# @echo Files with potentially dangerous functions. 
	# @egrep '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) ||true
	
#----------------------------------------------------------------------------------
CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
# These are the usual CFLAGS that you set in all of your projects, but with a few others
# that may be needed to build libraries. You may need to adjust these for different 
# platforms. Notice the OPTFLAGS variable at the end which lets people augment the build
# options as needed.

LIBS=-ldl $(OPTLIBS)
# Options used when linking a library, and allows someone else to augment the linking 
# options using the OPTLIBS variable.

PREFIX?=/usr/local
# Setting an optional variable called PREFIX that will only have this value if the 
# person running the Makefile didn't already give a PREFIX setting. That's what the ?= does.

SOURCES=$(wildcard src/**/*.c src/*.c)
# This fancy line of awesome dynamically creates the SOURCES variable by doing a wildcard
# search for all *.c files in the src/ directory. You have to give both src/**/*.c and
# src/*.c so that GNU make will include the files in src and also the ones below it.

OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
# Once you have the list of source files, you can then use the patsubst to take the SOURCES
# list of *.c files and make a new list of all the object files. You do this by telling
# patsubst to change all %.c extensions to %.o and then those are assigned to OBJECTS.

TEST_SRC=$(wildcard tests/*_tests.c)
# Using the wildcard again to find all the test source files for the unit tests. These are
# separate from the library's source files.

TESTS=$(patsubst %.c,%,$(TEST_SRC))
# Then using the same patsubst trick to dynamically get all the TEST targets. In this case
# I'm stripping away the .c extension so that a full program will be made with the same name.
# Previously I had replaced the .c with {.o} so an object file is created.

TARGET=build/libYOUR_LIBRARY.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))
# Finally, we say the ultimate target is build/libYOUR_LIBRARY.a, which you will change to
# be whatever library you are actually trying to build.

# The Target Build
all: $(TARGET) $(SO_TARGET) tests
# Remember that the first target is what make will run by default when no target is given.
# In this case it's called all: and it gives $(TARGET) tests as the targets to build. Look
# up at the TARGET variable and you see that's the library, so all: will first build the
# library. The tests target is then further down in the Makefile and builds the unit tests.

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all
# Another target for making "developer builds" that introduces a technique for changing
# options for just one target. If I do a "dev build" I want the CFLAGS to include options
# like -Wextra that are useful for finding bugs. If you place them on the target line as
# options like this, then give another line that says the original target (in this case all)
# then it will change the options you set. I use this for setting different flags on
# different platforms that need it.

$(TARGET): CFLAGS += -fPIC
# Builds the TARGET library, whatever that is, and also uses the same trick from line 15 of
# giving a target with just options changes to alter them for this run. In this case I'm
# adding -fPIC just for the library build using the += syntax to add it on.

$(TARGET): build $(OBJECTS)
# Now the real target where I say first make the build directory, then compile all the OBJECTS.
	ar rcs $@ $(OBJECTS)
# Runs the ar command which actually makes the TARGET. The syntax $@ $(OBJECTS) is a way
# of saying, "put the target for this Makefile source here and all the OBJECTS after
# that". In this case the $@ maps back to the $(TARGET) on line 19, which maps to 
# build/libYOUR_LIBRARY.a. It seems like a lot to keep track of this indirection, and it
# can be, but once you get it working this means you just change TARGET at the top and
# build a whole new library.
	ranlib $@
# Finally, to make the library you run ranlib on the TARGET and it's built.

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin
# This just makes the build/ or bin/ directories if they don't exist. This is then
# referenced from line 19 when it gives the build target to make sure the build/
# directory is made.

# The Unit Tests
.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
	@echo Files with potentially dangerous functions.
	@egrep $(BADFUNCS) $(SOURCES) || true