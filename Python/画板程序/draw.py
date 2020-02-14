import tkinter as tk

window=tk.Tk()
window.title('画板')
window.geometry('+250+100')
draw=tk.Canvas(window,width=800,height=400)
draw.pack()
def paint(event):
    draw.create_oval(event.x-5,event.y-5,event.x+5,event.y+5,fill='black')
def clear(event,x=tk.ALL):
    return draw.delete(x)
draw.bind('<B1-Motion>',paint)
draw.bind('<Key-space>',clear)
draw.focus_set()
tk.Label(window,text='按住鼠标左键绘图！空格键快捷清空！').pack(side=tk.BOTTOM)
tk.Button(window,text='清空画板',command=lambda x=tk.ALL:draw.delete(x)).pack(side=tk.BOTTOM)
tk.mainloop()
