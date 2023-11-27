obj-m += hello_world.o
 
#You can update your Beaglebone path here.
KDIR = /home/newjoiner/RUPENDRA/tmp/lib/modules/6.5.0-rc1/build
 
all:
  make -C $(KDIR)  M=$(shell pwd) modules
