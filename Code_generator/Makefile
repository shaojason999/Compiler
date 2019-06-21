CC = gcc -g
YFLAG = -d
FNAME = compiler_hw3
PARSER = myparser
OBJECT = lex.yy.c y.tab.c y.tab.h ${FNAME}.j ${FNAME}.class

all: scanner parser
	@${CC} -o ${PARSER} y.tab.c lex.yy.c

scanner:
	@lex ${FNAME}.l

parser:
	@yacc ${YFLAG} ${FNAME}.y

test:
	@./${PARSER} < ./example_input/basic_declaration.c
	@echo -e "\n\033[1;33mmain.class output\033[0m"
	@java -jar jasmin.jar ${FNAME}.j
	@java -Xverify:none ${FNAME} 

test1:
	@./${PARSER} < ./example_input/basic_function.c
	@echo -e "\n\033[1;33mmain.class output\033[0m"
	@java -jar jasmin.jar ${FNAME}.j
	@java -Xverify:none ${FNAME} 

test2:
	@./${PARSER} < ./example_input/basic_if_statement.c
	@echo -e "\n\033[1;33mmain.class output\033[0m"
	@java -jar jasmin.jar ${FNAME}.j
	@java -Xverify:none ${FNAME} 

test3:
	@./${PARSER} < ./example_input/basic_while_statement.c
	@echo -e "\n\033[1;33mmain.class output\033[0m"
	@java -jar jasmin.jar ${FNAME}.j
	@java -Xverify:none ${FNAME} 

my:
	@./${PARSER} < ./test.c
	@echo -e "\n\033[1;33mmain.class output\033[0m"
	@java -jar jasmin.jar ${FNAME}.j
	@java -Xverify:none ${FNAME} 

my2:
	@./${PARSER} < ./test2.c
	@echo -e "\n\033[1;33mmain.class output\033[0m"
	@java -jar jasmin.jar ${FNAME}.j
	@java -Xverify:none ${FNAME} 

clean:
	rm -f ${PARSER} ${OBJECT} 
