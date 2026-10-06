<h2><a href="https://leetcode.com/problems/isomorphic-strings">205. Isomorphic Strings</a></h2><h3>Easy</h3><hr><p>Given two strings <code>s</code> and <code>t</code>, <em>determine if they are isomorphic</em>.</p>

<p>Two strings <code>s</code> and <code>t</code> are isomorphic if the characters in <code>s</code> can be replaced to get <code>t</code>.</p>

<p>All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;egg&quot;, t = &quot;add&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>The strings <code>s</code> and <code>t</code> can be made identical by:</p>

<ul>
	<li>Mapping <code>&#39;e&#39;</code> to <code>&#39;a&#39;</code>.</li>
	<li>Mapping <code>&#39;g&#39;</code> to <code>&#39;d&#39;</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;f11&quot;, t = &quot;b23&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>The strings <code>s</code> and <code>t</code> can not be made identical as <code>&#39;1&#39;</code> needs to be mapped to both <code>&#39;2&#39;</code> and <code>&#39;3&#39;</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;paper&quot;, t = &quot;title&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>t.length == s.length</code></li>
	<li><code>s</code> and <code>t</code> consist of any valid ascii character.</li>
</ul>


## Approach

We maintain **two maps**:

```cpp
map<char, char> s1;
map<char, char> s2;
```

### 1. `s1` — Mapping from `s` to `t`

```text
s1[ch1] = ch2
```

It ensures that a character from `s` always maps to the same character in `t`.

### 2. `s2` — Mapping from `t` to `s`

```text
s2[ch2] = ch1
```

This prevents two different characters from `s` mapping to the same character in `t`.

For example:

```text
s = "ab"
t = "aa"
```

We get:

```text
a → a
b → a
```

This is invalid because both `a` and `b` cannot map to the same character.

The second map detects this.

---

## Algorithm

For every index `i`:

1. Take:

   ```cpp
   ch1 = s[i]
   ch2 = t[i]
   ```

2. Check whether `ch1` was already mapped.

   * If yes, its existing mapping must be `ch2`.
   * Otherwise, return `false`.

3. Check whether `ch2` was already mapped.

   * If yes, it must be mapped back to `ch1`.
   * Otherwise, return `false`.

4. Store both mappings:

   ```cpp
   s1[ch1] = ch2;
   s2[ch2] = ch1;
   ```

5. If all characters satisfy the mapping, return `true`.

---

## Code

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> s1;
        map<char, char> s2;

        for (int i = 0; i < s.size(); i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if (s1.find(ch1) != s1.end() && s1[ch1] != ch2 ||
                s2.find(ch2) != s2.end() && s2[ch2] != ch1)
                return false;

            // Mapping the character if not mapped
            s1[ch1] = ch2;
            s2[ch2] = ch1;
        }

        return true;
    }
};
```

---

## Dry Run

### Example

```text
s = "paper"
t = "title"
```

| `i` | `s[i]` | `t[i]` | Mapping |
| --: | :----: | :----: | :------ |
|   0 |    p   |    t   | p → t   |
|   1 |    a   |    i   | a → i   |
|   2 |    p   |    t   | p → t ✓ |
|   3 |    e   |    l   | e → l   |
|   4 |    r   |    e   | r → e   |

All mappings are consistent.

Therefore:

```text
Output: true
```

---

## Invalid Example

```text
s = "foo"
t = "bar"
```

Mappings start as:

```text
f → b
o → a
```

At the last character:

```text
o → r
```

But `o` was already mapped to `a`.

So the mapping is inconsistent.

```text
Output: false
```

---

## Complexity Analysis

Using `map<char, char>`:

### Time Complexity

Each `map` operation takes:

```text
O(log K)
```

where `K` is the number of distinct characters.

For `n` characters:

```text
O(n log K)
```

Since the character set is limited, this can effectively be considered:

```text
O(n)
```

### Space Complexity

We store mappings for the characters:

```text
O(K)
```

For a fixed character set, this is effectively:

```text
O(1)
```

---

## Key Idea

The most important concept is:

> **Mapping must work in both directions.**

We need:

```text
s → t
```

and

```text
t → s
```

The first map checks **consistent mapping**, while the second map checks **one-to-one mapping**.

```text
s1: s → t
s2: t → s
```

Both together ensure that the strings are truly isomorphic.

