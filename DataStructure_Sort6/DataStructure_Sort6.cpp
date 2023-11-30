#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int sorted[MAX_SIZE];
int list[MAX_SIZE];
int n;

// 전역 변수로 비교 횟수와 이동 횟수를 저장
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
            Comparisons++; // Pivot과 값을 비교할 때마다 비교 횟수 증가
        } while (low <= right && list[low] < pivot);
        do {
            high--;
            Comparisons++; // Pivot과 값을 비교할 때마다 비교 횟수 증가
        } while (high >= left && list[high] > pivot);
        if (low < high) {
            SWAP(list[low], list[high], temp);
            Moves++; // Swap할 때마다 이동 횟수 증가
        }
    } while (low < high);

    SWAP(list[left], list[high], temp);
    Moves++; // Swap할 때마다 이동 횟수 증가
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
        // 20번째 호출일 때만 출력
        print_array(list, n);
    }
}

int main(void)
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    // 전체 비교 횟수와 이동 횟수를 초기화
    int totalComparisons = 0;
    int totalMoves = 0;
    
    //20회 반복
    for (i = 0; i < 20; i++) {
        // 배열 초기화
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
    printf("quick sort:");// 퀵정렬 출력
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    // 평균값 계산 및 출력
    int avgComparisons = totalComparisons / 20;
    int avgMoves = totalMoves / 20;

    printf("Average Comparisons: %d\n", avgComparisons);
    printf("Average Moves: %d\n", avgMoves);

    return 0;
}