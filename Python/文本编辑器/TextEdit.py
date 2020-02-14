import tkinter as tk
import tkinter.messagebox as mb

'''主窗口'''
window=tk.Tk()
window.title('文本编辑器')
window.geometry('800x600+250+60')

'''菜单条'''
MenuBar = tk.Menu(window)
'''置为顶层菜单'''
window.config(menu=MenuBar)
'''添加子菜单'''
menu_file = tk.Menu(MenuBar)
MenuBar.add_cascade(label='文件',menu=menu_file)
menu_edit = tk.Menu(MenuBar)
MenuBar.add_cascade(label='编辑',menu=menu_edit)
'''选项事件'''
def open_file():
    try:
        with open(file='info.txt',mode='r') as f:
            lines = f.readline()
            while True:
                line = f.readline()
                if not line:
                    break
                lines += line
            text.delete(1.0,'end')
            text.insert(1.0,lines)
    except:
        with open(file='info.txt',mode='w') as f:
            pass
def save_file():
    with open(file='info.txt',mode='w') as f:
        lines = text.get(1.0,'end')
        f.write(lines)
def ToExit():
    choice = mb.askquestion('提示','是否退出？')
    if choice == 'yes':
        window.destroy()
    else:
        pass
def ToFind():
    find_bar = tk.Toplevel(window)
    find_bar.title('查找')
    find_bar.geometry('400x100+450+250')
    tk.Label(find_bar,text='查找内容：').place(relx=0.1,rely=0.3)
    str1 = tk.StringVar()
    find_text = tk.Entry(find_bar,textvariable=str1)
    find_text.place(relx=0.3,rely=0.3)
    find_text.focus_set()
    find_text.bind('<Return>',lambda event,x=str1 : x.set(text.search(x.get(),1.0,stopindex='end')))
    find_button = tk.Button(find_bar,text='查找',command=lambda x=str1 : x.set(text.search(x.get(),1.0,stopindex='end')))
    find_button.place(relx=0.75,rely=0.3)
def ToUndo():
    try:
        text.edit_undo()
    except:
        pass
def clear_text():
    choice = mb.askquestion('提示','是否清空内容？')
    if choice == 'yes':
        text.delete(1.0,'end')
    else:
        pass
'''子菜单添加选项'''
menu_file.add_command(label='打开',command=open_file)
menu_file.add_command(label='保存',command=save_file)
menu_file.add_command(label='退出',command=ToExit)
menu_edit.add_command(label='查找',command=ToFind)
menu_edit.add_command(label='撤销',command=ToUndo)
menu_edit.add_command(label='清空',command=clear_text)

'''Text组件'''
text = tk.Text(window,width=800,height=600,undo=True)
text.pack()
text.focus_set()

window.mainloop()
