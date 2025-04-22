#!/bin/bash
#find . -wholename "rime-out/tests"

format() {
	input() {
		find . -wholename "./rime-out/tests" | while read inpath; do
			judgedata_path="./judgedata/"
			inputfiles=$(ls $inpath | grep ".in$")
			cnt=0
			for i in $inputfiles; do
				#echo "cp" $inpath"/"$i $judgedata_path"/in"$cnt".txt"
				# echo $cnt $i
				cnt=$((cnt + 1))
				echo "$cnt $i" | cat >>$judgedata_path"/"case_mapping.txt
				cp "$inpath/$i" "$judgedata_path/in$cnt.txt"
			done
			echo $cnt | cat >$judgedata_path"/"case.txt
			echo "Found $cnt input cases"
		done
	}

	output() {
		find . -wholename "./rime-out/tests" | while read outpath; do
			judgedata_path="./judgedata/"
			outputfiles=$(ls $outpath | grep ".diff$")
			cnt=0
			for i in $outputfiles; do
				#echo $outpath"/"$i $judgedata_path"/out"$cnt".txt"
				cnt=$((cnt + 1))
				cp "$outpath/$i" "$judgedata_path/out$cnt.txt"
			done
			echo "Found $cnt output cases"
		done
	}

	[[ -d judgedata ]] && rm -rf judgedata
	mkdir judgedata
	input
	output
}

process() {
	# 生成物を保存するディレクトリ
	[[ -d ".generated" ]] && rm -rf ".generated"
	mkdir -p ".generated"
	
	hasError=0

	# ルートディレクトリの各サブディレクトリを処理
	for dir in ./*/; do
	  # tests ディレクトリが存在し、ディレクトリ名がrimeではない場合
	  if [ -d "${dir}tests" ] && [ "$(basename "$dir")" != "rime" ]; then
		echo -e "\e[32mProcessing: ${dir}\e[0m"
	
		# 対象ディレクトリに移動してフォーマット実行
		cd "$dir" || continue
		format
	
	
		# judgedata が生成されていればリネームして移動
		if [ -d "judgedata" ]; then
		  mv "judgedata" "../.generated/$(basename "$dir")"
		  rm -rf "../judgedata"
		fi



		# 問題文をコピー
		if [[ -f "statement-aoj" ]]; then
			cp "statement-aoj" "../.generated/$(basename "$dir")/"
		else
			echo -e "\e[31mERR: No statement-aoj found\e[0m"
			hasError=1
		fi

		# reactive judgeが存在する場合
		if [[ -f "./tests/reactive.cpp" || -f "./tests/reactive.cc" ]]; then
			echo -e "\e[34mDetected reactive judge\e[0m"
			[[ -f "./tests/reactive.cpp" ]] && cp "./tests/reactive.cpp" "../.generated/$(basename "$dir")/"
			[[ -f "./tests/reactive.cc" ]] && cp "./tests/reactive.cc" "../.generated/$(basename "$dir")/"
			if [[ -f "./tests/reactive.hpp" ]]; then
				cp "./tests/reactive.hpp" "../.generated/$(basename "$dir")/"
			else
				echo -e "\e[31mERR: No reactive.hpp found\e[0m"
				hasError=1
			fi
			if [[ -f "./tests/build.sh" ]]; then
				cp "./tests/build.sh" "../.generated/$(basename "$dir")/"
			else
				echo -e "\e[31mERR: No build.sh found\e[0m"
				hasError=1
			fi

		# custom judgeの場合
		elif [[ -f "./tests/judge.cpp" || -f "./tests/judge.cc" ]]; then
			echo -e "\e[34mDetected custom judge\e[0m"
			[[ -f "./tests/judge.cpp" ]] && cp "./tests/judge.cpp" "../.generated/$(basename "$dir")/"
			[[ -f "./tests/judge.cc" ]] && cp "./tests/judge.cc" "../.generated/$(basename "$dir")/"
			if [[ -f "./tests/testlib.h" ]]; then
				cp "./tests/testlib.h" "../.generated/$(basename "$dir")/"
			else
				echo -e "\e[31mERR: No testlib.h found\e[0m"
				hasError=1
			fi
			if [[ -f "./tests/build.sh" ]]; then
				cp "./tests/build.sh" "../.generated/$(basename "$dir")/"
			else
				echo -e "\e[31mERR: No build.sh found\e[0m"
				hasError=1
			fi
		fi

		echo ""
		cd .. || exit 128
	  fi
	done

	return $hasError
}

# メイン処理
if [[ "$1" != "--no-test" ]]; then
	if ! rime/rime.py test; then
		exit 1
	fi
fi

echo ""

process
