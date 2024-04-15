#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 5    // ������ �ִ� ũ��
typedef int element;        // �������� �ڷ���
element  stack[MAX_STACK_SIZE]; // 1���� �迭
int  top = -1;

// ���� ���� ���� �Լ�
int is_empty()
{
    return (top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
int push(element item)
{
    if (is_full()) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return -1; // ������ ��ȭ ������ �� -1�� ��ȯ
    }
    else {
        stack[++top] = item;
        return 0; // ���������� ���ԵǾ��� �� 0�� ��ȯ
    }
}

// ���� �Լ�
element pop()
{
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        return -1; // ������ ������� �� -1�� ��ȯ
    }
    else return stack[top--];
}

// ������ ��� ��Ҹ� ����ϴ� �Լ�
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
            if (push(rand_num) == -1) { // push �Լ����� -1�� ��ȯ�Ǹ� ������ ��ȭ ���¶�� �ǹ�
                printf("current rand_num : %d | Even\nPush %d - Stack is full\n", rand_num, rand_num);
            }
            else {
                printf("current rand_num : %d | Even\nPush : %d\n", rand_num, rand_num);
                print_stack();
            }
        }
        else {
            element popped = pop();
            if (popped == -1) { // pop �Լ����� -1�� ��ȯ�Ǹ� ������ ����ִٴ� �ǹ�
                printf("current rand_num : %d | Odd\nPop operation failed - Stack is empty\n", rand_num);
            }
            else {
                printf("current rand_num : %d | Odd\nPop : %d\n", rand_num, popped);
                print_stack();
            }
        }
    }
}