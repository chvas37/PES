#!/bin/bash

# Убедитесь, что файл log.txt существует и доступен
if [ ! -f log.txt ]; then
        echo "Файл log.txt не найден."
exit 1
fi

# Читаем файл построчно
while IFS= read -r line
do
# Разбиваем строку на составные части
IFS=' ' read -ra ADDR <<< "$line"
host="${ADDR[0]}"
timestamp=$(echo $line | cut -d '[' -f2 | cut -d ']' -f1)
request=$(echo $line | cut -d '"' -f2)
http_code=$(echo $line | cut -d '"' -f3 | cut -d ' ' -f2)
bytes=$(echo $line | cut -d '"' -f3 | cut -d ' ' -f3)
referrer=$(echo $line | cut -d '"' -f4)
agent=$(echo $line | cut -d '"' -f6)

# Выводим информацию
echo "Хост: $host"
echo "Время: $timestamp"
echo "Запрос: $request"
echo "Код ответа HTTP: $http_code"
echo "Количество байт: $bytes"
echo "Реферер: $referrer"
echo "Агент пользователя: $agent"
echo "----------------------------------"
done < "log.txt"
