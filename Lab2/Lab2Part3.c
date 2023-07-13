/*Tony wants to use a 4-digit combination lock on a safe where he puts his belongings when
he goes skiing. As a matter of good practice, he wants to change the combination every
time he goes. Since he does not want to worry about people finding out what his combination
is, he writes it on a paper using a coding scheme. If anyone reads his piece of paper,
they will still not know his combination.
The scheme he uses takes the real combination and swaps the 1st and the 4th digit of the
combination, and replaces each of the 2nd and 3rd digits by their 9’s complement. In other
words, a combination of the form abcd is encoded as d(9-b)(9-c)a.
For example, if the actual combination is 0428, the encrypted combination will be 8570
(note that 0 and 8 are swapped, 4 is replaced by 9-4, and 2 is replaced by 9-2). The nice
thing about his coding scheme is that you can apply it again on the encrypted combination
to calculate the real one.
Tony goes to a hypothetical company named Robert & Co. that makes software to secure
clients’ belongings, and he asks them to implement his coding scheme. Yanni, Tia and
Tanushree, who work there, wrote the following code to decipher Tony’s codes:////////

#include <stdio.h> 
int main(void) {
int encComb;
printf("Enter an encrypted 4-digit combination: ");
scanf("%d", &encComb);
// Determine the 4 digits of the encrypted combinaiton.
int d4, d3, d2, d1;
encComb = encComb / 1000;
d4 = encComb % 1000;
encComb = encComb / 100;
d3 = encComb % 100;
encComb = encComb / 10;
d2 = encComb % 10;
d1 = encComb;
// printing the decryped combination: d4 and d1 are swaped. d3 and d2 are
// are 9's complemented
printf("\nThe real combination is: %d%d%d%d\n", d1, 9 - d3, 9 - d2, d4);
return 0;
}

Dominik and Mohamed, who also work at Robert & Co., saw the code and decided to test
it. They entered the encrypted combination 8021, but the program did not output 1978.
They asked you to debug the program and fix the errors.
An example output of a functioning code is shown below:
Enter an encrypted 4-digit combination: 8021<enter>
The real combination is: 1978
Note: You may assume that the entered combination is a valid 4-digit integer number. No
negative numbers will be entered by the user. This means the numbers will be between
0000 and 9999. When reading the 4-digit combination from user input, you are not allowed
to scan in individual characters; instead, you should scan in a single integer using scanf.*/


#include <stdio.h>

int main(void) {
  int encComb;
  printf("Enter an encrypted 4-digit combination: ");
  scanf("%d", &encComb);

  // Determine the 4 digits of the encrypted combination.
  int d4, d3, d2, d1;
  d4 = encComb / 1000;
  d4 = d4 % 1000;
  d3 = (encComb - d4*1000) / 100;
  d3 = d3 % 100;
  d2 = (encComb - d4*1000 - d3*100) / 10;
  d2 = d2 % 10;
  d1 = (encComb - d4*1000 - d3*100 - d2*10);

  // printing the decrypted combination: d4 and d1 are swapped. d3 and d2 are
  // are 9's complemented
  printf("\nThe real combination is: %d%d%d%d\n", d1, 9 - d3, 9 - d2, d4);

  return 0;
}