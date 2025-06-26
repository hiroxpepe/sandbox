use std::fs::File;
use std::io::Write;
use std::time::Instant;
use rand::Rng;

const ARRAY_SIZE: usize = 30000; // ソートする配列のサイズ
const FILE_PATH: &str = "result/bubblesort_rs.csv"; // ソート結果を出力するパス

// バブルソートアルゴリズムを実行する関数
fn bubblesort(array: &mut [i32]) {
    let size = array.len();
    for i in 0..size - 1 {
        for j in 0..size - i - 1 {
            if array[j] > array[j + 1] {
                array.swap(j, j + 1);
            }
        }
    }
}

// 配列のデータをCSVファイルに出力する関数
fn save_array_to_csv(filepath: &str, array: &[i32]) {
    let mut file = File::create(filepath).expect("Error: creating CSV file.");
    file.write_all(b"index,value\n").expect("Error: writing CSV header.");
    for (i, &value) in array.iter().enumerate() {
        writeln!(file, "{},{}", i, value).expect("Error: writing CSV data.");
    }
    println!("A CSV file was saved successfully.");
}

fn main() {
    // 乱数で配列を初期化
    let mut array = Vec::with_capacity(ARRAY_SIZE);
    let mut rng = rand::thread_rng();
    for _ in 0..ARRAY_SIZE {
        array.push(rng.gen_range(0..i32::MAX));
    }

    // 関数の実行時間を測定
    let start_time = Instant::now();
    bubblesort(&mut array);
    let end_time = Instant::now();

    // 実行時間を秒に変換して表示
    let duration_seconds = end_time.duration_since(start_time).as_secs_f64();
    println!("Sorted {} elements in {:.5} seconds.", ARRAY_SIZE, duration_seconds);

    // ソート結果をCSVファイルに保存
    save_array_to_csv(FILE_PATH, &array);
}
