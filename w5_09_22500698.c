#include <stdio.h>

/*
다음과 같이 5명의 학생들에게 10문제의 답을 입력받아, 이를 채점하여 등급을 매기는 작업을 하는 프로그램을 작성하라. 학생별로 10개씩의 답안을 입력받은 후에, 각 등급별 학생 이름과 인원수를 출력하라.

단, 10문제의 정답은 미리 코드에 제시된 그대로 사용하라.

등급은 다음과 같이 결정한다.

1st : 9~10문제 맞춘 경우
2nd : 7~8문제 맞춘 경우
Fail : 6문제 이하로 맞춘 경우
변수는 제시된 것을 사용하되, 부득이한 경우 용도를 명시하고 추가해도 좋다.
*/

int main(void)
{
    int i, j;                                                          // 반복문을 위한 변수
    int jumsu = 0;                                                     // 점수 계산용 변수
    int count[3];                                                      // 인원수 계산용 변수 : 등급별로.
    char names[5][20] = {"James", "David", "Simon", "Peter", "Jason"}; // 학생 이름
    int sheet[5][10];                                                  // 학생별 답안내용
    int answer[10] = {1, 2, 3, 4, 1, 2, 3, 4, 3, 2};                   // 정답순서
    int grade[5];                                                      // 학생별 등급
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            sheet[i][j] = 0;           // sheet 배열 초기화
            scanf("%d", &sheet[i][j]); // i번째 학생의 답안 10개 입력
        }
    }
    for (i = 0; i < 5; i++)
    {
        grade[i] = 0;
        for (j = 0; j < 10; j++)
        {
            if (sheet[i][j] == answer[j])
            {
                jumsu = jumsu + 1;
            }
        }
        if (jumsu >= 9)
        {
            grade[i] = 1;
        }
        else if (jumsu >= 7)
        {
            grade[i] = 2;
        }
        else
        {
            grade[i] = 3;
        }
        jumsu = 0;
    }
    count[0] = 0; // 1등급
    count[1] = 0; // 2등급
    count[2] = 0; // Fail

    for (i = 0; i < 5; i++)
    {
        if (grade[i] == 1)
        {
            count[0] = count[0] + 1;
        }
        else if (grade[i] == 2)
        {
            count[1] = count[1] + 1;
        }
        else
        {
            count[2] = count[2] + 1;
        }
    }
    printf("Grade result\n");
    printf("1st : ");
    for (i = 0; i < 5; i++)
    {

        if (grade[i] == 1)
        {
            printf("%s", names[i]);
            printf(" ");
        }
    }
    printf("(%d)", count[0]);
    printf("\n");
    printf("2nd : ");
    for (i = 0; i < 5; i++)
    {

        if (grade[i] == 2)
        {
            printf("%s", names[i]);
            printf(" ");
        }
    }
    printf("(%d)", count[1]);
    printf("\n");
    printf("Fail : ");
    for (i = 0; i < 5; i++)
    {
        if (grade[i] == 3)
        {
            printf("%s", names[i]);
            printf(" ");
        }
    }
    printf("(%d)", count[2]);
    printf("\n");

    return 0;
}