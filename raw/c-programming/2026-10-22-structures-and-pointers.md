# Structures and Pointers in C++

> Source: https://icarus.cs.weber.edu/~dab/cs1410/textbook/5.Structures/pointers.html
> Collected: 2026-10-22
> Published: Unknown

5.4. Structures And Pointers

Time: 00:05:19 | Download: [Large](media/05-04-pointers.mp4), [Large (CC)](media/05-04-pointersCC.mp4), [Small](media/05-04-pointers \(small\).mp4) | [Streaming](media/05-04-pointers/index.html), [Streaming (CC)](media/streaming/pointers.html) | [Slides (PDF)](media/05-04-pointers.pdf)

**Review**

The current section applies many concepts from the previous pointer chapter. Please review the following as needed:

-   [Pointer Operators](../4.Pointers/operators.html)
-   [Dereferencing A Pointer](../4.Pointers/dereference.html)
-   [Stack And Heap](../4.Pointers/memory.html)
-   [new And delete](../4.Pointers/dynamic.html)
-   [Member Selection](../4.Pointers/member.html) (4.8)
    -   [Dot](structs.html#dot) (5.3)
    -   [Arrow](structs.html#arrow) (5.3)

Programs frequently use pointers in conjunction with structures. Consequently, programmers use all pointer and memory allocation operators with them. However, the arrow operator is the most frequent because it selects individual fields within a structure, allowing programs to save and retrieve structure data. Our previous explorations of the arrow operator focused on syntax and usage. In this section, we take a deeper, more elaborative approach, attempting better to understand the operator's impact on data in memory.

## Structures and The Arrow Operator

Structures allow programmers to group related data items into cohesive blocks the program can move and organize as a unit. Imagine that a programmer specifies a student structure that includes a student's name, identification number, and other relevant data. A program can move and organize a student's information as a unit. For example, it can arrange all students alphabetically or in ID order. But to realize structures' full benefits, a program must be able to access the individual fields saved within the structure, which is the selection operators' task.

[Choosing the correct selection operator](structs.html#choosing) depends on how the program references the structure. Programs can create structures on the stack, on the heap with `new`, or use the address of a stack object. Programs use the dot operator in the first case and the arrow operator for pointers in the second and third cases.

struct student					// 1
{
	int	id;
	string	name;
	double	gpa;
};
	.
	.
	.
student  s1 = { 123, "dilbert", 3.0 };		// 2
student* sp1 = &s1;				// 3
student* sp2 = new student;			// 4
	.
	.
	.
cout << s1.id << endl;				// 5
cout << sp1->name << endl;			// 6
cin >> sp2->gpa;				// 7

![The picture depicts two student structure objects as rectangles, each containing three smaller rectangles. Each small rectangle represents one of the members or fields in the student structure. The first rectangle is labeled s1, corresponding to statement 2 in the code fragment. It also has an arrow pointing from a second label, sp1, to the rectangle, representing a pointer pointing to the structure object and corresponding to statement 3. An arrow points from the label sp2 to the second rectangle, which corresponds to statement 4.](images/struct_pointer.png)

(a)

(b)

**The dot and the arrow operators**. The dot and arrow operators are different kinds of "selection" operators. They allow programmers to select the individual members or fields in a structure. The code fragment illustrates using the asterisk to define a pointer variable, the address-of operator, & to get the address of a local variable, s1, and the selection operators to access a structure's fields.

1.  1.  Specifies a structure named student with three fields: id, name, and gpa.
    2.  Defines and initializes an automatic or local structure object named s1.
    3.  Takes the address of s1 and saves it in a structure pointer named sp1.
    4.  Creates a new structure object dynamically on the heap with `new` and stores the address in a structure pointer named sp2.
    5.  s1 is not a pointer, so the dot operator is the correct member selection operator.
    6.  sp1 is a pointer, so the arrow operator is the correct member selection operator.
    7.  sp2 is a pointer, so the arrow operator is the correct member selection operator.
2.  An abstract representation of what occurs in memory.
    -   There is a subtle but crucial difference between the names s1 and sp1. The compiler maps the name s1 to the memory address of the illustrated structure and the name sp1 to a distinct variable *whose content is the address of the structure*. Ultimately, s1 and sp1 are two different names for the same structure object, making sp1 an alias for s1.
    -   sp2 points to a different object created with the new operator on the heap.

student* sp2 = new student { 987, "alice", 4.0 };

student* sp3 = sp2;

![A structure object depicted as a rectangle. The picture shows a single rectangle that represents a student object. Arrows from sp2 and sp3 to the rectangle represent two pointer variables pointing to the student structure.](images/struct_pointer3.png)

(a)

(b)

student* sp2 = new student { 987, "alice", 4.0 };

student s2 = *sp2;

![The picture shows two rectangles representing two structure objects. An arrow points from sp2 to the first rectangle. The picture illustrates that the second structure, a rectangle labeled s2, is created by copying the first structure or rectangle.](images/struct_pointer2.png)

(c)

(d)

**Structures and indirection - dereferencing a structure pointer**. A program may dereference *any* pointer, accessing the data it points to. Dereferencing a pointer to a structure creates an expression whose value is the entire structure. Working together, the assignment and dereference operators copy the dereferenced object.

1.  The first statement creates a student object on the heap with the `new` operator, saving its address in the pointer variable sp2. The second statement defines the pointer variable sp3 and copies the *address* saved in sp2 to it, but it does not copy the structure. Following the assignment, the two pointers point to the same student object.
2.  An abstract representation of the student object and the two pointers in memory.
3.  The first statement is identical to (a), creating a new student object on the heap. The second statement is similar to (a), but
    -   The structure variable s2 is not a pointer.
    -   The expression \*sp2 dereferences sp2 before the assignment operator runs. The expression's value is the complete structure sp2 points to.
    -   The assignment operator performs a byte-wise copy of the structure on the right-hand side of the assignment operator to the structure variable on the left-hand side.
4.  An abstract representation of memory illustrating the effect of the highlighted statement.

Understanding the dereference operator is challenging because it is a shorthand combining two distinct operations. Teasing apart the operations and representing each with a separate operator demonstrates the operations and their relative order. For example, `sp->name` is equivalent to `(*sp).name`. The dot operator has a higher [precedence](../glossary.html#precedence) than the dereference operator, making the parentheses mandatory. The dereference operator, \*, runs first, followed by the dot selection operator. Although programmers may use this two-step process, the arrow operator is more compact, clear, common, and typically preferred.

## Pointers, Structures, and Functions

Throughout the previous discussions, I assert that structures are convenient for programmers to "move" data in a program as a unit. By "move," I mean passing data to and returning it from functions. The textbook formally introduces functions in the next chapter, covering them in depth. Until then, your previous experience with Java methods or Python functions is sufficient for you to understand the basic concepts and syntax. If needed, please see [Function](../glossary.html#function) and [Function call](../glossary.html#function_call) for a quick review or overview.

void print(student temp)			// function definition
{
	cout << "ID:   " << temp.id << endl;
	cout << "Name: " << temp.name << endl;
	cout << "GPA:  " << temp.gpa << endl;
}
		.
		.
		.
print(s2);					// function call

![Two structure objects depicted as rectangles. Passing a structure to a function behaves like an assignment: the pass copies the structure's contents on the right side of the assignment operator to the structure on the left side.](images/structs3.png)

**Passing a struct as an argument**. When a program passes a structure into a function, it *copies* the entire structure from the function call to the function argument variable.

Passing a structure into a function copies the entire structure from one variable to another. C++ does not impose a size limit on structures, but copying very large structures takes a (relatively) long time. Passing a structure *pointer* to a function is one way to eliminate the overhead of passing a large structure. Paraphrasing [Gertrude Stein](http://en.wikipedia.org/wiki/Rose_is_a_rose_is_a_rose_is_a_rose), "An address is an address is an address." The size of an address is fixed, small, and independent of the data it points to. So, the value saved in a structure pointer, regardless of the structure's size, is the size of an address.

void print(student* temp)			// function definition
{
	cout << "ID:   " << temp->id << endl;
	cout << "Name: " << temp->name << endl;
	cout << "GPA:  " << temp->gpa << endl;
}
		.
		.
		.
print(&s2);					// function call

![A large rectangle, labeled s2, represents an object created from struct student. A smaller rectangle, labeled temp, is displayed inside the print function and has an arrow pointing to rectangle s2.](images/structs5.png)

**Passing a *pointer to* a structure**. Passing a structure's *address* to a function does not copy the structure. We say that the function's parameter, the variable temp, points to the original structure object, s2. So, while the function runs, the parameter temp is an alias or second name for s2. We can modify the previous print function example to illustrate passing a structure pointer by making three changes to the syntax:

1.  Define the formal parameter, temp, in the function definition as a pointer variable.
2.  Replace the dot operator with the arrow operator in all field selection operations.
3.  Get the structure's address with the address-of operator and pass it in the function call.

The print function demonstrates one way that pointers improve program performance. But pointers can improve performance in another way. The previous section ended the [read](structs.html#return_example) function, demonstrating a function returning a structure object by copying it from the function to the function call. However, if the program passes the *address* of the structure, as in Figure 4 above, there is only one structure but with *two* names: temp in the function scope and s2 in the calling scope. So, any changes the function makes through temp are seen in s2.

void read(student* temp)
{
	cout << "Enter a student id: ";
	cin >> temp->id >> endl;
	cout << "Enter a student name: ";
	cin >> temp->name >> endl;
	cout << "Enter a student gpa: ";
	cin >> temp->gpa >> endl;
}
		.
		.
		.
student	s;

read(&s);

Enter a student id: 975
Enter a student name: wally
Enter a student gpa: 1.3

(a)

(b)

![A large rectangle, labeled s, represents an object created from struct student. A smaller rectangle, labeled temp, is displayed inside the read function and has an arrow pointing to rectangles. The values entered by the prompts in (a) are saved in the fields of structure s.](images/structs6.png)

(c)

**"Returning" values through pointer parameters**. Functions with pointer parameters can send data back through them. The previous version of the [read function](structs.html#return) creates and fills a local student structure and returns it with a return statement, causing the program to *copy* the entire structure from the local variable temp to s3. The read function illustrated here has a void return type and no return statement - it can't return data the same way as the previous version.

1.  The variable temp points to structure s, so any modifications made through temp are made directly to object s. Said another way, the program accesses s indirectly through temp.
2.  The prompts printed by (a) and the corresponding user input.
3.  An abstract representation of temp pointing to s. The user input of (b) is stored in the structure object s.