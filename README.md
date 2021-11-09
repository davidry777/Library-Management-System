# Library System
 > Authors: [Daniel Castaneda](https://github.com/daniel-u-c), [David Ryan](https://github.com/davidry777), [Jason Giese](https://github.com/jsongi), [Gwen Kiler](https://github.com/gkiler)

## Project Description
 > This library system project is important because it allows us to implement an inheritance system in terms of accounts, and it will be interesting to see how the abstraction and encapsulation will control access in this program. It will also provide us with a good idea with how actual library systems, or other-related systems, work in real life compared to how we did it. It will also be interesting to see how we make a bare-bones recommendation system.
 > The languages/tools/technologies we plan to use are (subject to change):
 >   * [C++](https://www.cplusplus.com/) - A general-purpose programming language
 >   * [CMake](https://cmake.org/cmake/help/v3.22/) - A tool to manage building of source code.
 >   * [GoogleTest](https://github.com/google/googletest) - Google’s C++ testing and mocking framework
 >   * [Valgrind](https://www.valgrind.org) - An instrumentation framework for building dynamic analysis tools
 >   * [Git](https://git-scm.com/) - A distrubuted version control system
 >   * [GitHub](https://github.com/) - An online host for software development utilizing Git.

 > The Design Patterns used in this project are:
 >   * Strategy Pattern

 > The input of our project will be:
 >   * Book information by administrators (Title, genre, sub-genre, description, etc)
 >   * User account creation (Inputting username/password)
 >   * Search for books through user input
 >   * Select books to borrow

 > Our project will then output:
 >   * Book recommendations
 >   * Debt information
 >   * Book search
 >   * See account information
 >   * List of available books
 
 > Our project will contain features like:
 >   * User Account System with Different Privileges (Student, Adminsistrative, etc)
 >   * Book Checkout System
 >   * Account Debt Tracker
 >   * Available Books Displayed by a Specified Genre/Sub-Genre
 >   * Book Recommendations Based on User Behavior
 >   * User Data Encryption

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to:
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller actionable development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > **UML Diagram**
 > ![Library Management System UML Diagram](https://github.com/cs100/final-project-dcast162-nkile001-dryan011-jgies011/blob/master/images/Library%20System%20UML%20Diagram.png)
 > **Description**: For our program, the _LibrarySystem_ class is composed of both _UserSystem_ and _BookSystem_ classes. The _BookSystem_ class contains functionality to add books, remove books, and check the experiation date of each book. The unordered map inside _BookSystem_ is composed of Book objects, each containing the author, title, genre, number of pages, ISBN, and frequent checkouts. _BookSystem_ also keeps a queue of the Books that are checked out.
 > The _UserSystem_ class is composed of the _LoginSystem_ class, which gives the client functionality to login in and log out. _UserSystem_ is also composed of the _Person_ interface, which is needed to set the current person in this class and to add more users to the library system. The _Person_ interface contains personal information, as well as the password and current library. Its attributes and functions are then inherited by the _Librarian_ subclass, which gives the librarian functionality to add or remove books, and set their library; and the _User_ subclass, which gives library users functionality to checkout or return books, pay fines, and display checked out books. The _User_ subclass is also composed of the _DisplaySystem_ class, which its prime function is to display books based on different searching and sorting algorithms. The _DisplaySystem_ is composed of a _Search_ interface, which is later inherited by _GenreSearch_, _SubGenreSearch_, and _ISBNSearch_ child classes; and a _Sort_ interface, which is later inhertaed by _FrequencySort_ and _AlphabeticalSort_ subclasses
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design patterns did you use? For each design pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design patterns you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your TA you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
