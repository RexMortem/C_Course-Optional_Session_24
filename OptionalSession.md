# Session 4 - Optional Session 

This is an optional session featuring only exercises; please have a go at the first 3 sessions to learn the language before you attempt these.
For an alternate style of exercise, see <a href="#OtherExercises"> Other Exercises </a>!

Good luck and happy coding!

## <a name="Exercises"> </a>

It's time for the spooky end to the C Course

You're an up-and-coming career politician working for Party C, who has crawled up to the ranks and are primed to be a perfect candidate for Mayor of London - but oh no! You've made a crucial mistake; you coded something in Python! To punish you for using a language other than C, the party leader has relocated you to... Spookesville? You've never heard of this village, but if there's any way you're making it back to the big leagues, it's through making a name for yourself in this village. 

Fortunately, you learn on arrival that the mayoral elections are happening this week! If you become the mayor of Spookesville, then *surely* you'll gain the trust of the Party again and be promoted out of this eerie little village in a year or so. The voting will end on Halloween, so you need to gain votes and fast! You learn at the local pub that the big players around the village are the **Haunts of Halloween**; you're not sure why they have such an ominous title, but years of being a career politician have told you to not ask questions and 
With each exercise, you'll be asked to help a **Haunt of Halloween** and each Haunt will have their own particular demands; solve each of their problems to gain their trust and 


### <a name="Exercise1"> More Bats, More Problems </a>

You decide to enter the ominous-looking castle as there'll surely be a Haunt there! Lo and behold, a pale-white figure - surrounded by a swarm of bats - is crouched over a laptop and muttering curses; it's Dracula! 

1) Dracula has far too many bats to keep track of and is looking to cut down on his flock of bats (fun fact: there are 4 collective nouns for bats!) and he wants you to write a program to store the names of the bats; the problem is that even Dracula does not know how many bats there are! You know from your University days that this requires a data structure that can **grow** to fit more elements.

Dracula races the bats against each other, and feeds you the bat names in order of where they placed (e.g. the first bat is the bat in 1st place, the second bat is the bat in second place etc). Dracula wants to remove the `n` slowest bats from his flock, and gives you this number as the first input. Since you need to remove `n` of the latest elements added to the data structure, you recognise that you could code a **stack** for this problem! 

Output the bats you removed (in order of removal), followed by the remaining flock (in order from fastest to slowest). A typical input to this problem will look like this:

```
2
Neal 
Patrick 
Sharon 
Bob
Jonathan 
```

In this case, Dracula wants you to remove the 2 slowest bats (Bob and Jonathan), so the output should be:

```
Jonathan
Bob

Neal 
Patrick 
Sharon 
```

**Input Constraints:** Each name is guaranteed to be fewer than 20 characters.

**Test** your solution by feeding it an input file in `txtFiles/BatProblemInputs` using: 
```sh
cat txtFiles/BatProblemInputs/inputFileName.in | ./yourExe
```

**Hint 1:** There is a function *feof* (in `<stdio.h>`) that lets us test for if a given stream is at the end of a file. For example, `feof(stdin)`. 

**Hint 2:** You can use **malloc** and **realloc** to dynamically allocate memory for an array. You can create a growable Stack (or other data structure) using this. 

**Hint 3:** A string can be thought of as a pointer to a bunch of chars (the string would have type `char*`). An array of strings can be thought of as a pointer to a bunch of pointers which each point to a bunch of chars. This would have type `char**`. 

**Hint 4:** There is an implementation of an IntStack in `cFiles/exerciseHints/IntStack.c`. 

**Hint 5:** Solving the full problem, but for integers: `cFiles/exerciseHints/RemovingAdjacentDuplicatesIntStack.c`.

2) Solve the problem for names with an arbitrary length. 

### <a name="Exercise2"> Labyrinth Search </a>

## <a name="OtherExercises"> Other Exercises </a> 

There are many resources to practice **C** on, and a nice beginner-friendly one is [HackerRank](https://www.hackerrank.com/)!

Create an account as a **developer**, and go to the [C topic](https://www.hackerrank.com/domains/c). 