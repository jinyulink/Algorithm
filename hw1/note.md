# Algorithm HW1 note
## 1

## 2
用hash table
https://stackoverflow.com/questions/9214353/hash-table-runtime-complexity-insert-search-and-delete
## 3 
先for跑一遍x，每次在對y做二分搜? 應該是最快的了吧 O(mlogn)

(更 我笨 用two pointer 就可以線性時間解決.. O(m+n) 乾
## 4
the input is a sequence of n integers with many duplications, such that the number of distinct integers in the sequence is O(logn). Please design a sorting algorithm to sort such sequences using at most O(nloglogn) comparisons in the worst case. And why is lower bound of sorting O(nlogn) not satisfied in this case?

sol(1): https://www.algorist.com/algowiki_v2/index.php/TADM2E_4.23

sol(2): One possible algorithm to sort such sequences using at most O(nloglogn) comparisons is as follows:

Construct a balanced binary search tree, such as a red-black tree, from the input sequence. This can be done in O(nloglogn) time, since the height of the tree is O(loglogn) and each insertion takes O(loglogn) time.

Traverse the tree in-order, outputting each element as it is visited. This takes O(n) time.

The total running time of this algorithm is O(nloglogn), which satisfies the required upper bound.

The reason why the lower bound of sorting being O(nlogn) is not satisfied in this case is that the number of distinct integers in the sequence is only O(logn), which means that there are many duplications. This allows us to take advantage of the redundancy in the input to reduce the number of comparisons needed to sort the sequence. In particular, the binary search tree in our algorithm takes advantage of the fact that duplications can be stored more efficiently in a tree than in a comparison-based sorting algorithm that compares each pair of elements. This illustrates the importance of considering the properties of the input when designing efficient algorithms.

用紅黑樹來實作，其search/delete/insert 都是O(logn)，此題總共有logn個不同元素，講這些元素insert進RB-tree花費O(loglogn)，最後用inorder遍歷一遍這個樹，花費O(n)，就可以得到sorted的排序，是故，總time complexity=O(n*loglogn)

## 5
solution - https://atekihcan.github.io/CLRS/02/E02.02-02/