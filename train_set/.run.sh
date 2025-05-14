#!/bin/bash

# 设置 opam 环境
opam switch 5.1.0 > /dev/null 2>&1
eval $(opam env)

# 检查 config.txt 文件是否存在
if [[ ! -f "config.txt" ]]; then
  echo "错误：config.txt 文件不存在。"
  exit 1
fi

# 读取 config.txt 文件的每一行
while IFS=':' read -r path files; do
  # 检查行是否为空
  if [[ -n "$path" ]]; then
    # 将路径转换为绝对路径
    absolute_path=$(realpath "$path")

    # 进入指定的目录
    cd "$absolute_path" || continue

    # 检查是否有文件需要处理
    if [[ -n "$files" ]]; then
      # 仅移除行首和行尾的空白字符，保留文件名之间的空格
      files=$(echo "$files" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')

      # 创建一个数组来存储有效的文件
      valid_files=()
      
      # 检查每个文件是否存在
      for file in $files; do
        if [[ -f "$file" ]]; then
          valid_files+=("$file")
        else
          echo "错误：文件 $file 在 $absolute_path 中不存在。"
        fi
      done
      
      # 如果有有效文件，则一次性执行 frama-c 命令
      if [ ${#valid_files[@]} -gt 0 ]; then
        echo "正在处理文件: ${valid_files[*]}"
        
        # 执行 frama-c 命令，并捕获输出和错误
        if ! frama-c "${valid_files[@]}" -parf   2>&1; then
          echo "错误：frama-c 命令执行失败，文件：${valid_files[*]}"
        else
          echo "frama-c 命令执行成功，文件：${valid_files[*]}"
        fi
      else
        echo "警告：$absolute_path 中没有有效的文件。"
      fi
    else
      echo "警告：$absolute_path 中没有指定的文件。"
    fi
  fi
done < config.txt

echo "所有命令执行完毕。"
