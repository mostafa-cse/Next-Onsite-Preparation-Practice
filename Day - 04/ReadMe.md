## Problem - A(One Way Roads) : 
  - Simple dfs iteration on graph until reach `n + 1` level
  - Why level is `n + 1`
  - Detrmine cost when ti is W_i and 0
      - If we reverse the direction of an edge then cost will be `W_i`
      - otherwise cost will be `0`
      - Now itertive the graph and create a cycle with lowest cost
      - <img src = "https://github.com/user-attachments/assets/09506f0e-2c2e-4367-941f-2fbd5850f3cc"> </img>


## Problem - B(Jolly Jumpers) : 
  - determine the abssoulate difference between two consecutive element of array
  - then map this different of array
  - Now check element `1 - (N - 1)`
  - If all element is present then Print `YES` otherwise `NO`
  - ![image](https://github.com/user-attachments/assets/2745e81f-bb80-4fe1-bf66-73a4e787fe43)


## Problem - C(A Feast for the Fans) : 
  - Read Problem statemant carefully
  - Simple Modular Arithmetic operation

<details>
  <p> 
    Some Imprtant Info : 
      - int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      <br>
      - string a[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
      <br>
      - int Episod[] = {0, 10, 10, 10, 10, 10, 10, 7};
  </p>
</details>
