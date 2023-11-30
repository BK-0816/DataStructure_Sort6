#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int sorted[MAX_SIZE];
int list[MAX_SIZE];
int n;

// ���� ������ �� Ƚ���� �̵� Ƚ���� ����
int Comparisons = 0;
int Moves = 0;

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do {
            low++;
            Comparisons++; // Pivot�� ���� ���� ������ �� Ƚ�� ����
        } while (low <= right && list[low] < pivot);
        do {
            high--;
            Comparisons++; // Pivot�� ���� ���� ������ �� Ƚ�� ����
        } while (high >= left && list[high] > pivot);
        if (low < high) {
            SWAP(list[low], list[high], temp);
            Moves++; // Swap�� ������ �̵� Ƚ�� ����
        }
    } while (low < high);

    SWAP(list[left], list[high], temp);
    Moves++; // Swap�� ������ �̵� Ƚ�� ����
    return high;
}

void quick_sort(int list[], int left, int right, int iteration)
{
    if (left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1,iteration);
        quick_sort(list, q + 1, right,iteration);
    }
    if (iteration == 19) {
        // 20��° ȣ���� ���� ���
        print_array(list, n);
    }
}

int main(void)
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    // ��ü �� Ƚ���� �̵� Ƚ���� �ʱ�ȭ
    int totalComparisons = 0;
    int totalMoves = 0;
    
    //20ȸ �ݺ�
    for (i = 0; i < 20; i++) {
        // �迭 �ʱ�ȭ
        for (int j = 0; j < n; j++) {
            list[j] = rand() % 100;
        }
        if (i == 19) {
            printf("original list: ");
            print_array(list, n);
        }

        Comparisons = 0;
        Moves = 0;
        quick_sort(list, 0, n - 1,i);

        totalComparisons += Comparisons;
        totalMoves += Moves;
    }
    printf("quick sort:");// ������ ���
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    // ��հ� ��� �� ���
    int avgComparisons = totalComparisons / 20;
    int avgMoves = totalMoves / 20;

    printf("Average Comparisons: %d\n", avgComparisons);
    printf("Average Moves: %d\n", avgMoves);

    return 0;
}