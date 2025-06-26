package main

import (
	"fmt"
	"math"
	"math/rand"
	"os"
	"time"
)

const ARRAY_SIZE = 30000                     // ソートする配列のサイズ
const FILE_PATH = "result/bubblesort_go.csv" // ソート結果を出力するパス

// バブルソートアルゴリズムを実行する関数
func bubblesort(array []int) {
	size := len(array)
	for i := 0; i < size-1; i++ {
		for j := 0; j < size-i-1; j++ {
			if array[j] > array[j+1] {
				array[j], array[j+1] = array[j+1], array[j]
			}
		}
	}
}

// 配列のデータをCSVファイルに出力する関数
func save_array_to_csv(filepath string, array []int) {
	file, err := os.Create(filepath)
	if err != nil {
		fmt.Println("Error: opening CSV file.")
		return
	}
	defer file.Close()
	file.WriteString("index,value\n")
	for i, value := range array {
		file.WriteString(fmt.Sprintf("%d,%d\n", i, value))
	}
	fmt.Println("A CSV file was saved successfully.")
}

func main() {
	// 乱数で配列を初期化
	rand.Seed(time.Now().UnixNano())
	array := make([]int, ARRAY_SIZE)
	for i := 0; i < ARRAY_SIZE; i++ {
		array[i] = rand.Intn(math.MaxInt32)
	}

	// 関数の実行時間を測定
	start_time := time.Now()
	bubblesort(array)
	end_time := time.Now()

	// 実行時間を秒に変換して表示
	duration_seconds := end_time.Sub(start_time).Seconds()
	fmt.Printf("Sorted %d elements in %.5f seconds.\n", ARRAY_SIZE, duration_seconds)

	// ソート結果をCSVファイルに保存
	save_array_to_csv(FILE_PATH, array)
}
