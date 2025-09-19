# cse3150_week_3_hw
week 3 homework for cse3150

# Explanation:

Pointers were used for accessing the C-style strings as char arrays, as well as for changing a gpa value in the updateGPA function. Since the original gpa is passed as a pointer, the function has access to that variable directly via dereferencing. If it was just passed as a double, it would be impossible to access the original variable.

Const was used in the printStudent and averageGPA functions, which prevents any of the names or gpas from being mutated during iteration through the respective arrays.

References were used in the addStudent and printStudent functions. In addStudent, by passing size by reference, the function is then able to update the size variable in main. In printStudent, gpa is passed by reference, but it is also const, so it cannot be changed within the function.

Casting was used when printing the average GPA. The averageGPA function returns a double, but I used static_cast<int> so that it would print the rounded value.

Exceptions were used to stop attempts to append to a full array using the addStudent function and attempts to iterate through an empty array using the averageGPA function. In both cases it was done by simply checking the size of the array and throwing a string literal. I used try and catch blocks when these functions were called to handle the exception.

The most important/elaborate piece of control flow is the switch block used for the menu logic. It takes the terminal input for each case and performs the appropriate function calls or whatever other necessary actions. Other than that, there are some simple if statements used for error detection and for loops to iterate through the arrays.
