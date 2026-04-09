# Coding Interview Prep: The Essential Topics

> A curated, frequency-based guide to mastering technical interviews.  
> Based on real patterns from FAANG and top tech companies.

![Study Strategy](https://img.shields.io/badge/study-2%20weeks-brightgreen) ![Topics](https://img.shields.io/badge/topics-10%2B-blue)

---

## Tier 1: Absolute Must-Know (80% of interviews)

These topics appear in nearly every interview, regardless of level (junior to senior).

### 1. Arrays & Hashing (The King)

- **Why so frequent:** Simple, fast to code, and test the ability to optimize space/time.
- **Key patterns:** Two Pointers (reversing, removing duplicates), Sliding Window (max sum subarray, longest substring without repeats), Prefix Sum (range sum queries), Hash Map/Dictionary counting (finding duplicates, anagrams, two-sum).
- **Classic problem:** *"Given an array of integers nums and an integer target, return indices of the two numbers that add up to target."*

### 2. Strings

- **Why so frequent:** Real-world data is text. Tests attention to detail (character encoding, immutability).
- **Key patterns:** Palindrome checking (two pointers from ends), Anagram detection (sorting or char counting), Substring search (Sliding Window again), Character frequency counting.
- **Classic problem:** *"Given a string s, find the length of the longest substring without repeating characters."*

### 3. Recursion & Dynamic Programming (DP)

- **Why so frequent:** Demonstrates the ability to break complex problems into simpler sub-problems. Crucial for mid/senior roles.
- **Key patterns:** Fibonacci style (climbing stairs), 0/1 Knapsack (array partition into equal sums), Grid paths (unique paths, robot in a grid), House Robber (max non-adjacent sum).
- **Classic problem:** *"You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?"*

---

## Tier 2: Very Frequent (Needed for a passing grade)

### 4. Linked Lists

- **Why so frequent:** Tests pointer manipulation skills. Problems are usually short to solve, perfect for a 15-minute live coding segment.
- **Key patterns:** Slow-Fast pointer (find middle, detect cycle), Reversal (iterative vs recursive), Finding intersection point, Removing Nth node from end.
- **Classic problem:** *"Given the head of a linked list, reverse the list iteratively and recursively."*

### 5. Binary Trees & Tree Traversal

- **Why so frequent:** Tests recursive thinking and understanding of search algorithms.
- **Key patterns:** Depth-First Search (DFS: Pre-order, In-order, Post-order), Breadth-First Search (BFS: Level-order), Maximum depth/diameter, Lowest Common Ancestor (LCA).
- **Classic problem:** *"Given the root of a binary tree, return its maximum depth (or the diameter of the tree)."*

### 6. Binary Search (on arrays & answer space)

- **Why so frequent:** Deceptively simple but easy to get wrong with off-by-one errors.
- **Key patterns:** Standard binary search (sorted array), Search in rotated sorted array, Find first/last position of element, Binary search on answer (e.g., "find the minimum speed to arrive on time").
- **Classic problem:** *"Suppose an array sorted in ascending order is rotated at some pivot. Search for a target value."*

### 7. Sorting (not just calling `.sort()`)

- **Why so frequent:** Rarely implemented from scratch, but the appropriate sort and its complexity must be known.
- **Key patterns:** Merge Sort (divide & conquer, count inversions), Quick Sort (partitioning, Kth largest element), Custom comparators (sorting by multiple rules).
- **Classic problem:** *"Given an array of meeting time intervals, determine if a person could attend all meetings."* (Sorting by start time).

---

## Tier 3: Important for Mid/Senior & FAANG

### 8. Stacks & Queues

- **Key patterns:** Valid parentheses, Min stack (track min in O(1) time), Queue using two stacks, Monotonic stack (next greater element, daily temperatures).
- **Classic problem:** *"Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid."*

### 9. Heaps (Priority Queues)

- **Key patterns:** Top K elements (Kth largest, top K frequent), Merge K sorted lists, Running median.
- **Classic problem:** *"Find the Kth largest element in an unsorted array."*

### 10. Graphs (BFS & DFS)

- **Why so frequent:** Used for more complex systems (social networks, maps, dependency resolution).
- **Key patterns:** Number of islands (grid graph), Shortest path in unweighted graph (BFS), Cycle detection (directed/undirected), Topological sort (course schedule).
- **Classic problem:** *"Given a 2D grid of '1's (land) and '0's (water), count the number of islands."*

---

## Tier 4: Niche but Good to Know

- **Bit Manipulation:** XOR tricks (find single number in pairs), bit masking. *Less common in general, but Google/Apple prefer it.*
- **Tries (Prefix Trees):** Word search, autocomplete, longest common prefix. *Good for "word" problems.*
- **Backtracking:** Generate all permutations/subsets, N-Queens. *Often a sign that DP is a better fit.*
- **Intervals:** Merge intervals, insert interval, meeting rooms II (sweep line).

---

## The "Don't Waste Time" List (Rare for general SWE)

- Red-Black Trees / AVL Trees (know they exist, not how to implement)
- B-Trees (database internals only)
- Advanced Math (calculus, complex number theory)
- Low-level memory management (unless the role is embedded/C++)

---

## A 2-Week Study Strategy

> **Active recall is essential.** Passive reading is not sufficient.

| Day(s) | Focus Area | Action Items |
|--------|------------|---------------|
| 1–2 | Arrays, Hashing, Strings + Two Pointers & Sliding Window | Solve 5–7 easy/medium LeetCode problems per pattern |
| 3–4 | Recursion + DP (Climbing Stairs, House Robber) | Draw recursion tree on paper *first*, then code |
| 5–6 | Linked Lists + Binary Trees (DFS & BFS) | Implement reversal and traversals from scratch without an IDE |
| 7–8 | Binary Search + Sorting (custom comparators) | Practice rotated array search and custom sort rules |
| 9–10 | Stacks, Queues, Heaps (Top K problems) | Complete "valid parentheses", "min stack", "Kth largest" |
| 11–12 | Graphs (BFS/DFS for Number of Islands) | Solve islands, shortest path, and cycle detection problems |
| 13–14 | **Mock interviews** | Use Pramp or a peer. Time each session: 25 min problem + 5 min discussion |

---

## Final Tip

For every problem solved, **state the Time Complexity and Space Complexity aloud (or in writing) before writing any code.** Interviewers value this as much as the solution itself.
