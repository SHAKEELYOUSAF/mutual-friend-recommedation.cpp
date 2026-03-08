# mutual-friend-recommedation.cpp
A C++ social network simulation using an Adjacency Matrix to suggest friends based on mutual connections.


Overview

This project is a **console-based Social Network Simulation** developed in **C++**. It demonstrates how social networks can be modeled using **Graph Data Structures**, specifically an **Adjacency Matrix**.

The system allows users to register, connect with friends, view mutual friends, and receive friend recommendations based on shared connections.

This project is designed for **Data Structures and Algorithms (DSA)** learning, showing practical implementation of graphs in a real-world inspired scenario.


Features

1. User Registration

* Allows new users to register in the network.
* Prevents duplicate usernames.
* Maximum capacity of **20 users**.

2. Add Friend Connection

* Creates a friendship relationship between two users.
* Friendship is **bidirectional** (undirected graph).

3. Show All Users

Displays:

* User ID
* User Name
* List of their friends

4. Friend Suggestions

Suggests new friends based on:

* **Mutual connections**
* Users who are not already friends

Example output:


Suggestions for Ali
Ahmed (2 mutual friends)
Usman (1 mutual friend)
```

5. Mutual Friends Check

Shows:

* Whether two users are friends
* Their **common mutual friends**

6. Adjacency Matrix Display

Displays the complete **graph representation** of the network using an adjacency matrix.


Data Structures Used
 Graph Representation

The social network is implemented as a **Graph** where:

* **Vertices** = Users
* **Edges** = Friendships

The graph is stored using an **Adjacency Matrix**.


int Adjmatrix[Max][Max];

Where:

* `1` → Friendship exists
* `0` → No connection

 Program Structure

Main components of the system:

* `addUser()` → Registers new users
* `makeFriend()` → Creates friendship connections
* `showAll()` → Displays all users and their friends
* `getSuggestions()` → Suggests friends based on mutual connections
* `checkMutualFriends()` → Shows mutual friends between two users
* `displayMatrix()` → Displays adjacency matrix
* `Find_ID()` → Finds user index by name

Menu Interface

The program runs with a **simple console menu**:

```
=========== Social Network (Friend Recommendation System) =============
1. Add User
2. Make Friend
3. Show All Users
4. Get Suggestions
5. Check Mutual Friends
6. Display Matrix
7. Exit
```

---

Maximum Network Size


Maximum Users = 20

This limit can easily be increased by modifying:


const int Max = 20;

Concepts Demonstrated

This project demonstrates several **Data Structures concepts**:

* Graph Representation
* Adjacency Matrix
* Searching in Arrays
* Mutual Connections Logic
* Friend Recommendation Logic
* Basic Input Validation

How to Run

1. Compile the Program

Using g++:

g++ main.cpp -o social_network

2. Run the Program

./social_network


Example Use Case

1. Register users
2. Connect users as friends
3. View the network directory
4. Get friend recommendations
5. Check mutual friends between users

Future Improvements

Possible enhancements for the system:

* Increase network size dynamically
* Implement **Graph using Adjacency List**
* Add **Friend Removal**
* Add **User Deletion**
* GUI version of the system
* Save data using files
### Output Gallery
<table>
  <tr>
    <td><img src="IMAGE-01.jpeg" width="400"></td>
    <td><img src="IMAGE-02.jpeg" width="400"></td>
  </tr>
  <tr>
    <td><img src="IMAGE-03.jpeg" width="400"></td>
    <td><img src="IMAGE-04.jpeg" width="400"></td>
  </tr>
</table>
