<h2><a href="https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1?page=31&sortBy=submissions">Row with Minimum 1s</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a 2D <strong>binary matrix</strong>(1-based indexed)<strong> mat</strong>&nbsp;of dimensions <strong>nxm </strong>, determine the <strong>row</strong> that contains the <strong>minimum number </strong>of<strong> 1's</strong>.<br><strong>Note: </strong>The matrix contains only <strong>1's</strong> and <strong>0's</strong>. Also, if two or more rows contain the <strong>minimum number</strong> of <strong>1's</strong>, the answer is the <strong>lowest</strong> of those<strong> indices</strong>.</span></p>
<p><strong><span style="font-size: 18px;">Examples :</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>mat = [[1, 1, 1, 1], [1, 1, 0, 0], [0, 0, 1, 1], [1, 1, 1, 1]]
<strong>Output: </strong>2
<strong>Explanation: </strong>Rows 2 and 3 contain the minimum number of 1's (2 each). Since, row 2 is less than row 3. Thus, the answer is 2.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>mat = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
<strong>Output: </strong>1
<strong>Explanation: </strong>All the rows contain the same number of 1's (0 each). Among them, index 1 is the smallest, so the answer is 1.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n,m &lt;= 1000</span></p>
<p><span style="font-size: 18px;">0 &lt;= mat[i][j] &lt;= 1</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;