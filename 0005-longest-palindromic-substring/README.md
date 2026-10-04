<h2><a href="https://leetcode.com/problems/longest-palindromic-substring">5. Longest Palindromic Substring</a></h2><h3>Medium</h3><hr><p>Given a string <code>s</code>, return <em>the longest</em> <span data-keyword="palindromic-string"><em>palindromic</em></span> <span data-keyword="substring-nonempty"><em>substring</em></span> in <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;babad&quot;
<strong>Output:</strong> &quot;bab&quot;
<strong>Explanation:</strong> &quot;aba&quot; is also a valid answer.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cbbd&quot;
<strong>Output:</strong> &quot;bb&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consist of only digits and English letters.</li>
</ul>



# Longest Palindromic Substring

## Problem

Given a string `s`, find the **longest palindromic substring** in `s`.

A palindrome is a string that reads the same forward and backward.

### Examples

```text
Input:  "babad"
Output: "bab"
```

```text
Input:  "cbbd"
Output: "bb"
```

---

## Approach: Expand Around Center

Every palindrome has a **center**.

There are two types of palindromes:

### 1. Odd Length

Example:

```text
b a b
  ↑
center
```

The center is a single character.

For every index `i`:

```cpp
start = i;
end = i;
```

Then expand in both directions:

```cpp
start--;
end++;
```

We continue as long as:

```cpp
s[start] == s[end]
```

---

### 2. Even Length

Example:

```text
a b b a
  ↑ ↑
center
```

The center lies between two characters.

For every index `i`:

```cpp
start = i;
end = i + 1;
```

Then expand:

```cpp
start--;
end++;
```

Again, we continue while:

```cpp
s[start] == s[end]
```

---

## Why Do We Check Both?

Consider:

```text
"babad"
```

The longest palindrome is:

```text
"bab"
```

which has **odd length**.

But:

```text
"cbbd"
```

has:

```text
"bb"
```

which has **even length**.

Therefore, for every index, we check both:

```text
Odd  →  i, i
Even →  i, i+1
```

---

## Code

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        int bestStart = 0;
        int bestLen = 1;

        for(int i = 0; i < n; i++) {

            // EVEN length palindrome
            // center = i and i+1
            int start = i;
            int end = i + 1;

            while(start >= 0 && end < n && s[start] == s[end]) {

                if(end - start + 1 > bestLen) {
                    bestStart = start;
                    bestLen = end - start + 1;
                }

                start--;
                end++;
            }


            // ODD length palindrome
            // center = i
            start = i;
            end = i;

            while(start >= 0 && end < n && s[start] == s[end]) {

                if(end - start + 1 > bestLen) {
                    bestStart = start;
                    bestLen = end - start + 1;
                }

                start--;
                end++;
            }
        }

        return s.substr(bestStart, bestLen);
    }
};
```

---

## Dry Run

Consider:

```text
s = "cbbd"
```

For `i = 1`:

```text
c b b d
  ↑ ↑
  i i+1
```

We check:

```text
s[1] == s[2]
b == b
```

So we found:

```text
"bb"
```

Now expand:

```text
c b b d
↑     ↑
```

Check:

```text
c == d
```

False.

Therefore:

```text
Longest palindrome = "bb"
```

---

## Important Part

This condition:

```cpp
if(end - start + 1 > bestLen)
```

means:

> Update the answer only when the current palindrome is longer than the previous longest palindrome.

We store:

```cpp
bestStart
```

→ starting index of the longest palindrome.

```cpp
bestLen
```

→ length of the longest palindrome.

Finally:

```cpp
return s.substr(bestStart, bestLen);
```

returns the answer.

---

## Complexity

### Time Complexity

```text
O(n²)
```

There are `n` possible centers, and from each center we can expand up to `O(n)` characters.

Therefore:

```text
O(n) × O(n) = O(n²)
```

### Space Complexity

```text
O(1)
```

Only a few variables are used. No extra array, vector, or string is created for storing all palindromes.

---

## Key Takeaway

Remember the **Expand Around Center** pattern:

```text
ODD:
    i
    ↓
  ← i →

EVEN:
   i  i+1
   ↓   ↓
  ←     →
```

For every index:

```cpp
// Odd
start = i;
end = i;

// Even
start = i;
end = i + 1;
```

Then:

```cpp
while(start >= 0 && end < n && s[start] == s[end]) {
    start--;
    end++;
}
```

**Pattern to remember:**

> **Choose center → Compare left & right → Expand → Update longest**
