import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import static java.lang.System.*;

public class Bubblesort {
    static final int ARRAY_SIZE = 30000; // ソートする配列のサイズ
    static final String FILE_PATH = "result/bubblesort_java.csv"; // ソート結果を出力するパス

    // バブルソートアルゴリズムを実行する関数
    public static void bubblesort(int[] array) {
        int size = array.length;
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
    public static void saveArrayToCSV(String filepath, int[] array) {
        try {
            FileWriter writer = new FileWriter(filepath);
            writer.write("index,value\n");
            for (int i = 0; i < array.length; ++i) {
                writer.write(i + "," + array[i] + "\n");
            }
            writer.close();
            out.println("A CSV file was saved successfully.");
        } catch (IOException e) {
            out.println("Error: opening CSV file.");
        }
    }

    public static void main(String[] args) {
        // 乱数で配列を初期化
        int[] array = new int[ARRAY_SIZE];
        Random rand = new Random();
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            array[i] = rand.nextInt(Integer.MAX_VALUE);
        }

        // 関数の実行時間を測定
        long start_time = nanoTime();
        bubblesort(array);
        long end_time = nanoTime();

        // 実行時間を秒に変換して表示
        double duration_seconds = (double) (end_time - start_time) / 1e9;
        out.printf("Sorted %d elements in %.5f seconds.%n", ARRAY_SIZE, duration_seconds);

        // ソート結果をCSVファイルに保存
        saveArrayToCSV(FILE_PATH, array);
    }
}
