clean: FILES=$(shell find -path "*~" | tr '\n' ' ')
clean:
	[ "$(FILES)" != "" ] && rm $(FILES)
