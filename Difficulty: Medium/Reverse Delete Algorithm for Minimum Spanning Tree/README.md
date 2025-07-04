<h2><a href="https://www.geeksforgeeks.org/problems/reverse-delete-algorithm-for-minimum-spanning-tree1158/1?page=6&category=Graph&sortBy=submissions">Reverse Delete Algorithm for Minimum Spanning Tree</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Reverse Delete algorithm is closely related to Kruskal’s algorithm. In Reverse Delete algorithm, we sort all edges in decreasing order of their weights. After sorting, we one by one pick edges in decreasing order. We include current picked edge if excluding current edge causes disconnection in current graph. The main idea is delete edge if its deletion does not lead to disconnection of graph. Your task is to print the value of total weight of Minimum Spanning Tree formed.</span></p>
<p><strong><span style="font-size: 18px;">NOTE: Array elements represent the triplets U , V edge and Weight of that edge. Please read test cases explanation for more details.</span></strong></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;"><strong>V = </strong>4, <strong>E = </strong>5</span>
<span style="font-size: 18px;"><strong>Arr[] = </strong>{0, 1, 10, 0, 2, 6, 0, 3, 5, 1, 3, 15, 2, 3, 4}</span>
<span style="font-size: 18px;"><strong>Output:</strong></span>
<span style="font-size: 18px;">19</span>
<span style="font-size: 18px;"><strong>Explanation:<br><br></strong>Array elements represent the triplets are :</span></pre>
<pre><span>U V Weight<br>0 1  10<br>0 2  6<br>0 3  5<br>1 3  15<br>2 3  4</span></pre>
<pre><span style="font-size: 18px;"></span><span style="font-size: 18px;">The weight of the Minimum Spanning Tree formed is 19.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;"><strong>V = </strong>4, <strong>E = </strong>3</span>
<span style="font-size: 18px;"><strong>Arr[] = </strong>{0, 1, 98, 1, 3, 69, 0, 3, 25}</span>
<span style="font-size: 18px;"><strong>Output:</strong></span>
<span style="font-size: 18px;">192</span>
<span style="font-size: 18px;"><strong>Explanation:<br></strong></span>
<span style="font-size: 18px;">Array elements represent the triplets are :</span></pre>
<pre><span style="font-size: 18px;">U V Weight<br>0 1  98<br>1 3  69<br>0 3  25<br><br></span><span style="font-size: 18px;">The weight of the Minimum Spanning
Tree formed is 192.</span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>RevDelMST()</strong> which takes 2 Integers V, and E and an array of length 3*E where each triplet consists of two nodes u and v and weight of thir edge w as input and returns the Weight of the Minimum Spanning Tree.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(V*E)<br><strong>Expected Auxiliary Space:</strong> O(E)</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong></span><br><span style="font-size: 18px;">1 &lt;= V,E &lt;= 1000</span><br><span style="font-size: 18px;">1 &lt;= u,v &lt;= V<br>1 &lt;= w &lt;= 100</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;