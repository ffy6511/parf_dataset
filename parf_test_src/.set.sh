#!/bin/bash

# 创建配置文件
config_file="config.txt"
> "$config_file"  # 清空或创建配置文件

# 扫描当前目录下的所有 .c 文件
for c_file in *.c; do
  # 检查文件是否存在（避免在没有 .c 文件时的错误）
  if [ -f "$c_file" ]; then
    # 获取文件名（不含扩展名）
    filename="${c_file%.c}"
    
    # 创建与文件同名的目录
    mkdir -p "$filename"
    
    # 复制 .c 文件到新目录
    cp "$c_file" "$filename/$c_file"
    
    # 获取新目录的绝对路径
    abs_path=$(realpath "$filename")
    
    # 将信息写入配置文件
    echo "$abs_path: $c_file" >> "$config_file"
    
    echo "处理文件: $c_file -> $filename/$c_file"
  fi
done

echo "完成！配置信息已写入 $config_file"
