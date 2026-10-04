<h2><a href="https://leetcode.com/problems/happy-number">202. Happy Number</a></h2><h3>Easy</h3><hr><p>Write an algorithm to determine if a number <code>n</code> is happy.</p>

<p>A <strong>happy number</strong> is a number defined by the following process:</p>

<ul>
	<li>Starting with any positive integer, replace the number by the sum of the squares of its digits.</li>
	<li>Repeat the process until the number equals 1 (where it will stay), or it <strong>loops endlessly in a cycle</strong> which does not include 1.</li>
	<li>Those numbers for which this process <strong>ends in 1</strong> are happy.</li>
</ul>

<p>Return <code>true</code> <em>if</em> <code>n</code> <em>is a happy number, and</em> <code>false</code> <em>if not</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 19
<strong>Output:</strong> true
<strong>Explanation:</strong>
1<sup>2</sup> + 9<sup>2</sup> = 82
8<sup>2</sup> + 2<sup>2</sup> = 68
6<sup>2</sup> + 8<sup>2</sup> = 100
1<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>



# Happy Number

## Problem

A **Happy Number** is a number defined by the following process:

1. Start with any positive integer.
2. Replace the number by the sum of the squares of its digits.
3. Repeat the process.
4. If the number becomes `1`, it is a **Happy Number**.
5. If the process enters a cycle that does not include `1`, the number is **not a Happy Number**.

### Example

For `19`:

```text
19
→ 1² + 9²
→ 1 + 81
→ 82
→ 8² + 2²
→ 64 + 4
→ 68
→ 36 + 64
→ 100
→ 1
```

Therefore, `19` is a **Happy Number**.

---

## Approach

We use a `set` to keep track of numbers that we have already seen.

### Algorithm

1. Create an empty set `seen`.
2. While `n != 1`:

   * If `n` is already present in `seen`, a cycle exists.
   * Return `false`.
   * Otherwise, insert `n` into `seen`.
   * Replace `n` with the sum of the squares of its digits.
3. If `n` becomes `1`, return `true`.

### Why do we need `set`?

Sometimes the sequence never reaches `1` and starts repeating.

For example:

```text
2 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20
  → 4 → 16 → 37 → ...
```

Here `4` appears again, which means we are stuck in a cycle.

Therefore, the number is **not happy**.

---

## Code

```cpp
class Solution {
public:
    // Time: O(log n)
    // Space: O(log n)
    int nextSum(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        set<int> seen;

        while (n != 1) {

            // Cycle detected
            if (seen.count(n))
                return false;

            seen.insert(n);

            // Generate next number
            n = nextSum(n);
        }

        return true;
    }
};
```


---

## Dry Run

### Input: `19`

```text
seen = {}

n = 19
19 not in seen
insert 19

nextSum(19) = 1² + 9² = 82
```

```text
n = 82
82 not in seen
insert 82

nextSum(82) = 8² + 2² = 68
```

```text
n = 68
68 not in seen
insert 68

nextSum(68) = 6² + 8² = 100
```

```text
n = 100
100 not in seen
insert 100

nextSum(100) = 1² + 0² + 0² = 1
```

Now:

```text
n == 1
```

Therefore:

```text
Output: true
```

---

## Complexity Analysis

Let `d` be the number of digits in `n`.

### `nextSum()`

We process every digit once:

```text
O(d)
```

Since:

```text
d = O(log n)
```

Therefore:

```text
Time = O(log n)
```

### `isHappy()`

The sequence reaches either `1` or a cycle. The intermediate values become small, so the number of iterations is bounded.

For standard complexity analysis, this approach is commonly described as:

```text
Time: O(log n)
Space: O(log n)
```

The `set` requires extra space to store previously visited values.

---

## Key Idea

The most important concept is:

> **Happy Number = Repeatedly calculate sum of squares of digits + detect cycle.**

We use a `set` to answer:

```text
"Have I seen this number before?"
```

If **yes** → cycle → `false`

If we reach **1** → `true`

