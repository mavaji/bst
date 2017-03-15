# bst
A binary search tree with graphical representation.

[BST in Wikipedia](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)

#### Prerequisites
You may have these libraries installed
```text
sudo apt-get install libsdl1.2-dev
sudo apt install libsdl-gfx1.2-dev
sudo apt install libsdl-image1.2-dev
sudo apt-get install guile-1.8-dev
sudo apt install guile-gnutls
```

Follow instructions at: [Installing graphics.h in linux](http://glug.nith.ac.in/blog/installing-graphics-h-linux/)

#### Make
`g++ BST.cpp -lgraph`

#### Sample Execution
```text
Input Data:10
Input Data:50
Input Data:60
Input Data:70
Input Data:-1
Inorder Sweep: 10 50 60 70 
Heigth Of Tree is :3
Press any key to see graph of Tree...
Press any key to continue...

Inorder sweep of inverted tree is :70 60 50 10 
Heigth of inverted Tree is : 3
Press any key to see graph of Tree...
```

