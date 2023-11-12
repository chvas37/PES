//№1
//
//#include <iostream>
//#include <thread>
//
//void printLines() {
//    for (int i = 1; i <= 10; ++i) {
//        std::cout << "Line " << i << " from thread " << std::this_thread::get_id() << std::endl;
//    }
//}
//
//int main() {
//    // Отключаем буферизацию для stdout
//    setvbuf(stdout, nullptr, _IONBF, 0);
//
//    // Создаем новый поток
//    std::thread myThread(printLines);
//
//    // Выполняем те же действия в родительском потоке
//    printLines();
//
//    // Ждем, пока новый поток завершится
//    myThread.join();
//
//    return 0;
//}

//№2
//#include <iostream>
//#include <pthread.h>
//
//void* printLines(void* thread_id) {
//    intptr_t id = (intptr_t)thread_id;
//    for (int i = 1; i <= 10; ++i) {
//        std::cout << "Line " << i << " from thread " << id << std::endl;
//    }
//    return NULL;
//}
//
//int main() {
//    pthread_t myThread;
//    int rc;
//
//    // Создаем новый поток
//    rc = pthread_create(&myThread, NULL, printLines, (void*)1);
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    // Ожидаем завершения нового потока
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    // Выполняем те же действия в родительском потоке
//    printLines((void*)0);
//
//    return 0;
//}

//№3
//
//#include <iostream>
//#include <pthread.h>
//#include <sched.h>
//
//void* printLines(void* thread_id) {
//    pthread_t tid = pthread_self();
//    int policy;
//    struct sched_param param;
//
//    pthread_getschedparam(tid, &policy, &param);
//
//    std::cout << "Thread ID: " << tid << ", Priority: " << param.sched_priority << std::endl;
//
//    for (int i = 1; i <= 10; ++i) {
//        std::cout << "Line " << i << " from thread " << tid << std::endl;
//    }
//
//    pthread_exit(NULL);
//}
//
//int main() {
//    pthread_t myThread;
//    int rc;
//
//    // Создаем новый поток
//    rc = pthread_create(&myThread, NULL, printLines, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    // Ожидаем завершения нового потока
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    return 0;
//}

//№4
//
//#include <iostream>
//#include <pthread.h>
//#include <vector>
//#include <string>
//
//void* printLines(void* arg) {
//    std::vector<std::string> lines = *((std::vector<std::string>*)arg);
//
//    for (const auto& line : lines) {
//        std::cout << line << std::endl;
//    }
//
//    pthread_exit(NULL);
//}
//
//int main() {
//    pthread_t threads[4];
//    int rc;
//
//    std::vector<std::string> lines1 = {"Thread 1 Line 1", "Thread 1 Line 2", "Thread 1 Line 3"};
//    std::vector<std::string> lines2 = {"Thread 2 Line 1", "Thread 2 Line 2", "Thread 2 Line 3"};
//    std::vector<std::string> lines3 = {"Thread 3 Line 1", "Thread 3 Line 2", "Thread 3 Line 3"};
//    std::vector<std::string> lines4 = {"Thread 4 Line 1", "Thread 4 Line 2", "Thread 4 Line 3"};
//
//    std::vector<std::vector<std::string>> allLines = {lines1, lines2, lines3, lines4};
//
//    for (int i = 0; i < 4; ++i) {
//        rc = pthread_create(&threads[i], NULL, printLines, (void*)&allLines[i]);
//
//        if (rc) {
//            std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//            return -1;
//        }
//    }
//
//    for (int i = 0; i < 4; ++i) {
//        rc = pthread_join(threads[i], NULL);
//
//        if (rc) {
//            std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//            return -1;
//        }
//    }
//
//    return 0;
//}

//№5
//
//#include <iostream>
//#include <pthread.h>
//
//void* printAddress(void*) {
//    int i;
//    printf("Address of i in thread: %p\n", (void*)&i);
//    pthread_exit(NULL);
//}
//
//int main() {
//    int i;
//    printf("Address of i in main thread: %p\n", (void*)&i);
//
//    pthread_t myThread;
//    int rc;
//
//    rc = pthread_create(&myThread, NULL, printAddress, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    return 0;
//}

//№6

//#include <iostream>
//#include <pthread.h>
//
//void* printInfo(void* arg) {
//    int i;
//    printf("Thread Priority: %d\n", sched_get_priority_max(SCHED_FIFO));
//    printf("Address of i in thread: %p\n", (void*)&i);
//    pthread_exit(NULL);
//}
//
//int main() {
//    pthread_t myThread;
//    int rc;
//
//    // Создаем атрибуты нити
//    pthread_attr_t attr;
//    pthread_attr_init(&attr);
//
//    // Устанавливаем приоритет
//    struct sched_param param;
//    param.sched_priority = 99;  // Устанавливаем высший приоритет
//    pthread_attr_setschedparam(&attr, &param);
//
//    // Устанавливаем размер стека
//    size_t stackSize = 1024 * 1024; // 1 МБ
//    pthread_attr_setstacksize(&attr, stackSize);
//
//    // Создаем нить с установленными атрибутами
//    rc = pthread_create(&myThread, &attr, printInfo, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    // Ждем завершения нити
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    // Уничтожаем атрибуты нити
//    pthread_attr_destroy(&attr);
//
//    return 0;
//}

//№7
//
//#include <iostream>
//#include <pthread.h>
//#include <signal.h>
//#include <unistd.h>
//
//void signalHandler(int sig) {
//    std::cout << "Received signal: " << sig << " in child thread " << pthread_self() << std::endl;
//}
//
//void* childThread(void* arg) {
//    // Set up signal handling
//    struct sigaction sa;
//    sa.sa_handler = signalHandler;
//    sigemptyset(&sa.sa_mask);
//    sa.sa_flags = 0;
//    sigaction(SIGINT, &sa, NULL);
//
//    // Wait for signals indefinitely
//    while (1) {
//        pause();
//    }
//
//    return NULL;
//}
//
//int main() {
//    pthread_t myThread;
//    int rc;
//
//    // Create a new thread
//    rc = pthread_create(&myThread, NULL, childThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    // Send SIGINT signal to the child thread
//    pthread_kill(myThread, SIGINT);
//
//    // Wait for the child thread to finish
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    return 0;
//}

//№8
//
//#include <iostream>
//#include <pthread.h>
//#include <unistd.h>
//
//void* childThread(void*) {
//    while (1) {
//        std::cout << "Child thread is running..." << std::endl;
//        sleep(1); // Имитация выполнения какой-то работы
//    }
//    return NULL;
//}
//
//int main() {
//    pthread_t myThread;
//    int rc;
//
//    // Создаем новый поток
//    rc = pthread_create(&myThread, NULL, childThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    // Ждем 2 секунды
//    sleep(2);
//
//    // Прерываем дочерний поток
//    rc = pthread_cancel(myThread);
//
//    if (rc) {
//        std::cerr << "Error: Unable to cancel thread, " << rc << std::endl;
//        return -1;
//    }
//
//    // Ждем завершения дочернего потока
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    return 0;
//}

//№9
//
//#include <iostream>
//#include <pthread.h>
//#include <unistd.h>
//
//void cleanup(void* arg) {
//    std::cout << "Cleanup: Child thread is exiting..." << std::endl;
//}
//
//void* childThread(void*) {
//    pthread_cleanup_push(cleanup, NULL);
//
//        while (1) {
//            std::cout << "Child thread is running..." << std::endl;
//            sleep(1);
//        }
//
//    pthread_cleanup_pop(1);
//    return NULL;
//}
//
//int main() {
//    pthread_t myThread;
//    int rc;
//
//    // Создаем новый поток
//    rc = pthread_create(&myThread, NULL, childThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    // Ждем 2 секунды
//    sleep(2);
//
//    // Прерываем дочерний поток
//    rc = pthread_cancel(myThread);
//
//    if (rc) {
//        std::cerr << "Error: Unable to cancel thread, " << rc << std::endl;
//        return -1;
//    }
//
//    // Ждем завершения дочернего потока
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    return 0;
//}
//

//№10

//#include <iostream>
//#include <pthread.h>
//#include <stdint.h>
//
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//
//void* printLines(void* thread_id) {
//    intptr_t id = reinterpret_cast<intptr_t>(thread_id);
//
//    for (int i = 1; i <= 10; ++i) {
//        pthread_mutex_lock(&mutex);
//        std::cout << "Line " << i << " from thread " << id << std::endl;
//        pthread_mutex_unlock(&mutex);
//    }
//
//    return NULL;
//}
//
//int main() {
//    pthread_t myThread;
//    int rc;
//
//    rc = pthread_create(&myThread, NULL, printLines, reinterpret_cast<void*>(1));
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    for (int i = 1; i <= 10; ++i) {
//        pthread_mutex_lock(&mutex);
//        std::cout << "Line " << i << " from main thread" << std::endl;
//        pthread_mutex_unlock(&mutex);
//    }
//
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    return 0;
//}

//№11
//
//#include <iostream>
//#include <pthread.h>
//#include <stdint.h>
//
//pthread_mutex_t mutexMain = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t mutexChild = PTHREAD_MUTEX_INITIALIZER;
//
//void* printLines(void* thread_id) {
//    intptr_t id = reinterpret_cast<intptr_t>(thread_id);
//
//    for (int i = 1; i <= 10; ++i) {
//        if (id == 1) {
//            pthread_mutex_lock(&mutexMain);
//        } else {
//            pthread_mutex_lock(&mutexChild);
//        }
//
//        std::cout << "Line " << i << " from thread " << id << std::endl;
//
//        if (id == 1) {
//            pthread_mutex_unlock(&mutexChild);
//        } else {
//            pthread_mutex_unlock(&mutexMain);
//        }
//    }
//
//    return NULL;
//}
//
//int main() {
//    pthread_t myThread;
//    int rc;
//
//    rc = pthread_create(&myThread, NULL, printLines, reinterpret_cast<void*>(1));
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    printLines(reinterpret_cast<void*>(2));
//
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    return 0;
//}

//№12
//
//#include <iostream>
//#include <pthread.h>
//#include <cstdint>
//
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t condMain = PTHREAD_COND_INITIALIZER;
//pthread_cond_t condChild = PTHREAD_COND_INITIALIZER;
//
//bool isMainTurn = true;
//
//void* printLines(void* thread_id) {
//    intptr_t id = reinterpret_cast<intptr_t>(thread_id);
//
//    for (int i = 1; i <= 10; ++i) {
//        pthread_mutex_lock(&mutex);
//
//        while ((id == 1 && !isMainTurn) || (id == 2 && isMainTurn)) {
//            if (id == 1) {
//                pthread_cond_wait(&condMain, &mutex);
//            } else {
//                pthread_cond_wait(&condChild, &mutex);
//            }
//        }
//
//        std::cout << "Line " << i << " from thread " << id << std::endl;
//
//        isMainTurn = !isMainTurn;
//
//        if (id == 1) {
//            pthread_cond_signal(&condChild);
//        } else {
//            pthread_cond_signal(&condMain);
//        }
//
//        pthread_mutex_unlock(&mutex);
//    }
//
//    return NULL;
//}
//
//int main() {
//    pthread_t myThread;
//    int rc;
//
//    rc = pthread_create(&myThread, NULL, printLines, reinterpret_cast<void*>(1));
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    printLines(reinterpret_cast<void*>(2));
//
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    return 0;
//}

//№13
//
//#include <iostream>
//#include <pthread.h>
//#include <cstdint>
//
//pthread_mutex_t mutexMain = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t mutexChild = PTHREAD_MUTEX_INITIALIZER;
//
//void* printLines(void* thread_id) {
//    intptr_t id = reinterpret_cast<intptr_t>(thread_id);
//
//    for (int i = 1; i <= 10; ++i) {
//        if (id == 1) {
//            pthread_mutex_lock(&mutexMain);
//        } else {
//            pthread_mutex_lock(&mutexChild);
//        }
//
//        std::cout << "Line " << i << " from thread " << id << std::endl;
//
//        if (id == 1) {
//            pthread_mutex_unlock(&mutexChild);
//        } else {
//            pthread_mutex_unlock(&mutexMain);
//        }
//    }
//
//    return NULL;
//}
//
//int main() {
//    pthread_t myThread;
//    int rc;
//
//    rc = pthread_create(&myThread, NULL, printLines, reinterpret_cast<void*>(1));
//
//    if (rc) {
//        std::cerr << "Error: Unable to create thread, " << rc << std::endl;
//        return -1;
//    }
//
//    printLines(reinterpret_cast<void*>(2));
//
//    rc = pthread_join(myThread, NULL);
//
//    if (rc) {
//        std::cerr << "Error: Unable to join thread, " << rc << std::endl;
//        return -1;
//    }
//
//    return 0;
//}
//

//№14
//Доказательство неприменимо к семафорам-счетчикам потому, что семафоры-счетчики не обладают теми же ограничениями,
//что и мьютексы. В отличие от мьютексов, семафоры-счетчики позволяют нескольким потокам одновременно захватывать ресурс
//(если значение счетчика позволяет).
//
//В задаче 11, где мы пытались использовать два мьютекса, это приводит к взаимоблокировке.
//Оба потока ожидают освобождения другого мьютекса и в итоге взаимно блокируют друг друга.
//
//В случае с семафорами-счетчиками, каждый поток может успешно захватить семафор, если его значение позволяет.
//Таким образом, проблема взаимоблокировки, которая возникает при использовании двух мьютексов,
//не возникает при использовании семафоров-счетчиков.
//
//Вывод: В отличие от мьютексов, семафоры-счетчики позволяют более свободно управлять доступом к
//общему ресурсу и избегать проблем взаимоблокировки

//№15
//
//#include <iostream>
//#include <pthread.h>
//#include <list>
//#include <string>
//#include <mutex>
//#include <unistd.h>
//
//std::list<std::string> linkedList;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//
//void* sortList(void*) {
//    while (true) {
//        sleep(5);
//        pthread_mutex_lock(&mutex);
//        linkedList.sort();
//        pthread_mutex_unlock(&mutex);
//    }
//    return NULL;
//}
//
//void printList() {
//    pthread_mutex_lock(&mutex);
//    for (const auto& str : linkedList) {
//        std::cout << str << std::endl;
//    }
//    pthread_mutex_unlock(&mutex);
//}
//
//int main() {
//    pthread_t sortThread;
//    pthread_create(&sortThread, NULL, sortList, NULL);
//
//    std::string input;
//    while (true) {
//        std::getline(std::cin, input);
//        if (input.empty()) {
//            printList();
//        } else {
//            pthread_mutex_lock(&mutex);
//            while (input.size() > 80) {
//                linkedList.push_front(input.substr(0, 80));
//                input = input.substr(80);
//            }
//            linkedList.push_front(input);
//            pthread_mutex_unlock(&mutex);
//        }
//    }
//
//    return 0;
//}

//№16
//#include <iostream>
//#include <vector>
//#include <thread>
//#include <mutex>
//
//class CustomList {
//public:
//    CustomList(std::vector<int>& data) : data(data), mutexes(data.size()) {}
//
//    void swap(int i, int j) {
//        std::lock(mutexes[i], mutexes[j]);
//        std::lock_guard<std::mutex> lock1(mutexes[i], std::adopt_lock);
//        std::lock_guard<std::mutex> lock2(mutexes[j], std::adopt_lock);
//
//        std::swap(data[i], data[j]);
//    }
//
//    void bubble_sort(int start, int end) {
//        for (int i = start; i < end; ++i) {
//            for (int j = 0; j < data.size()-i-1; ++j) {
//                swap(j, j+1);
//            }
//        }
//    }
//
//    void print_list() {
//        for (const auto& item : data) {
//            std::cout << item << " ";
//        }
//        std::cout << std::endl;
//    }
//
//private:
//    std::vector<int>& data;
//    std::vector<std::mutex> mutexes;
//};
//
//int main() {
//    std::vector<int> data = {5, 3, 8, 1, 2};
//    CustomList customList(data);
//
//    // Create two sorting threads
//    std::thread thread1(&CustomList::bubble_sort, &customList, 0, data.size()/2);
//    std::thread thread2(&CustomList::bubble_sort, &customList, data.size()/2, data.size());
//
//    // Join the threads
//    thread1.join();
//    thread2.join();
//
//    customList.print_list();
//
//    return 0;
//}

//№17
//#include <iostream>
//#include <vector>
//#include <thread>
//#include <mutex>
//#include <chrono>
//
//class CustomList {
//public:
//    CustomList(std::vector<int>& data) : data(data), mutexes(data.size()) {}
//
//    void swap(int i, int j) {
//        std::lock(mutexes[i], mutexes[j]);
//        std::lock_guard<std::mutex> lock1(mutexes[i], std::adopt_lock);
//        std::lock_guard<std::mutex> lock2(mutexes[j], std::adopt_lock);
//
//        std::swap(data[i], data[j]);
//    }
//
//    void bubble_sort(int start, int end) {
//        for (int i = start; i < end; ++i) {
//            for (int j = 0; j < data.size()-i-1; ++j) {
//                swap(j, j+1);
//                std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка 1 секунда
//                print_list(); // Выводим текущее состояние списка после каждой перестановки
//            }
//        }
//    }
//
//    void print_list() {
//        for (const auto& item : data) {
//            std::cout << item << " ";
//        }
//        std::cout << std::endl;
//    }
//
//private:
//    std::vector<int>& data;
//    std::vector<std::mutex> mutexes;
//};
//
//int main() {
//    std::vector<int> data = {5, 3, 8, 1, 2};
//    CustomList customList(data);
//
//    // Create two sorting threads
//    std::thread thread1(&CustomList::bubble_sort, &customList, 0, data.size()/2);
//    std::thread thread2(&CustomList::bubble_sort, &customList, data.size()/2, data.size());
//
//    // Join the threads
//    thread1.join();
//    thread2.join();
//
//    return 0;
//}

//№18
//#include <iostream>
//#include <vector>
//#include <thread>
//#include <shared_mutex> // for std::shared_mutex
//#include <mutex>       // for std::unique_lock
//#include <chrono>
//
//class CustomList {
//public:
//    CustomList(std::vector<int>& data) : data(data) {}
//
//    void swap(int i, int j) {
//        std::unique_lock<std::shared_mutex> lock(mutex);
//        std::swap(data[i], data[j]);
//    }
//
//    void bubble_sort(int start, int end) {
//        for (int i = start; i < end; ++i) {
//            for (int j = 0; j < data.size()-i-1; ++j) {
//                swap(j, j+1);
//                std::this_thread::sleep_for(std::chrono::seconds(1));
//                print_list();
//            }
//        }
//    }
//
//    void print_list() {
//        std::shared_lock<std::shared_mutex> lock(mutex);
//        for (const auto& item : data) {
//            std::cout << item << " ";
//        }
//        std::cout << std::endl;
//    }
//
//private:
//    std::vector<int>& data;
//    mutable std::shared_mutex mutex;
//};
//
//int main() {
//    std::vector<int> data = {5, 3, 8, 1, 2};
//    CustomList customList(data);
//
//    // Create two sorting threads
//    std::thread thread1(&CustomList::bubble_sort, &customList, 0, data.size()/2);
//    std::thread thread2(&CustomList::bubble_sort, &customList, data.size()/2, data.size());
//
//    // Join the threads
//    thread1.join();
//    thread2.join();
//
//    return 0;
//}

//№19
//#include <iostream>
//#include <vector>
//#include <thread>
//#include <shared_mutex>
//#include <mutex> // Add this line
//#include <chrono>
//
//class CustomList {
//public:
//    CustomList(std::vector<int>& data) : data(data), mutexes(data.size()) {}
//
//    void swap(int i, int j) {
//        std::unique_lock<std::shared_timed_mutex> lock(mutexes[i], std::defer_lock);
//        std::unique_lock<std::shared_timed_mutex> lock2(mutexes[j], std::defer_lock);
//
//        std::lock(lock, lock2);
//
//        std::swap(data[i], data[j]);
//    }
//
//    void bubble_sort(int start, int end) {
//        for (int i = start; i < end; ++i) {
//            for (int j = 0; j < data.size()-i-1; ++j) {
//                swap(j, j+1);
//                std::this_thread::sleep_for(std::chrono::seconds(1));
//                print_list();
//            }
//        }
//    }
//
//    void print_list() {
//        std::shared_lock<std::shared_timed_mutex> lock(mutexes[0]);
//        for (const auto& item : data) {
//            std::cout << item << " ";
//        }
//        std::cout << std::endl;
//    }
//
//private:
//    std::vector<int>& data;
//    std::vector<std::shared_timed_mutex> mutexes;
//};
//
//int main() {
//    std::vector<int> data = {5, 3, 8, 1, 2};
//    CustomList customList(data);
//
//    // Create two sorting threads
//    std::thread thread1(&CustomList::bubble_sort, &customList, 0, data.size()/2);
//    std::thread thread2(&CustomList::bubble_sort, &customList, data.size()/2, data.size());
//
//    // Join the threads
//    thread1.join();
//    thread2.join();
//
//    return 0;
//}

//№20
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//std::mutex mtx;
//std::condition_variable cv;
//int countA = 0;
//int countB = 0;
//int countC = 0;
//
//const int targetWidgets = 5;  // Указывает, сколько винтиков нужно произвести
//
//void produceA() {
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Имитация производства детали A
//    {
//        std::unique_lock<std::mutex> lock(mtx);
//        countA++;
//    }
//    cv.notify_all();
//}
//
//void produceB() {
//    std::this_thread::sleep_for(std::chrono::seconds(2)); // Имитация производства детали B
//    {
//        std::unique_lock<std::mutex> lock(mtx);
//        countB++;
//    }
//    cv.notify_all();
//}
//
//void produceC() {
//    std::this_thread::sleep_for(std::chrono::seconds(3)); // Имитация производства детали C
//    {
//        std::unique_lock<std::mutex> lock(mtx);
//        countC++;
//    }
//    cv.notify_all();
//}
//
//void assembleWidget() {
//    std::unique_lock<std::mutex> lock(mtx);
//    cv.wait(lock, [] { return countA > 0 && countB > 0 && countC > 0; });
//
//    countA--;
//    countB--;
//    countC--;
//
//    std::cout << "Widget assembled!\n";
//    cv.notify_all();
//}
//
//int main() {
//    std::thread threadA, threadB, threadC, threadAssembly;
//
//    for (int i = 0; i < targetWidgets; ++i) {
//        threadA = std::thread(produceA);
//        threadB = std::thread(produceB);
//        threadC = std::thread(produceC);
//        threadAssembly = std::thread(assembleWidget);
//
//        threadA.join();
//        threadB.join();
//        threadC.join();
//        threadAssembly.join();
//    }
//
//    return 0;
//}

//№21
//#include <iostream>
//#include <curl/curl.h>
//
//size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
//    size_t totalSize = size * nmemb;
//    output->append(static_cast<char*>(contents), totalSize);
//    return totalSize;
//}
//
//int main(int argc, char* argv[]) {
//    if (argc != 2) {
//        std::cerr << "Usage: " << argv[0] << " <URL>" << std::endl;
//        return 1;
//    }
//
//    CURL* curl;
//    CURLcode res;
//
//    curl_global_init(CURL_GLOBAL_DEFAULT);
//
//    curl = curl_easy_init();
//    if (curl) {
//        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
//
//        // Set the write callback function
//        std::string response;
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
//
//        res = curl_easy_perform(curl);
//
//        if (res != CURLE_OK) {
//            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
//        } else {
//            // Print the response to the terminal
//            std::cout << response << std::endl;
//        }
//
//        curl_easy_cleanup(curl);
//    }
//
//    curl_global_cleanup();
//
//    return 0;
//}

//№22
//#include <iostream>
//#include <curl/curl.h>
//#include <boost/asio.hpp>
//
//class HttpClient {
//public:
//    HttpClient(boost::asio::io_context& ioContext)
//            : ioContext(ioContext),
//              resolver(ioContext),
//              socket(ioContext),
//              response(std::make_shared<std::string>()) {}
//
//    void makeRequest(const std::string& url) {
//        // Use asynchronous DNS resolution
//        resolver.async_resolve(url, "http",
//                               [this](const boost::system::error_code& ec, boost::asio::ip::tcp::resolver::results_type results) {
//                                   if (!ec) {
//                                       // Connect to the server
//                                       boost::asio::async_connect(socket, results,
//                                                                  [this](const boost::system::error_code& ec, const boost::asio::ip::tcp::endpoint& endpoint) {
//                                                                      if (!ec) {
//                                                                          // Perform the HTTP request
//                                                                          performHttpRequest();
//                                                                      } else {
//                                                                          std::cerr << "Connect error: " << ec.message() << std::endl;
//                                                                      }
//                                                                  }
//                                       );
//                                   } else {
//                                       std::cerr << "Resolve error: " << ec.message() << std::endl;
//                                   }
//                               }
//        );
//
//        ioContext.run(); // Run the io_context to start asynchronous operations
//    }
//
//private:
//    void performHttpRequest() {
//        // Use libcurl for the HTTP request
//        CURL* curl = curl_easy_init();
//        if (curl) {
//            curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
//            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HttpClient::writeCallback);
//            curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
//
//            // Start the asynchronous HTTP request
//            boost::asio::async_read_until(socket, responseBuffer, "\r\n\r\n",
//                                          [this, curl](const boost::system::error_code& ec, std::size_t bytesRead) {
//                                              if (!ec) {
//                                                  // Print the response to the terminal
//                                                  std::cout << response->substr(0, bytesRead) << std::endl;
//
//                                                  // Additional logic for handling the response data as needed
//
//                                                  // Close the socket and cleanup
//                                                  curl_easy_cleanup(curl);
//                                                  socket.close();
//                                              } else {
//                                                  std::cerr << "Read error: " << ec.message() << std::endl;
//                                              }
//                                          }
//            );
//        }
//    }
//
//    static size_t writeCallback(void* contents, size_t size, size_t nmemb, HttpClient* client) {
//        size_t totalSize = size * nmemb;
//        client->getResponse()->append(static_cast<char*>(contents), totalSize);
//        return totalSize;
//    }
//
//    std::shared_ptr<std::string> getResponse() const {
//        return response;
//    }
//
//private:
//    boost::asio::io_context& ioContext;
//    boost::asio::ip::tcp::resolver resolver;
//    boost::asio::ip::tcp::socket socket;
//    boost::asio::streambuf responseBuffer;
//    std::shared_ptr<std::string> response;
//};
//
//int main(int argc, char* argv[]) {
//    if (argc != 2) {
//        std::cerr << "Usage: " << argv[0] << " <URL>" << std::endl;
//        return 1;
//    }
//
//    boost::asio::io_context ioContext;
//    HttpClient httpClient(ioContext);
//
//    httpClient.makeRequest(argv[1]);
//
//    return 0;
//}

//№23
//#include <iostream>
//#include <thread>
//#include <curl/curl.h>
//
//class HttpClient {
//public:
//    HttpClient(const std::string& url) : url(url) {}
//
//    void run() {
//        // Запускаем поток для считывания данных из сетевого соединения
//        std::thread networkThread(&HttpClient::performHttpRequest, this);
//
//        // Основной поток взаимодействия с пользователем
//        interactWithUser();
//
//        // Ждем завершения потока сетевого соединения
//        networkThread.join();
//    }
//
//private:
//    void performHttpRequest() {
//        CURL* curl = curl_easy_init();
//        if (curl) {
//            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HttpClient::writeCallback);
//            curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
//
//            // Выполняем HTTP-запрос
//            CURLcode res = curl_easy_perform(curl);
//
//            if (res != CURLE_OK) {
//                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
//            }
//
//            // Очищаем curl
//            curl_easy_cleanup(curl);
//        }
//    }
//
//    static size_t writeCallback(void* contents, size_t size, size_t nmemb, HttpClient* client) {
//        size_t totalSize = size * nmemb;
//        // Обработка данных (вывод, сохранение и т.д.)
//        std::cout.write(static_cast<char*>(contents), totalSize);
//        return totalSize;
//    }
//
//    void interactWithUser() {
//        // Пример взаимодействия с пользователем (здесь может быть ваша логика)
//        std::string userInput;
//        do {
//            std::cout << "Enter 'q' to quit: ";
//            std::getline(std::cin, userInput);
//        } while (userInput != "q");
//    }
//
//private:
//    std::string url;
//};
//
//int main(int argc, char* argv[]) {
//    if (argc != 2) {
//        std::cerr << "Usage: " << argv[0] << " <URL>" << std::endl;
//        return 1;
//    }
//
//    HttpClient httpClient(argv[1]);
//    httpClient.run();
//
//    return 0;
//}

//№24
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <ctime>
//#include <cstdlib>
//#include <cstring>
//#include <unistd.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//
//const int MAX_BUFFER_SIZE = 102400;  /
//const int CACHE_QUOTA = 52428800;
//const int MAX_CLIENTS = 10;
//
//
//struct CacheEntry {
//    std::string url;
//    time_t lastAccessTime;
//    char* buffer;
//    size_t bufferSize;
//    size_t dataSize;
//};
//
//// Proxy class
//class Proxy {
//public:
//    Proxy(int port) : port(port) {
//        initializeServer();
//    }
//
//    void run() {
//        while (true) {
//            fd_set readFds;
//            int maxFd = 0;
//
//            FD_ZERO(&readFds);
//
//            // Add server socket to the set
//            FD_SET(serverSocket, &readFds);
//            maxFd = serverSocket;
//
//            // Add client sockets to the set
//            for (const auto& client : clients) {
//                FD_SET(client.socket, &readFds);
//                maxFd = std::max(maxFd, client.socket);
//            }
//
//            // Wait for activity on any socket
//            select(maxFd + 1, &readFds, nullptr, nullptr, nullptr);
//
//            // Check if there is a new connection on the server socket
//            if (FD_ISSET(serverSocket, &readFds)) {
//                acceptConnection();
//            }
//
//            // Check if there is data from clients
//            for (auto it = clients.begin(); it != clients.end();) {
//                if (FD_ISSET(it->socket, &readFds)) {
//                    processClient(*it);
//                    if (it->disconnect) {
//                        close(it->socket);
//                        it = clients.erase(it);
//                    } else {
//                        ++it;
//                    }
//                } else {
//                    ++it;
//                }
//            }
//        }
//    }
//
//private:
//    int serverSocket;
//    int port;
//
//    struct ClientInfo {
//        int socket;
//        bool disconnect;
//        CacheEntry* cacheEntry;
//    };
//
//    std::vector<ClientInfo> clients;
//    std::map<std::string, CacheEntry> cacheIndex;
//
//    void initializeServer() {
//        // Create server socket
//        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
//        if (serverSocket == -1) {
//            perror("Error creating socket");
//            exit(EXIT_FAILURE);
//        }
//
//        // Setup server address structure
//        sockaddr_in serverAddr{};
//        serverAddr.sin_family = AF_INET;
//        serverAddr.sin_addr.s_addr = INADDR_ANY;
//        serverAddr.sin_port = htons(port);
//
//        // Bind the server socket
//        if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
//            perror("Error binding");
//            close(serverSocket);
//            exit(EXIT_FAILURE);
//        }
//
//        // Start listening
//        if (listen(serverSocket, MAX_CLIENTS) == -1) {
//            perror("Error listening");
//            close(serverSocket);
//            exit(EXIT_FAILURE);
//        }
//
//        std::cout << "Proxy server is running on port " << port << std::endl;
//    }
//
//    void acceptConnection() {
//        sockaddr_in clientAddr{};
//        socklen_t clientAddrLen = sizeof(clientAddr);
//        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
//        if (clientSocket == -1) {
//            perror("Error accepting connection");
//            return;
//        }
//
//        std::cout << "Accepted new connection from " << inet_ntoa(clientAddr.sin_addr) << std::endl;
//
//        // Add the new client to the vector
//        clients.push_back({clientSocket, false, nullptr});
//    }
//
//    void processClient(ClientInfo& client) {
//        char buffer[MAX_BUFFER_SIZE] = {0};
//        ssize_t bytesRead = recv(client.socket, buffer, sizeof(buffer), 0);
//
//        if (bytesRead <= 0) {
//            // Connection closed by client
//            std::cout << "Client disconnected" << std::endl;
//            client.disconnect = true;
//            return;
//        }
//
//        std::string request(buffer);
//
//        // Check if the request is in the cache
//        auto cacheIt = cacheIndex.find(request);
//        if (cacheIt != cacheIndex.end()) {
//            std::cout << "Cache hit for URL: " << request << std::endl;
//            sendCachedResponse(client.socket, cacheIt->

//№25
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <ctime>
//#include <cstdlib>
//#include <cstring>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <unistd.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//
//const int MAX_BUFFER_SIZE = 102400;
//const int CACHE_QUOTA = 52428800;
//const int MAX_CLIENTS = 10;
//
//struct CacheEntry {
//    std::string url;
//    time_t lastAccessTime;
//    char* buffer;
//    size_t bufferSize;
//    size_t dataSize;
//};
//
//class Proxy {
//public:
//    Proxy(int port) : port(port) {
//        initializeServer();
//    }
//
//    void run() {
//        while (true) {
//            sockaddr_in clientAddr{};
//            socklen_t clientAddrLen = sizeof(clientAddr);
//            int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
//
//            if (clientSocket == -1) {
//                perror("Error accepting connection");
//                continue;
//            }
//
//            std::cout << "Accepted new connection from " << inet_ntoa(clientAddr.sin_addr) << std::endl;
//
//            std::thread(&Proxy::handleClient, this, clientSocket).detach();
//        }
//    }
//
//private:
//    int serverSocket;
//    int port;
//    std::mutex cacheMutex;
//    std::map<std::string, CacheEntry> cacheIndex;
//
//    void initializeServer() {
//        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
//        if (serverSocket == -1) {
//            perror("Error creating socket");
//            exit(EXIT_FAILURE);
//        }
//
//        sockaddr_in serverAddr{};
//        serverAddr.sin_family = AF_INET;
//        serverAddr.sin_addr.s_addr = INADDR_ANY;
//        serverAddr.sin_port = htons(port);
//
//        if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
//            perror("Error binding");
//            close(serverSocket);
//            exit(EXIT_FAILURE);
//        }
//
//        if (listen(serverSocket, MAX_CLIENTS) == -1) {
//            perror("Error listening");
//            close(serverSocket);
//            exit(EXIT_FAILURE);
//        }
//
//        std::cout << "Proxy server is running on port " << port << std::endl;
//    }
//
//    void handleClient(int clientSocket) {
//        char buffer[MAX_BUFFER_SIZE] = {0};
//        ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
//
//        if (bytesRead <= 0) {
//            std::cout << "Client disconnected" << std::endl;
//            close(clientSocket);
//            return;
//        }
//
//        std::string request(buffer);
//
//        auto cacheIt = cacheIndex.find(request);
//        if (cacheIt != cacheIndex.end()) {
//            std::cout << "Cache hit for URL: " << request << std::endl;
//            sendCachedResponse(clientSocket, cacheIt->second);
//        } else {
//            std::cout << "Cache miss for URL: " << request << std::endl;
//            fetchAndCacheResponse(clientSocket, request);
//        }
//
//        close(clientSocket);
//    }
//
//    void sendCachedResponse(int clientSocket, const CacheEntry& cacheEntry) {
//        std::lock_guard<std::mutex> lock(cacheMutex);
//        send(clientSocket, cacheEntry.buffer, cacheEntry.dataSize, 0);
//    }
//
//    void fetchAndCacheResponse(int clientSocket, const std::string& request) {
//
//    }
//};
//
//int main() {
//    Proxy proxy(8000);
//    proxy.run();
//    return 0;

//}
