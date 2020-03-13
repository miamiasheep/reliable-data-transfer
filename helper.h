#include "prog2.h"
int calcuateCheckSum(char* input)
{
    int checkSum = 0;
    int index = 0;
    while(input[index]!=0 && index < 20)
    {
		if(index == 0)
        {
            checkSum = input[index];
            index += 1;
            continue;
        }
        checkSum += input[index];
        if(checkSum > 255)
        {
            checkSum = checkSum - 255 + 1;
        }
        // perform one's complement
        checkSum = ~checkSum & 255;
        index ++;
    }
    return checkSum;
}
