# Vigenere-in-C

This is a remake of my original Vigenere project in Python.  It was one of my first few programming projects. 
I thought it would be a fun little thing to remake it as a little command line program.  There's not really much use for it, 
but it could be one of those funny little programs you have lying around your terminal in case you want to encode/decode something
on the fly. 

## How to use

Compile it with gcc, there's no dependencies or really anything fancy about this.  

The commands are simple too, the argument structure is just: Vigenere [encode, decode] [message] [key]

File options are coming soon

# The Original vs. This Rework

The main difference is that the program is just overall much better.  The code is much more organized and (I would hope) much better thought out.  
The original Python program had a lot of weird conversions between lists and strings in each function which made it pretty difficult to follow. 
Much of that has been simplified, sped up, and reworked.  One of the biggest changes is the way the program handles the core Caesar cipher.  Instead of
looping through each character passed to it (like the original), the funciton only works with one single char (since the Vigenere cipher only ever uses the 
Caesar cipher on one character).  Frankly, it's something I should have noticed when I first made it, but it's fixed here and I'm sure works much better 
because of it.

I've also gotten a bit ambitions and I'm currently working on a feature that will allow you to encode/decode an entire file.  This will be a bit more difficult,
but I've never really worked with much of any useful file I/O so it's another fun little thing to add.

If there's anything you'd like to add, or changes you'd like to suggest, let me know.  I'm always open to comments and criticism. 

If you'd like to read more, I will be posting an article about this on my blog: [Comming soon]
