ECE243 DE1-SoC Nios II PROJECT

Authors: Arnold Etta
         
_________John-David Genus


1.1 Goal

The goal of this project is to successfully take concepts learnt over the course of the winter semester about Computer Organization to build a fairly complex game.
Such concepts include: stack management, interrupt handling, memory-mapped I/O registers, I/O hardware interfacing, video buffering and audio synthesis. 
The game is to be built on the DE1-SoC board using the Nios II processor embedded in it to act as the software interface directing the hardware I/O devices. 
This project allows the use of C language in addition to the assembly language of the Nios II processor. We will be using a combination of the 2 languages with the 
C language mainly handling the game (software) functions and the assembly language to develop interrupt request handlers (hardware function).


1.2 Background and Motivation

The idea behind this game originates from the "Candy Crush" game. In Candy Crush, players try to attain target scores or missions within a limited time frame or swap 
amount. Candies could only be swapped between candies immediately around themselves. A match is attained when 2 or more candies of the same type align with each other 
in either the vertical and/or horizontal alignment; whereby, matched candies break into points and the gaps are filled with more candies.

In our version, we will be making use of fruits instead of candies. There will be 6 fruits and only 1 level (tbd later). Fruits will not have to be swapped between
neighbouring fruits; so, players can select any two fruits on the screen to swap them. We have made this change to reduce the complexity of the game implementation
and increase player freedom. To mitigate this change, a match will only be attained when 3 or more fruits of the same type line up. For the first level, players will be required to reach a certain score from a maximum swap amount decided by the game. Next levels may be time based and/or a combination of time and swap limiters.

Players will use the PS2 keyboard to select fruits for swapping. Scores and number of swaps remaining will be displayed on the VGA screen and HEX displays. Possible background music will be playing?
