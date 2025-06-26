import csv
import random
import time

ARRAY_SIZE = 30000  # ソートする配列のサイズ
FILE_PATH = "result/bubblesort_py.csv"  # ソート結果を出力するパス

# バブルソートアルゴリズムを実行する関数
def bubblesort(array):
    size = len(array)
    for i in range(size - 1):
        for j in range(size - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]

# 配列のデータをCSVファイルに出力する関数
def save_array_to_csv(filepath, array):
    try:
        with open(filepath, mode='w', newline='') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow(['index', 'value'])
            for i in range(len(array)):
                writer.writerow([i, array[i]])
        print("A CSV file was saved successfully.")
    except IOError:
        print("Error: opening CSV file.")

def main():
    # 乱数で配列を初期化
    array = []
    for _ in range(ARRAY_SIZE):
        random_value = random.randint(0, 0x7FFFFFFF)
        array.append(random_value)

    # 関数の実行時間を測定
    start_time = time.time()
    bubblesort(array)
    end_time = time.time()

    # 実行時間を秒に変換して表示
    duration_seconds = end_time - start_time
    print(f"Sorted {ARRAY_SIZE} elements in {duration_seconds:.5f} seconds.")

    # ソート結果をCSVファイルに保存
    save_array_to_csv(FILE_PATH, array)

if __name__ == "__main__":
    main()
