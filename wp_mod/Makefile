KERNEL_BUILD := /home/aaron/HTC_One_X/kernel/JB/ElementalX-5.4/
KERNEL_CROSS_COMPILE := /usr/bin/arm-linux-gnueabi-

obj-m += wp_mod.o

all:
	make -C $(KERNEL_BUILD) CROSS_COMPILE=$(KERNEL_CROSS_COMPILE) M=$(PWD) modules
	$(KERNEL_CROSS_COMPILE)strip --strip-debug wp_mod.ko

clean:
	make -C $(KERNEL_BUILD) M=$(PWD) clean 2> /dev/null
	rm -f modules.order *~
