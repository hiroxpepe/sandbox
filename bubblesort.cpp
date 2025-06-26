#include <chrono>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
using namespace std::chrono;
using namespace std::filesystem;

const long ARRAY_SIZE = 30000; // ソートする配列のサイズ
const string FILE_PATH = "result/bubblesort_cpp.csv"; // ソート結果を出力するパス

// バブルソートアルゴリズムを実行する関数
void bubblesort(int array[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

// 配列のデータをCSVファイルに出力する関数
void save_array_to_csv(const string& filepath, int array[], int array_size) {
    create_directories(path(filepath).parent_path());
    ofstream outfile(filepath);
    if (outfile.is_open()) {
        outfile << "index,value" << endl;
        for (int i = 0; i < array_size; ++i) {
            outfile << i << "," << array[i] << endl;
        }
        outfile.close();
        cout << "A CSV file was saved successfully." << endl;
    } else {
        cout << "Error: opening CSV file." << endl;
    }
}

int main() {
    // 乱数で配列を初期化
    srand(static_cast<unsigned int>(time(nullptr)));
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = rand() % RAND_MAX;
    }

    // 関数の実行時間を測定
    auto start_time = high_resolution_clock::now();
    bubblesort(array, ARRAY_SIZE);
    auto end_time = high_resolution_clock::now();

    // 実行時間を秒に変換して表示
    auto duration_microseconds = duration_cast<microseconds>(end_time - start_time).count();
    double duration_seconds = static_cast<double>(duration_microseconds) / 1e6;
    cout << "Sorted " << ARRAY_SIZE << " elements in " << fixed << setprecision(5) << setfill('0') << duration_seconds << " seconds." << endl;
    
    // ソート結果をCSVファイルに保存
    save_array_to_csv(FILE_PATH, array, ARRAY_SIZE);

    return 0;
}
