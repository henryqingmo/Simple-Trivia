# Simple-Trivia
Kahoot inspired trivia game based on C++ Qt framework

# How does it work?
Random numbers are generated through the srand function in [game.cpp](https://github.com/henryqingmo/Simple-Trivia/blob/master/game.cpp)
``` c++ 
srand(time(NULL));
```
The current time is used as a seeds and manipulated through an algorithm to ensure "real" random numbers

The range of the random number can be set as such in [main.cpp](https://github.com/henryqingmo/Simple-Trivia/blob/master/main.cpp)

``` c++ 
int generate_random(int min, int max)
{
    return rand()%(max + 1 - min) + min;
}

```

Through the srand function, the program 
1. Generate two random numbers
2. Randomly selects an operation (and caculates the answer)
3. Generate three simliar numbers based on the answer
4. Randomly selects a button for the correct answers and the other threes for the wrong answers

And thats the basis of the game!

# Installation:
## Windows
### Requirements: 64-bits windows 10 or above
[click here to instal](https://github.com/henryqingmo/Simple-Trivia/releases/download/v1.3.1/Simple-Trivia_Setup.exe)
## Linux
### Requirements: qtframework 5.15 

    git clone https://github.com/henryqingmo/Simple-Trivia.git
    cd Simple-Trivia
    chmod +x Simple-Trivia
    ./Simple-Trivia

