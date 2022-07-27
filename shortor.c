//
// Created by Matthew Cheng on 5/5/21.
//

#include <stdio.h>
#include <math.h>

int neg (int num);

int rmult (int x, int y);

int square (int num);

int rfact (int n);

int main() {
    // input
    int arr[4] = {4, -9, 13, 0};

    //declare and initialize helper variables
    int i = 0;
    int num = arr[0];
    int num2;
    int print, status;

    //mainloop
    do {
        printf("%10d    0x%.8x\n",num,num);

        //call neg and print return value
        print = neg(num);
        printf("%10d    0x%.8x\n",print,print);

        //call square and print return value
        print = square(num);
        printf("%10d    0x%.8x\n",print,print);

        //set num2 equal to num
        num2 = num;
        if (num2 < 0)
            //call neg on num2 if negative
            num2 = neg(num2);

        //call rfact and print return value
        print = rfact(num2);
        printf("%10d    0x%.8x\n",print,print);

        //set status equal to 0
        status = 0;

        //add 1 if odd
        if (num & 1)
            status += 1;

        //add 2 if negative
        if (num < 0)
            status += 2;

        //add 4 if square is greater than 100
        if (square(num) > 100)
            status += 4;

        //add 16
        status += 16;

        //print status
        printf("              0x%.8x\n",status);

        //print hex 1's
        printf("              0x%x%x%x%x%x%x%x%x\n",1,1,1,1,1,1,1,1);

        //next input
        i++;
        num = arr[i];

    } while (num != 0);

    return 0;
}

int neg (int num) {
    return 0-num;
}

int rmult (int x, int y) {
    int result;

    if (y == 1)
        //base case
        result = x;
    else
        //recursive case
        result = x + rmult(x,y-1);

    return result;
}

int square (int num) {
    // ensure num is positive
    if (num < 0)
        num = neg(num);

    // multiply num by itself and return it
    return rmult(num,num);
}

int rfact (int n) {
    int result;

    if (n <= 1)
        //base case
        result = 1;
    else
        //recursive case
        result = rmult(rfact(n-1),n);

    return result;
}

