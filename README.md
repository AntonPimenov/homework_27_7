ЗАДАЧА: 
В качестве итогового домашнего задания необходимо реализовать концепцию чата с использованием контейнеров стандартной библиотеки шаблонов.
Добавьте в ваш проект чата логгирование сообщений от других участников чата и своих сообщений.

Для этого напишите класс Logger, через который будет проходить вся работа с файлом логов. Сохраняйте сообщения в файл на диске, можете назвать его log.txt. При создании объекта логгера должно производиться открытие файла, а при его разрушении — закрытие файла (концепт RAII).


Преимущества использования std::map:

    Быстрый поиск пользователей и сообщений.

    Удобство работы с данными.

    Чистый и понятный код.


    Использование std::map:

        map<string, User> для хранения пользователей. Ключ — логин, значение — объект User.

        map<string, vector<Message>> для хранения сообщений. Ключ — логин получателя, значение — вектор сообщений.

    Упрощение поиска:

        Поиск пользователя по логину выполняется за O(log n) с помощью users.find(login).

        Поиск сообщений для конкретного пользователя также выполняется за O(log n).

    Улучшенная структура данных:

        Сообщения хранятся в виде вектора для каждого пользователя, что упрощает доступ к ним.

        Что добавлено:

    Класс Logger:

        Открывает файл log.txt при создании объекта и закрывает его при разрушении (RAII).

        Метод log() для потокобезопасной записи строки в файл.

        Метод readLine() для потокобезопасного чтения строки из файла.

    Логгирование в классе Chat:

        Логгируются события: регистрация, вход, отправка сообщений, выход.

        Логи записываются в файл log.txt.

    Потокобезопасность:

        Используется std::mutex для синхронизации доступа к файлу.

        Преимущества:

    Потокобезопасность: Использование мьютексов гарантирует корректную работу в многопоточной среде.

    Инкапсуляция: Класс Logger скрывает детали реализации многопоточности.

    Логгирование: Все важные события записываются в файл для последующего анализа.