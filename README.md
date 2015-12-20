# midterm 1

The goals of this project was to compare the calculation of two different types of series, both of which will calculate pi.
The code itself allows for the calculation over a loop in which the number of elements in the series is doubled which allows to test
many interations until the value of pi is within the accepted error of 10^-6. In addition the goal of this project was also to time the 
two different series and to then see the ratio of the time it took to run each of them until they were within the error. The results make
it abundantly clear that the Baily-Borwein-Plouffe serries does a much more effecient job at calculating pi accuratly, only needing to run 
four times in comparison the Leibniz series needing to run 1048576 times to get within the same level of accuracy. As for the time the 
ratio of running the time of the Leibniz divided by that of the BBP yields a result of around 40000 showing again how much more effecient 
the BBP series is at calculating pi.
