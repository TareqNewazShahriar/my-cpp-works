
## Solve ACM.UVa Problems
Time limit: 5 Seconds

Sorting and searching is an important algorithm in programming. Therefore, you nee
appropriate algorithm in speed and memory point of view.
Now you are given ‘ **n** ’ number of ACM.UVa problems with their serial number and n
ascending order by problems serial number and find a problem.

### Input specification

First number **n** indicates how many problems number with name has in this input where
**n** ≤ 5000 (But ACM.UVa has 1782 problems till 18 Jan 2006. So there may have duplicate
lines followed, the problems number-name is given. Then a blank line and then given a prob
The problem numbers is ≤10999 and the name is ≤75 characters.

### Output specification

First display in a line “Task **t:** ”, a space; then display “ **Problem_number Problem_Name** f
Where **t** is replaced by consecutive task number starts from **1**. **Problem_number** and
replaced by the searched problem’s number and name. Finally, **p** is replaced by the search
position. Each problem number should be right aligned in a field of 6 characters after the t
colon.

### Sample Input & Output

Input
```
8
10914 Abundance and Perfect Number
10920 Spiral Tap
10055 Hashmat the brave warrior
10525 New To Bangladesh
10923 Seven Seas
10059 The Hazard of CSE Department!
10924 Prime Words
10169 Urn-ball Probabilities!

Seven Seas
```
Output
```
Task 1: 10923 Seven Seas is found at positi
```

Input
```
11
10064 Traveling in another dimension
10880 Colin and Ryan
10087 The Tajmahal of ++Y2K
10875 Big Math
107 The Cat in the Hat
10091 The Valentine's Day
10641 Barisal Stadium
10108 The Mosquito Killer Mosquitos
10881 Piotr’s Ant

Task 2: 107 The Cat in the Hat is found at
```

Outut
```
The Cat in the Hat
```

---
Problem Setter: Tariq Newaz Shahriar
