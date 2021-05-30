## Open the Door

A rectangle area has **m**x**n** line and column. There have doors and path. One row can occupy only one door. You can go only up, down, right or left and can step once at a time in one grid. Every door is looked. You have the key of the first door. If you unlock this door then you can collect the key of the second door, which is in the nearest row, which row contains a door. Here, a 4X6 rectangle grid is illustrated\-

```
               X....#     « 1st door X = Your Default Position

2nd door »     #.....     . (Dot) \=path

               .....#     « 3rd door # (sharp)=door

4th door »     #.....
```

You cannot open the 2nd door before the 1st door, because the key of the 2nd door you can get by unlocking the 1st door. Although the 2nd door is nearer than the 1st door. So you must open doors row by row. This process will be continued before the last door. Now, you are in the first position of the rectangle; your target is to unlock the last door. There has several doors and you evaluate how many steps are needed to open the last door.

**Input**

The first line of the input contains the number of input cases in the input file. Each case starts with a line containing two integers, the row (1≤ **m** ≤500) and column

(2≤ **n** ≤500) of the rectangle grid. Then follows **m** lines, each contains **n** characters. Input will be terminated by two zero. This input will not be processed.

**Output**

For each input case, output one line containing a single integer, the necessary steps to reach to the last door.

**Sample Input**

**Output**
```
2

4 5

...#.

..#..

....#

.#...

2 4

....

#...

0 0

12

1
```

-----

Problem Setter: Tariq Newaz Shahriar


Although in Bangladesh we have faults in our computer education

 system, we learn programming at an age which is often too late

\-Shahriar Manzoor, Southeast University

 Elite problem setter of International Collegiate Programming Contest (ACM ICPC)
