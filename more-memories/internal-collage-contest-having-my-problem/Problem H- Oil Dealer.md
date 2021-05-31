## Oil Dealer

In a village, there has a very renowned oil dealer. He is so popular for his honesty that about 10 to 15 surrounded villages shopkeepers buy their oil from him. He takes order only from 7 AM to 12 PM. All the shopkeepers’ places there order with their container. The oil dealer gives a number for every container. Every shopkeeper must come the next day to take their oil. Oil dealer has an interesting characteristic. He has a large number of pots to take the oil from the oil drum. He selects such a pot that can fill up all the containers perfectly. For instance, for an 18-unit container, if he selects 6, then 6-unit pot takes exactly 3 times to fill up the container. He does not take 5-unit pot for 18-unit container, because after taking 3 times to fill 15 unit; then how does he fill up remaining 3 units by this pot. Thus, the selected pot is not only to fill up one container but it can fill up all the containers also. As a result, choosing only one pot - is always minimizes his tasks and time as well; above all, he can fulfill the orders within the rest of the day. Now orders are increased and it is difficult to find out the pot. Now he calls your programming team to write a program to solve his problem (without any remuneration!).

### Input

Each line begins with a number of orders **N**≤5000. Next **N** integers (less then 2^31) mentioned the ordered quantity for oil by the customers; given in the same line.

### Output

You print the unit of the pot in a line. For simplicity assume all the capacities are measured in the same unit.

### Sample input
```
3

14 14 35 

5

32 12 16 12 8
```

### Output
```
7

4
```

-----
Problem Setter: Khaled Mahmood Shahriar
