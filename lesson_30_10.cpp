// №1
//
//#!/bin/bash
//
//// Убедитесь, что файл log.txt существует и доступен
//if [ ! -f log.txt ]; then
//        echo "Файл log.txt не найден."
//exit 1
//fi
//
//// Читаем файл построчно
//while IFS= read -r line
//do
//// Разбиваем строку на составные части
//IFS=' ' read -ra ADDR <<< "$line"
//host="${ADDR[0]}"
//timestamp=$(echo $line | cut -d '[' -f2 | cut -d ']' -f1)
//request=$(echo $line | cut -d '"' -f2)
//http_code=$(echo $line | cut -d '"' -f3 | cut -d ' ' -f2)
//bytes=$(echo $line | cut -d '"' -f3 | cut -d ' ' -f3)
//referrer=$(echo $line | cut -d '"' -f4)
//agent=$(echo $line | cut -d '"' -f6)
//
//// Выводим информацию
//echo "Хост: $host"
//echo "Время: $timestamp"
//echo "Запрос: $request"
//echo "Код ответа HTTP: $http_code"
//echo "Количество байт: $bytes"
//echo "Реферер: $referrer"
//echo "Агент пользователя: $agent"
//echo "----------------------------------"
//done < "log.txt"
//
// №2
//
//#!/bin/bash
//
//// Проверяем, существует ли файл log.txt
//if [ ! -f log.txt ]; then
//        echo "Файл log.txt не найден."
//exit 1
//fi
//
//// Считываем параметр, если он был передан
//        http_code_filter=$1
//
//// Читаем файл построчно
//while IFS= read -r line
//do
// // Разбиваем строку на составные части
//IFS=' ' read -ra ADDR <<< "$line"
//http_code=$(echo $line | cut -d '"' -f3 | cut -d ' ' -f2)
//
//// Фильтруем строки по коду ответа, если параметр был передан
//if [[ -z "$http_code_filter" || "$http_code" == "$http_code_filter" ]]; then
//        host="${ADDR[0]}"
//timestamp=$(echo $line | cut -d '[' -f2 | cut -d ']' -f1)
//request=$(echo $line | cut -d '"' -f2)
//bytes=$(echo $line | cut -d '"' -f3 | cut -d ' ' -f3)
//referrer=$(echo $line | cut -d '"' -f4)
//agent=$(echo $line | cut -d '"' -f6)
//
//// Выводим информацию
//echo "Хост: $host"
//echo "Время: $timestamp"
//echo "Запрос: $request"
//echo "Код ответа HTTP: $http_code"
//echo "Количество байт: $bytes"
//echo "Реферер: $referrer"
//echo "Агент пользователя: $agent"
//echo "----------------------------------"
//fi
//        done < "log.txt"
//
// №3
//
//#!/bin/bash
//
//// Проверяем, существует ли файл log.txt
//if [ ! -f log.txt ]; then
//        echo "Файл log.txt не найден."
//exit 1
//fi
//
//// Инициализация переменных фильтра
//        host_filter=""
//timestamp_filter=""
//http_code_filter=""
//
//// Обработка ключей
//while getopts "h:t:c:" opt; do
//case $opt in
//h) host_filter=$OPTARG ;;
//t) timestamp_filter=$OPTARG ;;
//c) http_code_filter=$OPTARG ;;
//\?) echo "Неверный ключ: -$OPTARG" >&2
//exit 1
//esac
//        done
//
//// Читаем файл построчно
//while IFS= read -r line
//do
//// Извлекаем данные из строки
//IFS=' ' read -ra ADDR <<< "$line"
//host="${ADDR[0]}"
//timestamp=$(echo $line | cut -d '[' -f2 | cut -d ']' -f1)
//request=$(echo $line | cut -d '"' -f2)
//http_code=$(echo $line | cut -d '"' -f3 | cut -d ' ' -f2)
//bytes=$(echo $line | cut -d '"' -f3 | cut -d ' ' -f3)
//referrer=$(echo $line | cut -d '"' -f4)
//agent=$(echo $line | cut -d '"' -f6)
//
//// Фильтрация
//if [[ ( -z "$host_filter" || "$host" == "$host_filter" ) &&
//( -z "$timestamp_filter" || "$timestamp" == "$timestamp_filter" ) &&
//( -z "$http_code_filter" || "$http_code" == "$http_code_filter" ) ]]; then
//        echo "Хост: $host"
//echo "Время: $timestamp"
//echo "Запрос: $request"
//echo "Код ответа HTTP: $http_code"
//echo "Количество байт: $bytes"
//echo "Реферер: $referrer"
//echo "Агент пользователя: $agent"
//echo "----------------------------------"
//fi
//        done < "log.txt"
//
// № Задание 4
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main(int argc, char *argv[]) {
//    FILE *file;
//    char line[1024]; // Предполагаем, что каждая строка не превышает 1024 символов
//
//    file = fopen("log.txt", "r");
//    if (file == NULL) {
//        perror("Ошибка при открытии файла");
//        return 1;
//    }
//
//    while (fgets(line, sizeof(line), file)) {
//        char host[50], timestamp[50], request[100], referrer[100], agent[100];
//        int http_code, bytes;
//
//        sscanf(line, "%s - - [%[^]]] \"%[^\"]\" %d %d \"%[^\"]\" \"%[^\"]\"",
//               host, timestamp, request, &http_code, &bytes, referrer, agent);
//
//        // Пример фильтрации: выводим только строки с кодом HTTP 200
//        if (http_code == 200) {
//            printf("Хост: %s\n", host);
//            printf("Время: %s\n", timestamp);
//            printf("Запрос: %s\n", request);
//            printf("Код ответа HTTP: %d\n", http_code);
//            printf("Количество байт: %d\n", bytes);
//            printf("Реферер: %s\n", referrer);
//            printf("Агент пользователя: %s\n", agent);
//            printf("----------------------------------\n");
//        }
//    }
//    fclose(file);
//    return 0;
//}
