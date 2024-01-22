#include "mainwindow.h"
#include <QDebug>
#include <QLocale>
#include <QString>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

//Глава 2

    //2.1. Псевдонимы для элементарных типов

    //qint8 — псевдоним для типа signed char:
    //typedef signed char qint8;
    //quint8 и uchar — псевдонимы для типа unsigned char:
    //typedef unsigned char quint8;
    //typedef unsigned char uchar;
    //qint16 — псевдоним для типа short:
    //typedef short qint16;
    //quint16 и ushort — псевдонимы для типа unsigned short:
    //typedef unsigned short quint16;
    //typedef unsigned short ushort;
    //qint32 — псевдоним для типа int:
    //typedef int qint32;
    //quint32 и uint — псевдонимы для типа unsigned int:
    //typedef unsigned int quint32;
    //typedef unsigned int uint;

    //ulong — псевдоним для типа unsigned long:
    //typedef unsigned long ulong;

    //qint64 и qlonglong — псевдонимы для типа long long:
    //typedef long long qint64;
    //typedef qint64 qlonglong;
    //При указании значения после числа необходимо добавить буквы LL или использовать макрос Q_INT64_C():
    {
    qint64 x = 9223372036854775807LL;
    qint64 y = Q_INT64_C(9223372036854775807);
    }

    //quint64 и qulonglong — псевдонимы для типа unsigned long long:
    //typedef unsigned long long quint64;
    //typedef quint64 qulonglong;
    //При указании значения после числа необходимо добавить буквы ULL или использовать макрос Q_UINT64_C():
    {
    quint64 x = 18446744073709551615ULL;
    quint64 y = Q_UINT64_C(18446744073709551615);
    }

    //qreal — вещественное число. Соответствует типу double (в большинстве случаев) или float (при указании дополнительно флага):
    /*
    #if defined(QT_COORD_TYPE)
    typedef QT_COORD_TYPE qreal;
    #else
    typedef double qreal;
    #endif
    */

    //Дополнительные типы:
    //    typedef QIntegerForSizeof<void *>::Unsigned quintptr;
    //    typedef QIntegerForSizeof<void *>::Signed qptrdiff;
    //    typedef qptrdiff qintptr;
    //    using qsizetype = QIntegerForSizeof<std::size_t>::Signed;


    // .2. Класс QChar: символ в кодировке Unicode

    {
    QChar ch1(1082);
    qDebug() << ch1;// '\u043a'
    QChar ch2(L'к');
    qDebug() << ch2;// '\u043a'
    QChar ch3(u'к');
    qDebug() << ch3;// '\u043a'
    QChar ch4;
    qDebug() << ch4;// '\x0'
    }

    qDebug() << "\n########### p49 1 ##########\n";

    { // статическими методами fromLatin1() и fromUcs2().
    QChar ch1 = QChar::fromLatin1('d');
    qDebug() << ch1; // 'd'
    QChar ch2 = QChar::fromUcs2(u'к');
    qDebug() << ch2; // '\u043a'
    }

    qDebug() << "\n########## p49 2 ###########\n";


    { //двумя объектами определены операции ==, !=, <, >, <= и >=:
    QChar ch1(u'd');
    QChar ch2(u'd');
    QChar ch3(u's');
    qDebug() << (ch1 == ch2);   // true
    qDebug() << (ch1 != ch2);   // false
    qDebug() << (ch1  < ch3);   // true
    qDebug() << (ch1  > ch3);   // false
    qDebug() << (ch1  <= ch3);  // true
    qDebug() << (ch1 >= ch3);   // false
    }

    qDebug() << "\n########## p50 1 ###########\n";
    {
    QChar ch1(L'к');
    QChar ch2(L'd');
    // dont worked!!!!!!!
    //    QChar ch1 = L'к';
    //    QChar ch2 = L'd';

    char16_t ch3 = ch1.unicode();
    qDebug() << ch3; // '\u043a'
    qDebug() << (ushort)ch3; // 1082
    qDebug() << ch2.toLatin1(); // d
    }

    qDebug() << "\n########## p50 2 ###########\n";
    {
    QChar ch1(L'К');
    QChar ch2(L'D');
    // dont worked!!!!!!!
    //QChar ch1 = L'К';
    //QChar ch2 = L'D';
    qDebug() << ch1.toLower(); // '\u043a'
    qDebug() << ch2.toLower(); // 'd'
    }

    qDebug() << "\n########## p50 3 ###########\n";
    {
    QChar ch1(L'k');
    QChar ch2(L'd');
    qDebug() << ch1.toUpper(); // '\u041a'
    qDebug() << ch2.toUpper(); // 'D'
    }

    qDebug() << "\n########## p50 4 ###########\n";
    {
    QChar ch1 = 'D';
    QChar ch2 = 'd';
    qDebug() << ch1.isLower(); // false
    qDebug() << ch2.isLower(); // true
    }

    qDebug() << "\n########## p50 5 ###########\n";
    {
    QChar ch1 = 'D';
    QChar ch2 = 'd';
    qDebug() << ch1.isUpper(); // true
    qDebug() << ch2.isUpper(); // false
    }

    qDebug() << "\n########## p51 1 ###########\n";
    {
    QChar ch1 = '1';
    QChar ch2 = 'd';
    qDebug() << ch1.isDigit(); // true
    qDebug() << ch2.isDigit(); // false
    }

    qDebug() << "\n########## p51 2 ###########\n";
    {
    QChar ch1 = '1';
    QChar ch2 = 'd';
    qDebug() << ch1.isNumber(); // true
    qDebug() << ch2.isNumber(); // false
    }

    {
    QChar ch1 = '2';
    QChar ch2 = 'd';
    qDebug() << ch1.digitValue(); // 2
    qDebug() << ch2.digitValue(); // -1
    }

    {
    QChar ch1 = '1';
    QChar ch2 = 'd';
    qDebug() << ch1.isLetter(); // false
    qDebug() << ch2.isLetter(); // true
    }

    qDebug() << "\n########## p52 ###########\n";
    {
    QChar ch1 = 'd';
    QChar ch2 = ' ';
    qDebug() << ch1.isSpace(); // false
    qDebug() << ch2.isSpace(); // true
    }

    {
    QChar ch1 = 'd';
    QChar ch2 = '\r';
    qDebug() << ch1.isLetterOrNumber(); // true
    qDebug() << ch2.isLetterOrNumber(); // false
    }

    {
    QChar ch1 = '.';
    QChar ch2 = ',';
    qDebug() << ch1.isPunct(); // true
    qDebug() << ch2.isPunct(); // true
    }

    {
    QChar ch1 = '8';
    QChar ch2 = '\r';
    qDebug() << ch1.isPrint(); // true
    qDebug() << ch2.isPrint(); // false
    }

    {
    QChar ch1;
    QChar ch2 = 'd';
    qDebug() << ch1.isNull(); // true
    qDebug() << ch2.isNull(); // false
    }


    //    2.3. Класс QString: строка в кодировке Unicode

    qDebug() << "\n########## p53 ###########\n";
    {
    QChar ch = 'd';
    QString str1 = ch;
    qDebug() << str1; // "d"
    QString str2(5, ch);
    qDebug() << str2; // "ddddd"
    }

    {
    QString str = "строка";
    qDebug() << str; // "строка"
    }

    qDebug() << "\n########## p54 ###########\n";
    {
    QString str1 = QString::fromUtf8("строка");
    qDebug() << str1; // "строка"
    std::string s("строка");
    QString str2 = QString::fromStdString(s);
    qDebug() << str2; // "строка"
    std::wstring w(L"строка");
    QString str3 = QString::fromStdWString(w);
    qDebug() << str3; // "строка"
    }

    //    2.3.2. Преобразование объекта в другой тип данных
    qDebug() << "\n########## p55 ###########\n";
    {
    QString str1 = "строка";
    std::string s = str1.toStdString();
    QString str2 = QString::fromStdString(s);
    qDebug() << str2; // "строка"
    std::wstring w = str1.toStdWString();
    qDebug() << w; // "строка"
    }

    //    2.3.3. Получение и изменение размера строки
    {
    QString str("строка");
    qDebug() << str.size();
    qDebug() << str.length();   // 6
    qDebug() << str.count();    // 6
    }

    {
    QString str("строка");
    qDebug() << str.size(); // 6
    qDebug() << str.capacity(); // 12
    str += " строка2 строка3";
    qDebug() << str.size(); // 22
    qDebug() << str.capacity(); // 24
    }

    qDebug() << "\n########## p56 ###########\n";
    {
    QString str("строка");
    str.reserve(50);
    qDebug() << str.size();//6
    qDebug() << str.capacity();// 50
    str += " строка2 строка3";
    qDebug() << str.size();// 22
    qDebug() << str.capacity();// 50
    }

    {
    QString str("строка");
    str.reserve(50);
    qDebug() << str.capacity(); // 50
    str.squeeze();
    qDebug() << str.capacity(); // 6
    }

    qDebug() << "\n########## p57 ###########\n";
    {
    QString str("строка");
    str.resize(4);
    qDebug() << str; // "стро"
    str.resize(8, '*');
    qDebug() << str; // "стро****"
    }

    {
    QString str("строка");
    str.clear();
    qDebug() << str.size(); // 0
    }

    {
    QString str("строка");
    qDebug() << str.isEmpty(); // false
    str.clear();
    qDebug() << str.isEmpty(); // true
    }

    {
    QString str1;
    qDebug() << str1.isNull(); // true
    QString str2("");
    qDebug() << str2.isNull(); // false
    }

    {
    QString str = "ABC";
    str.fill('*');
    qDebug() << str; // "***"
    str.fill('+', 2);
    qDebug() << str; // "++"
    }

    qDebug() << "\n########## p58 ###########\n";
    {
    QString str = "строка";
    QString str2 = str.leftJustified(10, '*');
    qDebug() << str2; // "строка****"
    }

    {
    QString str = "строка";
    QString str2 = str.leftJustified(3, '*');
    qDebug() << str2; // "строка"
    str2 = str.leftJustified(3, '*', true);
    qDebug() << str2; // "стр"
    }

    {
    QString str = "строка";
    QString str2 = str.rightJustified(10, '*');
    qDebug() << str2; // "****строка"
    }

    {
    QString str = "строка";
    QString str2 = str.rightJustified(3, '*');
    qDebug() << str2; // "строка"
    str2 = str.rightJustified(3, '*', true);
    qDebug() << str2; // "стр"
    }

    qDebug() << "\n########## p59 ###########\n";
    // 2.3.4. Доступ к отдельным символам
    {
    //Пример доступа к символу по индексу:
    QString str = "string";
    qDebug() << str[0]; // 's'
    str[0] = QChar('S');
    qDebug() << str; // "String"
    }

    {
    QString str = "string";
    qDebug() << str.at(0); // 's'
    }

    {
    QString str = "String";
    str.front() = 's';
    qDebug() << str.front();
    qDebug() << str;
    // 's'
    // "string"
    }

    {
    QString str = "String";
    str.back() = 'G';
    qDebug() << str.back();// 'G'
    qDebug() << str; // "StrinG"
    }

    // 2.3.5. Перебор символов строки

    {
    QString str = "string";
    for (qsizetype i = 0, len = str.size(); i < len; ++i) {
        qDebug() << str[i]; }
    }

    {
    QString str = "string";
    for (QChar &ch : str) {
        qDebug() << ch; }
    }

    qDebug() << "\n########## p60 - 62 ###########\n";
    // 2.3.6. Итераторы
    // Итератор — это объект, выполняющий в контейнере роль указателя.
    {
    QString str = "String";
    QString::iterator it = str.begin();
    qDebug() << *it; // 'S'
    }

    {
    QString str = "String";
    QString::iterator it = str.end();
    qDebug() << *(--it); // 'g'
    }

    { //
    qDebug() << "\nЛистинг 2.1. Перебор символов в строке с помощью итераторов\n";
    QString str = "String";
    QString::iterator it1, it2;
    QString::reverse_iterator it3, it4;
    it1 = str.begin();
    *it1 = 's'; // Изменение значения
    // Перебор символов в прямом порядке
    for (it1 = str.begin(), it2 = str.end();
    it1 != it2;
    ++it1) {
    qDebug() << *it1; }
    qDebug() << "------------------";
    // Перебор символов в обратном порядке
    for (it3 = str.rbegin(), it4 = str.rend();
    it3 != it4; ++it3) {
    qDebug() << *it3;
    }

    }

    // 2.3.7. Конкатенация строк

    {
    QString str1 = "A", str2 = "B";
    QString str3 = str1 + str2;
    qDebug() << str3; // "AB"
    }

    {
    QString str1 = "A", str2, str3;
    str2 = str1 + "B";
    str3 = "B" + str1;
    qDebug() << str2; // "AB"
    qDebug() << str3; // "BA"
    }

    {
    QString str1 = "A", str2 = "B";
    str1 += "C";
    qDebug() << str1; // "AC"
    str2 += str1;
    qDebug() << str2; // "BAC"
    str2 += QChar(L'D');
    qDebug() << str2; // "BACD"
    }

    // 2.3.8. Добавление и вставка символов
    qDebug() << "\n########## p63 ###########\n";
    {
    QString str = "String";
    str.push_back('1');
    qDebug() << str; // "String1"
    str.push_back(" String2");
    qDebug() << str; // "String1 String2"
    }

    {
    QString str = "String";
    str.append('1');
    qDebug() << str; // "String1"
    str.append(" String2").append(" String3");
    qDebug() << str; // "String1 String2 String3"
    }

    {
    QString str = "A";
    str.insert(0, '*'); // В начало строки
    qDebug() << str; // "*A"
    str.insert(str.size(), "+++"); // В конец строки
    qDebug() << str; // "*A+++"
    }

    qDebug() << "\n########## p64-65 ###########\n";
    {
    QString str = "A";
    str.push_front('*');
    qDebug() << str;        // "*A"
    str.push_front("+++");
    qDebug() << str;        // "+++*A"
    }

    {
    QString str = "ABC";
    qDebug() << str.repeated(3); // "ABCABCABC"
    }

    // 2.3.9. Удаление символов
    {
    QString str("строка");
    str.truncate(4);
    qDebug() << str; // "стро"
    }

    {
    QString str("строка");
    str.clear();
    qDebug() << str.size(); // 0
    }

    {
    QString str = "ABCDE";
    QString::const_iterator last = str.cend();
    QString::const_iterator first = str.cbegin();
    ++first;
    --last;
    QString::iterator it = str.erase(first, last);
    qDebug() << str; // "AE"
    qDebug() << *it; // 'E'
    }

    {
    QString str = "nN123n";
    qsizetype n = erase(str, QChar('n'));
    qDebug() << str; // "N123"
    qDebug() << n; // 2
    }

    {
    QString str = "nN123n";
    qsizetype n = erase_if(str, [](const QChar &ch){
        return (ch == QChar(L'n')) || (ch == QChar(L'N')); });
    qDebug() << str; // "123"
    qDebug() << n; // 3
    }

    {
    QString str = "123456";
    str.remove(0, 3);
    qDebug() << str;    // "456"
    str.remove('6');
    qDebug() << str;    // "45"
    str.remove("5");
    qDebug() << str;    // "4"
    }

    {
    QString str = "nN123";
    str.remove("n", Qt::CaseSensitive);
    qDebug() << str; // "N123"
    str = "nN123";
    str.remove("n", Qt::CaseInsensitive);
    qDebug() << str; // "123"
    }

    {
    QString str = "nN123";
    str.removeIf([](const QChar &ch){
        return (ch == QChar(L'n')) || (ch == QChar(L'N')); });
    qDebug() << str; // "123"
    }

    qDebug() << "\n########## p67 - 68 ###########\n";
    {
    QString str = " str\n\r\v\t\f";
    qDebug() << str.trimmed(); // "str"
    }

    {
    QString str = " str \n\v str\n\r\v\t\f";
    qDebug() << str.simplified(); // "str str"
    }

    {
    QString str = "123456";
    str.chop(3);
    qDebug() << str; // "123"
    }

    {
    QString str = "123456";
    QString str2 = str.chopped(3);
    qDebug() << str2; // "123"
    }

    {
    QString str = "123456";
    QString str2 = str.first(3);
    qDebug() << str2; // "123"
    }

    {
    QString str = "123456";
    QString str2 = str.left(3);
    qDebug() << str2; // "123"
    str2 = str.left(8);
    qDebug() << str2; // "123456"
    }

    {
    QString str = "123456";
    QString str2 = str.last(3);
    qDebug() << str2; // "456"
    }

    {
    QString str = "123456";
    QString str2 = str.right(3);
    qDebug() << str2; // "456"
    str2 = str.right(8);
    qDebug() << str2; // "123456"
    }

    // 2.3.10. Изменение регистра символо
    {
    QString str1 = "СТРОКА";
    QString str2 = str1.toLower();
    qDebug() << str2;           // "строка"
    }

    {
    QString str1 = "строка";
    QString str2 = str1.toUpper();
    qDebug() << str2;           // "СТРОКА"
    }


    qDebug() << "\n########## p69 ###########\n";
    {
    QString str1 = "строка";
    QString str2 = "СТРОКА";
    qDebug() << str1.isLower(); // true
    qDebug() << str2.isLower(); // false
    }

    {
    QString str1 = "строка";
    QString str2 = "СТРОКА";
    qDebug() << str1.isUpper(); // false
    qDebug() << str2.isUpper(); // true
    }

    // 2.3.11. Получение фрагмента строки
    {
    QString str = "строка";
    qDebug() << str.sliced(0, 3);   // "стр"
    qDebug() << str.sliced(3);      // "ока"
    }

    {
    QString str = "строка";
    qDebug() << str.mid(0, 3); // "стр"
    qDebug() << str.mid(3); // "ока"
    }

    {
    QString str = "строка";
    qDebug() << str.mid(10, 3); // ""
    qDebug() << str.mid(3, 8); // "ока"
    }

    qDebug() << "\n########## p70 ###########\n";
    // 2.3.12. Поиск в строке
    {
    QString str = "123454321";
    qDebug() << str.indexOf('2');   // 1
    qDebug() << str.indexOf('6');   // -1
    qDebug() << str.indexOf('2', 3);// 7
    qDebug() << str.indexOf("2");// 1
    qDebug() << str.indexOf("6");// -1
    qDebug() << str.indexOf("2", 3);// 7
    }

    {
    QString str = "строка";
    qDebug() << str.indexOf("т", 0, Qt::CaseSensitive); // 1
    qDebug() << str.indexOf("Т", 0, Qt::CaseSensitive); // -1
    qDebug() << str.indexOf("Т", 0, Qt::CaseInsensitive); // 1
    }

    {
    QString str = "123454321";
    qDebug() << str.contains('2');
    qDebug() << str.contains('6');
    qDebug() << str.contains("2");
    qDebug() << str.contains("6");
    // true // false // true // false
    }

    qDebug() << "\n########## p72 ###########\n";
    {
    QString str = "строка";
    qDebug() << str.startsWith("с");
    qDebug() << str.startsWith("С");
    qDebug() << str.startsWith("стр");
    qDebug() << str.startsWith("Стр");
    // true // false // true // false
    }

    {
    QString str = "строка";
    qDebug() << str.startsWith("с", Qt::CaseSensitive); // true
    qDebug() << str.startsWith("С", Qt::CaseSensitive); // false
    qDebug() << str.startsWith("С", Qt::CaseInsensitive); // true
    }

    qDebug() << "\n########## p72 ###########\n";

    {
    //swap() — меняет содержимое двух строк местами.
    QString str1("12345"), str2("67890");
    str1.swap(str2);
    qDebug() << str1; // "67890" qDebug() << str2; // "12345"
    }

    {
    //replace() — заменяет фрагмент строки отдельным символом или подстрокой. Если вставляемая подстрока меньше фрагмента, то остальные символы сдвига- ются к началу строки, а если больше, то раздвигаются таким образом, чтобы вместить всю вставляемую подстроку. Прототипы метода:
    QString str = "12345";
    str.replace(0, 3, '*');
    qDebug() << str; // "*45"
    str = "12345";
    str.replace(0, 3, "++++");
    qDebug() << str;
    // "++++45"
    str = "12345";
    str.replace('2', '8');
    }

    {
    QString str = "строка";
    qDebug() << str.endsWith("а");
    qDebug() << str.endsWith("А");
    qDebug() << str.endsWith("ока");
    qDebug() << str.endsWith("Ока");
    // true // false // true // false
    }

    qDebug() << "\n########## p73 ###########\n";
    {
    QString str = "строка";
    qDebug() << str.endsWith("а", Qt::CaseSensitive); // true
    qDebug() << str.endsWith("А", Qt::CaseSensitive); // false
    qDebug() << str.endsWith("А", Qt::CaseInsensitive); // true
    }

    {
    QString str = "пример пример";
    qDebug() << str.count("п");
    qDebug() << str.count("т");
    qDebug() << str.count("при");
    qDebug() << str.count("При");
    //2 //0 // 2 // 0
    }

    {
    QString str = "пример пример";
    qDebug() << str.count("П", Qt::CaseSensitive); // 0
    qDebug() << str.count("П", Qt::CaseInsensitive); // 2
    }


    // 2.3.13. Замена в строке
    qDebug() << "\n########## p74 ###########\n";
    {

    QString str = "ABC";
    str.fill('*');
    qDebug() << str;
    str.fill('+', 2);
    qDebug() << str;
    // "***" // "++"
    }

    {
    QString str1("12345"), str2("67890");
    str1.swap(str2);
    qDebug() << str1; // "67890"
    qDebug() << str2; // "12345"
    }

    {
    QString str = "12345";
    str.replace(0, 3, '*');
    qDebug() << str; // "*45"
    str = "12345";
    str.replace(0, 3, "++++");
    qDebug() << str; // "++++45"
    str = "12345";
    str.replace('2', '8');
    qDebug() << str; // "18345"
    str = "12345";
    str.replace("234", "+++");
    qDebug() << str; // "1+++5"
    str = "12 34 532";

    // #include <QRegularExpression>

    str.replace(QRegularExpression("[0-9]+"), "+");
    qDebug() << str; // "+ + +"
    }


    qDebug() << "\n########## p75 ###########\n";
    {
    QString str = "тест";
    str.replace("Е", "о", Qt::CaseSensitive);
    qDebug() << str; // "тест"
    str.replace("Е", "о", Qt::CaseInsensitive);
    qDebug() << str; // "тост"
    }

    {
    QString str = "<b>\"&";
    QString str2 = str.toHtmlEscaped();
    qDebug() << str2; // "&lt;b&gt;&quot;&amp;"
    }


    //2.3.14. Сравнение строк
    {
    QString str1 = "abc", str2 = "abcd";
    if (str1 == str2) {
    qDebug() << "str1 == str2"; }
    else if (str1 < str2) {
    qDebug() << "str1 < str2";
    }
    else if (str1 > str2) {
    qDebug() << "str1 > str2"; }
    // Результат: str1 < str2
    }


//76 Глава 2
// char a[] = "abc", b[] = "abc";
//QString c = "abc";
//qDebug() << (a == b); // Сравниваются адреса!!! qDebug() << (a == c); // OK (равны)
//qDebug() << (c == b); // OK (равны)
//Для сравнения объекта класса QString с другим объектом класса QString можно ис- пользовать метод compare(). В качестве значения метод возвращает:
// отрицательное число — если объект класса QString меньше строки, переданной в качестве параметра;
// 0 — если строки равны;
// положительное число — если объект класса QString больше строки, переданной
//в качестве параметра.
//Прототипы метода:
//int compare(QChar ch, Qt::CaseSensitivity cs = Qt::CaseSensitive) const int compare(const QString &other,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) const int compare(QStringView s,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) const int compare(QLatin1String other,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) const
//Пример:
//QString str1 = "abc", str2 = "abd"; qDebug() << str1.compare("abd"); // -1 qDebug() << str2.compare("abd"); //0 qDebug() << str1.compare("abb"); //1
//Если в параметре cs указана константа Qt::CaseSensitive, то сравнение зависит от регистра символов. Чтобы сравнение не зависело от регистра символов, нужно ука- зать константу Qt::CaseInsensitive:
//QString str1 = "abc", str2 = "ABC";
//qDebug() << str1.compare(str2, Qt::CaseSensitive); // 32 qDebug() << str1.compare(str2, Qt::CaseInsensitive); // 0
//Можно также воспользоваться статическим методом compare(). Прототипы метода:
//static int compare(const QString &s1, const QString &s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)
//static int compare(const QString &s1, QLatin1String s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)
//static int compare(QLatin1String s1, const QString &s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)
//static int compare(const QString &s1, QStringView s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)
//static int compare(QStringView s1, const QString &s2, Qt::CaseSensitivity cs = Qt::CaseSensitive)

//Работа с символами и строками
//77
// Пример:
//QString str1 = "abc", str2 = "abd"; qDebug() << QString::compare(str1, "abd"); qDebug() << QString::compare(str2, "abd"); qDebug() << QString::compare(str1, "abb");
//// -1 // 0 // 1
//Если в параметре cs указана константа Qt::CaseSensitive, то сравнение зависит от регистра символов. Чтобы сравнение не зависело от регистра символов, нужно ука- зать константу Qt::CaseInsensitive:
//QString str1 = "abc", str2 = "ABC";
//qDebug() << QString::compare(str1, str2, Qt::CaseSensitive); // 32 qDebug() << QString::compare(str1, str2, Qt::CaseInsensitive); // 0
//Можно также воспользоваться статическим методом localeAwareCompare(), кото- рый учитывает настройки локали. Прототипы метода:
//static int localeAwareCompare(const QString &s1, const QString &s2) static int localeAwareCompare(QStringView s1, QStringView s2)
//Пример:
//QString str1 = "abc", str2 = "abd";
//qDebug() << QString::localeAwareCompare(str1, "abd"); // -1 qDebug() << QString::localeAwareCompare(str2, "abd"); // 0 qDebug() << QString::localeAwareCompare(str1, "abb"); // 1
//2.3.15. Преобразование строки в число
//Для преобразования строки в число используются следующие методы:
//short toShort(bool *ok = nullptr, int base = 10) const
//ushort toUShort(bool *ok = nullptr, int base = 10) const
//int toInt(bool *ok = nullptr, int base = 10) const
//uint toUInt(bool *ok = nullptr, int base = 10) const
//long toLong(bool *ok = nullptr, int base = 10) const
//ulong toULong(bool *ok = nullptr, int base = 10) const qlonglong toLongLong(bool *ok = nullptr, int base = 10) const qulonglong toULongLong(bool *ok = nullptr, int base = 10) const float toFloat(bool *ok = nullptr) const
//double toDouble(bool *ok = nullptr) const
//Пробельные символы в начале строки игнорируются. Результат выполнения опера- ции доступен через первый параметр (значение true, если операция выполнена успешно). Метод возвращает преобразованное число или значение 0, если преобра- зовать не удалось. Пример преобразования строки в целое число:
//QString str = " \n\r25"; bool ok;
//int n = str.toInt(&ok); qDebug() << n; // 25 qDebug() << ok; // true

//78 Глава 2
// str = "ff";
//n = str.toInt(&ok); qDebug() << n; // 0 qDebug() << ok; // false
//В параметре base можно указать систему счисления или значение 0, при котором система счисления определяется автоматически:
//QString str = " \n\r25"; bool ok;
//int n = str.toInt(&ok, 10); qDebug() << n; // 25 qDebug() << ok; // true
//str = "ff";
//n = str.toInt(&ok, 16); qDebug() << n; // 255 qDebug() << ok; // true
//При преобразовании всегда используется локаль C. Если нужно учитывать настрой- ки произвольной локали, то следует воспользоваться следующими методами из класса QLocale:
//#include <QLocale>
//short toShort(const QString &s, bool *ok = nullptr) const
//short toShort(QStringView s, bool *ok = nullptr) const
//ushort toUShort(const QString &s, bool *ok = nullptr) const
//ushort toUShort(QStringView s, bool *ok = nullptr) const
//int toInt(const QString &s, bool *ok = nullptr) const
//int toInt(QStringView s, bool *ok = nullptr) const
//uint toUInt(const QString &s, bool *ok = nullptr) const
//uint toUInt(QStringView s, bool *ok = nullptr) const
//long toLong(const QString &s, bool *ok = nullptr) const
//long toLong(QStringView s, bool *ok = nullptr) const
//ulong toULong(const QString &s, bool *ok = nullptr) const
//ulong toULong(QStringView s, bool *ok = nullptr) const
//qlonglong toLongLong(const QString &s, bool *ok = nullptr) const qlonglong toLongLong(QStringView s, bool *ok = nullptr) const qulonglong toULongLong(const QString &s, bool *ok = nullptr) const qulonglong toULongLong(QStringView s, bool *ok = nullptr) const float toFloat(const QString &s, bool *ok = nullptr) const
//float toFloat(QStringView s, bool *ok = nullptr) const
//double toDouble(const QString &s, bool *ok = nullptr) const
//double toDouble(QStringView s, bool *ok = nullptr) const
//Пример:
//QString str = "25.56"; bool ok;
//double n qDebug() qDebug()
//= str.toDouble(&ok); << n; // 25.56
//<< ok; // true

//Работа с символами и строками 79
// str = "25,56";
//n = str.toDouble(&ok); qDebug() << n; // 0
//qDebug() << ok; // false QLocale ru(QLocale::Russian); n = ru.toDouble(str, &ok); qDebug() << n; // 25.56 qDebug() << ok; // true
//2.3.16. Преобразование числа в строку
//Преобразовать число в строку позволяют следующие методы:
//QString &setNum(short n, int base = 10)
//QString &setNum(ushort n, int base = 10)
//QString &setNum(int n, int base = 10)
//QString &setNum(uint n, int base = 10)
//QString &setNum(long n, int base = 10)
//QString &setNum(ulong n, int base = 10)
//QString &setNum(qlonglong n, int base = 10)
//QString &setNum(qulonglong n, int base = 10)
//QString &setNum(float n, char format = 'g', int precision = 6) QString &setNum(double n, char format = 'g', int precision = 6)
//А также статические методы:
//static QString number(int n, int base = 10)
//static QString number(uint n, int base = 10)
//static QString number(long n, int base = 10)
//static QString number(ulong n, int base = 10)
//static QString number(qlonglong n, int base = 10)
//static QString number(qulonglong n, int base = 10)
//static QString number(double n, char format = 'g', int precision = 6)
//Пример:
//QString str;
//str.setNum(25);
//qDebug() << str; // "25" str.setNum(25.56);
//qDebug() << str; // "25.56" str = QString::number(25); qDebug() << str; // "25"
//str = QString::number(25.56); qDebug() << str; // "25.56"
//В параметре base можно указать систему счисления:
//QString str; str.setNum(255, 16); qDebug() << str; // "ff"

//80 Глава 2
// str = QString::number(255, 16); qDebug() << str; // "ff"
//При преобразовании всегда используется локаль C. Если нужно учитывать настрой- ки произвольной локали, то следует воспользоваться методом toString() из класса QLocale:
//#include <QLocale>
//QString toString(short i) const
//QString toString(ushort i) const
//QString toString(int i) const
//QString toString(uint i) const
//QString toString(long i) const
//QString toString(ulong i) const
//QString toString(qlonglong i) const
//QString toString(qulonglong i) const
//QString toString(float i, char f = 'g', int prec = 6) const QString toString(double i, char f = 'g', int prec = 6) const
//Пример:
//QLocale ru(QLocale::Russian); QString str = ru.toString(25.56); qDebug() << str; // "25,56"
//2.3.17. Форматирование строки
//Выполнить подстановку значения в строку позволяет метод arg(). Прототипы метода:
//QString QString QString QString QString QString QString QString QString QString
//arg(short a, int fieldWidth = 0, int base = 10, QChar fillChar = QLatin1Char(' ')) const
//arg(ushort a, int fieldWidth = 0, int base = 10, QChar fillChar = QLatin1Char(' ')) const
//arg(int a, int fieldWidth = 0, int base = 10, QChar fillChar = QLatin1Char(' ')) const
//arg(uint a, int fieldWidth = 0, int base = 10, QChar fillChar = QLatin1Char(' ')) const
//arg(long a, int fieldWidth = 0, int base = 10, QChar fillChar = QLatin1Char(' ')) const
//arg(ulong a, int fieldWidth = 0, int base = 10, QChar fillChar = QLatin1Char(' ')) const
//arg(qlonglong a, int fieldWidth = 0, int base = 10, QChar fillChar = QLatin1Char(' ')) const
//arg(qulonglong a, int fieldWidth = 0, int base = 10, QChar fillChar = QLatin1Char(' ')) const
//arg(double a, int fieldWidth = 0, char format = 'g',
//int precision = -1, QChar fillChar = QLatin1Char(' ')) const
//arg(char a, int fieldWidth = 0,
//QChar fillChar = QLatin1Char(' ')) const

//Работа с символами и строками
//81
// QString arg(QChar a, int fieldWidth = 0,
//QChar fillChar = QLatin1Char(' ')) QString arg(const QString &a, int fieldWidth = QChar fillChar = QLatin1Char(' ')) QString arg(QStringView a, int fieldWidth = 0, QChar fillChar = QLatin1Char(' '))
//const 0, const
//const QString arg(QLatin1String a, int fieldWidth = 0,
//QChar fillChar = QLatin1Char(' ')) const QString arg(Args &&... args) const
//Место вставки в строке помечается комбинацией %N, где N — число от 1 до 99:
//QString str = QString("%1").arg(25.56);
//qDebug() << str; // "25.56"
//QString str2 = QString("%1 %2").arg(2).arg("июня"); qDebug() << str2; // "2 июня"
//При преобразовании всегда используется локаль C. Если нужно учитывать настрой- ки произвольной локали, то следует перед цифрой указать букву L:
//// Настройка локали QLocale::setDefault(QLocale(QLocale::Russian)); QString str = QString("%1 %L2").arg(25.56).arg(25.56); qDebug() << str; // "25.56 25,56"
//В параметре fieldWidth можно указать ширину поля. Если число положительное, то выравнивание производится по правой стороне поля, а если отрицательное — по левой стороне поля. Пустое пространство заполняется символом fillChar:
//QString str = QString("%1").arg(25, 7, 10, QChar(L'*')); qDebug() << str; // "*****25"
//QString str2 = QString("%1").arg(25, -7, 10, QChar(L'*')); qDebug() << str2; // "25*****"
//Для форматирования строки можно также воспользоваться следующими статиче- скими методами:
//static QString asprintf(const char *cformat, ...)
//static QString vasprintf(const char *cformat, va_list ap)
//Пример:
//QString str = QString::asprintf("%d %.2f", 2, 2.5); qDebug() << str; // "2 2.50"
//2.3.18. Разделение строки на подстроки по разделителю
//Метод split() разбивает строку по разделителю или шаблону и возвращает список подстрок. Прототипы метода:
//QStringList split(QChar sep,
//Qt::SplitBehavior behavior = Qt::KeepEmptyParts,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) const

//82 Глава 2
// QStringList split(const QString &sep,
//Qt::SplitBehavior behavior = Qt::KeepEmptyParts,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) const QStringList split(const QRegularExpression &re,
//Qt::SplitBehavior behavior = Qt::KeepEmptyParts) const
//Если в параметре behavior указано значение Qt::SkipEmptyParts, то пустые под-
//строки не будут добавляться в список. Пример:
//// #include <QStringList>
//QString str = "12,,34,56";
//QStringList list = str.split(L',', Qt::KeepEmptyParts); qDebug() << list; // QList("12", "", "34", "56") QStringList list2 = str.split(L',', Qt::SkipEmptyParts); qDebug() << list2; // QList("12", "34", "56")
//Если в параметре cs указана константа Qt::CaseSensitive, то сравнение зависит от регистра символов. Чтобы сравнение не зависело от регистра символов, нужно ука- зать константу Qt::CaseInsensitive:
//// #include <QStringList>
//QString str = "12aA34a56";
//QStringList list = str.split("a", Qt::SkipEmptyParts,
//Qt::CaseSensitive); qDebug() << list; // QList("12", "A34", "56")
//QStringList list2 = str.split("a", Qt::SkipEmptyParts, Qt::CaseInsensitive);
//qDebug() << list2; // QList("12", "34", "56")
//В первом параметре можно указать шаблон регулярного выражения:
//// #include <QStringList>
//// #include <QRegularExpression>
//QString str = "word1, word2\nword3\r\nword4.word5"; QStringList list = str.split(QRegularExpression("[\\s,.]+"),
//Qt::SkipEmptyParts);
//// QList("word1", "word2", "word3", "word4", "word5")
//Пример добавления всех букв из строки в список:
//QString str = "word";
//QStringList list = str.split(QString(), Qt::SkipEmptyParts); qDebug() << list; // QList("w", "o", "r", "d")
//Выполнить обратную операцию позволяет метод join() из класса QStringList (см. разд. 2.4.13):
//// #include <QStringList>
//QStringList list = { "A", "B", "C", "D" }; QString str = list.join(L',');
//qDebug() << str; // "A,B,C,D"
//qDebug() << list;

//Работа с символами и строками 83
// Метод section() разделяет строку на подстроки по разделителю и возвращает стро- ку, содержащую подстроки от индекса start до индекса end. Прототипы метода:
//QString section(QChar sep, qsizetype start, qsizetype end = -1, QString::SectionFlags flags = SectionDefault) const
//QString section(const QString &sep, qsizetype start, qsizetype end = -1, QString::SectionFlags flags = SectionDefault) const
//QString section(const QRegularExpression &re, qsizetype start, qsizetype end = -1,
//QString::SectionFlags flags = SectionDefault) const
//Пример:
//QString str = "1,2,3,4,5,6";
//QString str2 = str.section(L',', 2, 2); qDebug() << str2; // "3"
//str2 = str.section(L',', 2, 3); qDebug() << str2; // "3,4"
//str2 = str.section(L',', 2, 4); qDebug() << str2; // "3,4,5"
//2.4. Класс QStringList: список строк
//Класс QStringList описывает список строк (специализация QList<QString>). Под-
//ключение заголовочного файла:
//#include <QStringList>
//2.4.1. Создание объекта
//Класс QStringList содержит следующие конструкторы:
//QStringList(const QString &str) QStringList(const QList<QString> &other) QStringList(QList<QString> &&other)
//Пример:
//QStringList list(QString("A")); qDebug() << list; // QList("A") QStringList list2(list); qDebug() << list2; // QList("A")
//Класс QStringList наследует такие конструкторы из класса QList:
//QList()
//QList(qsizetype size)
//QList(qsizetype size, QList::parameter_type value) QList(std::initializer_list<T> args) QList(InputIterator first, InputIterator last)

//84 Глава 2
// Пример:
//QStringList list;
//list << "A" << "B" << "C";
//qDebug() << list; // QList("A", "B", "C") QStringList list2 = {QString("A"), QString("B")}; qDebug() << list2; // QList("A", "B")
//QStringList list3(list.begin(), list.end()); qDebug() << list3; // QList("A", "B", "C")
//Над двумя объектами определены операции ==, !=, <, <=, > и >=. Пример сравнения двух объектов:
//QStringList list;
//list << "A" << "B" << "C";
//QStringList list2(list.begin(), list.end()); if (list == list2) {
//qDebug() << "list == list2"; }
//Кроме того, один объект можно присвоить другому объекту. В этом случае выпол- няется поэлементное копирование (оператор копирования) или перемещение эле- ментов (оператор перемещения). Пример:
//QStringList list, list2;
//list << "A" << "B" << "C";
//// Создание копии
//list2 = list;
//list2.front() = "D";
//qDebug() << list; // QList("A", "B", "C") qDebug() << list2; // QList("D", "B", "C")
//Доступно также присваивание элементов из списка инициализации:
//QStringList list;
//list = {"A", "B", "C"};
//qDebug() << list; // QList("A", "B", "C")
//2.4.2. Вставка элементов
//Вставить элементы в конец списка можно с помощью оператора <<:
//QStringList list, list2;
//list << "A" << "B";
//list << "C";
//qDebug() << list; // QList("A", "B", "C") list2 << list;
//qDebug() << list2; // QList("A", "B", "C")
//Добавить элементы в конец списка позволяет также оператор +=:
//QStringList list, list2; list += "A";
//list += "B";

//Работа с символами и строками 85
// list2 += "C";
//list += list2;
//qDebug() << list; // QList("A", "B", "C")
//Для объединения двух списков можно воспользоваться оператором +:
//QStringList list, list2, list3; list << "A" << "B";
//list2 << "C" << "D";
//list3 = list + list2;
//qDebug() << list3; // QList("A", "B", "C", "D")
//Вставить элементы позволяют также следующие методы:
// push_front() — добавляет элемент в начало списка. Прототипы метода:
//void push_front(QList::parameter_type value) void push_front(QList::rvalue_ref value)
// push_back() — добавляет элемент в конец списка. Прототипы метода: void push_back(QList::parameter_type value)
//void push_back(QList::rvalue_ref value)
//Пример:
//QStringList list = { "B", "C" }; list.push_front("A"); // В начало list.push_back("D"); // В конец
//qDebug() << list; // QList("A", "B", "C", "D")
// prepend() — добавляет элемент в начало списка. Прототипы метода: void prepend(QList::parameter_type value)
//void prepend(QList::rvalue_ref value)
// append() — добавляет элемент в конец списка. Прототипы метода:
//void append(QList::parameter_type value) void append(QList::rvalue_ref value) void append(const QList<T> &value)
//void append(QList<T> &&value)
//Пример:
//QStringList list = { "B" };
//list.prepend("A");
//list.append("C");
//qDebug() << list;
//QStringList list2 = { "D", "E" }; list.append(list2); // В конец qDebug() << list; // QList("A",
//// В начало // В конец
//// QList("A",
//"B", "C")
//"B", "C", "D", "E")
// insert() — вставляет элемент перед указанной позицией. Прототипы метода:
//QList::iterator insert(qsizetype i, QList::parameter_type value) QList::iterator insert(qsizetype i, qsizetype count,
//QList::parameter_type value)

//86 Глава 2
// QList::iterator insert(qsizetype i, QList::rvalue_ref value) QList::iterator insert(QList::const_iterator before,
//QList::parameter_type value) QList::iterator insert(QList::const_iterator before, qsizetype count, QList::parameter_type value) QList::iterator insert(QList::const_iterator before,
//QList::rvalue_ref value)
//Пример:
//QStringList list = { "B" };
//list.insert(0, "A"); // В начало list.insert(list.size(), "C"); // В конец qDebug() << list; // QList("A", "B", "C") QStringList list2 = { "B" }; list2.insert(list2.cbegin(), "A"); // В начало list2.insert(list2.cend(), "C"); // В конец qDebug() << list2; // QList("A", "B", "C")
// emplace() — вставляет элемент в заданную первым параметром позицию. Значе- ния, указанные через запятую, передаются конструктору объекта. Прототипы метода:
//QList::iterator emplace(qsizetype i, Args &&... args) QList::iterator emplace(QList::const_iterator before,
//Args &&... args)
//Пример:
//QStringList list = { "B" }; list.emplace(0, "A"); // В начало qDebug() << list; // QList("A", "B")
// emplace_back() и emplaceBack() — создают объект, передавая конструктору ука- занные через запятую значения, а затем добавляют объект в конец списка. Про- тотипы методов:
//QList::reference emplace_back(Args &&... args) QList::reference emplaceBack(Args &&... args)
//Пример:
//QStringList list = { "A" }; list.emplace_back("B");
//list.emplaceBack("C");
//qDebug() << list; // QList("A", "B", "C")
// swap() — меняет элементы двух списков местами:
//QStringList list = { "A" }, list2 = { "B" }; list.swap(list2);
//qDebug() << list; // QList("B") qDebug() << list2; // QList("A")

//Работа с символами и строками 87
//  swapItemsAt() — меняет два элемента местами. Прототип метода: void swapItemsAt(qsizetype i, qsizetype j)
//Пример:
//QStringList list = { "A", "B" }; list.swapItemsAt(0, 1);
//qDebug() << list; // QList("B", "A")
//2.4.3. Определение и изменение количества элементов
//Для определения и изменения количества элементов списка предназначены сле- дующие методы:
// size(), length() и count() — возвращают количество элементов списка. Прото- типы методов:
//qsizetype size() const qsizetype length() const qsizetype count() const
//Пример:
//QStringList list = { "A", "B", "C" }; qDebug() << list.size(); // 3 qDebug() << list.length(); // 3 qDebug() << list.count(); // 3
// empty() и isEmpty() — возвращают значение true, если список не содержит эле- ментов, и false — в противном случае. Прототипы методов:
//bool empty() const bool isEmpty() const
//Пример:
//QStringList list;
//qDebug() << list.empty(); // true qDebug() << list.isEmpty(); // true list = { "A", "B", "C" };
//qDebug() << list.empty(); // false qDebug() << list.isEmpty(); // false
// resize() — задает количество элементов, равное числу size. Если указанное количество элементов меньше текущего количества, то лишние элементы будут удалены, в противном случае в конец добавляются пустые строки. Прототип метода:
//void resize(qsizetype size)
//Пример:
//QStringList list = { "A", "B", "C" }; list.resize(2);

//88
//Глава 2
// qDebug() << list; list.resize(4); qDebug() << list;
//// QList("A", "B")
//// QList("A", "B", "", "")
// capacity() — возвращает количество элементов, которое может содержать спи- сок без перераспределения памяти. Прототип метода:
//qsizetype capacity() const
// reserve() — позволяет задать минимальное количество элементов, которое
//может содержать список без перераспределения памяти. Прототип метода:
//void reserve(qsizetype size)
//Пример указания минимального размера списка:
//QStringList list;
//list.reserve(50);
//qDebug() << list.size(); // 0 qDebug() << list.capacity(); // 50
// shrink_to_fit() и squeeze() — уменьшают размер списка до минимального зна- чения. Прототипы методов:
//void shrink_to_fit() void squeeze()
//Пример:
//QStringList list;
//list.reserve(50);
//qDebug() << list.capacity(); // 50 list.squeeze();
//qDebug() << list.capacity(); // 0
//2.4.4. Удаление элементов
//Для удаления элементов предназначены следующие методы:
// pop_front() и removeFirst() — удаляют первый элемент. Прототипы методов:
//void pop_front() void removeFirst()
//Пример:
//QStringList list = { "A", "B", "C" }; list.pop_front();
//qDebug() << list; // QList("B", "C") list.removeFirst();
//qDebug() << list; // QList("C")
// pop_back() и removeLast() — удаляют последний элемент. Прототипы методов:
//void pop_back() void removeLast()

//Работа с символами и строками 89
// Пример:
//QStringList list = list.pop_back(); qDebug() << list; list.removeLast(); qDebug() << list;
//{ "A", "B", "C" };
//// QList("A", "B")
//// QList("A")
// erase() — удаляет один элемент или элементы из диапазона. Прототипы метода:
//QList::iterator erase(QList::const_iterator pos) QList::iterator erase(QList::const_iterator begin,
//QList::const_iterator end)
//Пример:
//QStringList list = { "A", "B", "C", "D" }; list.erase(list.cbegin());
//qDebug() << list; // QList("B", "C", "D") list.erase(list.cbegin(), list.cend()); qDebug() << list; // QList()
//Для удаления элементов можно также воспользоваться функцией erase(). Про- тотип функции:
//qsizetype erase(QList<T> &list, const AT &t)
// erase_if() — удаляет элементы, для которых функция pred возвращает true.
//Прототип функции:
//qsizetype erase_if(QList<T> &list, Predicate pred)
//Пример:
//QStringList list = { "A", "B", "C", "B" }; qsizetype n = erase_if(list, [](const QString &s){
//return s == QString("B"); });
//qDebug() << list; // QList("A", "C") qDebug() << n; // 2
// remove() — удаляет n элементов, начиная с индекса i. Прототип метода: void remove(qsizetype i, qsizetype n = 1)
//Пример:
//QStringList list = list.remove(0, 3); qDebug() << list; list = { "A", "B", list.remove(1); qDebug() << list;
//{ "A", "B", "C", "D" };
//// QList("D") "C", "D" };
//// QList("A", "C", "D")
// removeAt() — удаляет элемент, расположенный по индексу i. Прототип метода: void removeAt(qsizetype i)

//90 Глава 2
// Пример:
//QStringList list = { "A", "B", "C", "D" }; list.removeAt(0);
//qDebug() << list; // QList("B", "C", "D")
// removeOne() — удаляет первый элемент с указанным значением. Прототип ме- тода:
//bool removeOne(const AT &t)
//Пример:
//QStringList list = { "A", "B", "C", "B" };
//qDebug() << list.removeOne("B"); // true
//qDebug() << list; // QList("A", "C", "B")
// removeAll() — удаляет все элементы с указанным значением и возвращает коли- чество удаленных элементов. Прототип метода:
//qsizetype removeAll(const AT &t)
//Пример:
//QStringList list = { "A", "B", "C", "B" };
//qDebug() << list.removeAll("B"); // 2
//qDebug() << list; // QList("A", "C")
// removeIf() — удаляет элементы, для которых функция pred возвращает true. Прототип метода:
//qsizetype removeIf(Predicate pred)
//Пример:
//QStringList list = { "A", "B", "C", "B" }; qsizetype n = list.removeIf([](const QString &s){
//return s == QString("B"); });
//qDebug() << n; // 2
//qDebug() << list; // QList("A", "C")
// takeFirst() — удаляет первый элемент и возвращает его. Прототип метода:
//QList::value_type takeFirst()
//Пример:
//QStringList list = { "A", "B", "C" }; QString s = list.takeFirst(); qDebug() << s; // "A"
//qDebug() << list; // QList("B", "C")
// takeLast() — удаляет последний элемент и возвращает его. Прототип метода: QList::value_type takeLast()

//Работа с символами и строками 91
// Пример:
//QStringList list = { "A", "B", "C" }; QString s = list.takeLast();
//qDebug() << s; // "C"
//qDebug() << list; // QList("A", "B")
// takeAt() — удаляет элемент с указанным индексом и возвращает его. Прототип метода:
//T takeAt(qsizetype i)
//Пример:
//QStringList list = { "A", "B", "C" }; QString s = list.takeAt(1);
//qDebug() << s; // "B"
//qDebug() << list; // QList("A", "C")
// clear() — удаляет все элементы. Прототип метода: void clear()
//Пример:
//QStringList list = { "A", "B", "C" }; list.clear();
//qDebug() << list; // QList()
// removeDuplicates() — удаляет все повторы элементов. Метод возвращает коли- чество удаленных элементов. Прототип метода:
//qsizetype removeDuplicates()
//Пример:
//QStringList list = { "A", "B", "B", "A" }; qsizetype n = list.removeDuplicates(); qDebug() << list; // QList("A", "B") qDebug() << n; // 2
//2.4.5. Доступ к элементам
//Обратиться к элементам списка можно, указав индекс внутри квадратных скобок. Можно как получить значение, так и изменить его:
//QStringList list = { "A", "B", "C" }; qDebug() << list[0]; // "A"
//list[0] = "D";
//qDebug() << list; // QList("D", "B", "C")
//Для доступа к элементам списка предназначены следующие методы:
// front() — возвращает ссылку на первый элемент. Метод позволяет как полу- чить значение, так и изменить его. Прототипы метода:

//92 Глава 2
// QList::reference front() QList::const_reference front() const
// back() — возвращает ссылку на последний элемент. Метод позволяет как полу- чить значение, так и изменить его. Прототипы метода:
//QList::reference back() QList::const_reference back() const
//Пример:
//QStringList list = { "A", list.front() = "D"; list.back() = "E"; qDebug() << list.front(); qDebug() << list.back(); qDebug() << list;
//"B", "C" };
//// "D"
//// "E"
//// QList("D", "B", "E")
// at() — возвращает константную ссылку на элемент, расположенный по указан- ному индексу. Прототип метода:
//QList::const_reference at(qsizetype i) const
//Пример:
//QStringList list = { "A", "B", "C" }; qDebug() << list.at(0); // "A"
// first() — возвращает ссылку на первый элемент. Метод позволяет как полу- чить значение, так и изменить его. Прототипы метода:
//T &first()
//const T &first() const
// last() — возвращает ссылку на последний элемент. Метод позволяет как полу- чить значение, так и изменить его. Прототипы метода:
//T &last()
//const T &last() const
//Пример:
//QStringList list = { "A", list.first() = "D"; list.last() = "E"; qDebug() << list.first(); qDebug() << list.last(); qDebug() << list;
//"B", "C" };
//// "D"
//// "E"
//// QList("D", "B", "E")
// value() — возвращает значение элемента, расположенного по указанному ин- дексу, или значение defaultValue, если такого индекса нет. Прототипы метода:
//T value(qsizetype i) const
//T value(qsizetype i, QList::parameter_type defaultValue) const

//Работа с символами и строками 93
// Пример:
//QStringList list = { "A", "B", "C" }; qDebug() << list.value(0); // "A" qDebug() << list.value(1); // "B"
//Можно также воспользоваться следующими методами:
//QList::pointer data() QList::const_pointer data() const QList::const_pointer constData() const const T &constFirst() const
//const T &constLast() const
//2.4.6. Итераторы
//Итератор — это объект, выполняющий в контейнере роль указателя. С помощью итератора можно перемещаться внутри контейнера и получать доступ к отдельным элементам. В классе QList определены следующие типы итераторов:
// iterator — итератор. При увеличении значения итератор перемещается к концу списка. Пример объявления переменной:
//QStringList::iterator it;
// const_iterator — константный итератор. Изменить значение, на которое ссыла-
//ется итератор, нельзя. Пример объявления переменной:
//QStringList::const_iterator it;
// reverse_iterator — обратный итератор. При увеличении значения итератор
//перемещается к началу списка. Пример объявления переменной:
//QStringList::reverse_iterator it;
// const_reverse_iterator — константный обратный итератор. Изменить значение,
//на которое ссылается итератор, нельзя. Пример объявления переменной:
//QStringList::const_reverse_iterator it;
//Присвоить значения переменным позволяют следующие методы:
// begin() — возвращает итератор, установленный на первый элемент. Прототипы метода:
//QList::iterator begin() QList::const_iterator begin() const
//Выведем первый элемент:
//QStringList list = { "A", "B", "C" }; QStringList::iterator it = list.begin(); qDebug() << *it; // "A"
// end() — возвращает итератор, установленный на позицию после последнего элемента. Прототипы метода:

//94 Глава 2
// QList::iterator end() QList::const_iterator end() const
//Выведем последний символ строки:
//QStringList list = { "A", "B", "C" }; QStringList::iterator it = list.end(); qDebug() << *(--it); // "C"
// cbegin() и constBegin() — возвращают константный итератор, установленный на первый символ строки. Прототипы методов:
//QList::const_iterator cbegin() const
//QList::const_iterator constBegin() const
// cend() и constEnd() — возвращают константный итератор, установленный на позицию после последнего символа строки. Прототипы методов:
//QList::const_iterator cend() const QList::const_iterator constEnd() const
// rbegin() — возвращает обратный итератор, установленный на последний эле- мент. Прототипы метода:
//QList::reverse_iterator rbegin() QList::const_reverse_iterator rbegin() const
//Выведем последний элемент:
//QStringList list = { "A", "B", "C" }; QStringList::reverse_iterator it = list.rbegin(); qDebug() << *it; // "C"
// rend() — возвращает обратный итератор, установленный на позицию перед первым элементом. Прототипы метода:
//QList::reverse_iterator rend() QList::const_reverse_iterator rend() const
//Выведем первый элемент:
//QStringList list = { "A", "B", "C" }; QStringList::reverse_iterator it = list.rend(); qDebug() << *(--it); // "A"
// crbegin() — возвращает константный обратный итератор, установленный на последний элемент. Прототип метода:
//QList::const_reverse_iterator crbegin() const
// crend() — возвращает константный обратный итератор, установленный на по-
//зицию перед первым элементом. Прототип метода:
//QList::const_reverse_iterator crend() const
//С итераторами можно производить такие же операции, как и с указателями. Чтобы получить или изменить значение, на которое ссылается итератор, перед названием

//Работа с символами и строками 95
// переменной указывается оператор * (*it). Перемещение итератора осуществляется с помощью операторов +, -, ++ и --. Кроме того, итераторы можно сравнивать с по- мощью операторов сравнения.
//2.4.7. Перебор элементов
//Перебрать все элементы можно с помощью циклов for, for each и итераторов. Пример использования цикла for each:
//QStringList list = { "A", "B", "C" }; for (QString &el : list) {
//qDebug() << el; }
//Пример перебора элементов с помощью итераторов и цикла for:
//QStringList list = { "A", "B", "C" }; QStringList::iterator it1, it2; QStringList::reverse_iterator it3, it4; // Перебор в прямом порядке
//for (it1 = list.begin(), it2 = list.end(); it1 != it2; ++it1) { qDebug() << *it1;
//}
//qDebug() << "------------------";
//// Перебор в обратном порядке
//for (it3 = list.rbegin(), it4 = list.rend(); it3 != it4; ++it3) {
//qDebug() << *it3; }
//2.4.8. Сортировка списка
//Для сортировки списка предназначен метод sort(). Прототип метода: void sort(Qt::CaseSensitivity cs = Qt::CaseSensitive)
//Если в параметре cs указана константа Qt::CaseSensitive, то сравнение зависит от регистра символов. Чтобы сравнение не зависело от регистра символов, нужно ука- зать константу Qt::CaseInsensitive:
//QStringList list = { "C", "A", "B" }; list.sort(Qt::CaseSensitive);
//qDebug() << list; // QList("A", "B", "C")
//2.4.9. Получение фрагмента списка
//Получить фрагмент списка позволяют следующие методы:
// sliced() — возвращает фрагмент длиной n, начиная с индекса pos. Если второй параметр не задан, то возвращаются все элементы до конца списка. Прототипы метода:

//96
//Глава 2
// QList<T> QList<T>
//Пример:
//QStringList list = { "A", "B", "C", "D" }; QStringList list2 = list.sliced(1); qDebug() << list2; // QList("B", "C", "D") list2 = list.sliced(1, 2);
//qDebug() << list2; // QList("B", "C")
// mid() — возвращает фрагмент длиной length, начиная с индекса pos. Если вто- рой параметр не задан, то возвращаются все элементы до конца списка. Прото- тип метода:
//QList<T> mid(qsizetype pos, qsizetype length = -1) const
//Пример:
//QStringList list = { "A", "B", "C", "D" }; QStringList list2 = list.mid(1);
//qDebug() << list2; // QList("B", "C", "D") list2 = list.mid(1, 2);
//qDebug() << list2; // QList("B", "C")
// first() — возвращает список с первыми элементами в количестве n. Прототип
//метода:
//QList<T> first(qsizetype n) const
//Пример:
//QStringList list = { "A", "B", "C", "D" }; QStringList list2 = list.first(2); qDebug() << list2; // QList("A", "B")
// last() — возвращает список с последними элементами в количестве n. Прото- тип метода:
//QList<T> last(qsizetype n) const
//Пример:
//QStringList list = { "A", "B", "C", "D" }; QStringList list2 = list.last(2);
//qDebug() << list2; // QList("C", "D")
//2.4.10. Поиск элементов
//Выполнить поиск элемента внутри списка позволяют следующие методы:
// indexOf() — производит поиск элемента с начала списка или с индекса from до конца списка. Возвращает индекс первого совпадения, если элемент найден, или значение –1 — в противном случае. Прототипы метода:
//sliced(qsizetype pos) const sliced(qsizetype pos, qsizetype n) const

//Работа с символами и строками 97
// qsizetype indexOf(const AT &value, qsizetype from = 0) const qsizetype indexOf(const QRegularExpression &re,
//qsizetype from = 0) const
//Пример:
//QStringList list = { "A", "B", "C", "B" }; qDebug() << list.indexOf("B"); // 1 qDebug() << list.indexOf("D"); // -1 qDebug() << list.indexOf("B", 2); // 3
// lastIndexOf() — производит поиск элемента с конца списка или с индекса from до начала списка. Возвращает индекс первого совпадения, если элемент найден, или значение –1 — в противном случае. Прототипы метода:
//qsizetype lastIndexOf(const AT &value, qsizetype from = -1) const qsizetype lastIndexOf(const QRegularExpression &re,
//qsizetype from = -1) const
//Пример:
//QStringList list = { "A", "B", "C", "B" }; qDebug() << list.lastIndexOf("B"); // 3 qDebug() << list.lastIndexOf("D"); // -1 qDebug() << list.lastIndexOf("B", 2); // 1
// contains() — проверяет, содержит ли список указанный элемент. Если содер- жит, то возвращается значение true, в противном случае — false. Прототипы метода:
//bool contains(const QString &str, Qt::CaseSensitivity
//bool contains(QLatin1String str, Qt::CaseSensitivity
//bool contains(QStringView str, Qt::CaseSensitivity
//cs = Qt::CaseSensitive) const
//cs = Qt::CaseSensitive) const
//cs = Qt::CaseSensitive) const
//Если в параметре cs указана константа Qt::CaseSensitive, то сравнение зависит от регистра символов. Чтобы сравнение не зависело от регистра символов, нуж- но указать константу Qt::CaseInsensitive:
//QStringList list = { "A", "B", "C" };
//qDebug() << list.contains("B");
//qDebug() << list.contains("D");
//qDebug() << list.contains("b");
//qDebug() << list.contains("b", Qt::CaseInsensitive); // true
// startsWith() — проверяет, начинается ли список с указанного элемента. Если начинается, то возвращается значение true, в противном случае — false. Прото- тип метода:
//bool startsWith(QList::parameter_type value) const
//// true // false // false

//98
//Глава 2
// Пример:
//QStringList list = { "A", "B", "C" }; qDebug() << list.startsWith("A"); qDebug() << list.startsWith("B");
//// true // false
//endsWith() — проверяет, заканчивается ли список указанным элементом. Если заканчивается, то возвращается значение true, в противном случае — false. Прототип метода:
//bool endsWith(QList::parameter_type value) const
//Пример:
//QStringList list = { "A", "B", "C" }; qDebug() << list.endsWith("C"); // true qDebug() << list.endsWith("B"); // false
//count() — возвращает число вхождений элемента в список. Если элемент в спи- ске отсутствует, то возвращается значение 0. Прототип метода:
//qsizetype count(const AT &value) const
//Пример:
//QStringList list = { "A", "B", "C", "B" }; qDebug() << list.count("B"); // 2 qDebug() << list.count("D"); // 0
//2.4.11. Замена элементов
//Произвести замену в списке позволяют следующие методы:
// fill() — заменяет все элементы указанным элементом. Во втором параметре можно передать новый размер списка. Прототип метода:
//QList<T> &fill(QList::parameter_type value, qsizetype size = -1)
//Пример:
//QStringList list = { "A", "B", "C" };
//qDebug() << list.fill("*"); // QList("*", "*", "*") qDebug() << list.fill("+", 2); // QList("+", "+")
// move() — перемещает элемент. Прототип метода: void move(qsizetype from, qsizetype to)
//Пример:
//QStringList list = { "A", "B", "C" }; list.move(1, 2);
//qDebug() << list; // QList("A", "C", "B")
// replace() — заменяет элемент. Прототипы метода:
//void replace(qsizetype i, QList::parameter_type value) void replace(qsizetype i, QList::rvalue_ref value)
//
//

//Работа с символами и строками 99
// Пример:
//QStringList list = { "A", "B", "C" }; list.replace(1, "D");
//qDebug() << list; // QList("A", "D", "C")
// replaceInStrings() — заменяет фрагмент before фрагментом after во всех эле- ментах списка. Прототипы метода:
//QStringList &replaceInStrings(const QString &before, const QString &after,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) QStringList &replaceInStrings(QStringView before,
//QStringView after,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) QStringList &replaceInStrings(const QString &before,
//QStringView after,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) QStringList &replaceInStrings(QStringView before,
//const QString &after,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) QStringList &replaceInStrings(const QRegularExpression &re,
//const QString &after)
//Заменим все числа символом + с помощью регулярного выражения:
//// #include <QRegularExpression>
//QStringList list = { "A12", "B23", "C45" }; list.replaceInStrings(QRegularExpression("[0-9]+"), "+"); qDebug() << list; // QList("A+", "B+", "C+")
//Если в параметре cs указана константа Qt::CaseSensitive, то поиск зависит от регистра символов. Чтобы поиск не зависел от регистра символов, нужно ука- зать константу Qt::CaseInsensitive:
//QStringList list = { "A1", "a2", "B3" }; list.replaceInStrings("a", "+");
//qDebug() << list; // QList("A1", "+2", "B3") list.replaceInStrings("a", "+", Qt::CaseInsensitive); qDebug() << list; // QList("+1", "+2", "B3")
//2.4.12. Фильтрация списка
//Метод filter() возвращает список строк, содержащих подстроку str. Прототипы метода:
//QStringList filter(const QString &str,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) const
//QStringList filter(QStringView str,
//Qt::CaseSensitivity cs = Qt::CaseSensitive) const
//QStringList filter(const QRegularExpression &re) const

//100 Глава 2
// Пример получения элементов, содержащих числа:
//// #include <QRegularExpression>
//QStringList list = { "A12", "B23", "C", "D" };
//QStringList list2 = list.filter(QRegularExpression("[0-9]+")); qDebug() << list2; // QList("A12", "B23")
//Если в параметре cs указана константа Qt::CaseSensitive, то поиск зависит от реги- стра символов. Чтобы поиск не зависел от регистра символов, нужно указать кон- станту Qt::CaseInsensitive:
//QStringList list = { "A", "a", "C", "D" }; QStringList list2 = list.filter("a");
//qDebug() << list2; // QList("a")
//list2 = list.filter("a", Qt::CaseInsensitive); qDebug() << list2; // QList("A", "a")
//2.4.13. Преобразование списка в строку
//Преобразовать список в строку позволяет метод join(). Элементы добавляются через указанный разделитель. Прототипы метода:
//QString join(QChar separator) const
//QString join(const QString &separator) const QString join(QStringView separator) const QString join(QLatin1String separator) const
//Пример:
//QStringList list = { "A", "B", "C", "D" }; QString str = list.join(L',');
//qDebug() << str; // "A,B,C,D"
//str = list.join("+");
//qDebug() << str; // "A+B+C+D"
//Выполнить обратную операцию позволяет метод split() из класса QString
//(см. разд. 2.3.18):
//QString str = "A,B,C,D";
//QStringList list = str.split(",");
//qDebug() << list; // QList("A", "B", "C", "D")











   //#########
    {
    // Настройка локали
    QLocale::setDefault(QLocale(QLocale::Russian));
    QString str = QString("%1 %L2").arg(25.56).arg(25.56);
    qDebug() << str; // "25.56 25,56"
    }

    {
    QLocale egyptian(QLocale::Arabic, QLocale::Egypt);
    QString s1 = egyptian.toString(1.571429E+07, 'e');
    QString s2 = egyptian.toString(10);

    double d = egyptian.toDouble(s1);
    int i = egyptian.toInt(s2);

    qDebug() << s1 << " " << s2 << " " << d;
    }

    {
    QString str = "String";
    QString::iterator it1, it2;
    QString::reverse_iterator it3, it4;
    it1 = str.begin();
    *it1 = 's'; // Изменение значения
    // Перебор символов в прямом порядке
    for (it1 = str.begin(), it2 = str.end();
         it1 != it2; ++it1)
    {
        qDebug() << *it1;
    }
    qDebug() << "------------------";
    // Перебор символов в обратном порядке
    for (it3 = str.rbegin(), it4 = str.rend();
         it3 != it4; ++it3) {
        qDebug() << *it3;
    }
    }

    {
    QString str1 = "A", str2 = "B";
        QString str3 = str1 + str2;
    qDebug() << str3; // "AB"
    // объект класса QString с C-строкой в кодировке UTF-8:
    }

    {
    QString str1 = "A", str2, str3;
    str2 = str1 + "B";
    str3 = "B" + str1;
    qDebug() << str2; // "AB"
    qDebug() << str3; // "BA"
    //Помимо оператора + доступен оператор +=, который производит конкатенацию с присваиванием:
    }

    {
    QString str1 = "A", str2 = "B"; str1 += "C";
    qDebug() << str1; // "AC"
    str2 += str1;
    qDebug() << str2; // "BAC"
    str2 += QChar(L'D');
    qDebug() << str2; // "BACD"
    }

    {
    QString str = "String";
    str.push_back('1');
    qDebug() << str; // "String1"
    str.push_back(" String2");
    qDebug() << str; // "String1 String2"
    }

    {
    QString str = "String"; //wchar_t
    str.append('1');
    qDebug() << str; // "String1"
    str.append(" String2").append(" String3");
    qDebug() << str; // "String1 String2 String3"
    }

    {
    QString str = "A";
    str.insert(0, '*'); // В начало строки
    qDebug() << str; // "*A"
    str.insert(str.size(), "+++"); // В конец строки
    qDebug() << str; // "*A+++"
    }
}

MainWindow::~MainWindow()
{
}


