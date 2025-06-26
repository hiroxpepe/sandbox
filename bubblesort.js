const fs = require('fs');

const ARRAY_SIZE = 30000; // ソートする配列のサイズ
const FILE_PATH = 'result/bubblesort_js.csv'; // ソート結果を出力するパス

// バブルソートアルゴリズムを実行する関数
function bubblesort(array) {
    const size = array.length;
    for (let i = 0; i < size - 1; ++i) {
        for (let j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                const temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// 配列のデータをCSVファイルに出力する関数
function save_array_to_csv(filepath, array) {
    try {
        const writer = fs.createWriteStream(filepath);
        writer.write('index,value\n');
        for (let i = 0; i < array.length; ++i) {
            writer.write(`${i},${array[i]}\n`);
        }
        writer.end();
        console.log('A CSV file was saved successfully.');
    } catch (error) {
        console.error('Error: opening CSV file.');
    }
}

function main() {
    // 乱数で配列を初期化
    const array = new Array(ARRAY_SIZE);
    for (let i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = Math.floor(Math.random() * 0x7FFFFFFF);
    }

    // 関数の実行時間を測定
    const start_time = process.hrtime.bigint();
    bubblesort(array);
    const end_time = process.hrtime.bigint();

    // 実行時間を秒に変換して表示
    const duration_seconds = Number(end_time - start_time) / 1e9;
    console.log(`Sorted ${ARRAY_SIZE} elements in ${duration_seconds.toFixed(5)} seconds.`);

    // ソート結果をCSVファイルに保存
    save_array_to_csv(FILE_PATH, array);
}

main();
