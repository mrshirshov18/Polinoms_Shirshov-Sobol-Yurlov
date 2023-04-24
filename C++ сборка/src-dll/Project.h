#include <iostream>
#include "Polinom.h"
#include "NoSortedTable1.h"
#include "NoSortedTable2.h"
#include "SortedTable.h"
#include "HashTable1.h"
#include "TreeTable.h"
#include "Postfix.h"

//#define _CRT_SECURE_NO_WARNINGS
#define  MATH_DLL_EXPORTS

#ifdef MATH_STATIC
#define MATHLIBRARY_API
#endif
#ifdef MATH_DLL_EXPORTS
#define MATHLIBRARY_API extern "C" __declspec(dllexport)
#endif
#ifdef MATH_DLL_IMPORT
#define MATHLIBRARY_API extern "C" __declspec(dllimport)
#endif

/// <summary>
///     �������� ������� 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
MATHLIBRARY_API int sum(int, int);

/// <summary>
/// </summary>
/// <param name="pol1"></param>
/// <param name="pol2"></param>
/// <param name="Znak"></param>
/// <returns>
///     ���������� ������ Pol1 <Znak> Pol2
/// </returns>
MATHLIBRARY_API const char* fun_pol1_znak_pol2(char* buff, int buff_size, const char* pol1, const char* pol2, const char* Znak);

/// <summary>
/// </summary>
/// <param name="pol1"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
/// <returns>
///     ���������� �������� �������� � �����
/// </returns>
MATHLIBRARY_API const char* fun_pol_in_point(char* buff, int buff_size, const char* pol1, const char* x, const char* y, const char* z);

/// <summary>
///     �������� ������� �� ���������
/// </summary>
/// <param name="pol1"></param>
/// <param name="constant"></param>
/// <returns></returns>
MATHLIBRARY_API const char* fun_pol_mul_const(char* buff, int buff_size, const char* pol1, const char* constant);

/// <summary>
///     ��������� ������ ������ ��������
/// </summary>
/// <param name="num"></param>
/// <returns>
///     ��� ���������� ������ 1
/// </returns>
extern "C" __declspec(dllexport) const int calcTable(const char* num);


/// <summary>
///     !!!!!
///     ����� ����������� ����� ���������� ������� calcTable(char* num)
///     !!!!
///     /*while (getPolinomeItem(buff)) {
///         cout << buff << endl;
///     }*/
///     ���� true ������� ��������
/// </summary>
/// <param name="buff">
///     i��� ������� ������� ������� � buff
/// </param>
/// <param name="num">
///     ����� ������� � ������� ��������
/// </param>
/// <returns>
///     ���������� true ���� ������� ����
/// </returns>
/// 
MATHLIBRARY_API const bool returnbool();
MATHLIBRARY_API const bool returnbool2(int index);
MATHLIBRARY_API const int retursize();
MATHLIBRARY_API const bool fun_give_table_item1(char* buff, int buff_size, const char* num);
MATHLIBRARY_API const char* fun_give_table_item2(char* buff, int buff_size, const char* num, int iter);
MATHLIBRARY_API const char* fun_give_table(char* buff, int buff_size, const char* num);

/// <summary>
///     ����� �������, ��������� �������� �� ��� �������
/// </summary>
/// <param name="num"></param>
/// <param name="expression"></param>
/// <param name="name"></param>
/// <returns>
///     ���������� ����������� �������
/// </returns>
MATHLIBRARY_API const char* fun_long_expression(char* buff, int buff_size, const char* num, const char* expression, const char* name);

