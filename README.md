# subnetcalc #
A very simple subnet calculator written in C. It's nothing fancy at all,
just a small project of mine to get me going with C.

Simply build it (make), run it (./subnetcalc) and enter the subnet 
mask in slash notation but without the slash. 
For example enter 24 for a 24-bit subnet mask and the
program will output the total number of addresses in the range aswell
as the total number of usable address for hosts.

You can also give the netmask to the program as an argument. For example:

    $> ./subnetcalc 24
    Netmask bit: 24

    256 total addresses
    254 usable addresses for hosts

