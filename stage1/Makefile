include ./inc.mk

CFLAG = -Wall
CFLAGS += -c
INCPATH = header/

EXE=stage1
SRC=$(wildcard src/*.cpp)
INC=$(wildcard header/*.h)

.PHONY: all build

#  $@: The filename representing the target.
#  $%: The filename element of an archive member specification.
#  $<: The filename of the first prerequisite.
#  $?: The names of all prerequisites that are newer than the target, separated by spaces.
#  $^: The filenames of all the prerequisites, separated by spaces. This list has duplicate 
#      filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.
#  $+: Similar to $^, this is the names of all the prerequisites separated by spaces, except 
#      that $+ includes duplicates. This variable was created for specific situations such 
#       as arguments to linkers where duplicate values have meaning.
#  $*: The stem of the target filename. A stem is typically a filename without its suffix. 
#      Its use outside of pattern rules is discouraged.
 
all: create_build_dir srcDir
	@echo " generating binary now "
	${CXX} build/obj/*.o -o ${EXE}
	@mv ${EXE} build/bin/.
	
srcDir: $(SRC)
	@echo " building src now "
	${CXX} $(CFLAGS) $^ -I${INCPATH}
	-@mv *.o build/obj/.
	
create_build_dir:
	-@mkdir -p build/lib
	-@mkdir -p build/obj
	-@mkdir -p build/bin
	
clean:
	-@rm -rf build
	