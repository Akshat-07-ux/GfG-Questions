<h2><a href="https://www.geeksforgeeks.org/problems/better-string/1?page=26&sortBy=submissions">Better String</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a pair of strings of equal lengths, Geek wants to find the <strong>better string</strong>. The <strong>better string </strong>is the string having more number of <strong>distinct</strong> <strong>subsequences</strong>.<br></span><span style="font-size: 18px;">If both the strings have equal count of distinct subsequence then return&nbsp;<strong>str1</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
str1 = "gfg", str2 = "ggg"
<strong>Output:</strong> "gfg"
<strong>Explanation: "</strong>gfg" have 6 distinct subsequences whereas "ggg" have 3 distinct subsequences. 
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> str1 = "a", str2 = "b"
<strong>Output:</strong> "a"
<strong>Explanation: </strong>Both the strings have only 1 distinct subsequence. </span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>betterString()</strong> which takes <strong>str1</strong>&nbsp;and <strong>str2</strong>&nbsp;as input parameters and returns the better string.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O( N</span><span style="font-size: 18px;">&nbsp;</span><span style="font-size: 18px;">)</span><span style="font-size: 18px;">, where&nbsp;</span><strong style="font-size: 18px;">N</strong><span style="font-size: 18px;"> is the length of both provided strings.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Auxiliary Space:</strong>&nbsp;</span><span style="font-size: 18px;">O( N</span><span style="font-size: 18px;">&nbsp;</span><span style="font-size: 18px;">)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 30</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Recursion</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;