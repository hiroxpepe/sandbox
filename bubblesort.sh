#!/bin/bash

ARRAY_SIZE=30000 # ソートする配列のサイズ
FILE_PATH="result/bubblesort_sh_fast.csv" # ソート結果を出力するパス

# 配列のデータをCSVファイルに出力する関数
save_array_to_csv() {
    local filepath=$1
    shift
    local array=("$@")
    # 出力先のディレクトリがなければ作成
    mkdir -p "$(dirname "$filepath")"
    echo "index,value" > "$filepath"
    for ((i = 0; i < ${#array[@]}; i++)); do
        echo "$i,${array[i]}" >> "$filepath"
    done
    echo "A CSV file was saved successfully to $filepath"
}

# 乱数で配列を初期化
array=()
# RANDOMの上限は32767なので、より大きな乱数を生成するために工夫
for ((i = 0; i < ARRAY_SIZE; i++)); do
    array[i]=$(( (RANDOM << 15) | RANDOM ))
done

# --- 高速化されたソート処理 ---
start_time=$(date +%s.%N)

# 配列を改行区切りで出力し、`sort -n`コマンドで数値としてソートし、
# 結果を `mapfile` (readarray) で新しい配列に一括で読み込む
mapfile -t sorted_array < <(printf "%s\n" "${array[@]}" | sort -n)

end_time=$(date +%s.%N)
# --- ここまで ---

# 実行時間を計算して表示
duration_seconds=$(echo "$end_time - $start_time" | bc)
printf "Sorted %d elements in %.5f seconds.\n" "$ARRAY_SIZE" "$duration_seconds"

# ソート結果をCSVファイルに保存
save_array_to_csv "$FILE_PATH" "${sorted_array[@]}"
