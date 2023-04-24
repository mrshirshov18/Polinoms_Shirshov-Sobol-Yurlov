# Polinoms_Shirshov-Sobol-Yurlov
Цель: разработать программную систему для выполнения алгебраических операций над полиномами от трех переменных.

Условия/требования

• Полиномы хранятся в виде списка.
• Полиномы хранятся во всех таблицах одновременно. Ключом является имя.
• Таблиц д.б. 6 видов: линейная на массиве, линейная на списке, упорядоченная на массиве, дерево (АВЛ или красно-черное), две хэш-таблицы.
• Операции над отдельным полиномом: вычисление в точке, умножение на константу, производная*, интеграл*.
• Операции в выражениях из полиномов: сложение, вычитание,умножение на константу, умножение полиномов*, деление полиномов*. Операции должны выполняться, используя постфиксную форму.
• Операции над таблицами: добавление полинома (во все сразу), удаление полинома (во всех сразу), поиск (только в активной таблице, выполняется в процессе вычисления выражений, составленных из имен полиномов).
• Активная (выбранная пользователем) таблица должна выводиться на экран в формате, как минимум, двух столбцов: 1) имя полинома, 2) строковое представление полинома.
Пример

Пусть к настоящему моменту в таблицах хранятся полиномы, указанные ниже.

pol1 = 3.2x2y3z1 – 1.3x1z4

pol2 = –3.2x2y3z1 + 1.3x1z4

const6 = 6.0

q = 4.0x2

Пусть введено следующее выражение: new_pol = 2 * pol1 + 2 * pol2 + 3.6 * q – const6

Требуется:

• Найти в активной таблице все полиномы (сообщить об ошибке при необходимости).
• Сформировать новый полином, вычислив выражение. В данном случае должен получиться полином new_pol = 14.4x2 – 6.0.
• Добавить новый полином во все таблицы.

new_version
