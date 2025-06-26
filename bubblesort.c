#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 30000 // ソートする配列のサイズ
#define FILE_PATH "result/bubblesort_c.csv" // ソート結果を出力するパス

// バブルソートアルゴリズムを実行する関数
void bubblesort(int array[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// 配列のデータをCSVファイルに出力する関数
void save_array_to_csv(const char* filepath, int array[], int array_size) {
    FILE* outfile = fopen(filepath, "w");
    if (outfile != NULL) {
        fprintf(outfile, "index,value\n");
        for (int i = 0; i < array_size; ++i) {
            fprintf(outfile, "%d,%d\n", i, array[i]);
        }
        fclose(outfile);
        printf("A CSV file was saved successfully.\n");
    } else {
        printf("Error: opening CSV file.\n");
    }
}

int main() {
    // 乱数で配列を初期化
    srand((unsigned int)time(NULL));
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = rand() % RAND_MAX;
    }

    // 関数の実行時間を測定
    clock_t start_time = clock();
    bubblesort(array, ARRAY_SIZE);
    clock_t end_time = clock();

    // 実行時間を秒に変換して表示
    double duration_seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Sorted %d elements in %.5lf seconds.\n", ARRAY_SIZE, duration_seconds);

    // ソート結果をCSVファイルに保存
    save_array_to_csv(FILE_PATH, array, ARRAY_SIZE);

    return 0;
}
