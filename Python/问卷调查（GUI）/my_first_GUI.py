'''
Created on 2020年2月13日
@author: ZhaoGuiFu
'''

import tkinter as tk
import tkinter.messagebox as mb

'''主窗口'''
Window = tk.Tk()
'''主窗口标题'''
Window.title('登录')
'''主窗口大小及位置'''
Window.geometry('250x200+500+200')

tk.Label(Window,text='用户名：',height=4).grid(row=0,column=0)
tk.Label(Window,text='密 码：',height=4).grid(row=1,column=0)
str1 = tk.StringVar()
str2 = tk.StringVar()
'''从文件读取用户名与密码'''
try:
    with open(file='user_psw.txt',mode='r') as f:
        str1.set(f.readline())
        str2.set(f.readline())
except:
    pass
'''创建Entry对象'''
e1 = tk.Entry(Window,textvariable=str1)
e2 = tk.Entry(Window,textvariable=str2,show='*')
'''以grid布局显示'''
e1.grid(row=0,column=1)
e2.grid(row=1,column=1)
e1.focus_set()
'''e1回车事件'''
def e1_e2_Return(event):
    if str1.get().strip() != '' and str2.get().strip() != '':
        login()
    elif str1.get().strip() != '' and str2.get().strip() == '':
        e2.focus_set()
    elif str1.get().strip() == '':
        e1.focus_set()
'''事件绑定'''
e1.bind('<Return>',e1_e2_Return)
e2.bind('<Return>',e1_e2_Return)

'''登录事件'''
def login():
    if str1.get().strip() == str2.get().strip():
        '''保存用户名与密码'''
        with open(file='user_psw.txt',mode='w') as f:
            f.write(str1.get())
            f.write('\n'+str2.get())
        '''销毁登录窗口'''
        Window.destroy()
        '''创建顶层窗口'''
        top = tk.Tk()
        top.title('问卷调查')
        top.geometry('800x400+200+100')
        
        '''创建Menu'''
        MenuBar = tk.Menu(top)
        '''设置为顶级菜单'''
        top.config(menu=MenuBar)
        '''创建子菜单'''
        MenuFile = tk.Menu(MenuBar)
        MenuBar.add_cascade(label='文件',menu=MenuFile)
        MenuEdit = tk.Menu(MenuBar)
        MenuBar.add_cascade(label='编辑',menu=MenuEdit)
        '''向子菜单添加选项'''
        def ToExit():
            choice = mb.askquestion('提示', '是否退出？')
            if choice == 'yes':
                top.destroy()
            else:
                pass
        def ToSave():
            with open(file='info.txt',mode='w') as f:
                f.write(str(v1.get()))
        MenuFile.add_command(label='退出',command=ToExit)
        MenuEdit.add_command(label='保存',command=ToSave)
        
        '''创建LabelFrame对象'''
        group1 = tk.LabelFrame(top,text='你最喜欢哪门编程语言？（单选）',padx=10,pady=10)
        '''以pack()布局显示该对象'''
        group1.grid(row=0,column=0,padx=10,pady=10)
        '''选项列表'''
        Langs=[('PYTHON',1),('JAVA',2),('C++',3),('C',4)]
        '''整数对象，表示选中的num'''
        v1 = tk.IntVar()
        '''从文件读取内容'''
        try:
            with open(file='info.txt',mode='r') as f:
                v1.set(f.readline())
        except:
            with open(file='info.txt',mode='w') as f:
                pass
        '''循环向group1添加内容'''
        for lang,num in Langs:
            '''创建Radiobutton'''
            bt = tk.Radiobutton(group1,text=lang,variable=v1,value=num)
            '''以pack()布局显示'''
            bt.pack(anchor=tk.W)

        '''创建LabelFrame对象'''
        group2 = tk.LabelFrame(top,text='你学过下列哪些编程语言？（多选）',padx=10,pady=10)
        '''以pack()布局显示该对象'''
        group2.grid(row=0,column=1,padx=10,pady=10)
        '''循环向group2添加内容'''
        for lang,num in Langs:
            '''创建Checkbutton'''
            bt = tk.Checkbutton(group2,text=lang,variable=tk.IntVar())
            '''以pack()布局显示'''
            bt.pack(anchor=tk.W)
        
        '''创建LabelFrame对象'''
        group3 = tk.LabelFrame(top,text='你学的第一门编程语言？',padx=10,pady=10)
        '''以pack()布局显示该对象'''
        group3.grid(row=0,column=2,padx=10,pady=10)
        '''创建OptionMenu'''
        options = ['PYTHON','JAVA','C++','C']
        sv = tk.StringVar()
        sv.set(options[0])
        om = tk.OptionMenu(group3,sv,*options).pack()
        
        top.mainloop()
    else:
        str2.set('')
'''登录按钮'''
tk.Button(Window,text='登录',width=8,command=login).grid(row=2,column=1)

Window.mainloop()
