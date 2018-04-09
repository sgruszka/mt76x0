KDIR ?= /lib/modules/`uname -r`/build

obj-m += mt76x0.o

mt76x0-objs	= \
	usb.o init.o main.o mcu.o trace.o dma.o core.o eeprom.o phy.o \
	mac.o util.o debugfs.o tx.o
ccflags-y := -DDEBUG
CFLAGS_trace.o := -I$(src)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean


