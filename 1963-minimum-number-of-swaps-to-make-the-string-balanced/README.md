<h2><a href="https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced">2095. Minimum Number of Swaps to Make the String Balanced</a></h2><h3>Medium</h3><hr><p>You are given a <strong>0-indexed</strong> string <code>s</code> of <strong>even</strong> length <code>n</code>. The string consists of <strong>exactly</strong> <code>n / 2</code> opening brackets <code>&#39;[&#39;</code> and <code>n / 2</code> closing brackets <code>&#39;]&#39;</code>.</p>

<p>A string is called <strong>balanced</strong> if and only if:</p>

<ul>
	<li>It is the empty string, or</li>
	<li>It can be written as <code>AB</code>, where both <code>A</code> and <code>B</code> are <strong>balanced</strong> strings, or</li>
	<li>It can be written as <code>[C]</code>, where <code>C</code> is a <strong>balanced</strong> string.</li>
</ul>

<p>You may swap the brackets at <strong>any</strong> two indices <strong>any</strong> number of times.</p>

<p>Return <em>the <strong>minimum</strong> number of swaps to make </em><code>s</code> <em><strong>balanced</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;][][&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can make the string balanced by swapping index 0 with index 3.
The resulting string is &quot;[[]]&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;]]][[[&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can do the following to make the string balanced:
- Swap index 0 with index 4. s = &quot;[]][][&quot;.
- Swap index 1 with index 5. s = &quot;[[][]]&quot;.
The resulting string is &quot;[[][]]&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;[]&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> The string is already balanced.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>6</sup></code></li>
	<li><code>n</code> is even.</li>
	<li><code>s[i]</code> is either <code>&#39;[&#39; </code>or <code>&#39;]&#39;</code>.</li>
	<li>The number of opening brackets <code>&#39;[&#39;</code> equals <code>n / 2</code>, and the number of closing brackets <code>&#39;]&#39;</code> equals <code>n / 2</code>.</li>
</ul>


# Minimum Swaps to Balance Brackets

## Problem

Given a string `s` containing only `[` and `]`, find the **minimum number of swaps** required to make the bracket string balanced.

If the length of the string is odd, it is impossible to balance the string, so return `-1`.

### Example

```text
Input:  s = "[]][]["

Output: 1
```

By swapping the appropriate brackets, the string can be made balanced.

---

# Solution 1: Using Stack

### Approach

We use a stack to keep track of unmatched opening brackets `[`.

For every character:

* If it is `[`, push it into the stack.
* If it is `]` and the stack is not empty, it matches an existing `[`, so pop the stack.
* If it is `]` and the stack is empty, it is an **unmatched closing bracket**. Increase `c`.

At the end:

```text
c = number of unmatched closing brackets
```

Each swap can fix two unmatched closing brackets, so the answer is:

```cpp
(c + 1) / 2
```

which is equivalent to:

```text
ceil(c / 2)
```

### Code

```cpp
class Solution {
public:
    int minSwaps(string s) {

        // If string length is odd
        if(s.length() & 1)
            return -1;

        stack<char> st;
        int n = s.length();

        int c = 0; // count of unmatched closing brackets

        for(int i = 0; i < n; i++) {

            if(s[i] == '[') {
                st.push('[');
            }

            // s[i] = ']' and stack is not empty
            else if(s[i] == ']' && !st.empty()) {
                st.pop();
            }

            // unmatched closing bracket
            else {
                c++;
            }
        }

        return (c + 1) / 2;
    }
};
```

## Dry Run

Consider:

```text
s = "]]][[["
```

| Character | Stack | `c` |
| --------- | ----- | --: |
| `]`       | empty |   1 |
| `]`       | empty |   2 |
| `]`       | empty |   3 |
| `[`       | `[`   |   3 |
| `[`       | `[[`  |   3 |
| `[`       | `[[[` |   3 |

Therefore:

```text
c = 3
```

Minimum swaps:

```text
(c + 1) / 2
= (3 + 1) / 2
= 2
```

### Complexity

```text
Time:  O(n)
Space: O(n)
```

The stack can contain up to `n` opening brackets.

---

# Solution 2: Optimized — Without Stack

We can optimize the space from `O(n)` to `O(1)`.

Instead of storing every `[`, maintain a `balance`.

### Meaning of `balance`

```text
'[' → balance++
']' → balance--
```

If `balance` becomes negative, it means we have encountered an unmatched `]`.

We count it in `c` and reset the balance to `0`.

### Code

```cpp
class Solution {
public:
    int minSwaps(string s) {

        int balance = 0;
        int c = 0;   // unmatched closing brackets

        for(char ch : s) {

            if(ch == '[') {
                balance++;
            }
            else {
                balance--;

                // Extra closing bracket
                if(balance < 0) {
                    c++;
                    balance = 0;
                }
            }
        }

        return (c + 1) / 2;
    }
};
```

## Dry Run

For:

```text
s = "]]][[["
```

| Character | Balance | Unmatched `c` |
| --------- | ------: | ------------: |
| `]`       |  -1 → 0 |             1 |
| `]`       |  -1 → 0 |             2 |
| `]`       |  -1 → 0 |             3 |
| `[`       |       1 |             3 |
| `[`       |       2 |             3 |
| `[`       |       3 |             3 |

Therefore:

```text
c = 3
```

Answer:

```text
(c + 1) / 2 = 2
```

### Complexity

```text
Time:  O(n)
Space: O(1)
```

---

# Why `(c + 1) / 2`?

Suppose there are `c` unmatched closing brackets.

Every swap can fix **two** unmatched closing brackets.

Therefore:

```text
c = 1 → 1 swap
c = 2 → 1 swap
c = 3 → 2 swaps
c = 4 → 2 swaps
c = 5 → 3 swaps
```

This is:

```cpp
ceil(c / 2)
```

Using integer arithmetic:

```cpp
(c + 1) / 2
```

---

# Comparison

| Approach | Time   | Space  |
| -------- | ------ | ------ |
| Stack    | `O(n)` | `O(n)` |
| Balance  | `O(n)` | `O(1)` |

### Key Takeaway

The **stack solution is intuitive** because it explicitly stores unmatched `[` brackets.

The **balance solution is optimized** because we only need to know how many unmatched brackets exist, not store them.

```text
Stack → O(n) space
Balance → O(1) space
```
