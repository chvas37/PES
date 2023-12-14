//№1 Реализуйте очередь с нисходящим приоритетом.

//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//// Структура для представления элемента с приоритетом
//struct PriorityQueueElement {
//    int value;
//    int priority;
//
//    // Конструктор для удобной инициализации
//    PriorityQueueElement(int val, int prio) : value(val), priority(prio) {}
//
//    // Перегрузка оператора "<" для сравнения по приоритету
//    bool operator<(const PriorityQueueElement& other) const {
//        return priority < other.priority;
//    }
//};
//
//// Реализация приоритетной очереди
//class PriorityQueue {
//private:
//    priority_queue<PriorityQueueElement> pq;
//
//public:
//    // Метод для вставки элемента в очередь
//    void enqueue(int value, int priority) {
//        pq.push(PriorityQueueElement(value, priority));
//    }
//
//    // Метод для извлечения элемента с наивысшим приоритетом
//    int dequeue() {
//        if (!pq.empty()) {
//            int result = pq.top().value;
//            pq.pop();
//            return result;
//        } else {
//            // Возвращаем какой-то код ошибки, так как очередь пуста
//            return -1;
//        }
//    }
//
//    // Метод для проверки, пуста ли очередь
//    bool isEmpty() {
//        return pq.empty();
//    }
//};
//
//int main() {
//    // Пример использования приоритетной очереди
//    PriorityQueue priorityQueue;
//
//    priorityQueue.enqueue(1, 3);
//    priorityQueue.enqueue(2, 1);
//    priorityQueue.enqueue(3, 2);
//
//    while (!priorityQueue.isEmpty()) {
//        cout << "Dequeued: " << priorityQueue.dequeue() << endl;
//    }
//
//    return 0;
//}

//№2 Реализуйте ADT с круговой очередью, используя Arrays.
//
//#include <iostream>
//
//const int MAX_SIZE = 5;  // Максимальный размер очереди
//
//class CircularQueue {
//private:
//    int front, rear;
//    int arr[MAX_SIZE];
//
//public:
//    CircularQueue() : front(-1), rear(-1) {}
//
//    // Метод для проверки, пуста ли очередь
//    bool isEmpty() {
//        return front == -1 && rear == -1;
//    }
//
//    // Метод для проверки, полна ли очередь
//    bool isFull() {
//        return (rear + 1) % MAX_SIZE == front;
//    }
//
//    // Метод для добавления элемента в очередь
//    void enqueue(int value) {
//        if (isFull()) {
//            std::cout << "Queue is full. Cannot enqueue.\n";
//            return;
//        }
//
//        if (isEmpty()) {
//            front = rear = 0;
//        } else {
//            rear = (rear + 1) % MAX_SIZE;
//        }
//
//        arr[rear] = value;
//    }
//
//    // Метод для удаления элемента из очереди
//    int dequeue() {
//        if (isEmpty()) {
//            std::cout << "Queue is empty. Cannot dequeue.\n";
//            return -1;
//        }
//
//        int removedValue = arr[front];
//
//        if (front == rear) {
//            // Очередь содержала только один элемент
//            front = rear = -1;
//        } else {
//            front = (front + 1) % MAX_SIZE;
//        }
//
//        return removedValue;
//    }
//
//    // Метод для получения значения первого элемента без его удаления
//    int peek() {
//        if (isEmpty()) {
//            std::cout << "Queue is empty. Cannot peek.\n";
//            return -1;
//        }
//
//        return arr[front];
//    }
//};
//
//int main() {
//    CircularQueue circularQueue;
//
//    circularQueue.enqueue(1);
//    circularQueue.enqueue(2);
//    circularQueue.enqueue(3);
//
//    std::cout << "Peek: " << circularQueue.peek() << "\n";
//
//    std::cout << "Dequeued: " << circularQueue.dequeue() << "\n";
//    std::cout << "Dequeued: " << circularQueue.dequeue() << "\n";
//
//    circularQueue.enqueue(4);
//
//    std::cout << "Peek: " << circularQueue.peek() << "\n";
//
//    return 0;
//}
