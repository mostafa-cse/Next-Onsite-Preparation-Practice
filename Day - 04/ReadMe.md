## Problem - A(One Way Roads) : 
  - Simple dfs iteration on graph until reach `n + 1` level
  - Why level is `n + 1`
  - Detrmine cost when ti is W_i and 0
      - If we reverse the direction of an edge then cost will be `W_i`
      - otherwise cost will be `0`
      - Now itertive the graph and create a cycle with lowest cost
      - <details> <img src = "https://github.com/user-attachments/assets/09506f0e-2c2e-4367-941f-2fbd5850f3cc"> </img> </details>


## Problem - B(Jolly Jumpers) : 
  - determine the abssoulate difference between two consecutive element of array
  - then map this different of array
  - Now check element `1 - (N - 1)`
  - If all element is present then Print `YES` otherwise `NO`
  - <details> ![image](https://github.com/user-attachments/assets/2745e81f-bb80-4fe1-bf66-73a4e787fe43) </details>


## Problem - C(A Feast for the Fans) : 
  - Read Problem statemant carefully
  - Simple Modular Arithmetic operation
  - Some Imprtant Info :
    
<details>
    Month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
</details>

<details>
    Month_Name[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
</details>

<details>
      Episod[] = {0, 10, 10, 10, 10, 10, 10, 7};
</details>

## Problem - D(Rider) : 


## Problem - E(The Haunted House) : 
  - Use String substr() sunction and determine substring `string length / 2`
  - reverse print the string

## Problem - F(Intelligent Factorial Factorization) : 
 - Read Problem statement and see casrefully the output Format
 - Think about factorial of `N >= 10`
 - Opp! it consists of multiplication primes
 - determine maximum prime till `N`
 - Now determine how many times A Prime number contribute to build this factorial
 - Now think about `lagrange's Theorem`
<details> ![image](https://github.com/user-attachments/assets/6666ba85-dcbf-4445-8a50-fc9953a2f971)</details>

## Problem - G(Love Letters!) 
  - Simple maping each character
  - if number of character is Prime then print
  - otherwise no character has Prime number of occerences then print `Love is painful !`

## Problem - H(Brush) : 
  - Read Problem Carefully
  - think the moving direction of the Brush
  - it is only `vertical`, So we need only y points, ignore x
  - Now think greedy, then Why greedy fails
  - think about Dynamic Programming
  - Why dp and solve
  - how many ways we can select a point and moves from this point
      - this point to upper
      - this point to `width / 2` upper
      - this point to `(width + 1) / 2` upper 
  - <details> <image src = "https://github.com/user-attachments/assets/2c53f9c0-97d6-4a37-ba0b-4497feeac488"> </image> </details> 

## Problem - I(Prochur Chhuti Lagbe (প্রচুর ছুটি লাগবে))
  - Simple marking and observation Problem
  - count number of days suti if this interval is not laying any of other suti
  - then mark

## Problem - J(Ecological Premium)
  - Simple observation Problem
  - <details> <image src = "https://github.com/user-attachments/assets/5b71e7b1-cd4c-4c05-8f00-d22e6e590ee3"> </image> </details>

## Problem - K(Collectors Problem) : 
  

## Problem - L(Primary Arithmetic)
  - Using only simple Arithmetic Sum
  - count `Sum / 10` and `Sum /= 10`
  - <details> <image src = "https://github.com/user-attachments/assets/149f8b4a-3b91-4520-b472-a566f256b774"> </image> </details>
