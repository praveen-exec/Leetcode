<h2><a href="https://leetcode.com/problems/reverse-words-in-a-string">151. Reverse Words in a String</a></h2><h3>Medium</h3><hr><p>Given an input string <code>s</code>, reverse the order of the <strong>words</strong>.</p>

<p>A <strong>word</strong> is defined as a sequence of non-space characters. The <strong>words</strong> in <code>s</code> will be separated by at least one space.</p>

<p>Return <em>a string of the words in reverse order concatenated by a single space.</em></p>

<p><b>Note</b> that <code>s</code> may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;the sky is blue&quot;
<strong>Output:</strong> &quot;blue is sky the&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;  hello world  &quot;
<strong>Output:</strong> &quot;world hello&quot;
<strong>Explanation:</strong> Your reversed string should not contain leading or trailing spaces.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a good   example&quot;
<strong>Output:</strong> &quot;example good a&quot;
<strong>Explanation:</strong> You need to reduce multiple spaces between two words to a single space in the reversed string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> contains English letters (upper-case and lower-case), digits, and spaces <code>&#39; &#39;</code>.</li>
	<li>There is <strong>at least one</strong> word in <code>s</code>.</li>
</ul>

<p>&nbsp;</p>
<p><b data-stringify-type="bold">Follow-up:&nbsp;</b>If the string data type is mutable in your language, can&nbsp;you solve it&nbsp;<b data-stringify-type="bold">in-place</b>&nbsp;with&nbsp;<code data-stringify-type="code">O(1)</code>&nbsp;extra space?</p>



# Reverse Words in a String

## Problem

Given a string `s`, reverse the order of the words in the string.

### Example

**Input:**

```text
s = "the sky is blue"
```

**Output:**

```text
"blue is sky the"
```

---

## Approach

We use the following steps:

### 1. Reverse the complete string

```cpp
reverse(s.begin(), s.end());
```

For example:

```text
"the sky is blue"
```

becomes:

```text
"eulb si yks eht"
```

Now the words are present in **reverse order**, but each individual word is also reversed.

---

### 2. Tokenize the string

We use `stringstream`:

```cpp
stringstream ss(s);
string token;

while (ss >> token) {
    tokens.push_back(token);
}
```

The `>>` operator separates words using whitespace.

It also automatically handles:

* Multiple spaces
* Leading spaces
* Trailing spaces

For example:

```text
"hello   world"
```

is tokenized as:

```text
hello
world
```

---

### 3. Reverse each word

After reversing the complete string, each word is reversed.

For example:

```text
"eulb si yks eht"
```

So we reverse every token:

```cpp
reverse(tokens[i].begin(), tokens[i].end());
```

This gives:

```text
blue
is
sky
the
```

---

### 4. Build the answer

We append every reversed word:

```cpp
ans += " " + tokens[i];
```

For:

```text
blue
is
sky
the
```

we get:

```text
" blue is sky the"
```

Finally:

```cpp
return ans.substr(1);
```

removes the extra space at the beginning:

```text
"blue is sky the"
```

---

## Code

```cpp
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        vector<string> tokens;

        stringstream ss(s);
        string token = "";

        while (ss >> token) {
            tokens.push_back(token);
        }

        string ans = "";

        for (int i = 0; i < tokens.size(); i++) {
            reverse(tokens[i].begin(), tokens[i].end());
            ans += " " + tokens[i];
        }

        return ans.substr(1);
    }
};
```

---

## Dry Run

### Input

```text
"the sky is blue"
```

### Reverse complete string

```text
"eulb si yks eht"
```

### Tokenize

```text
tokens = ["eulb", "si", "yks", "eht"]
```

### Reverse each token

```text
["blue", "is", "sky", "the"]
```

### Build answer

```text
" blue is sky the"
```

### Remove first space

```text
"blue is sky the"
```

---

## Why do we reverse twice?

This is the main idea of the solution.

### First reverse

```cpp
reverse(s.begin(), s.end());
```

Changes the **order of words**:

```text
the sky is blue
        ↓
blue is sky the
```

But it also reverses the characters of each word:

```text
eulb si yks eht
```

### Second reverse

We reverse every individual word:

```cpp
reverse(tokens[i].begin(), tokens[i].end());
```

So:

```text
eulb → blue
si   → is
yks  → sky
eht  → the
```

Therefore, we get:

```text
blue is sky the
```

---

## Complexity

Let `n` be the length of the string.

### Time Complexity

```text
O(n)
```

* Reverse complete string → `O(n)`
* Tokenization → `O(n)`
* Reverse all words → `O(n)`
* Construct answer → `O(n)`

Overall:

```text
O(n)
```

### Space Complexity

```text
O(n)
```

because we store the tokens and the resulting string.

---

## Key Takeaway

The trick is:

```text
Reverse entire string
        ↓
Tokenize words
        ↓
Reverse every word
        ↓
Build answer
```

**Reverse the whole string → reverse each word → words are in reversed order.**

