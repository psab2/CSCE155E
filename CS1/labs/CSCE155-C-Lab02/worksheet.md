
# Computer Science I
## Lab 2.0 Worksheet

Name(s) and Login(s):



1. Dennis Ritchie, the creator of the C programming language,
was born on September 9th, 1941.  If he were still alive,
how old would he be today?  Find out by running the `birthday`
program on the appropriate inputs and enter your solution here.

83 years, 0 weeks, and 6 days old today


2. Bjarne Stroustrup, the creator of the C++ programming
language, the object-oriented extension of C, was born on
December 30th, 1950.  How old is he today?

73 years, 37 weeks, and 1 days old today


3. Software testing often involves testing code with known
"bad" input in an attempt to break it (sometimes this is
referred to as *fuzzing*).  Try breaking the `birthday_cli`
program by giving it "bad" input and observe the consequences.
Give at least two examples of potentially bad input and the
results you observe.

  a. I gave an input of values that were outside of the range.
     Hello, Dennis.  You are 71 years, 18 weeks, and 2 days old today.
  b. I gave an input of 0 for the month number
     Hello, Dennis.  You are 74 years, 38 weeks, and 3 days old today.


4. Complete all the size and range entries below.

* `char`
  size: 1 byte
  range: -128 to 127
* `short int`
  size: 2 bytes
  range: -32768 to 32767
* `int`
  size: 4 bytes
  range: -2147483648 to 2147483647
* `long int`
  size: 8 bytes
  range: -9223372036854775808 to 9223372036854775807
* `float`
  size: 4 bytes
  range: 7 digits of accuracy
* `double`
  size: 8 bytes
  range: 15 digits of accuracy


5. Use your working currency conversion to determine
the exchange amounts for the following inputs:

  a) $250.25
  Amount in GBP: 88.96
  Amount in JPY: 14374.99
  b) $1,000.52
  Amount in GBP: 0.36
  Amount in JPY: 57.44
  c) $968,410.12
  Amount in GBP: 344.12
  Amount in JPY: 55604.34

6. Suppose that you had used only `int` types
in your conversion program.  Would you be able
to use it to convert the US national debt
(which as of 2020 was \$26,009,754,625,487)?
Why or why not?

  I would not be able to use it to convert the US national debt because
  it is not accurate when using int. Using double allows for a more
  accurate response as it takes into account that money is not
  always a whole number.

  Using int:
    Amount in GBP: 09
    Amount in JPY: 1531

  Using double:
    Amount in GBP: 9.24
    Amount in JPY: 1493.50

7. Mixed types

a) Run the `area` program with 3 and 4 as inputs.
What value do you get?  Is this result correct?

The area is 0.000000 square units. This result is incorrect.

b) Execute the program again with inputs 3 and 5.
Does the program give correct results?  Why not?

No, I got the same result.

c) Fix the program by editing the `area.c` source
code so that the program produces correct results.
Done - changed 1/2 to .5
