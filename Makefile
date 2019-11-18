NAME = pathfinder

INC =  ./inc/header.h \
	./inc/libmx.h \

HEADTMP = header.h \
	libmx.h \

SRCS = ./src/main.c \
	./src/mx_is_valid_string.c \
	./src/mx_read_line.c \
	./src/mx_is_file_empty.c \
	./src/mx_is_valid_first_line.c \
	./src/validation.c \
	./src/mx_atoi_positive_valid.c \
	./src/createMatrix.c \
	./src/initComeFrom.c \
	./src/initIsOnPlace.c \
	./src/initPathMas.c \
	./src/findMin.c \
	./src/find.c \
	./src/cpyStructure.c \
	./src/sortList.c \
	./src/reverseList.c \
	./src/deikstra.c \
	./src/findShortestFor.c \
	./src/output.c \
	./src/lengthOfList.c \
	./src/weightBetweenPoints.c \
	./src/indexToNameOfPoint.c \
	./src/mx_file_to_masRoads.c \
	./src/haveRoad.c \
	./src/indexOfPoint.c \
	./src/mx_file_to_masPoints.c \
	./src/index_of_same_point.c \
	./src/fillListOfOutput.c \
	./src/isDuplicate.c \
	./src/pushBack.c \
	./src/createNode.c \

CTMP = main.c \
	mx_is_valid_string.c \
	mx_read_line.c \
	mx_is_file_empty.c \
	mx_is_valid_first_line.c \
	validation.c \
	mx_atoi_positive_valid.c \
	createMatrix.c \
	initComeFrom.c \
	initIsOnPlace.c \
	initPathMas.c \
	findMin.c \
	find.c \
	cpyStructure.c \
	sortList.c \
	reverseList.c \
	deikstra.c \
	findShortestFor.c \
	output.c \
	lengthOfList.c \
	weightBetweenPoints.c \
	indexToNameOfPoint.c \
	mx_file_to_masRoads.c \
	haveRoad.c \
	indexOfPoint.c \
	mx_file_to_masPoints.c \
	index_of_same_point.c \
	fillListOfOutput.c \
	isDuplicate.c \
	pushBack.c \
	createNode.c \

OUTTMP = main.o \
	mx_is_valid_string.o \
	mx_read_line.o \
	mx_is_file_empty.o \
	mx_is_valid_first_line.o \
	validation.o \
	mx_atoi_positive_valid.o \
	createMatrix.o \
	initComeFrom.o \
	initIsOnPlace.o \
	initPathMas.o \
	findMin.o \
	find.o \
	cpyStructure.o \
	sortList.o \
	reverseList.o \
	deikstra.o \
	findShortestFor.o \
	output.o \
	lengthOfList.o \
	weightBetweenPoints.o \
	indexToNameOfPoint.o \
	mx_file_to_masRoads.o \
	haveRoad.o \
	indexOfPoint.o \
	mx_file_to_masPoints.o \
	index_of_same_point.o \
	fillListOfOutput.o \
	isDuplicate.o \
	pushBack.o \
	createNode.o \
	

OUT = ./obj/main.o \
	./obj/mx_is_valid_string.o \
	./obj/mx_read_line.o \
	./obj/mx_is_file_empty.o \
	./obj/mx_is_valid_first_line.o \
	./obj/validation.o \
	./obj/mx_atoi_positive_valid.o \
	./obj/createMatrix.o \
	./obj/initComeFrom.o \
	./obj/initIsOnPlace.o \
	./obj/initPathMas.o \
	./obj/findMin.o \
	./obj/find.o \
	./obj/cpyStructure.o \
	./obj/sortList.o \
	./obj/reverseList.o \
	./obj/deikstra.o \
	./obj/findShortestFor.o \
	./obj/output.o \
	./obj/lengthOfList.o \
	./obj/weightBetweenPoints.o \
	./obj/indexToNameOfPoint.o \
	./obj/mx_file_to_masRoads.o \
	./obj/haveRoad.o \
	./obj/indexOfPoint.o \
	./obj/mx_file_to_masPoints.o \
	./obj/index_of_same_point.o \
	./obj/fillListOfOutput.o \
	./obj/isDuplicate.o \
	./obj/pushBack.o \
	./obj/createNode.o \

DFLAGS = -fsanitize=address -g
CFLSGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: clean install uninstall

install:
	@cd libmx && make install
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLSGS) -c $(CTMP)
	@clang $(CFLSGS) ./libmx/libmx.a $(CTMP) -o $(NAME) 
	@mkdir -p obj
	@mv $(OUTTMP) ./obj
uninstall:
	@cd libmx && make uninstall
	@rm -rf $(CTMP) 
	@rm -rf $(OUT) 
	@rm -rf $(HEADTMP) 
	@rm -rf ./obj/ 
clean: 
	@cd libmx && make clean
	@rm -rf $(NAME)
	@rm -rf $(CTMP)
	@rm -rf $(OUT)
	@rm -rf $(OUTTMP)
	@rm -rf $(HEADTMP)
	@rm -rf ./obj/ 
reinstall: clean all
start: all 
	@./pathfinder