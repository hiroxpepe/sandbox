using System;
using System.IO;
using static System.Console;
using static System.DateTime;

public class Program {
    const int ARRAY_SIZE = 30000; // ソートする配列のサイズ
    const string FILE_PATH = "result/bubblesort_cs.csv"; // ソート結果を出力するパス

    // バブルソートアルゴリズムを実行する関数
    static void bubblesort(int[] array) {
        int size = array.Length;
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
    static void saveArrayToCSV(string filepath, int[] array) {
        try {
            using (StreamWriter writer = new(filepath)) {
                writer.WriteLine("index,value");
                for (int i = 0; i < array.Length; ++i) {
                    writer.WriteLine($"{i},{array[i]}");
                }
            }
            WriteLine("A CSV file was saved successfully.");
        } catch (IOException) {
            WriteLine("Error: opening CSV file.");
        }
    }

    static void Main(string[] args) {
        // 乱数で配列を初期化
        int[] array = new int[ARRAY_SIZE];
        Random rand = new();
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            array[i] = rand.Next(int.MaxValue);
        }

        // 関数の実行時間を測定
        long start_time = Now.Ticks;
        bubblesort(array);
        long end_time = Now.Ticks;

        // 実行時間を秒に変換して表示
        double duration_seconds = (end_time - start_time) / 1e7;
        WriteLine($"Sorted {ARRAY_SIZE} elements in {duration_seconds:f5} seconds.");

        // ソート結果をCSVファイルに保存
        saveArrayToCSV(FILE_PATH, array);
    }
}
