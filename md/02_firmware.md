
[Back to main](../README.md#firmware)

# https://github.com/bus710/study_chibios_linux/blob/master/README.md

# install gcc-arm.
# use english directory path for decoding unicode.

sudo apt-get install python-pip

# check pip version... should support py2.7.
# although we just install pip, we need to explicitly use pip2 in the shell to distinguish pip2 and pip3.

sudo pip2 install mbed-cli
mbed new mbed_test
cd mbed_test
mbed update
cd mbed-os
sudo pip2 install -r requirements.txt

cd ..

# edit mbed_setting.py 
# add GCC_ARM_PATH="/usr/bin/"

touch main.cpp

# write a simple code for main
# #include "mbed.h"
# int main(){
#   while (true){ wait(0.5); }
# }

mbed compile -t GCC_ARM -m DISCO_F407VG (or NUCLEO_F446RE)
mbed export -i GNUARMECLIPSE -m DISCO_F407VG (or NUCLEO_F446RE)

# copy interface and board directories from /usr/share/openocd/scripts
# IMPORTANT - import MBED project not "makefile project from existing".
