CC := gcc

bin/:
	mkdir bin

bin/print-generator: bin/ print-generator/main.c
	$(CC) -o bin/print-generator print-generator/main.c

.PHONY: clean build

clean:
	rm -r bin

build: bin/print-generator

