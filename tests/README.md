# Libft Test  
Test your libft functions made at 42 school with this piece of code. Clone it somewhere. Open the Makefile and specify your libft.a location, and open in 'includes' folder, the libft_test.h to relocate your libft.h file too. Then execute "make test"; you can run the test.out.
This test was made by myself and sometimes thanks to the help of other tests like the moulitest or unittest. You should have compiled your librairies first before using this test.

![example](https://raw.githubusercontent.com/Kant1-0/libft-test/master/img-test.png)

### Here is the help!  
This programm helps you to test your libft project made at 42 - or anyone willing to recode on his/her own the lib c. It's just another test among other available on Github, and it was at first made to help me understand how to debug a code.  
If you are learning, I advise you better debugg your functions yourself. Or you can still help me to improve this debugging programm, that is quite simple to understand for newbies ;)  

### How to use me?!  
Just enter those few arguments while executing the code:  
* **part1** = test only part 1 of libft;  
* **part2** = test only part 2 of libft;  
* **bonus** = test only bonus of libft;  
* **all** = test the whole libft, bonus included;  
* **-debug** = enter the debugging mode (still beta);  
 * *'xxx*' : where xxx is the name of the function to debugg. There can be one or more functions separated by space.  
If you enter no argument, everything will be debbug.  
 * *'exit'* ; tape exit to go back to normal mode.  
* **help** = show this help file  

### TO DO:  
Few things left to do!
* The debugging mode to complete... Debug mode is meant to show the difference between the output of your ft_function and the libc function (or what should have been output).
* Add a function able to get/catch the user input and give a debugging result of the function on screen.
* Handle a way to skip functions that were not yet created by user in debug mode.
