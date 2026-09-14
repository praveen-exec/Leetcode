<h2><a href="https://leetcode.com/problems/rotate-string">812. Rotate String</a></h2><h3>Easy</h3><hr><p>Given two strings <code>s</code> and <code>goal</code>, return <code>true</code> <em>if and only if</em> <code>s</code> <em>can become</em> <code>goal</code> <em>after some number of <strong>shifts</strong> on</em> <code>s</code>.</p>

<p>A <strong>shift</strong> on <code>s</code> consists of moving the leftmost character of <code>s</code> to the rightmost position.</p>

<ul>
	<li>For example, if <code>s = &quot;abcde&quot;</code>, then it will be <code>&quot;bcdea&quot;</code> after one shift.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "abcde", goal = "cdeab"
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcde", goal = "abced"
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, goal.length &lt;= 100</code></li>
	<li><code>s</code> and <code>goal</code> consist of lowercase English letters.</li>
</ul>



# 🔄 Rotate String

## 📌 Problem

Given two strings `s` and `goal`, determine whether `s` can be converted into `goal` by repeatedly moving the **first character to the end**.

### Example

```text
s = "abcde"

After 1 shift → "bcdea"
After 2 shifts → "cdeab"
After 3 shifts → "deabc"
After 4 shifts → "eabcd"
```

If:

```text
goal = "deabc"
```

then the answer is:

```text
true
```

---

# 💭 Approach 1: `s + s` and `find()`

## Intuition

Instead of actually performing every rotation, we can use one important observation:

If `goal` is a rotation of `s`, then `goal` will always appear inside:

```text
s + s
```

For example:

```text
s = "abcde"

s + s = "abcdeabcde"
```

Inside this string, we can find:

```text
abcde
bcdea
cdeab
deabc
eabcd
```

Therefore, if `goal` exists inside `s + s`, it must be a valid rotation.

---

## Algorithm

1. Check whether the lengths of `s` and `goal` are equal.
2. Create `s1 = s + s`.
3. Search for `goal` inside `s1` using `find()`.
4. If found, return `true`.
5. Otherwise, return `false`.

---

## Code

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.length();
        int m = goal.length();

        // Different lengths cannot be rotations
        if(n != m)
            return false;

        // All rotations can be found in s + s
        string s1 = s + s;

        // Check whether goal exists
        return s1.find(goal) != string::npos;
    }
};
```

---

## 🔍 `find()` Explanation

```cpp
s1.find(goal)
```

returns the starting index if `goal` is found.

For example:

```cpp
string s1 = "abcdeabcde";

s1.find("deabc");
```

Output:

```text
3
```

So:

```cpp
s1.find(goal) != string::npos
```

means:

> `goal` was successfully found.

If it is not found:

```cpp
s1.find(goal) == string::npos
```

---

# 💭 Approach 2: Simulate Every Rotation

## Intuition

We can directly perform the shifts one by one.

Suppose:

```text
s = "abcde"
```

To perform one left shift:

```cpp
s = s.substr(1) + s[0];
```

### Breakdown

```cpp
s.substr(1)
```

gives:

```text
"bcde"
```

and:

```cpp
s[0]
```

is:

```text
'a'
```

Therefore:

```text
"bcde" + "a"
```

becomes:

```text
"bcdea"
```

This is exactly one rotation.

---

## Algorithm

1. Check whether both strings have the same length.
2. Perform a left rotation.
3. Compare the rotated string with `goal`.
4. If equal, return `true`.
5. Repeat for all possible rotations.
6. If no rotation matches, return `false`.

---

## Code

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.length();
        int m = goal.length();

        // Different lengths cannot be rotations
        if(n != m)
            return false;

        for(int i = 0; i < n; i++) {

            // Move first character to the end
            s = s.substr(1) + s[0];

            // Check current rotation
            if(s == goal)
                return true;
        }

        return false;
    }
};
```

---

# 🧪 Dry Run — Approach 2

### Input

```text
s = "abcde"
goal = "deabc"
```

### Initial

```text
abcde
```

### Rotation 1

```text
bcdea
```

```text
bcdea != deabc
```

### Rotation 2

```text
cdeab
```

```text
cdeab != deabc
```

### Rotation 3

```text
deabc
```

```text
deabc == deabc
```

Therefore:

```text
true
```

---

# ⚠️ Edge Case

### Different lengths

```text
s = "abc"
goal = "abcd"
```

Clearly, rotation is impossible.

So:

```cpp
if(n != m)
    return false;
```

is necessary.

---

# 📊 Complexity

| Approach              |              Time | Space |
| --------------------- | ----------------: | ----: |
| `s + s` + `find()`    | O(n²) worst case* |  O(n) |
| `substr()` simulation |             O(n²) |  O(n) |

*The exact complexity of `find()` depends on the underlying library implementation.

---

# ⚔️ Which Approach Is Better?

### Approach 1 — `s + s`

```cpp
(s + s).find(goal)
```

is generally the **preferred solution**.

Why?

* Short
* Elegant
* Uses an important string observation
* No need to manually simulate rotations

### Approach 2 — Simulation

```cpp
s = s.substr(1) + s[0];
```

is useful when learning because it shows exactly how a rotation happens.

---

# Key Takeaway

Remember this trick:

```text
If goal is a rotation of s

        ↓

goal will exist in

        ↓

      s + s
```

So the main idea is:

```cpp
s + s
```

and then:

```cpp
find(goal)
```

### One-line version

```cpp
return s.length() == goal.length() &&
       (s + s).find(goal) != string::npos;
```

This is the key pattern to remember for the **Rotate String** problem.
