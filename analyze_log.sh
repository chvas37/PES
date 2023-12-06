#!/bin/bash

# Проверка наличия файла log.txt
if [ ! -f "log.txt" ]; then
  echo "Файл log.txt не найден."
  exit 1
fi

# Чтение файла построчно и вывод информации
while IFS= read -r line; do
  # Используем awk для извлечения нужных полей
  host=$(echo "$line" | awk '{print $1}')
  timestamp=$(echo "$line" | awk -F '[][]' '{print $2}')
  request=$(echo "$line" | awk -F '"' '{print $2}')
  status_code=$(echo "$line" | awk '{print $9}')
  bytes_sent=$(echo "$line" | awk '{print $10}')
  referer=$(echo "$line" | awk -F '"' '{print $4}')
  user_agent=$(echo "$line" | awk -F '"' '{print $6}')

  # Вывод информации
  echo "Хост клиента: $host"
  echo "Штамп времени: $timestamp"
  echo "HTTP запрос: $request"
  echo "Код HTTP ответа: $status_code"
  echo "Количество переданных байт: $bytes_sent"
  echo "Реферер: $referer"
  echo "Название клиента (браузер): $user_agent"
  echo "--------------------------"

done < "log.txt"
