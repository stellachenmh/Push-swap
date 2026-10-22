# Rank of all elements in an array

> Source: https://www.geeksforgeeks.org/dsa/rank-elements-array/
> Collected: 2026-10-22
> Published: 2024-03-29

Rank of all elements in an array

Last Updated : 29 Mar, 2024

Given an array of N integers with duplicates allowed. All elements are ranked from 1 to N in ascending order if they are distinct. If there are say x repeated elements of a particular value then each element should be assigned a rank equal to the arithmetic mean of x consecutive ranks.

****Examples:****

Input : 20 30 10
Output : 2.0 3.0 1.0
Input : 10 12 15 12 10 25 12
Output : 1.5, 4.0, 6.0, 4.0, 1.5, 7.0, 4.0
10 is the smallest and there are two 10s so
take the average of two consecutive ranks
1 and 2 i.e. 1.5 . Next smallest element is 12.
Since, two elements are already ranked, the
next rank that can be given is 3. However, there
are three 12's so the rank of 2 is (3+4+5) / 3 = 4.
Next smallest element is 15. There is only one 15
so 15 gets a rank of 6 since 5 elements are ranked.
Next element is 25 and it gets a rank of 7.
Input : 1, 2, 5, 2, 1, 60, 3
Output : 1.5, 3.5, 6.0, 3.5, 1.5, 7.0, 5.0


****Method I (Simple):****
Consider that there are no repeated elements. In such a case the rank of each element is simply 1 + the count of smaller elements in the array. Now if the array were to contain repeated elements then modify the ranks by considering the no of equal elements too. If there are exactly r elements which are less than e and s elements which are equal to e, then e gets the rank given by

(r + r+1 + r+2 ... r+s-1)/s
\[Separating all r's and applying
[natural number sum formula](https://www.geeksforgeeks.org/dsa/program-find-sum-first-n-natural-numbers/)\]
\= (r\*s + s\*(s-1)/2)/s
\= r + 0.5\*(s-1)

****Algorithm:****

function rankify(A)
    N = length of A
    R is the array for storing ranks
    for i in 0..N-1
        r = 1, s = 1
        for j in 0..N-1
            if j != i and A[j] < A[i]
                r += 1
            if j != i and A[j] = A[i]
                s += 1
        // Assign Rank to A[i]
        R[i] = r + 0.5\*(s-1)
    return R

Implementation of the method is given below

C++`// CPP Code to find rank of elements #include <bits/stdc++.h> using namespace std;  // Function to find rank void rankify(int* A , int n) {      // Rank Vector     float R[n] = {0};          // Sweep through all elements in A for each     // element count the number of less than and     // equal elements separately in r and s.     for (int i = 0; i < n; i++) {         int r = 1, s = 1;                  for (int j = 0; j < n; j++) {             if (j != i && A[j] < A[i])                 r += 1;                              if (j != i && A[j] == A[i])                 s += 1;              }                  // Use formula to obtain rank         R[i] = r + (float)(s - 1) / (float) 2;          }           for (int i = 0; i < n; i++)         cout << R[i] << ' ';      }      // Driver Code int main() {     int A[] = {1, 2, 5, 2, 1, 25, 2};     int n = sizeof(A) / sizeof(A[0]);          for (int i = 0; i < n; i++)     cout << A[i] << ' ';     cout << '\n';          rankify(A, n);          return 0; }  // This code is contributed by Gitanjali.`
Java`// Java Code to find rank of elements public class GfG {          // Function to print m Maximum elements     public static void rankify(int A[], int n)     {         // Rank Vector         float R[] = new float[n];              // Sweep through all elements in A         // for each element count the number         // of less than and equal elements         // separately in r and s         for (int i = 0; i < n; i++) {             int r = 1, s = 1;                          for (int j = 0; j < n; j++)              {                 if (j != i && A[j] < A[i])                     r += 1;                                      if (j != i && A[j] == A[i])                     s += 1;                  }                  // Use formula to obtain  rank         R[i] = r + (float)(s - 1) / (float) 2;              }               for (int i = 0; i < n; i++)             System.out.print(R[i] + "  ");              }      // Driver code     public static void main(String args[])     {         int A[] = {1, 2, 5, 2, 1, 25, 2};         int n = A.length;               for (int i = 0; i < n; i++)             System.out.print(A[i] + "    ");             System.out.println();             rankify(A, n);     } }  // This code is contributed by Swetank Modi`
Python3`# Python Code to find  # rank of elements def rankify(A):      # Rank Vector     R = [0 for x in range(len(A))]      # Sweep through all elements     # in A for each element count     # the number of less than and      # equal elements separately     # in r and s.     for i in range(len(A)):         (r, s) = (1, 1)         for j in range(len(A)):             if j != i and A[j] < A[i]:                 r += 1             if j != i && A[j] == A[i]:                 s += 1                        # Use formula to obtain rank         R[i] = r + (s - 1) / 2      # Return Rank Vector     return R  if __name__ == "__main__":     A = [1, 2, 5, 2, 1, 25, 2]     print(A)     print(rankify(A))`
C#`// C# Code to find rank of elements using System;  public class GfG {          // Function to print m Maximum     // elements     public static void rankify(int []A, int n)     {         // Rank Vector         float []R = new float[n];              // Sweep through all elements         // in A  for each element count         // the number  of less than and         // equal elements separately in         // r and s         for (int i = 0; i < n; i++) {             int r = 1, s = 1;                          for (int j = 0; j < n; j++)              {                 if (j != i && A[j] < A[i])                     r += 1;                                      if (j != i && A[j] == A[i])                     s += 1;              }                  // Use formula to obtain rank         R[i] = r + (float)(s - 1) / (float) 2;              }               for (int i = 0; i < n; i++)             Console.Write(R[i] + " ");              }      // Driver code     public static void Main()     {         int []A = {1, 2, 5, 2, 1, 25, 2};         int n = A.Length;              for (int i = 0; i < n; i++)             Console.Write(A[i] + " ");             Console.WriteLine();             rankify(A, n);     } }  // This code is contributed by vt_m.`
JavaScript`<script>  // JavaScript Code to find rank of elements        // Function to find rank       function rankify(A, n) {         // Rank Vector         var R = [...Array(n)];          // Sweep through all elements in A for each         // element count the number of less than and         // equal elements separately in r and s.         for (var i = 0; i < n; i++) {           var r = 1,             s = 1;            for (var j = 0; j < n; j++) {             if (j != i && A[j] < A[i]) r += 1;              if (j != i && A[j] == A[i]) s += 1;           }            // Use formula to obtain rank           R[i] = parseFloat(r + parseFloat(s - 1) / parseFloat(2));         }          for (var i = 0; i < n; i++)           document.write(parseFloat(R[i]).toFixed(1) + "&nbsp;&nbsp;");       }        // Driver Code       var A = [1, 2, 5, 2, 1, 25, 2];       var n = A.length;       for (var i = 0; i < n; i++) document.write(A[i] + "&nbsp;&nbsp;");       document.write("<br>");       rankify(A, n);        </script>`
PHP`<?php // PHP Code to find rank of elements   // Function to find rank  function rankify($A , $n)  {       // Rank Vector      $R = array(0);           // Sweep through all elements in A for each      // element count the number of less than and      // equal elements separately in r and s.      for ($i = 0; $i < $n; $i++)      {          $r = 1;         $s = 1;                   for ($j = 0; $j < $n; $j++)          {              if ($j != i && $A[$j] < $A[$i])                  $r += 1;                               if ($j != $i && $A[$j] == $A[$i])                  $s += 1;              }                   // Use formula to obtain rank          $R[$i] = $r + (float)($s - 1) / (float) 2;           }           for ($i = 0; $i < $n; $i++)          print number_format($R[i], 1) . ' ';  }   // Driver Code $A = array(1, 2, 5, 2, 1, 25, 2);  $n = count($A); for ($i = 0; $i < n; $i++)  echo $A[i] . ' ';  echo "\n";   rankify($A, $n);   // This code is contributed by Rajput-Ji ?>`

  
**Output**

1 2 5 2 1 25 2 
1.5 4 6 4 1.5 7 4 

****Time Complexity:**** O(N\*N),  
****Auxiliary Space:**** O(N)

****Method II (Efficient)****
In this method, create another array (T) of tuples. The first element of the tuple stores the value while the second element refers to the index of the value in the array. Then, sort T in ascending order using the first value of each tuple. Once sorted it is guaranteed that equal elements become adjacent. Then simply walk down T, find the no of adjacent elements and set ranks for each of these elements. Use the second member of each tuple to determine the indices of the values.
Algorithm

function rankify_improved(A)
    N = Length of A
    T = Array of tuples (i,j),
        where i = A[i] and j = i
    R = Array for storing ranks
    Sort T in ascending order
    according to i

    for j in 0...N-1
        k = j
        // Find adjacent elements
        while A[k] == A[k+1]
            k += 1
        // No of adjacent elements
        n = k - j + 1
        // Modify rank for each
        // adjacent element
        for j in 0..n-1
            // Get the index of the
            // jth adjacent element
            index = T[i+j][1]
            R[index] = r + (n-1)*0.5
        // Skip n ranks
        r += n
        // Skip n indices
        j += n
    return R


The code implementation of the method is given below

C++`// CPP Code to find rank of elements #include <bits/stdc++.h> using namespace std;  bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {     return (a.first < b.first); }  // Function to find rank void rankify_improved(int A[] , int n) {      // Rank Vector     float R[n] = {0};          // Create an auxiliary array of tuples     // Each tuple stores the data as well     // as its index in A     vector <pair<int,int>> T(n);     for(int i = 0; i < n; i++)     {         T[i].first=A[i];         T[i].second=i;     }               // T[][0] is the data and T[][1] is     // the index of data in A       // Sort T according to first element     sort(T.begin(),T.end(),sortbysec);       float rank = 1, m = 1,i = 0;       while(i < n){         float j = i;           // Get no of elements with equal rank         while(j < n - 1 && T[j].first == T[j + 1].first)             j += 1;           m = j - i + 1;           for(int k=0;k<m;k++){               // For each equal element use formula             // obtain index of T[i+j][0] in A             int idx = T[i+k].second;             R[idx] = (double)(rank + (m - 1) * 0.5);         }           // Increment rank and i         rank += m;         i += m;     }     for (int i = 0; i < n; i++)         cout << (double)R[i] << ' ';      }      // Driver Code int main() {     int A[] = {1, 2, 5, 2, 1, 25, 2};     int n = sizeof(A) / sizeof(A[0]);          for (int i = 0; i < n; i++)     cout << A[i] << ' ';     cout << '\n';          rankify_improved(A, n);          return 0; }  // This code is contributed by Aarti_Rathi`
Java`// Java implementation to find rank of elements import java.util.Arrays; import java.util.Comparator;  class Pair {   // each element having its first and second   int first, second;    public Pair(int first, int second)   {     this.first = first;     this.second = second;   }    // Function to find rank   static void rankify_improved(int A[] , int n)   {     // Rank Vector     float R[] = new float[n];     for(int i=0;i<n;i++)     {       R[i]=0;     }      // Create an auxiliary array of tuples     // Each tuple stores the data as well     // as its index in A     Pair T[] = new Pair[n];      // for each element of input array create a     // structure element to store its index and     // factors count     for (int i=0; i<n; i++)     {       T[i] = new Pair(A[i],i);     }      // T[][0] is the data and T[][1] is     // the index of data in A      // Sort T according to first element     Arrays.sort(T,new Comparator<Pair>() {        @Override       // compare method for the elements       // of the structure       public int compare(Pair e1, Pair e2) {         // if two elements have the same number         // of factors then sort them in increasing         // order of their index in the input array         if (e1.first == e2.first)           return e1.second > e2.second ? -1 : 1;          // sort in decreasing order of number of factors         return e1.first < e2.first ? -1 : 1;       }      });      float rank = 1, m = 1;     int i = 0;      while(i < n){       int j = i;        // Get no of elements with equal rank       while(j < n - 1 && T[j].first == T[j + 1].first)         j += 1;        m = j - i + 1;        for(int k=0;k<m;k++){          // For each equal element use formula         // obtain index of T[i+j][0] in A         int idx = T[i+k].second;         R[idx] = (float)((float)rank + (float)(m - 1) * 0.5);       }        // Increment rank and i       rank += m;       i += m;     }      for (int k=0; k<n; k++)       System.out.print((double)R[k]+"  ");   }    // Driver code   public static void main(String args[])   {     int A[] = {1, 2, 5, 2, 1, 25, 2};     n = A.length;      for (int i = 0; i < n; i++)       System.out.print(A[i] + "    ");     System.out.println();     rankify_improved(A, n);   } }  // This code is contributed by Aarti_Rathi`
Python3`# Python code to find  # rank of elements def rankify_improved(A):          # create rank vector     R = [0 for i in range(len(A))]      # Create an auxiliary array of tuples     # Each tuple stores the data as well     # as its index in A     T = [(A[i], i) for i in range(len(A))]      # T[][0] is the data and T[][1] is     // the index of data in A      // Sort T according to first element     T.sort(key=lambda x: x[0])      (rank, n, i) = (1, 1, 0)      while i < len(A):         j = i          // Get no of elements with equal rank         while j < len(A) - 1 and T[j][0] == T[j + 1][0]:             j += 1         n = j - i + 1          for j in range(n):              // For each equal element use formula             // obtain index of T[i+j][0] in A             idx = T[i+j][1]             R[idx] = rank + (n - 1) * 0.5          // Increment rank and i         rank += n         i += n      return R  if __name__ == "__main__":     A = [1, 2, 5, 2, 1, 25, 2]     print(A)     print(rankify_improved(A))`
C#`using System; using System.Collections.Generic; using System.Linq;  class Program {     // Custom comparer to sort the pairs by their first     // element     static int SortByFirstElement(KeyValuePair<int, int> a,                                   KeyValuePair<int, int> b)     {         return a.Key.CompareTo(b.Key);     }      // Function to find rank     static void RankifyImproved(int[] A, int n)     {         // Rank Vector         double[] R = new double[n];          // Create a list of key-value pairs to store the     // data and its index in A         List<KeyValuePair<int, int> > T             = new List<KeyValuePair<int, int> >();         for (int i = 0; i < n; i++) {             T.Add(new KeyValuePair<int, int>(A[i], i));         }          // Sort T according to the first element         T.Sort(SortByFirstElement);          double rank = 1;         double m = 1;         int currentIndex = 0;          while (currentIndex < n) {             double j = currentIndex;              // Get the number of elements with equal rank             while (j < n - 1                    && T[(int)j].Key == T[(int)(j + 1)].Key)                 j += 1;              m = j - currentIndex + 1;              for (int k = 0; k < m; k++) {                 // For each equal element, use the formula                 // to obtain the index of                 // T[currentIndex+k][0] in A                 int idx = T[currentIndex + k].Value;                 R[idx] = rank + (m - 1) * 0.5;             }              // Increment rank and currentIndex             rank += m;             currentIndex += (int)m;         }          for (int j = 0; j < n; j++)             Console.Write(R[j] + " ");     }      // Driver Code     static Main(string[] args)     {         int[] A = { 1, 2, 5, 2, 1, 25, 2 };         int n = A.Length;          for (int i = 0; i < n; i++)             Console.Write(A[i] + " ");         Console.WriteLine();          RankifyImproved(A, n);          Console.ReadLine();     } }`
JavaScript`<script>  // JavaScript code to find // rank of elements function rankify_improved(A) {          // create rank vector     let R = new Array(A.length).fill(0)      // Create an auxiliary array of tuples     // Each tuple stores the data as well     // as its index in A     let T = new Array(A.length);     for(let i = 0; i < A.length; i++)     {         T[i] = [A[i], i]     }      // T[][0] is the data and T[][1] is     // the index of data in A      // Sort T according to first element     T.sort((a,b) => a[0]-b[0])      let rank = 1, n = 1,i = 0      while(i < A.length){         let j = i          // Get no of elements with equal rank         while(j < A.length - 1 && T[j][0] == T[j + 1][0])             j += 1          n = j - i + 1          for(let j=0;j<n;j++){              // For each equal element use formula             // obtain index of T[i+j][0] in A             let idx = T[i+j][1]             R[idx] = rank + (n - 1) * 0.5         }          // Increment rank and i         rank += n         i += n     }     return R }  // Driver code let A = [1, 2, 5, 2, 1, 25, 2] document.write(A,"</br>") document.write(rankify_improved(A),"</br>")  // This code is contributed by shinjanpatra  </script>`

  
**Output**

1 2 5 2 1 25 2 
1.5 4 6 4 1.5 7 4 

****Time Complexity:**** O(N Log N).  
****Auxiliary Space:**** O(N)