//#include <iostream>
//
//int main() {
////дроби
//    int N;
//
//    do{
//        scanf("%d",&N);
//    }while(N<=0);
//    int i;
//    float counter=0;
//    for (i=1;i<=N;i++){
//        counter += i/pow(2,i);
//    }
//    printf("%f \n", counter);
////дроби с факториалом
//    double fact(int N)
//    {
//        if(N < 0)
//            return 0;
//        if (N == 0)
//            return 1;
//        else
//            return N * fact(N - 1);
//    }
//
//    int N;
//
//    do{
//        scanf("%d",&N);
//    }while(N<=0);
//    int i;
//    float counter=0;
//    for (i=1;i<=N;i++){
//        counter += i/fact(i);
//        printf("%f \n", counter);
//    }
//
//}

////Задача №1
//#include <stdio.h>
//#include <algorithm>
//
//int main() {
//    int a;
//    int b;
//    int c;
//    scanf("%d%d", &a,&b);
//    c = a;
//    printf("%d %d \n", b, c);
//    std::swap(a,b);
//    printf("%d %d",a,b);
//}

////Задача №2
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    int a;
//    int b;
//    float c;
//    scanf("%d%d", &a,&b);
//    c = sqrt(pow(a,2)+pow(b,2));
//    printf("%f", c);
//}

//Задача №3
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    int a;
//    int b;
//    do{
//        scanf("%d", &a);
//    }while(a<=0);
//
//    b = a%10;
//    printf("%d", b);
//}
//
//Задача №4
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    int a;
//    int b;
//    do{
//        scanf("%d", &a);
//    }while(a<=0);
//
//    b = (a%100-a%10)/10;
//    printf("%d", b);
//}
//
//Задача №5
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    int a;
//    int b;
//    do{
//        scanf("%d", &a);
//    }while(a<=0);
//
//    b = (a-a%10)/10;
//    //b = a/10;
//    printf("%d", b);
//}
//
//Задача №6
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    int a;
//    int b;
//    float c;
//    scanf("%d%d", &a, &b);
//
//    c = (float)(a+b)/2;
//    printf("%f", c);
//}
//
//Задача №7
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    int a;
//    int b;
//    float c;
//    scanf("%d%d", &a, &b);
//
//    c = sqrt(a*b);
//    printf("%f", c);
//}
//
//Задача №8
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    float a;
//    float b;
//    float c;
//    float d;
//    float z;
//    scanf("%f%f%f%f", &a, &b, &c, &d);
//
//    z = sqrt(pow(a-c,2)+pow(b-d,2));
//    printf("%f", z);
//}
//
//Задача №9
//// Online C++ compiler to run C++ program online
//#include <iostream>
//
//int main() {
//    int a, b, c;
//    scanf("%d%d%d", &a,&b,&c);
//    if ((a>b&&a<c)||(a<b&&a>c))
//        printf("Среднее число: %d", a);
//    else if ((b>a&&b<c)||(b<a&&b>c))
//        printf("Среднее число: %d", b);
//    else
//        printf("Среднее число: %d", c);
//}
//
//Задача №10
//#include <iostream>
//#include <math.h>
//
//int main() {
//    int a, b, c;
//    float D, x1, x2;
//    scanf("%d%d%d", &a,&b,&c);
//    D = pow(b,2)-4*a*c;
//    if (D<0){
//        printf("Корней нет");
//    }
//    else if (D==0){
//        x1 = -b/(2*a);
//        printf("Корень один %f", x1);
//    }
//    else {
//        x1 = (-b+sqrt(D))/(2*a);
//        x2 = (-b-sqrt(D))/(2*a);
//        printf("Два корня: x1 = %f, x2 = %f", x1, x2);
//    }
//}
//
//
//Задача №11
//#include <iostream>
//
//int main() {
//    int a, b, c;
//    scanf("%d%d%d", &a,&b,&c);
//    if ((a>b&&a>c))
//        printf("Наибольшее число: %d", a);
//    else if ((b>a&&b>c))
//        printf("Наибольшее число: %d", b);
//    else
//        printf("Наибольшее число: %d", c);
//}
//
//Задание №12
//#include <iostream>
//
//int main() {
//    int a, b, c;
//    scanf("%d%d%d", &a,&b,&c);
//    if (a>(b+c)||b>(a+c)||c>(a+b))
//        printf("Треугольник не существует");
//    else
//        printf("Треугольник существует \n");
//    if (a==b&&a==c&&b==c)
//        printf("Треугольник равносторонний");
//    else if (a==b||a==c||b==c)
//        printf("Треугольник равнобедренный");
//    else
//        printf("Треугольник разносторонний");
//}
//
//Задание №13
//#include <iostream>
//
//int main() {
//    int x, y;
//    scanf("%d%d", &x,&y);
//    if (x>0&&y>0)
//        printf("Первая координатная плоскость");
//    else if (x<0&&y>0)
//        printf("Вторая координатная плоскость");
//    else if (x<0&&y<0)
//        printf("Третья координатная плоскость");
//    else
//        printf("Четвёртая координатная плоскосий");
//}
//
//Задание №14
//#include <iostream>
//
//int main() {
//    int x;
//    int d = 1;
//    scanf("%d", &x);
//    while (x>0){
//        d = d*x;
//        x = x-2;
//    }
//    printf("Ответ: %d", d);
//}
//
//Задание №15
//#include <iostream>
//
//int main() {
//    int x;
//    int d = 1;
//    scanf("%d", &x);
//    int i;
//    for (i=0;i<=x/2-1;i++){
//        d = d*(x-2*i);
//    }
//    printf("Ответ: %d", d);
//}
//
//Задание №16
//#include <iostream>
//
//int main() {
//    int a,b;
//    scanf("%d%d", &a,&b);
//    int i, j;
//    for (i==a;i<=b;i++){
//        for (j=2;j<=9;j++){
//            if ((i!=j)&&(i%j==0))
//                break;
//            printf("Простое число: %d", i);
//        }
//    }
//}
//
//#include <stdbool.h>
//#include <stdio.h>
//
//bool isPrime(int n)
//{
//    if (n == 2 || n == 3)
//        return true;
//    if (n % 2 == 0 || n % 3 == 0)
//        return false;
//
//    for (int i = 5; i * i <= n; i = i + 6)
//        if (n % i == 0 || n % (i + 2) == 0)
//            return false;
//
//    return true;
//}
//
//void primeInRange(int L, int R)
//{
//
//    if (R >= 2 && L <= 2) {
//        printf("2 ");
//        L = 3;
//    }
//    if (L % 2 == 0)
//        L++;
//
//
//    for (int i = L; i <= R; i += 2) {
//
//        if (isPrime(i))
//            printf("%d ", i);
//    }
//}
//
//int main()
//{
//    int L = 1;
//    int R = 15;
//
//    primeInRange(L, R);
//
//    return 0;
//}
//
//Задание №17
//#include <iostream>
//
//int main() {
//    int x;
//    int counter;
//    do{
//        scanf("%d",&x);
//        counter = counter+x;
//        if (x!=-9999)
//            printf("%d ",x);
//    }while(x!=-9999);
//    printf("%d", counter);
//}
//
//Задание №18
//#include <iostream>
//
//int main() {
//    int x;
//    int maxx=0, minn=0;
//    do{
//        scanf("%d",&x);
//        if (x > maxx)
//            maxx = x;
//        else if (x<minn)
//            minn = x;
//        if (x!=0)
//            printf("%d ",x);
//    }while(x!=0);
//    printf("\nМаксимальное число: %d \n", maxx);
//    printf("Минимальное число: %d \n", minn);
//}
//
//Задача №19
//#include <iostream>
//#include <math.h>
//
//int main() {
//    int N;
//    scanf("%d", &N);
//    for (int i=1;i<=N;i++){
//        int x = pow(i,2);
//        printf("%d ", x);
//    }
//}
//
//Задача №20
//#include <iostream>
//using namespace std;
//signed main()
//
//{
//    int n, i = 1;
//    cin >> n;
//    while (i < n)
//        i = i * 22;
//    if (i == n)
//        cout << "Является степенью";
//    else
//        cout << "Не является степенью";
//    return 0;
//}
//
//Задание №21
//#include <iostream>
//
//int main() {
//    int N;
//    scanf("%d", &N);
//    while(N>0){
//        printf("%d", N%10);
//        N = N/10;
//    }
//}
//
//Задание №22
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int a, b;
//    std::vector< int > arr_a;
//    std::vector< int > arr_b;
//    std::vector< int > arr_c;
//    int i,j;
//    scanf("%d%d", &a, &b);
//    for (i=2;i<=a;i++){
//        if (a%i==0){
//            arr_a.push_back(i);
//        }
//    }
//    for (i=2;i<=b;i++){
//        if (b%i==0){
//            arr_b.push_back(i);
//        }
//    }
//    for (i=1; i<=arr_a.size(); i++){
//        for (j=1; j<=arr_b.size(); j++){
//            if(i==j){
//                arr_c.push_back(i);
//            }
//        }
//    }
//    int mul = 1;
//    for (int i=0; i<arr_c.size(); i++) {
//        mul=mul*arr_c[i];
//    }
//    printf("НОД двух чисел: %d\n", mul);
//    for (i=1; i<=arr_a.size(); i++){
//        printf("%d ", arr_a[i]);
//    }
//}
//
//#include <iostream>
//int NOD(int a, int b)
//{
//    while(a > 0 && b > 0)
//
//        if(a > b)
//            a %= b;
//
//        else
//            b %= a;
//
//    return a + b;
//}
//
//int main() {
//    int a,b;
//    scanf("%d%d", &a, &b);
//    printf("%d", NOD(a,b));
//}
//
//Задание №23
//#include <iostream>
//
//int main() {
//    int a;
//    scanf("%d", &a);
//    if (a==1){
//        printf("Плохо");
//    }
//    else if (a==2){
//        printf("Неудовлетворительно");
//    }
//    else if (a==3){
//        printf("Удовлетворительно");
//    }
//    else if (a==4){
//        printf("Хорошо");
//    }
//    else if (a==5){
//        printf("Отлично");
//    }
//}
//
//Задача №24
//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    int x1,y1,z1;
//    scanf("%d%d%d", &x1, &y1, &z1);
//    int x2,y2,z2;
//    scanf("%d%d%d", &x2, &y2, &z2);
//    printf("Длина вектора 1:%f\n", sqrt(pow(x1,2)+pow(y1,2)+pow(z1,2)));
//    printf("Длина вектора 2:%f\n", sqrt(pow(x2,2)+pow(y2,2)+pow(z2,2)));
//    int z = x1*x2+y1*y2+z1*z2;
//    printf("Скалярное произведение: %f\n", z);
//}