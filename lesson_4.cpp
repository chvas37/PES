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
