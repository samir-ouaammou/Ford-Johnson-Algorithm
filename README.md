# Merge-Insertion Sort (Ford-Johnson Algorithm)

## Overview

This project demonstrates an advanced sorting algorithm called **Merge-Insertion Sort** (also known as **Ford-Johnson Algorithm**), designed to minimize the number of comparisons while sorting a list of integers. This implementation is done in C++ using vectors.

---

## 🚀 What You Will Learn

* How **Merge Sort** and **Insertion Sort** are combined for efficiency.
* The importance of the **Jacobsthal sequence** in insertion ordering.
* How to perform optimized **Binary Search**.
* How to handle edge cases like duplicate input and invalid values.

---

![alt text](<Screenshot from 2025-07-29 09-57-21.png>)

---

## 🛠️ Installation

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/samir-ouaammou/Merge-Insertion-Sort-Algorithm
   ```

2. Navigate to the project directory:
   ```bash
   cd Merge-Insertion-Sort-Algorithm
   ```

3. Compile the source files using `make`:
   ```bash
   make 
   ```

4. Clean up compiled files:
   ```bash
   make clean
   ```

5. To remove all object files and the executable:
   ```bash
   make fclean
   ```

6. To recompile the project from scratch:
   ```bash
   make re
   ```

7. Run the program:
   ```bash
   ./PmergeMe 5 2 9 3 7 1 6
   ```

---

## 💡 Algorithm Components

### 📦 Merge-Insertion Sort

* A hybrid algorithm combining **Merge Sort** and **Binary Insertion**.
* Reduces total comparisons especially for small inputs.
* Inspired by the Ford-Johnson algorithm (1959).

### 🧠 Merge Sort (used recursively on big elements)

1. Split input into pairs.
2. For each pair: the larger value goes into the `bigs` list, the smaller into the `smalls` list.
3. Recursively sort the `bigs` list.

### 🧮 Insertion Sort (Binary + Order)

* After sorting the `bigs`, the `smalls` are inserted one by one using **Binary Search**.
* The order of insertion follows a **Jacobsthal-based sequence** to minimize comparisons.

### 🔍 Binary Search

* For each insertion, we use `std::lower_bound()` (which performs binary search internally).
* It allows fast location of the correct position to insert an element in a sorted vector.

### 📊 Jacobsthal Sequence

* Defines the order in which the "small" elements should be inserted.
* Formula:

  * J(n) = J(n - 1) + 2 \* J(n - 2)
  * Initial values: J(0) = 0, J(1) = 1
* Helps to optimize the number of comparisons when inserting elements.

Example sequence: `0, 1, 3, 5, 11, 21, ...`

---

## 🔍 Step-by-Step Breakdown

### 1. Parse & Validate Input

* Ensure all inputs are valid integers.
* No negative values.
* No duplicates.

### 2. Pair Elements

* Group the input in pairs.
* Save the largest from each pair in `bigs`, the smallest in `smalls`.
* If the total number of elements is odd, track the leftover.

### 3. Recursively Sort `bigs`

* `sortVector()` is called recursively on `bigs`.

### 4. Generate Jacobsthal Insertion Order

* `insertOrder(n)` computes the optimized order.
* This ensures efficient insertions with fewer comparisons.

### 5. Insert `smalls`

* Insert each element from `smalls` into the sorted `bigs` using binary search and the Jacobsthal order.

### 6. Insert the Leftover

* If there was an odd number of elements, insert the leftover at the correct position.

### 7. Display Results

* Print the vector before and after sorting.
* Show the execution time.

---

## 🧪 Sample Output

```bash
Before: 5 2 9 3 7 1 6
After: 1 2 3 5 6 7 9
Time to process a range of 7 elements with std::vector : 12.00 us
```

---

## 📂 File Structure

```
.
├── main.cpp               # Implementation file
├── README.md              # This file
└── assets/
    └── merge-insertion-diagram.png # Suggested image illustrating the algorithm
```

---

## 🧠 Advanced Concepts Used

* Recursion
* Pairing strategy
* Binary search with `lower_bound()`
* Custom insertion sequence (Jacobsthal)
* Performance timing with `gettimeofday()`

---

## 🧵 Credits

Developed by **Samir Ouaammou** as part of 1337/42 core curriculum.

---

## 🏁 TL;DR

This project brings theory and practice together with an elegant algorithm that combines classical ideas with smart optimizations. Merge-Insertion Sort is not just sorting — it's sorting with strategy.

🔥 Happy Hacking!

---

### 📚 Recommended Resources

Want to dive deeper? Here are some great resources to understand Merge-insertion sort better:
- [Lode's Computer Graphics Tutorial](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [Lode's Computer Graphics Tutorial](https://en.wikipedia.org/wiki/Jacobsthal_number)

---

Thank you for checking out my (Merge Insertion Sort Algorithm) project! Stay tuned for more exciting challenges. 🔥
