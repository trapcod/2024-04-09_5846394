#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 5    // 스택의 최대 크기
typedef int element;        // 데이터의 자료형
element  stack[MAX_STACK_SIZE]; // 1차원 배열
int  top = -1;

// 공백 상태 검출 함수
int is_empty()
{
    return (top == -1);
}
// 포화 상태 검출 함수
int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
int push(element item)
{
    if (is_full()) {
        fprintf(stderr, "스택 포화 에러\n");
        return -1; // 스택이 포화 상태일 때 -1을 반환
    }
    else {
        stack[++top] = item;
        return 0; // 성공적으로 삽입되었을 때 0을 반환
    }
}

// 삭제 함수
element pop()
{
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        return -1; // 스택이 비어있을 때 -1을 반환
    }
    else return stack[top--];
}

// 스택의 모든 요소를 출력하는 함수
void print_stack() {
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(void)
{
    srand(time(NULL));

    for (int i = 1; i < 30; i++) {
        int rand_num = rand() % 100 + 1;

        if (rand_num % 2 == 0) {
            if (push(rand_num) == -1) { // push 함수에서 -1이 반환되면 스택이 포화 상태라는 의미
                printf("current rand_num : %d | Even\nPush %d - Stack is full\n", rand_num, rand_num);
            }
            else {
                printf("current rand_num : %d | Even\nPush : %d\n", rand_num, rand_num);
                print_stack();
            }
        }
        else {
            element popped = pop();
            if (popped == -1) { // pop 함수에서 -1이 반환되면 스택이 비어있다는 의미
                printf("current rand_num : %d | Odd\nPop operation failed - Stack is empty\n", rand_num);
            }
            else {
                printf("current rand_num : %d | Odd\nPop : %d\n", rand_num, popped);
                print_stack();
            }
        }
    }
}