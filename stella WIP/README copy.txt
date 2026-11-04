

check if stack contains
only integer values (both negative and positive)
any duplicates
ints outside valid range? 
Err to std err.

swap - do nothing if only one or no elements
push - do nothing if 'from' stack is empty 

Take a list of arguments
First is stack a as a list of integers. How will it know when this ends and we got to optional?
No parameters, display nothing and...give prompt back?


optional
- Strategy selector
- Benchmark mode

Bonus
- Checker 



Simon
git reset (hash)
git checkout (file name) 


Variadic arguments
Necessary for this project? Need at least one fixed parameter, except C26 onward. Can the fixed parameter be the program name? AI says yes
Why do you need vas when argc exists? 

Max elements for array
size_t is the max bytes, not max no of elements
Can get the # of elements in an array by dividing its size in bytes (via sizeof) by size of each element. However if you pass a pointer to the array, that would measure the pointer size instead and give the wrong result. 
printf("%lu", (SIZE_MAX / sizeof(int)));
4611686018427387903

AI improvements to check duplicates 
const int *arr, null ptr chk, else if unnecessary

Mistakes
Two errors hiding each other. single = 1/3. 1.0/3.0 caught the error 
double vs float? AI advises double for general calculations, float if memory is constrained 


ranking function
https://www.geeksforgeeks.org/dsa/rank-elements-array/ 

NUS explanation of Quick Sort which is O n log n https://www.comp.nus.edu.sg/~stevenha/cs1020e/lectures/L10%20-%20Sorting.pdf 
Heap sort, Geeks for Geeks https://www.geeksforgeeks.org/dsa/heap-sort/ 


Things to KIV
argc is an int. Can you pass more args than that? Tough in practice. argv[argc] must be a null ptr. https://stackoverflow.com/questions/28075323/can-argc-overflow

Negative integers...radix sorts non-neg? Rank ints gets rid of this problem

Linked list vs stack

Why are we minimising operations? The rank ints algo is 0n2




Leave out
Geeks for geeks on shell sort https://www.geeksforgeeks.org/dsa/shell-sort/ 
Stack overflow, worst case for shell sort? (Wiki diff answer?) https://stackoverflow.com/questions/46715038/worst-scenario-for-shell-sort-Θn3-2-or-onlogn2

Complexity of sqrt chunks
Divide range into chunks sized sqrt n. Starting from the (lowest) chunk, go through range and push items belonging to that chunk to next stack. Then go to next chunk. 
After stack A is empty, bring items back to A. Within each chunk sized sqrt n, at most X operations to reorder them? The worst-case # of steps to reorder n elements is n steps? 
3 elements, 3 2 1. Can be solved in 2 steps?

Grokking algorithms https://github.com/42YerevanProjects/push_swap/blob/master/resources/Aditya%20Bhargava%20-%20Grokking%20Algorithms_%20An%20illustrated%20guide%20for%20programmers%20and%20other%20curious%20people-Manning%20Publications%20(2016).pdf 

Thinking about medium algorithm 
Bucket sort divides based on value, works best for uniform distributions. Block sort goes by fixed block size. https://www.geeksforgeeks.org/dsa/bucket-sort-2/ https://www.geeksforgeeks.org/dsa/introduction-to-block-sort/ 

Sort individual buckets using insertion sort, then concatenate buckets. Since buckets were by value, can concatenate directly. Insertion sort because stable? Yes. Worst case all in one bucket, On2. But if I am using ranked indexes, wouldn't happen. 

Block sort, fixed size. Fixed block size, sort using comparison-based algorithm, merge using eg priority queue or min heap. 

Which one should I use? Sqrt n buckets, sqrt n block size. 
I can't use insertion sort. Only pushing here and there.


Understanding time complexity of algorithms in a simple way. log n often means you divide by 2, rounding down, trying to get 0. https://medium.com/@kyledeguzmanx/give-me-5-minutes-and-ill-teach-you-how-to-find-the-time-complexity-of-an-algorithm-23be4d4179ee

n sqrt n is also known as n^3/2
Whether block or bucket sort, I have sqrt n buckets or blocks of sqrt n size. The n comes from...sorting each bucket? Merging? 
Insertion sort, suggested by bucket sort, is On2. To calculate worst-case scenario, think of the worst case! Bucket sort time complexity reduces to the time complexity of the underlying algorithm used...
Block sort according to Geeks for Geeks is n log n. 

log means how many times is (10?) multiplied to get this other number https://www.reddit.com/r/explainlikeimfive/comments/1dcy8ug/eli5_what_exactly_is_a_logarithm_and_what_does_it/



Talking to AI again
Strongly disagree with it on block- vs chunk-based sorting. Ugh. 
Good point on stack B rotations being more expensive, because targeted search. 
Reading Oliver's implementation. L is NOT a lower bound. Just that anything <= i goes to the bottom of stack B, anything within i + range goes to the top. 

Thoughts on Oliver's approach. He's using i as the midpoint rather than a range midpoint. I know we can have ints smaller than the lower boundary, so that solves what I didn't understand from AI's explanation. K-shaped stack B! 


Sqrt function must stop BEFORE it exceeds n. No, <= but decrement

Stupid AI and its suggestion to use a NULL ptr instead of empty array!!! seg fault




Other people who did it
Push swap tips. Sort small stacks separately, rotate in direction w lowest cost, combine operations. His explanation of chunk sorting sounds like my understanding of bucket sort. He used 5 chunks for 500 nos, other guy used 11. https://www.linkedin.com/pulse/push-swap-art-sorting-two-stacks-anass-outiskte-bjsje/ 

Person who is using buckets, by value. Push over the value nearer to top/bottom of stack. Used 11 chunks for 500 nos. https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a 

Oliver...k-sort, range? https://github.com/OliverKingz/push_swap 
Why is K-sort n log n? 

This person did 3 layers. Noted that the ranking layer is least efficient. Linked lists vs stacks. https://medium.com/@tajdine.zouhair/mastering-push-swap-the-path-to-sorting-500-numbers-in-under-3-850-moves-977a8292aebb 



Person who used 'longest sorted sequence' calculation with doubly-linked lists. Also checked if sequence is in reverse order, if yes swap first two elements, which eliminates need to do 'sort 3 ints'? Also calculates 'cost' of pushing back. One move, push immediately. Two moves, stop calculating for other candidates once you hit two moves. https://medium.com/@dansylvain84/my-implementation-of-the-42-push-swap-project-2706fd8c2e9f 

Person who used radix sort, links to 'tutorial' on radix sort. Works for non-neg? https://github.com/42YerevanProjects/push_swap 


SImon's resources
Simon, how core git developers configure git https://blog.gitbutler.com/how-git-core-devs-configure-git 
Git collab slides https://simonlau.github.io/git-branch-workflow/1 
Unit testing https://simonlau.github.io/slides/1 

Get Github student pack https://github-portal.42.fr/login 

My thoughts
What is main.c? Parser? Strategy?
Simon said sometimes don't print anything at all
Print to 'black hole' on Linux

Do we compile using libft's Makefile? How does the Makefile work for printf and libft?
Use exit for what? 
Update sort simple and medium to take in new parameter for printing

No parameters specified...show error when
Benchmark mode needs printf to 2dp 


