README.txt

PA3.c

1. The function main takes two arguments, an integer argc and an array of string *argv[]. Inside the function, it checks whether the command line has less than 3 strings, if is, print an error and exit.If not, it allocates memory for the input file through a while loop. Every time it adds a FILE into the FILE **input, it will call the function parseFile to parse the file and then close the file and keep looping. Then it calls the function balanceNode to balance in Tree.c to balance the tree. Later on, we have two pointers to intergers to record the amount of distinct words and total amount of words. Then it calls the function printTree to print the tree in the outputfile. At the end it free the input and close the output file.

Input.c

1. The function parseFile take 3 argument, a FILE *fp, a Node *p and a Node *parent, and it return a pointer to a Node. It mainly parse the file input and take each work found in the input file into the tree. Inside the function, it uses a while loop. The while loop ends when fgetc detect EOF. Inside the while loop, the function first check the case of "'s" and record them. Then it check whether the char is a letter. It stores the letter into temp(The temporary space for char to stay). After it finds a full word, it will set the next char in temp[] to be 0(representing the null character), allocate the correct memory for the string word and copy the string from temp to word. Then it calls the addItem function in Tree.c and reset the count. 

Output.c

1. The function printTree takes 4 arguments, a Node *p, a FILE *file_A, a pointer to int distinct and a pointer to int total, and it returns a pointer to FILE file_A. Inside the function, it checks whether p is null and p's leftChild is null. If no, it will recursivelt call printTree and change the argument Node *p to p.leftChild. Then it will print the count and work for p if p is not null. Later on, it will recursively call printTree to print the rightChild to print the whole tree by alphabatic order.

Tree.c 

1. The function addItem takes 3 arguments, a Node *p, a char *w and a Node *parent, and returns a pointer to Node. It adds the item into the tree by its alphabetic order. Inside the fuction, it set up the content of the Node and its parent if p equals null and returns p. If p!= null, it will let int c equals strcmp p.word and w. If c = 0, they are the same word and increse the count for p. If c<0, goes into the leftChild of p by addItem function. If c>0, recusively goes into the leftChild of p by addItem function. Again and again, until it finds an empty space. This is a recursion for add to the desired spot of tree.

2. The function balanceNode takes an argument, Node *p and returns a pointer to Node. It balances the tree by calculating the balanceFactor and make movement of the tree. Inside the function, it calls balanceNode(p.leftChild) if p.leftChild exists first. If it reaches the leftest, it will start calling balanceNode(p.rightChild), if p.rightChild exists. Because of that, it will balance the leftest node first and then start balancing the whole tree. Later on, it checks the balance factor for the node its currently balancing. It will depend the current node's balance factor to keep balancing the tree recursively.  If its heavy on left, the function will make movement to the current node's leftChild based on its balance factor(Balance factor will be explained in getBalanceFactor function). And the same for heavy on right.  If its heavy on right, the function will make movement to the current node's leftRight based on its balance factor. This makes the recursion that will balance the each node of the tree and then balance the whole tree. And there two seperate cases for each of them, heavy on leftRight,leftLeft,rightRight and rightLeft. Inside the recursion, it eitehr calls the function rotateRightLeft or rotateLeftLeft or rotateRightRight or rotateLeftRight to balance the tree depends on the real situation.

3. The function getBalanceFactor takes an argument Node *p, return return an integer. Inside the function, it recursively goes through p's leftChild and rightChild by calling the function getHeight and make change to the bf. If making change to a leftChild bf will plus the value returned by getHeight and minus the value if the changed was maded to bf of a rightChild.Balance factor is actually for all of p's children the amount of leftChild minus the amount of rightChild so that we can know which direction it tilts to. 

4. The function getHeight taks an argument Node *p and returns an integer. Inside the function, it goes through getHeight of all the nodes by recursion and records the amount of p's leftChild(The total amount of all left nodes of p's childs) and the amount of p's rightChild(Similar to the case in the previous parenthesis) into height_left and height_right. At the end it returns the larger value. 

5. The function rotateLeftLeft, rotateLeftRight, rotateRightLeft and rotateRightRight all takes an argument Node *p. and returns a pointer to Node. Because they are really kind of similar in process, I will just talk about all of them at one time. It makes changes on the seven variable ---- p,p.leftChild,p.rightChild,p.leftChild.leftChild,p.leftChild.rightChild,p.rightChild.leftChild and p.rightChild.rightChild depending on whether the tree is heavy on leftLeft or leftRight or RightLeft or rightRight.



Loop Invariant:
1.The while loop In PA3.c main function. It loop through argv[2] to argv[argc-2] to store all of the input file needs to be read and start parsing each file. Every time it adds a FILE into the FILE **input, it will call the function parseFile to parse the file and then close the file and keep looping.

2. The while loop in function parseFile. It loops through the FILE *fp when fgetc() does not equal to EOF.  Inside the while loop, the function first check the case of "'s" and record them. Then it check whether the char is a letter. It stores the letter into temp(The temporary space for char to stay). After it finds a full word, it will set the next char in temp[] to be 0(representing the null character), allocate the correct memory for the string word and copy the string from temp to word. Then it calls the addItem function in Tree.c and reset the count. 

All of others are recursions not loop.



AVL part:
It actually recursively goes through each node by calling the function balanceNode of each node.It balances the tree by calculating the balanceFactor and make movement of the tree. Inside the function, it calls balanceNode(p.leftChild) if p.leftChild exists first. If it reaches the leftest, it will start calling balanceNode(p.rightChild), if p.rightChild exists. Because of that, it will balance the leftest node first and then start balancing the whole tree. Later on, it checks the balance factor for the node its currently balancing. Balance factor is actually for all of current node's children the amount of leftChild minus the amount of rightChild so that we can know which direction it tilts to. The AVL will depend on the current node's balance factor to keep balancing the tree recursively. There are four cases heavy on leftRight, leftLeft, rightRight or rightLeft. Inside the recursion, it eitehr calls the function rotateRightLeft or rotateLeftLeft or rotateRightRight or rotateLeftRight to balance the tree depends on the case situation. 

The way we know the tree is balanced is because the balance factor for each node is either 0,1 or -1. So the whole tree is balanced.

