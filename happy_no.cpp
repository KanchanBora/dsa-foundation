// C++ program to check a number is a Happy number or not

/*
Input: n = 19
Output: 19 is a Happy Number
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
As we reached to 1, 19 is a Happy Number.

*/


/*
Complexity Analysis:

Time Complexity: O(n*log(n)).
Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

//we treat every number as a node and replace it by square of sum of digit as a link
int func(int n)
{
int r;
int s = 0;
	while(n!=0)
    {
        r = n%10;
        s += (r*r);
        n/= 10;
    }
    return s;
}
/*we will keep two numbers slow and fast both initialized from a given number, 
slow is replaced one step at a time and fast is replaced two steps at a time. 
If they meet at 1, then the given number is Happy Number otherwise not */ 

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = func(slow);
        fast = func(func(fast));
    }
    while(slow!= fast);
    return slow == 1;  
}

int main()
{
	int n;
	cout<<"\n Enter the number :";
	cin>>n;
	if (isHappy(n))
		cout << n << " is a Happy number\n";
	else
		cout << n << " is not a Happy number\n";
}

