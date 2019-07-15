## a-new-Evict-time-attack-without-explicit-knowledge-of-offset-address
This repository is an implementation of a new Evic+time side channel attack. 

This attack should be performed on a virtual machine dedicated for the execution of this program. So the safety of your
host machine will not be affected in any way.

It attacks OpenSSL's AES-128's t-table implementation. In order to perform this attack on your own machine,
follow the steps outlined below.

## OpenSSL Installation

Trusted Versions of OpenSSL can be found at: https://www.openssl.org/source/old/. This attack will work for most
versions, but the specific version I used was version openssl-1.1.0f. After downloading the OpenSSL source, go to
the Downloads folder and unzip with:

    tar -xvf openssl-1.1.0f.tar.gz

Now we need to configure OpenSSL to use its t-table c implementation as opposed to the assembly implementation default.
OpenSSL also needs to be configured with debug symbols and specified to use a shared object as opposed to an .a library.
For the appropriate configuration, run:

    cd ~/Downloads/openssl-1.1.0f
    ./config -d shared no-asm no-hw
    
For the selected version: 1.1.0f, this configuration will install OpenSSL in the /usr/local/ directory. The configuration parameters specify
that we allow for debug symbols (used to locate T-table locations), create a shared object, only use c implementations of aes
(to use the t-tables), and to not use any hardware routines. To proceed with the install, run:

    sudo make
    sudo make install_sw
## compute Required_Numberof_Element1 & Required_Numberof_Element2
specify the number of set, way set and capacity of the last level of cache memory, in your system.
calculate the N (Required_Numberof_Element1 in preattack.cpp & masterattack.cpp) using the above information and equition3 in papaer.
in accordance with the value of Required_Numberof_Element1, consider a suitable value for Required_Numberof_Element2. The value of Required_Numberof_Element2 must be greater than (Required_Numberof_Element2>((4096*Required_Numberof_Element1)+64).
## compile and run preattack.cpp
put the Required_Numberof_Element1 & Required_Numberof_Element2 values inside preattack.cpp and compile that with appropriate number of encyption.

compile the preattack.cpp with below command:
g++ preattack.cpp -o preattack -I/usr/local/include/ssl -L/usr/local/lib -lcrypto
Next, use ./preattack to run the preattack.cpp
the output of this compile is 64 element.
specify the largest element created. using the element number and key in preattack.cpp, specify the block whose elements have the same virtual addresses in p. using the resulting block, compute smaller 12-bits of the virtual address of other elements.

## compile and run masterattack.cpp 
you must determine values base1 to base 3, in such a way that smaller 12-bit of Elements in M0[0],M1[0],M2[0],M3[0] be equal with smaller 12-bit of p matrix in preattack.cpp. 
Next, use below command to run and compile masteattack.cpp
g++ masterattack.cpp -o masterattack -I/usr/local/include/ssl -L/usr/local/lib -lcrypto
./masterattack





