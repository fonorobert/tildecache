builddir = build
srcdir = src
CC = gcc
CFLAGS = -lm

srcfiles = $(notdir $(wildcard $(srcdir)/*.c))
outputs = $(basename $(srcfiles))

all: $(outputs)

$(outputs): %: $(srcdir)/%.c
	$(CC) $(CFLAGS) -o $(builddir)/$@ $<

clean:
	rm build/*
