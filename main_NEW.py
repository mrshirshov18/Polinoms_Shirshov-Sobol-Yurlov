import time
import eel
import threading
import ctypes



lib=ctypes.CDLL('./Polinom.dll')


nowisday = time.strftime("%B", time.localtime())

pentrika=10
data_1=0
data_2=0
data_3=0
data_4=0
data_5=0
data_6=0

@eel.expose
def send(num1,num2,plus, knopka1):
        print(f"[{threading.current_thread().name}]-{'mythread'}")
        time.sleep(1)
        global pol1, pol2,Znak
        global knop1
        pol1=str(num1).encode("utf-8")
        pol2=str(num2).encode("utf-8")
        Znak=str(plus).encode("utf-8")
        knop1=knopka1
        '''print(pol1)
        print(pol2)
        print(Znak)
        print(knop1)'''

        def two_polinoms(knop1):
                if knop1 == "on":

                        buff_size = 1024  # задаем размер буфера

                        buff = ctypes.create_string_buffer(buff_size)  # создаем буфер на запись
                        lib.fun_pol1_znak_pol2.restype=ctypes.c_char_p
                        global result
                        result= lib.fun_pol1_znak_pol2(buff, buff_size, pol1, pol2, Znak).decode('utf-8')
                        '''print(result)'''


        two_polinoms(knop1)
        html1 = f'''<!DOCTYPE html>
                <html>
                <head>
                  <meta charset="UTF-8">
                  <script src="eel1.js"></script>
                  <title>Two polinoms</title>
                </head>
                <body>
                        <h1>RESULT: </h1>
                        <textarea disabled type="text" id="message" rows="30" cols="150">{result}</textarea><br>
                </body>
                </html>'''
        def new_window1(knop1):
                if knop1 == "on":
                        with open('html/localfile1.html', 'w') as file:
                                file.write(html1)
                        eel.start("localfile1.html", size=(500, 800), mode='сhrome', port=0)
        new_window1(knop1)

@eel.expose
def send1(num3,cor1,cor2,cor3,per,knopka2):
        global pol, x, y, z, constant
        global knop2
        pol = str(num3).encode("utf-8")
        x=str(cor1).encode("utf-8")
        y=str(cor2).encode("utf-8")
        z=str(cor3).encode("utf-8")
        constant=str(per).encode("utf-8")
        knop2=knopka2
        '''print(pol)
        print(x)
        print(y)
        print(z)
        print(constant)
        print(knop2)'''

        def two_intouch(knop2):
                if knop2 == "on":

                        buff_size1 = 1024  # задаем размер буфера

                        buff1 = ctypes.create_string_buffer(buff_size1)  # создаем буфер на запись
                        lib.fun_pol_in_point.restype = ctypes.c_char_p
                        global result1
                        result1= lib.fun_pol_in_point(buff1, buff_size1, pol, x, y, z).decode('utf-8')
                        '''print(result1)'''


        two_intouch(knop2)
        def mul_const(knop2):
                if knop2 == "on":

                        buff_size2 = 1024  # задаем размер буфера

                        buff2 = ctypes.create_string_buffer(buff_size2)  # создаем буфер на запись
                        lib.fun_pol_mul_const.restype = ctypes.c_char_p
                        global result2
                        result2 = lib.fun_pol_mul_const(buff2, buff_size2, pol, constant).decode('utf-8')
                        '''print(result2)'''


        mul_const(knop2)

        html2 = f'''<!DOCTYPE html>
                       <html>
                       <head>
                         <meta charset="UTF-8">
                         <script src="eel2.js"></script>
                         <title>Operations</title>
                       </head>
                       <body>
                               <h1>REZULT: </h1>
                               <textarea disabled type="text" id="message" rows="30" cols="150">Count in (x,y,z): {result1}
        Miltiplication by a constant: {result2}</textarea><br>
                       </body>
                       </html>'''
        def new_window2(knop2):
                if knop2 == "on":
                        with open('html/localfile2.html', 'w') as file:
                                file.write(html2)
                        eel.start("localfile2.html", size=(500, 800), mode='сhrome', port=0)

        new_window2(knop2)

@eel.expose
def send2(new_pol_js,name_pol_js,tablitsa,knopka3):
        global pol_variety, nameof_pol_variety, one_of_six, knop3
        # new_pol_js = "X+2"
        # name_pol_js = "MY"
        pol_variety = str(new_pol_js).encode("utf-8")
        nameof_pol_variety = str(name_pol_js).encode("utf-8")
        one_of_six = str(tablitsa).encode("utf-8")
        knop3 = knopka3
        '''print(pol_variety)
        print(nameof_pol_variety)
        print(one_of_six)
        print(knop3)'''

        def numberoftable(knop3):
                if knop3 == "on":
                        # Заполняем таблица и возвращаем количество
                        lib.calcTable.restype = ctypes.c_int
                        lib.retursize.restype = ctypes.c_int
                        global item_cnt
                        item_cnt = lib.calcTable(one_of_six)
                        item_cnt = lib.retursize()
                        # Создаем буфер для реузльтата
                        buff_size10 = 1024
                        global buff10  # создаем буфер
                        buff10 = ctypes.create_string_buffer(buff_size10)  # задаем размер буфера
                        lib.fun_give_table_item2.restype = ctypes.c_char_p  # буфер указатель на строку

                        def zapusk(item_cnt):
                                # Перезаписываем файл с items
                                with open('html/localfile4.html', 'w') as file:
                                        file.write("")
                                # Получаем items
                                while (item_cnt > 0):
                                        global stroka
                                        item_cnt = item_cnt - 1  # одновременно и номер item, но выборка будет в обратном порядке
                                        stroka = lib.fun_give_table_item2(buff10, buff_size10, one_of_six,
                                                                          item_cnt).decode('utf-8')
                                        stroka = stroka + "<br>"
                                        # добавляем в выходной файл
                                        with open('html/localfile4.html', 'a') as file:
                                                # file.write(" = ")
                                                file.write(stroka)
                                                file.write("\n")
                                # Отображаем рузультат
                                eel.start("localfile4.html", size=(500, 800), mode='сhrome', port=0)

                        zapusk(item_cnt)

        numberoftable(knop3)


                        











thr1=threading.Thread(target=send,args=(data_1,data_2,data_3,data_4), name="thr-1")
thr1.start()
eel.init("html")
eel.start("window.html", size=(500, 800), port=8000)


'''thr2=threading.Thread(target=new_window,args=(data_5,data_6), name="thr-2")
thr2.start()'''


'''Первая функция - полином 1, полином 2, знак
вторая функция - полином, икс, игрек, зэд, \
третья полином константа
четвертая функция - номер таблицы, 
пятая выражение, название выражения'''
