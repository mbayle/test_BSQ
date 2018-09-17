OUTPUT=bsq
DIR_SOURCES=sources
DIR_OBJECTS=objects
DIR_INCLUDES=includes
FILES_NEUTRALB=$(basename $(wildcard $(DIR_SOURCES)/*))
FILES_NEUTRAL=$(FILES_NEUTRALB:$(DIR_SOURCES)/%=%)
FILES_SOURCES=$(addprefix $(DIR_SOURCES)/,$(addsuffix .c,$(FILES_NEUTRAL)))
FILES_OBJECTS=$(addprefix $(DIR_OBJECTS)/,$(addsuffix .o,$(FILES_NEUTRAL)))
FILES_INCLUDES=$(wildcard $(DIR_INCLUDES)/*);
FLAGS=-Wall -Wextra -Werror -g -O0

.PHONY: directories

all: directories $(FILES_OBJECTS)
	gcc $(FILES_OBJECTS) *.a -o $(OUTPUT)
re: fclean all
clean:
	@touch $(DIR_OBJECTS)/a.o
	rm $(DIR_OBJECTS)/*.o
fclean: clean
	@touch $(OUTPUT)
	rm $(OUTPUT)

directories: $(DIR_SOURCES) $(DIR_OBJECTS) $(DIR_INCLUDES)

$(DIR_SOURCES):
	mkdir $(DIR_SOURCES)
$(DIR_OBJECTS):
	mkdir $(DIR_OBJECTS)
$(DIR_INCLUDES):
	mkdir $(DIR_INCLUDES)

$(DIR_OBJECTS)/%.o:$(DIR_SOURCES)/%.c $(FILES_INCLUDES)
	gcc $(FLAGS) -I$(DIR_INCLUDES) -c $< -o $@
