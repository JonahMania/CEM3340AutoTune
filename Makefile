NAME=autoTune

SRC=main.c MCP42.c

SRCPATH=./
OBJ=$(addprefix $(SRCPATH), $(SRC:.c=.o))

MODEL=attiny84
CC=avr-gcc
CFLAGS=-g -std=c11 -Os -mmcu=$(MODEL)
LINKFLAGS=-g -mmcu=$(MODEL)

RM=rm -f

all: $(OBJ)
	$(CC) $(LINKFLAGS) $(OBJ) -o $(NAME).elf
	avr-objcopy -j .text -j .data -O ihex $(NAME).elf $(NAME).hex


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

flash:
	avrdude -p $(MODEL) -P usb -c usbasp -U flash:w:$(NAME).hex

clean:
	-$(RM) $(NAME)
	-$(RM) *.o
	-$(RM) *.elf
	-$(RM) *.hex
	-$(RM) *.core
	-$(RM) *.stackdump
	-$(RM) $(SRCPATH)*.o
	-$(RM) $(SRCPATH)*.elf
	-$(RM) $(SRCPATH)*.hex
	-$(RM) $(SRCPATH)*.core
	-$(RM) $(SRCPATH)*.stackdump

remake: clean all
