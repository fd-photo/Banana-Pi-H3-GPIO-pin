# Banana-Pi-H3-GPIO-pin
Banana Pi BPI-P2 Zero H3+ GPIO stepper_motor 

// compile
gcc -c main.c gpio.c
gcc main.o gpio.o -o rezult

//run 
./result steps(strps number) direction(1 or 0)
./result 1000 1 
