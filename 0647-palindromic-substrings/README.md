<h2><a href="https://leetcode.com/problems/palindromic-substrings">647. Palindromic Substrings</a></h2><h3>Medium</h3><hr><p>Given a string <code>s</code>, return <em>the number of <strong>palindromic substrings</strong> in it</em>.</p>

<p>A string is a <strong>palindrome</strong> when it reads the same backward as forward.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within the string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abc&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> Three palindromic strings: &quot;a&quot;, &quot;b&quot;, &quot;c&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aaa&quot;
<strong>Output:</strong> 6
<strong>Explanation:</strong> Six palindromic strings: &quot;a&quot;, &quot;a&quot;, &quot;a&quot;, &quot;aa&quot;, &quot;aa&quot;, &quot;aaa&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>



# SOLUTION

# Count Palindromic Substrings — Brute Force

## Problem

Given a string `s`, count the number of **palindromic substrings** in the string.

A palindrome is a string that reads the same from left to right and right to left.

### Example

```text
Input:
s = "aaa"

Palindromic substrings:
"a", "a", "a", "aa", "aa", "aaa"

Output:
6
```

---

## Approach: Brute Force

The brute force approach is simple:

1. Generate **all possible substrings** of the given string.
2. Check whether each substring is a palindrome.
3. If it is a palindrome, increment the count.
4. Return the final count.

### Basic Idea

```text
String
  ↓
Generate all substrings
  ↓
Check each substring
  ↓
Is it a palindrome?
  ↓
Yes → count++
  ↓
Return count
```

---

## Generating All Substrings

Two nested loops are used:

```cpp
for (int i = 0; i < s.length(); i++) {
    for (int j = i; j < s.length(); j++) {
```

Here:

* `i` = starting index
* `j` = ending index

For each pair of `i` and `j`, we create a substring:

```cpp
string temp = s.substr(i, j - i + 1);
```

### `substr()` Explanation

The syntax is:

```cpp
s.substr(start, length)
```

Therefore:

```cpp
s.substr(i, j - i + 1)
```

means:

```text
Start  = i
Length = j - i + 1
```

For example:

```text
s = "abcde"
i = 1
j = 3
```

Then:

```cpp
s.substr(1, 3)
```

gives:

```text
"bcd"
```

---

## Checking Palindrome

A separate function `ispalindrome()` checks whether a substring is a palindrome.

Two pointers are used:

```cpp
int start = 0;
int end = s.length() - 1;
```

The characters at both ends are compared.

```cpp
if (s[start++] != s[end--])
    return false;
```

If the characters are different, the string is not a palindrome.

If all corresponding characters match:

```cpp
return true;
```

### Example

For:

```text
"abba"
```

```text
a b b a
↑     ↑
start end
```

Compare:

```text
a == a
b == b
```

Therefore `"abba"` is a palindrome.

---

## Complete Code

```cpp
class Solution {
public:

    bool ispalindrome(string &s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }

        return true;
    }

    int countSubstrings(string s) {

        int count = 0;

        // Generate all substrings
        for (int i = 0; i < s.length(); i++) {

            for (int j = i; j < s.length(); j++) {

                // Create substring
                string temp = s.substr(i, j - i + 1);

                // Check if palindrome
                if (ispalindrome(temp)) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

---

## Dry Run

Consider:

```text
s = "aba"
```

### Generate substrings

For `i = 0`:

```text
"a"
"ab"
"aba"
```

For `i = 1`:

```text
"b"
"ba"
```

For `i = 2`:

```text
"a"
```

Total substrings:

```text
6
```

Now check each:

| Substring | Palindrome? |
| --------- | ----------- |
| `"a"`     | Yes         |
| `"ab"`    | No          |
| `"aba"`   | Yes         |
| `"b"`     | Yes         |
| `"ba"`    | No          |
| `"a"`     | Yes         |

Therefore:

```text
Answer = 4
```

---

## Why Is This Brute Force?

This solution does not use any special optimization.

It simply:

```text
Try every substring
       ↓
Check every substring
       ↓
Count the palindromes
```

We check even the substrings that are obviously not palindromes.

That is why this is called the **Brute Force approach**.

---

## Complexity Analysis

There are `O(n²)` possible substrings.

For every substring, checking whether it is a palindrome can take `O(n)` time.

Therefore:

### Time Complexity

```text
O(n³)
```

### Space Complexity

The temporary substring can contain up to `n` characters:

```text
O(n)
```

---

## Key Points

* Use **two nested loops** to generate all substrings.
* Use `substr(i, j - i + 1)` to create each substring.
* Use **two pointers** to check whether the substring is a palindrome.
* Increment `count` whenever a palindrome is found.
* This is a **Brute Force** solution.
* Time complexity is **O(n³)**.
* Space complexity is **O(n)**.

## Summary

```text
             Given String
                  ↓
          Generate substrings
                  ↓
          Check palindrome
             ↙          ↘
           Yes           No
            ↓             ↓
         count++        Ignore
            ↓             ↓
            └──────┬──────┘
                   ↓
              Next substring
                   ↓
              Return count
```


# Count Palindromic Substrings ==> OPTIMIZED

## Problem

Given a string `s`, count how many **palindromic substrings** are present in the string.

A palindrome is a string that reads the same from left to right and right to left.

### Example

```text
Input:  s = "aaa"

Palindromic substrings:
"a"
"a"
"a"
"aa"
"aa"
"aaa"

Output: 6
```

---

## Approach: Expand Around Center

Every palindrome has a **center**.

There are two possible types:

### 1. Odd Length Palindrome

Example:

```text
"aba"
  ↑
center
```

The center is a single character.

We initialize:

```cpp
left = center;
right = center;
```

Then expand in both directions while the characters are equal.

```text
    b
   / \
  a   a
```

---

### 2. Even Length Palindrome

Example:

```text
"abba"
   ↑
 center is between the two b's
```

Here, the center lies between two characters.

We initialize:

```cpp
left = center;
right = center + 1;
```

Then expand outward.

```text
a b | b a
  ↑   ↑
left  right
```

---

## Algorithm

For every index `center`:

1. Treat `center` as the center of an odd-length palindrome.
2. Expand left and right.
3. Every time both characters are equal, increment `count`.
4. Treat the gap between `center` and `center + 1` as the center of an even-length palindrome.
5. Expand again.
6. Return the total count.

---

## Code

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        // Check for all centers
        for (int center = 0; center < n; center++) {

            // Odd length palindrome
            int left = center;
            int right = center;

            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }

            // Even length palindrome
            left = center;
            right = center + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};
```

---

## Dry Run

Consider:

```text
s = "aba"
```

### Center = 0

Odd:

```text
a
```

Palindrome → `count = 1`

No more expansion possible.

Even:

```text
a | b
```

Not equal → stop.

---

### Center = 1

Odd:

```text
 b
```

Palindrome → `count = 2`

Expand:

```text
a b a
↑   ↑
```

`a == a`

Palindrome → `count = 3`

---

### Center = 2

Odd:

```text
a
```

Palindrome → `count = 4`

So:

```text
Output = 4
```

The palindromic substrings are:

```text
"a"
"b"
"a"
"aba"
```

---

## Why We Check Both Cases

If we only checked:

```cpp
left = center;
right = center;
```

we would find only **odd-length** palindromes.

For example:

```text
aba
abcba
```

But we would miss:

```text
aa
abba
```

Therefore, we need both:

```cpp
// Odd
left = center;
right = center;
```

and:

```cpp
// Even
left = center;
right = center + 1;
```

---

## Complexity

There are `n` possible centers.

For each center, we expand at most `n` characters.

### Time Complexity

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

No extra array or vector is required.

---

## Key Idea

Remember:

```text
Every palindrome has a center.
          ↓
Try every center.
          ↓
Expand left and right.
          ↓
If characters match → palindrome found.
          ↓
Count it.
```

### Important

```text
Odd palindrome:
left = center
right = center

Even palindrome:
left = center
right = center + 1
```

This technique is called **Expand Around Center**.
