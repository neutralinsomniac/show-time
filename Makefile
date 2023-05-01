all: show-time

show-time: show-time.c
	gcc -o $@ $<

clean:
	rm -f show-time
