#include <stdio.h>

// 1. 사용자에게 1부터 100사이의 숫자를 10개 입력받는다.
// 이를 순서대로 출력하라. 단, 사용자가 입력하는 동안 이미 입력한 숫자와 같은 숫자를 입력하면 "잘못 입력하였습니다. 다시 입력하세요."라는 문구와 함께 다시 입력받도록 하라. 입력이 완료되면 10개의 수를 모두 출력하라.

// 변수는 다음과 같이 사용하라.

// int number[10];     // 사용자가 입력한 숫자 10개
// int count;          // 현재까지 입력된 숫자의 갯수(0~10)
// int i;              // 반복문을 위한 변수

int main()
{
    int input=10;
    int number[10]; // 사용자가 입력한 숫자 10개
    int count = 1;  // 현재까지 입력된 숫자의 갯수(0~10)
    int i = 0;      // 반복문을 위한 변수
    int px = 0;
    printf("Enter a number between 1 and 100.\n");
    while (count <= 10)
    {
        number[i] = 0;
        printf("Enter the %dth number: ", count);
        scanf("%d", &number[i]);
        if (count == 1)
        {
            count = count + 1;
            i++;
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (number[j] == number[i] || number[i] <= 0 || number[i] > 100)
                {
                    printf("Invalid input. Please enter again.\n");
                    px = 1;
                    break;
                }
                else
                {
                    px = 0;
                }
            }
            if (px == 0)
            {
                count = count + 1;
                i++;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("The %dth number is %d.\n", i + 1, number[i]);
    }

    return 0;
}