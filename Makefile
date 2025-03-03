CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
TARGET = cacheMe.exe
SRCS = main.c rodcut.c input_output.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS) rodcut.h input_output.h
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)