//Задача №1

//#include <iostream>
//
//void selectionSort(int arr[], int n) {
//    for (int i = 0; i < n - 1; ++i) {
//        int minIndex = i;
//        for (int j = i + 1; j < n; ++j) {
//            if (arr[j] < arr[minIndex]) {
//                minIndex = j;
//            }
//        }
//
//        std::swap(arr[i], arr[minIndex]);
//    }
//}
//
//int main() {
//    int arr[] = {64, 25, 12, 22, 11};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    std::cout << "Исходный массив: ";
//    for (int i = 0; i < n; ++i) {
//        std::cout << arr[i] << " ";
//    }
//
//    selectionSort(arr, n);
//
//    std::cout << "\nОтсортированный массив: ";
//    for (int i = 0; i < n; ++i) {
//        std::cout << arr[i] << " ";
//    }
//
//    return 0;
//}

//Задача №2

//#include <iostream>
//#include <cmath>
//
//int findClosestToAverage(int arr[], int n) {
//    // Находим среднее значение массива
//    double average = 0;
//    for (int i = 0; i < n; ++i) {
//        average += arr[i];
//    }
//    average /= n;
//
//    // Ищем элемент, наиболее близкий к среднему значению
//    int closest = arr[0];
//    double minDifference = std::abs(arr[0] - average);
//
//    for (int i = 1; i < n; ++i) {
//        double difference = std::abs(arr[i] - average);
//        if (difference < minDifference) {
//            minDifference = difference;
//            closest = arr[i];
//        }
//    }
//
//    return closest;
//}
//
//int main() {
//    int arr[] = {3, 7, 2, 8, 4};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    std::cout << "Массив: ";
//    for (int i = 0; i < n; ++i) {
//        std::cout << arr[i] << " ";
//    }
//
//    int closestElement = findClosestToAverage(arr, n);
//
//    std::cout << "\nЭлемент, наиболее близкий к среднему значению: " << closestElement << std::endl;
//
//    return 0;
//}
