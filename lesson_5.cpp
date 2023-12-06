////№1
////#include <iostream>
////#include <vector>
////
////class Matrix {
////private:
////    int rows;
////    int cols;
////    std::vector<std::vector<double>> data;
////
////public:
////    Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {}
////
////    // Метод для получения значения элемента матрицы
////    double get(int row, int col) const {
////        if (row < 0 || row >= rows || col < 0 || col >= cols) {
////            std::cerr << "Недопустимый индекс" << std::endl;
////            return 0.0;
////        }
////        return data[row][col];
////    }
////
////    // Метод для установки значения элемента матрицы
////    void set(int row, int col, double value) {
////        if (row < 0 || row >= rows || col < 0 || col >= cols) {
////            std::cerr << "Недопустимый индекс" << std::endl;
////            return;
////        }
////        data[row][col] = value;
////    }
////
////    // Метод для сложения двух матриц
////    Matrix operator+(const Matrix& other) const {
////        if (rows != other.rows || cols != other.cols) {
////            std::cerr << "Несоответствующие размеры матриц для сложения" << std::endl;
////            return Matrix(0, 0);
////        }
////
////        Matrix result(rows, cols);
////        for (int i = 0; i < rows; ++i) {
////            for (int j = 0; j < cols; ++j) {
////                result.set(i, j, data[i][j] + other.data[i][j]);
////            }
////        }
////        return result;
////    }
////
////    // Метод для вычитания двух матриц
////    Matrix operator-(const Matrix& other) const {
////        if (rows != other.rows || cols != other.cols) {
////            std::cerr << "Несоответствующие размеры матриц для вычитания" << std::endl;
////            return Matrix(0, 0);
////        }
////
////        Matrix result(rows, cols);
////        for (int i = 0; i < rows; ++i) {
////            for (int j = 0; j < cols; ++j) {
////                result.set(i, j, data[i][j] - other.data[i][j]);
////            }
////        }
////        return result;
////    }
////
////    // Метод для умножения матрицы на число
////    Matrix operator*(double scalar) const {
////        Matrix result(rows, cols);
////        for (int i = 0; i < rows; ++i) {
////            for (int j = 0; j < cols; ++j) {
////                result.set(i, j, data[i][j] * scalar);
////            }
////        }
////        return result;
////    }
////
////    // Метод для произведения двух матриц
////    Matrix operator*(const Matrix& other) const {
////        if (cols != other.rows) {
////            std::cerr << "Несоответствующие размеры матриц для умножения" << std::endl;
////            return Matrix(0, 0);
////        }
////
////        int resultRows = rows;
////        int resultCols = other.cols;
////        Matrix result(resultRows, resultCols);
////
////        for (int i = 0; i < resultRows; ++i) {
////            for (int j = 0; j < resultCols; ++j) {
////                double sum = 0.0;
////                for (int k = 0; k < cols; ++k) {
////                    sum += data[i][k] * other.data[k][j];
////                }
////                result.set(i, j, sum);
////            }
////        }
////        return result;
////    }
////
////    // Метод для вычисления транспонированной матрицы
////    Matrix transpose() const {
////        Matrix result(cols, rows);
////        for (int i = 0; i < rows; ++i) {
////            for (int j = 0; j < cols; ++j) {
////                result.set(j, i, data[i][j]);
////            }
////        }
////        return result;
////    }
////
////    // Метод для возведения матрицы в степень (целое число)
////    Matrix power(int exponent) const {
////        if (rows != cols) {
////            std::cerr << "Матрица должна быть квадратной для возведения в степень" << std::endl;
////            return Matrix(0, 0);
////        }
////
////        if (exponent == 0) {
////            Matrix result(rows, cols);
////            for (int i = 0; i < rows; ++i) {
////                result.set(i, i, 1.0);  // Единичная матрица
////            }
////            return result;
////        }
////
////        if (exponent < 0) {
////            std::cerr << "Отрицательная степень не поддерживается" << std::endl;
////            return Matrix(0, 0);
////        }
////
////        Matrix result = *this;
////        for (int i = 1; i < exponent; ++i) {
////            result = result * (*this);
////        }
////        return result;
////    }
////
////    // Метод для вывода матрицы
////    void print() const {
////        for (int i = 0; i < rows; ++i) {
////            for (int j = 0; j < cols; ++j) {
////                std::cout << data[i][j] << " ";
////            }
////            std::cout << std::endl;
////        }
////    }
////};
////
////int main() {
////    Matrix A(2, 2);
////    Matrix B(2, 2);
////
////    // Заполнение матриц A и B значениями
////
////    Matrix C = A + B; // Сложение матриц
////    Matrix D = A - B; // Вычитание матриц
////    Matrix E = A * 2.0; // Умножение матрицы на число
////    Matrix F = A * B; // Произведение двух матриц
////    Matrix G = A.transpose(); // Транспонированная матрица
////    Matrix H = A.power(2); // Возведение матрицы в степень
////
////    // Вывод результатов
////    std::cout << "Матрица C (Сложение):" << std::endl;
////    C.print();
////
////    std::cout << "Матрица D (Вычитание):" << std::endl;
////    D.print();
////
////    std::cout << "Матрица E (Умножение на число):" << std::endl;
////    E.print();
////
////    std::cout << "Матрица F (Произведение двух матриц):" << std::endl;
////    F.print();
////
////    std::cout << "Матрица G (Транспонированная матрица):" << std::endl;
////    G.print();
////
////    std::cout << "Матрица H (Возведение в степень 2):" << std::endl;
////    H.print();
////
////    return 0;
////}
////
////№2
////#include <iostream>
////#include <cmath>
////#include <vector>
////#include <cstdlib>
////#include <ctime>
////
////class Vector {
////private:
////    double x;
////    double y;
////    double z;
////
////public:
////    Vector(double x, double y, double z) : x(x), y(y), z(z) {}
////
////    double length() const {
////        return sqrt(x * x + y * y + z * z);
////    }
////
////    double dotProduct(const Vector& other) const {
////        return x * other.x + y * other.y + z * other.z;
////    }
////
////    Vector crossProduct(const Vector& other) const {
////        double resultX = y * other.z - z * other.y;
////        double resultY = z * other.x - x * other.z;
////        double resultZ = x * other.y - y * other.x;
////        return Vector(resultX, resultY, resultZ);
////    }
////
////    double angleCosine(const Vector& other) const {
////        double dot = dotProduct(other);
////        double lengthProduct = length() * other.length();
////        return dot / lengthProduct;
////    }
////
////    Vector add(const Vector& other) const {
////        return Vector(x + other.x, y + other.y, z + other.z);
////    }
////
////    Vector subtract(const Vector& other) const {
////        return Vector(x - other.x, y - other.y, z - other.z);
////    }
////
////    static std::vector<Vector> randomVectors(int N) {
////        std::vector<Vector> vectors;
////        std::srand(static_cast<unsigned>(std::time(nullptr)));
////        for (int i = 0; i < N; ++i) {
////            double x = static_cast<double>(std::rand()) / RAND_MAX * 2.0 - 1.0;
////            double y = static_cast<double>(std::rand()) / RAND_MAX * 2.0 - 1.0;
////            double z = static_cast<double>(std::rand()) / RAND_MAX * 2.0 - 1.0;
////            vectors.push_back(Vector(x, y, z));
////        }
////        return vectors;
////    }
////
////    void print() const {
////        std::cout << "(" << x << ", " << y << ", " << z << ")";
////    }
////};
////
////int main() {
////    Vector v1(1.0, 2.0, 3.0);
////    Vector v2(4.0, 5.0, 6.0);
////
////    std::cout << "Length of v1: " << v1.length() << std::endl;
////    std::cout << "Dot product of v1 and v2: " << v1.dotProduct(v2) << std::endl;
////
////    Vector cross = v1.crossProduct(v2);
////    std::cout << "Cross product of v1 and v2: ";
////    cross.print();
////    std::cout << std::endl;
////
////    std::cout << "Cosine of angle between v1 and v2: " << v1.angleCosine(v2) << std::endl;
////
////    Vector sum = v1.add(v2);
////    std::cout << "Sum of v1 and v2: ";
////    sum.print();
////    std::cout << std::endl;
////
////    Vector difference = v1.subtract(v2);
////    std::cout << "Difference of v1 and v2: ";
////    difference.print();
////    std::cout << std::endl;
////
////    std::vector<Vector> randomVectors = Vector::randomVectors(3);
////    std::cout << "Random vectors: ";
////    for (const Vector& vector : randomVectors) {
////        vector.print();
////        std::cout << " ";
////    }
////    std::cout << std::endl;
////
////    return 0;
////}
////
////
////№3
////#include <iostream>
////#include <vector>
////
////// Базовый класс для трехмерных фигур
////class Shape {
////public:
////    virtual double getVolume() const = 0;
////
////};
////
////// Класс для сферы
////class Sphere : public Shape {
////private:
////    double radius;
////
////public:
////    Sphere(double r) : radius(r) {}
////
////    double getVolume() const override {
////        return (4.0 / 3.0) * 3.14159265359 * radius * radius * radius;
////    }
////};
////
////// Класс для параллелепипеда
////class Cuboid : public Shape {
////private:
////    double length;
////    double width;
////    double height;
////
////public:
////    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {}
////
////    double getVolume() const override {
////        return length * width * height;
////    }
////};
////
////// Класс контейнера для фигур
////class Box {
////private:
////    double capacity; // Объем контейнера
////    double usedSpace; // Занятое место
////    std::vector<Shape*> shapes; // Вектор указателей на фигуры
////
////public:
////    Box(double c) : capacity(c), usedSpace(0.0) {}
////
////    bool add(Shape* shape) {
////        if (usedSpace + shape->getVolume() <= capacity) {
////            shapes.push_back(shape);
////            usedSpace += shape->getVolume();
////            return true;
////        }
////        return false; // Не хватает места
////    }
////
////    double getUsedSpace() const {
////        return usedSpace;
////    }
////};
////
////int main() {
////    Box box(1000.0); // Создаем контейнер объемом 1000
////
////    Sphere sphere1(5.0);
////    Cuboid cuboid1(10.0, 2.0, 5.0);
////    Sphere sphere2(3.0);
////
////    // Пытаемся добавить фигуры в контейнер
////    if (box.add(&sphere1)) {
////        std::cout << "Добавлена сфера 1" << std::endl;
////    } else {
////        std::cout << "Не удалось добавить сферу 1" << std::endl;
////    }
////
////    if (box.add(&cuboid1)) {
////        std::cout << "Добавлен параллелепипед 1" << std::endl;
////    } else {
////        std::cout << "Не удалось добавить параллелепипед 1" << std::endl;
////    }
////
////    if (box.add(&sphere2)) {
////        std::cout << "Добавлена сфера 2" << std::endl;
////    } else {
////        std::cout << "Не удалось добавить сферу 2" << std::endl;
////    }
////
////    std::cout << "Использовано места в контейнере: " << box.getUsedSpace() << " единиц объема" << std::endl;
////
////    return 0;
////}
//
////№4
////#include <iostream>
////#include <vector>
////
////// Абстрактный класс для трехмерных фигур
////class Shape {
////public:
////    virtual double getVolume() const = 0;
////};
////
////// Класс для сферы
////class Sphere : public Shape {
////private:
////    double radius;
////
////public:
////    Sphere(double r) : radius(r) {}
////
////    double getVolume() const override {
////        return (4.0 / 3.0) * 3.14159265359 * radius * radius * radius;
////    }
////};
////
////// Класс для параллелепипеда
////class Cuboid : public Shape {
////private:
////    double length;
////    double width;
////    double height;
////
////public:
////    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {}
////
////    double getVolume() const override {
////        return length * width * height;
////    }
////};
////
////// Класс контейнера для фигур
////class Box {
////private:
////    double capacity; // Объем контейнера
////    double usedSpace; // Занятое место
////    std::vector<Shape*> shapes; // Вектор указателей на фигуры
////
////public:
////    Box(double c) : capacity(c), usedSpace(0.0) {}
////
////    bool add(Shape* shape) {
////        if (usedSpace + shape->getVolume() <= capacity) {
////            shapes.push_back(shape);
////            usedSpace += shape->getVolume();
////            return true;
////        }
////        return false; // Не хватает места
////    }
//
//    double getUsedSpace() const {
//        return usedSpace;
//    }
//};
//
//int main() {
//    Box box(1000.0); // Создаем контейнер объемом 1000
//
//    Sphere sphere1(5.0);
//    Cuboid cuboid1(10.0, 2.0, 5.0);
//    Sphere sphere2(3.0);
//
//    // Пытаемся добавить фигуры в контейнер
//    if (box.add(&sphere1)) {
//        std::cout << "Добавлена сфера 1" << std::endl;
//    } else {
//        std::cout << "Не удалось добавить сферу 1" << std::endl;
//    }
//
//    if (box.add(&cuboid1)) {
//        std::cout << "Добавлен параллелепипед 1" << std::endl;
//    } else {
//        std::cout << "Не удалось добавить параллелепипед 1" << std::endl;
//    }
//
//    if (box.add(&sphere2)) {
//        std::cout << "Добавлена сфера 2" << std::endl;
//    } else {
//        std::cout << "Не удалось добавить сферу 2" << std::endl;
//    }
//
//    std::cout << "Использовано места в контейнере: " << box.getUsedSpace() << " единиц объема" << std::endl;
//
//    return 0;
//}

//№5
//#include <iostream>
//#include <vector>
//#include <random>
//
//class WeightedRandomSelector {
//private:
//    std::vector<int> values;
//    std::vector<int> weights;
//    std::random_device rd;
//    std::mt19937 gen;
//
//public:
//    WeightedRandomSelector(const std::vector<int>& vals, const std::vector<int>& wts)
//            : values(vals), weights(wts), gen(rd()) {}
//
//    int select() {
//        if (values.empty() || weights.empty() || values.size() != weights.size()) {
//            throw std::invalid_argument("Invalid input data");
//        }
//
//        // Создаем взвешенный список значений
//        std::vector<int> weightedValues;
//        for (size_t i = 0; i < values.size(); ++i) {
//            for (int j = 0; j < weights[i]; ++j) {
//                weightedValues.push_back(values[i]);
//            }
//        }
//
//        // Выбираем случайный элемент из взвешенного списка
//        std::uniform_int_distribution<int> dist(0, weightedValues.size() - 1);
//        int randomIndex = dist(gen);
//        return weightedValues[randomIndex];
//    }
//};
//
//int main() {
//    std::vector<int> values = {1, 2, 3};
//    std::vector<int> weights = {1, 2, 10};
//
//    WeightedRandomSelector selector(values, weights);
//
//    // Пример выбора элемента с учетом весов
//    int selectedValue = selector.select();
//    std::cout << "Selected value: " << selectedValue << std::endl;
//
//    return 0;
//}

//№6
//#include <iostream>
//#include <string>
//
//class Tiles {
//public:
//    std::string brand;
//    double size_h;
//    double size_w;
//    double price;
//
//    void getData() {
//        std::cout << "Brand: " << brand << std::endl;
//        std::cout << "Size (height x width): " << size_h << " x " << size_w << " cm" << std::endl;
//        std::cout << "Price: $" << price << std::endl;
//    }
//};
//
//int main() {
//    Tiles tiles1;
//    tiles1.brand = "ExampleBrand";
//    tiles1.size_h = 10.0;
//    tiles1.size_w = 20.0;
//    tiles1.price = 15.99;
//
//    Tiles tiles2;
//    tiles2.brand = "AnotherBrand";
//    tiles2.size_h = 15.0;
//    tiles2.size_w = 30.0;
//    tiles2.price = 19.99;
//
//    std::cout << "Tile 1:" << std::endl;
//    tiles1.getData();
//
//    std::cout << std::endl;
//
//    std::cout << "Tile 2:" << std::endl;
//    tiles2.getData();
//
//    return 0;
//}

//№7
//#include <iostream>
//#include <string>
//
//class Children {
//private:
//    std::string firstName;
//    std::string lastName;
//    int age;
//
//public:
//    void inputData() {
//        std::cout << "Введите имя ребенка: ";
//        std::cin >> firstName;
//        std::cout << "Введите фамилию ребенка: ";
//        std::cin >> lastName;
//        std::cout << "Введите возраст ребенка: ";
//        std::cin >> age;
//    }
//
//    void displayData() {
//        std::cout << "Имя ребенка: " << firstName << std::endl;
//        std::cout << "Фамилия ребенка: " << lastName << std::endl;
//        std::cout << "Возраст ребенка: " << age << " лет" << std::endl;
//    }
//};
//
//int main() {
//    Children child1;
//    Children child2;
//
//    std::cout << "Введите данные для первого ребенка:" << std::endl;
//    child1.inputData();
//
//    std::cout << std::endl;
//
//    std::cout << "Введите данные для второго ребенка:" << std::endl;
//    child2.inputData();
//
//    std::cout << std::endl;
//
//    std::cout << "Данные первого ребенка:" << std::endl;
//    child1.displayData();
//
//    std::cout << std::endl;
//
//    std::cout << "Данные второго ребенка:" << std::endl;
//    child2.displayData();
//
//    return 0;
//}

//№8
//#include <iostream>
//#include <vector>
//
//class ArrayTransformer {
//private:
//    std::vector<std::vector<int>> array;
//
//public:
//    // Конструктор класса
//    ArrayTransformer(int rows, int cols) : array(rows, std::vector<int>(cols, 0)) {}
//
//    // Метод для заполнения массива значениями
//    void fillArray() {
//        std::cout << "Введите элементы массива:" << std::endl;
//        for (size_t i = 0; i < array.size(); ++i) {
//            for (size_t j = 0; j < array[i].size(); ++j) {
//                std::cin >> array[i][j];
//            }
//        }
//    }
//
//    // Метод для преобразования строк в столбцы
//    void transformArray() {
//        if (array.empty() || array[0].empty()) {
//            std::cerr << "Массив пустой или имеет нулевой размер." << std::endl;
//            return;
//        }
//
//        std::vector<std::vector<int>> newArray(array[0].size(), std::vector<int>(array.size(), 0));
//
//        for (size_t i = 0; i < array.size(); ++i) {
//            for (size_t j = 0; j < array[i].size(); ++j) {
//                newArray[j][i] = array[i][j];
//            }
//        }
//
//        array = newArray;
//    }
//
//    // Метод для отображения массива на экране
//    void displayArray() const {
//        std::cout << "Массив после преобразования:" << std::endl;
//        for (size_t i = 0; i < array.size(); ++i) {
//            for (size_t j = 0; j < array[i].size(); ++j) {
//                std::cout << array[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
//};
//
//int main() {
//    int rows, cols;
//
//    std::cout << "Введите количество строк и столбцов массива: ";
//    std::cin >> rows >> cols;
//
//    ArrayTransformer transformer(rows, cols);
//
//    transformer.fillArray();
//    transformer.transformArray();
//    transformer.displayArray();
//
//    return 0;
//}

//№9
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <algorithm>
//
//// Абстрактный базовый класс для работников
//class Employee {
//protected:
//    int id;
//    std::string name;
//
//public:
//    Employee(int id, const std::string& name) : id(id), name(name) {}
//
//    virtual double calculateSalary() const = 0;
//
//    int getId() const { return id; }
//    const std::string& getName() const { return name; }
//};
//
//// Класс для работников с почасовой оплатой
//class HourlyEmployee : public Employee {
//private:
//    double hourlyRate;
//
//public:
//    HourlyEmployee(int id, const std::string& name, double hourlyRate)
//            : Employee(id, name), hourlyRate(hourlyRate) {}
//
//    double calculateSalary() const override {
//        return 20.8 * 8 * hourlyRate;
//    }
//};
//
//// Класс для работников с фиксированной оплатой
//class FixedSalaryEmployee : public Employee {
//private:
//    double fixedSalary;
//
//public:
//    FixedSalaryEmployee(int id, const std::string& name, double fixedSalary)
//            : Employee(id, name), fixedSalary(fixedSalary) {}
//
//    double calculateSalary() const override {
//        return fixedSalary;
//    }
//};
//
//// Функция для сортировки работников по убыванию зарплаты и имени
//bool compareEmployees(const Employee* a, const Employee* b) {
//    if (a->calculateSalary() != b->calculateSalary()) {
//        return a->calculateSalary() > b->calculateSalary();
//    }
//    return a->getName() < b->getName();
//}
//
//int main() {
//    std::vector<Employee*> employees;
//
//    employees.push_back(new HourlyEmployee(1, "Иван", 15.0));
//    employees.push_back(new FixedSalaryEmployee(2, "Петр", 3000.0));
//    employees.push_back(new HourlyEmployee(3, "Мария", 20.0));
//    employees.push_back(new FixedSalaryEmployee(4, "Анна", 2500.0));
//    employees.push_back(new HourlyEmployee(5, "Дмитрий", 18.0));
//
//    // Сортировка работников
//    std::sort(employees.begin(), employees.end(), compareEmployees);
//
//    // Вывод информации о работниках
//    std::cout << "Идентификатор\tИмя\tСреднемесячная зарплата" << std::endl;
//    for (const Employee* employee : employees) {
//        std::cout << employee->getId() << "\t" << employee->getName() << "\t" << employee->calculateSalary() << std::endl;
//    }
//
//    // Вывод первых 5 имен
//    std::cout << "Первые 5 имен: ";
//    for (size_t i = 0; i < std::min(5, employees.size()); ++i) {
//        std::cout << employees[i]->getName() << " ";
//    }
//    std::cout << std::endl;
//
//    // Вывод последних 3 идентификаторов
//    std::cout << "Последние 3 идентификатора: ";
//    for (size_t i = std::max(0, static_cast<int>(employees.size()) - 3); i < employees.size(); ++i) {
//        std::cout << employees[i]->getId() << " ";
//    }
//    std::cout << std::endl;
//
//    // Освобождение памяти
//    for (Employee* employee : employees) {
//        delete employee;
//    }
//
//    return 0;
//}
