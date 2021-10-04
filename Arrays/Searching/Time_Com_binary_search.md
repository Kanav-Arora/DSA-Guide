## Time complexity of binary search

<br>

After first iteration, length of array -> n

After second iteration, length of array -> n/2

After third iteration, length of array -> n/4

.

.

.

.

After kth iteration, length of array -> n/(2<sup>k</sup>)) 

Let the length of array become 1 after kth iteration

<center>

n/2<sup>k</sup> = 1

n = 2<sup>k</sup>

log<sub>2</sub> (n)  =  log<sub>2</sub> (2<sup>k</sup>)

log<sub>2</sub> (n)  =  k log<sub>2</sub> (2)

k = log<sub>2</sub> (n)


</center>

***

<br>

***Time Complexity = O(log<sub>2</sub> (n))***


