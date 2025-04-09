# Ford-Johnson Merge-Insertion Sort

## Overview

This repository implements the Ford-Johnson Merge-Insertion Sort algorithm, also known as the Merge-Insertion Sort. This algorithm is particularly notable for its focus on minimizing the number of comparisons, making it theoretically close to optimal for this metric.

## Algorithm Description

The Ford-Johnson algorithm combines several techniques to achieve efficient sorting:

1. **Paired Elements**: Elements are processed in pairs
2. **Recursion**: Larger elements are sorted recursively
3. **Binary Insertion**: Smaller elements are inserted using binary search
4. **Jacobsthal Numbers**: Used to determine optimal insertion order

## Implementation Details

### Full Implementation

```cpp
void PmergeMe::merge_insert_vec(std::vector<int> &vec)
{
    // Base case: already sorted if 0 or 1 elements
    if (vec.size() <= 1)
        return;

    // Containers for our algorithm
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> sorted;
    size_t check = vec.size() % 2;  // Check if we have odd number of elements

    // Step 1: Create sorted pairs
    for (size_t i = 0; i < vec.size() - check; i += 2)
    {
        if (vec[i] > vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }

    // Handle odd element if present
    int odd = -1;
    if (check)
        odd = vec[vec.size() - 1];

    // Step 2: Extract larger elements
    std::vector<int> large;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        large.push_back(pairs[i].first);
    }

    // Step 3: Recursively sort larger elements
    merge_insert_vec(large);

    // Step 4: Initialize sorted with main chain
    sorted = large;

    // Step 5: Insert smaller elements using Jacobsthal sequence
    if (!pairs.empty()) {
        // Insert first small element
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[0].second);
        sorted.insert(pos, pairs[0].second);
    }

    // Generate Jacobsthal numbers
    std::vector<int> jacobsthal = jacobsthal_number(pairs.size());

    // Insert remaining elements by Jacobsthal ranges
    for (size_t j = 1; j < jacobsthal.size(); j++)
    {
        for (size_t i = jacobsthal[j - 1] + 1; i <= jacobsthal[j] && i < pairs.size(); i++)
        {
            std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
            sorted.insert(pos, pairs[i].second);
        }
    }

    // Insert any remaining elements not covered by Jacobsthal sequence
    for (size_t i = jacobsthal.back() + 1; i < pairs.size(); i++)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
        sorted.insert(pos, pairs[i].second);
    }

    // Insert odd element if it exists
    if (odd != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), odd);
        sorted.insert(pos, odd);
    }

    // Update original vector with sorted result
    vec = sorted;
}
```

### 1. Pairing Elements - Deep Dive

```cpp
// Create sorted pairs
for (size_t i = 0; i < vec.size() - check; i += 2)
{
    if (vec[i] > vec[i + 1])
        pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    else
        pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
}

// Handle odd element if present
int odd = -1;
if (check)
    odd = vec[vec.size() - 1];
```

**How it works:**
- We take elements in pairs (0-1, 2-3, 4-5, etc.)
- For each pair, we determine the larger and smaller element
- We create a pair with the larger element first and smaller element second
- If there's an odd number of elements, we handle the last one separately

**Example:**
```
Original array: [7, 3, 9, 2, 5, 8]
Pairing: Compare (7,3), (9,2), (5,8)
Results in pairs: [(7,3), (9,2), (8,5)]
No odd element since length is even
```

```
Original array: [7, 3, 9, 2, 5]
Pairing: Compare (7,3), (9,2)
Results in pairs: [(7,3), (9,2)]
Odd element: 5
```

### 2. Extracting and Sorting Main Chain - Deep Dive

```cpp
// Extract larger elements
std::vector<int> large;
for (size_t i = 0; i < pairs.size(); i++)
{
    large.push_back(pairs[i].first);
}

// Recursively sort larger elements
merge_insert_vec(large);

// Initialize sorted with main chain
sorted = large;
```

**How it works:**
- We extract the first element (larger) from each pair
- We recursively apply the same algorithm to this array of larger elements
- After recursion, `large` contains the sorted larger elements (main chain)
- We initialize our final sorted array with this main chain

**Example:**
```
From pairs: [(7,3), (9,2), (8,5)]
Extract larger elements: [7, 9, 8]
After recursive sort, large becomes: [7, 8, 9]
Main chain: [7, 8, 9]
```

**Recursive Example Trace:**
1. Original: [7, 3, 9, 2, 8, 5]
2. Pairs: [(7,3), (9,2), (8,5)]
3. Large elements: [7, 9, 8]
4. Recursive call on [7, 9, 8]:
   - Pairs: [(9,7), (8,_)]
   - Large elements: [9]
   - Recursive call on [9] (base case, already sorted)
   - Insert 7: [7, 9]
   - Insert 8: [7, 8, 9]
5. Main chain: [7, 8, 9]

### 3. Jacobsthal Number Generation - Deep Dive

```cpp
std::vector<int> jacobsthal_number(size_t size)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (1)
    {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= static_cast<int>(size))
            break;
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}
```

**How it works:**
- Start with initial Jacobsthal numbers [0, 1]
- Each subsequent number follows the formula: J(n) = J(n-1) + 2*J(n-2)
- Continue generating until we exceed the size parameter
- These numbers define the optimal ranges for insertion

**Example:**
```
For size = 10:
Start with [0, 1]
Next: 1 + 2*0 = 1 → [0, 1, 1]
Next: 1 + 2*1 = 3 → [0, 1, 1, 3]
Next: 3 + 2*1 = 5 → [0, 1, 1, 3, 5]
Next: 5 + 2*3 = 11 (exceeds 10, stop)
Final sequence: [0, 1, 1, 3, 5]
```

### 4. Main Insertion Phase with Jacobsthal Ranges - Deep Dive

```cpp
// Insert first small element
if (!pairs.empty()) {
    std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[0].second);
    sorted.insert(pos, pairs[0].second);
}

// Generate Jacobsthal numbers
std::vector<int> jacobsthal = jacobsthal_number(pairs.size());

// Insert remaining elements by Jacobsthal ranges
for (size_t j = 1; j < jacobsthal.size(); j++)
{
    for (size_t i = jacobsthal[j - 1] + 1; i <= jacobsthal[j] && i < pairs.size(); i++)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
        sorted.insert(pos, pairs[i].second);
    }
}
```

**How it works:**
- First, insert the smallest element from the first pair (special case)
- Then generate Jacobsthal numbers up to the size of our pairs array
- Process elements in ranges defined by consecutive Jacobsthal numbers
- Use binary search (`lower_bound`) to find the correct insertion position
- This specific ordering minimizes the total number of comparisons

**Example with detailed tracing:**
```
Pairs: [(7,3), (9,2), (8,5)]
Main chain: [7, 8, 9]
Jacobsthal numbers: [0, 1, 1, 3]

First small element (pairs[0].second = 3):
  - Binary search locates position after 3
  - Insert 3: [3, 7, 8, 9]

Process range from jacobsthal[1-1]+1 = 1 to jacobsthal[1] = 1:
  - Insert pairs[1].second = 2:
  - Binary search locates position before 3
  - Insert 2: [2, 3, 7, 8, 9]

Process range from jacobsthal[2-1]+1 = 2 to jacobsthal[2] = 1:
  - Empty range (2 > 1)

Process range from jacobsthal[3-1]+1 = 2 to jacobsthal[3] = 3:
  - Insert pairs[2].second = 5:
  - Binary search locates position between 3 and 7
  - Insert 5: [2, 3, 5, 7, 8, 9]
```

### 5. Handling Remaining Elements - Deep Dive

```cpp
// Insert any remaining elements not covered by Jacobsthal sequence
for (size_t i = jacobsthal.back() + 1; i < pairs.size(); i++)
{
    std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
    sorted.insert(pos, pairs[i].second);
}

// Insert odd element if it exists
if (odd != -1)
{
    std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), odd);
    sorted.insert(pos, odd);
}
```

**How it works:**
- Insert any elements with indices beyond the largest Jacobsthal number
- For each element, use binary search to find the correct position
- Finally, if there was an unpaired element (odd length array), insert it
- The result is a fully sorted array

**Example:**
```
Continuing from above, if pairs.size() was 7 with jacobsthal = [0, 1, 1, 3, 5]:
- Insert elements with indices 6 and up (beyond jacobsthal.back() = 5)

For odd element example:
Original array: [7, 3, 9, 2, 5]
At this point: [2, 3, 7, 9]
Odd element: 5
Binary search locates position between 3 and 7
Final result: [2, 3, 5, 7, 9]
```

## Complete Example - Step by Step

Let's follow the algorithm with input: `[9, 4, 7, 2, 5, 8, 1]`

### 1. Pairing
- Pairs: [(9,4), (7,2), (8,1)]
- Odd element: 5

### 2. Extract Larger Elements
- Large elements: [9, 7, 8]

### 3. Recursively Sort Larger Elements
- Recursive call:
  - Pairs: [(9,7), (8,_)]
  - Large elements: [9]
  - Base case (size 1): [9] is already sorted
  - Insert 7 using binary search: [7, 9]
  - Insert 8 using binary search: [7, 8, 9]
- Main chain: [7, 8, 9]

### 4. Insert Smaller Elements
- Jacobsthal numbers: [0, 1, 1, 3]
- Insert first small element (pairs[0].second = 4): [4, 7, 8, 9]
- Process range (1 to 1):
  - Insert pairs[1].second = 2: [2, 4, 7, 8, 9]
- Process range (2 to 1): Empty range
- Process range (2 to 3):
  - Insert pairs[2].second = 1: [1, 2, 4, 7, 8, 9]

### 5. Insert Odd Element
- Insert 5 using binary search: [1, 2, 4, 5, 7, 8, 9]

### Final Sorted Array
- Result: [1, 2, 4, 5, 7, 8, 9]

## Time and Space Complexity

### Time Complexity Analysis
- **Best/Average/Worst Case**: O(n log n)
  - Recursion: T(n) = T(n/2) + O(n) → O(n log n)
  - Binary search insertions: Each insertion is O(log n), and we do O(n) insertions → O(n log n)
  - The Jacobsthal ordering optimizes the constant factor for comparisons

### Space Complexity
- **Auxiliary Space**: O(n)
  - Storage for pairs: O(n)
  - Storage for recursion: O(log n) stack space
  - Storage for temporary arrays: O(n)

## Advantages and Disadvantages

### Advantages
- Approaches theoretical minimum number of comparisons
- Demonstrates sophisticated algorithm design techniques
- Efficient for small inputs where comparison cost dominates

### Disadvantages
- More complex implementation than other O(n log n) algorithms
- Memory overhead due to additional data structures
- Higher constant factors for operations other than comparisons

## References

- Ford, L. R., Jr. and Johnson, S. M. (1959), "A Tournament Problem", The American Mathematical Monthly 66(5): 387–389
- Knuth, D. E. "The Art of Computer Programming, Volume 3: Sorting and Searching"
- Manacher, G. K. (1979), "The Ford-Johnson Sorting Algorithm Is Not Optimal", Journal of the ACM 26: 441–456
