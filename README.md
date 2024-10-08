Проект: Реализация очереди, стека и дека на C++
Описание
Данный проект представляет реализацию базовых структур данных (очередь, стек, дек) на языке C++. Каждая структура реализована с использованием стандартной библиотеки C++ и предоставляет основные операции, необходимые для работы с данными.

Классы:
Очередь (Queue) — реализует структуру данных "Очередь" (FIFO), используя стандартную библиотеку C++ (std::queue).
Стек (Stack) — реализует структуру данных "Стек" (LIFO), основанную на двух очередях.
Дек (Deque) — реализует структуру данных "Дек" (двусторонняя очередь), используя две очереди.
Основные возможности
Очередь (Queue):

Добавление элемента в очередь (enqueue).
Удаление элемента из очереди (dequeue).
Получение переднего элемента очереди без удаления (front).
Проверка на пустоту очереди (isEmpty).
Стек (Stack):

Добавление элемента на вершину стека (push).
Удаление элемента с вершины стека (pop).
Получение верхнего элемента без удаления (top).
Проверка на пустоту стека (isEmpty).
Дек (Deque):

Добавление элемента в начало дека (addFront).
Добавление элемента в конец дека (addRear).
Удаление элемента с начала дека (removeFront).
Удаление элемента с конца дека (removeRear).
Проверка на пустоту дека (isEmpty).
Структура проекта
main.cpp — основной файл с пользовательским интерфейсом, который предоставляет меню для выполнения операций с очередью, стеком и деком.
Queue.h / Queue.cpp — содержит реализацию класса Queue.
Stack.h / Stack.cpp — содержит реализацию класса Stack, построенного на основе очереди.
Deque.h / Deque.cpp — содержит реализацию класса Deque, построенного на основе двух очередей.
Как использовать
Клонируйте репозиторий:

bash
Копировать код
git clone https://github.com/username/repository-name.git
Скомпилируйте проект:

bash
Копировать код
g++ main.cpp Queue.cpp Stack.cpp Deque.cpp -o containers
Запустите скомпилированное приложение:

bash
Копировать код
./containers
Следуйте инструкциям в консольном меню для выполнения различных операций с очередью, стеком и деком.

Пример работы программы
Очередь: добавьте элемент, удалите элемент или получите передний элемент очереди.
Стек: добавьте элемент на вершину, удалите элемент с вершины или получите верхний элемент.
Дек: добавьте элемент в начало или конец дека, удалите элемент с начала или конца.
Требования
Компилятор C++ (поддержка C++11 или выше).
Операционная система: Windows, Linux, macOS.
