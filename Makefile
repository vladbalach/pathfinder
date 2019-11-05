NAME = pathfinder

INC =  ./inc/header.h \
	./inc/libmx.h \

HEADTMP = header.h \
	libmx.h \

SRCS = ./src/main.c \
	./src/mx_file_to_list.c \
	./src/mx_is_valid_string.c \
	./src/mx_read_line.c \
	./src/mx_is_file_empty.c \
	./src/mx_is_valid_first_line.c \
	./src/validation.c \
	./src/mx_atoi_positive_valid.c \

CTMP = main.c \
	mx_file_to_list.c \
	mx_is_valid_string.c \
	mx_read_line.c \
	mx_is_file_empty.c \
	mx_is_valid_first_line.c \
	validation.c \
	mx_atoi_positive_valid.c \

OUTTMP = main.o \
	mx_file_to_list.o \
	mx_is_valid_string.o \
	mx_read_line.o \
	mx_is_file_empty.o \
	mx_is_valid_first_line.o \
	validation.o \
	mx_atoi_positive_valid.o \

OUT = ./obj/main.o \
	./obj/mx_file_to_list.o \
	./obj/mx_is_valid_string.o \
	./obj/mx_read_line.o \
	./obj/mx_is_file_empty.o \
	./obj/mx_is_valid_first_line.o \
	./obj/validation.o \
	./obj/mx_atoi_positive_valid.o \

DFLAGS = -fsanitize=address -g
CFLSGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: installTest uninstall

install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLSGS) -c $(CTMP)
	@clang $(CFLSGS) libmx.a $(CTMP) -o $(NAME) 
	@mkdir -p obj
	@mv $(OUTTMP) ./obj
installTest:
	@cp $(SRCS) .
	@cp $(INC) .
	@gcc -c $(CTMP)
	@gcc libmx.a $(CTMP) -o $(NAME) 
	@mkdir -p obj
	@mv $(OUTTMP) ./obj
uninstall:
	@rm -rf $(CTMP) 
	@rm -rf $(OUT) 
	@rm -rf $(HEADTMP) 
	@rm -rf ./obj/ 
clean: 
	@rm -rf $(NAME)
	@rm -rf $(CTMP)
	@rm -rf $(OUT)
	@rm -rf $(OUTTMP)
	@rm -rf $(HEADTMP)
	@rm -rf ./obj/ 
reinstall: clean all
start: all 
	@./pathfinder