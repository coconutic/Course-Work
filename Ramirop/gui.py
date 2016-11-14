import Tkinter as tk
from main import *

root = tk.Tk()
root.wm_title("Htop")
root.minsize(width = 900, height = 620)
root.maxsize(width = 900, height = 620)
root.resizable(width = False, height = False)

v_uptime = tk.StringVar()
v_task = tk.StringVar()
v_thr = tk.StringVar()

flag_sort_pid = False
flag_sort_name = False
flag_filter = False
flag_search = False

def kill_proc():
    pass

def suspend_proc():
    pass

def resume_proc():
    pass

def terminate_proc():
    pass

def set_nice_proc():
    pass

popup = tk.Menu(root, tearoff=0)
popup.add_command(label = "Kill", command = kill_proc)
popup.add_command(label = "Suspend", command = suspend_proc)
popup.add_command(label = "Resume", command = resume_proc)
popup.add_command(label = "Terminate", command = terminate_proc)
popup.add_separator()
popup.add_command(label="Set nice", command = set_nice_proc)

def view_popup(event):
    print "click!"
    popup.tk_popup(event.x_root, event.y_root, 0)

def set_flag_pid():
    global flag_sort_pid
    flag_sort_pid = True


def set_flag_name():
    global flag_sort_name
    flag_sort_name = True


def set_flag_filter():
    global flag_filter
    flag_filter = True


def set_flag_search():
    global flag_search
    flag_search = True


def build_app():
    btn1 = tk.Button(root, text = "Sort by pid", width = 10, fg = "#6543B5", command = set_flag_pid)
    btn2 = tk.Button(root, text = "Sort by name", width = 10, fg = "#6543B5", command = set_flag_name)
    btn3 = tk.Button(root, text = "Filter", width = 10, fg = "#6543B5", command = set_flag_filter)
    btn4 = tk.Button(root, text = "Search", width = 10, fg = "#6543B5", command = set_flag_search)
    tx = tk.Text(root, font = ('times',12), width = 75, height = 1, wrap = tk.WORD, 
            highlightbackground = "#6543B5")

    scrollbar = tk.Scrollbar(root)
    lb = tk.Listbox(root, font = ('Monaco', 12), width = 117, height = 25, selectbackground = "#FFE692",
            yscrollcommand = scrollbar.set)
    scrollbar.config(command = lb.yview)
    lb.bind("<Button-2>", view_popup)
    table_row = tk.Label(root, font = ('aAssuanNr', 14), fg = "#2341B6", text = "   Pid                                     Name                                           User name              Status     Nice         Memory %              Cpu %")
    uptime_l = tk.Label(root, text = 'Uptime : ', font = ('Monaco', 15), fg = "#07C8F9")
    uptime_value = tk.Label(root, textvariable = v_uptime, font = ('Monaco', 15), fg = "#F9B807")
    tasks_l = tk.Label(root, text = 'Tasks : ', font = ('Monaco', 15), fg = "#07C8F9")
    tasks_value = tk.Label(root, textvariable = v_task, font = ('Monaco', 15), fg = "#F9B807")
    run_threads_l = tk.Label(root, text = 'Run threads : ', font = ('Monaco', 15), fg = "#07C8F9")
    run_threads_value = tk.Label(root, textvariable = v_thr, font = ('Monaco', 15), fg = "#F9B807")

    btn1.place(x = 5, y = 600)
    btn2.place(x = 105, y = 600)
    btn3.place(x = 205, y = 600)
    btn4.place(x = 305, y = 600)

    tx.place(x = 405, y = 597) 
    lb.place(x = 10, y = 140)
    table_row.place(x = 10, y = 110)

    uptime_l.place(x = 10, y = 20)
    uptime_value.place(x = 89, y = 20) 
    tasks_l.place(x = 10, y = 45)
    tasks_value.place(x = 82, y = 45)
    run_threads_l.place(x = 10, y = 70)
    run_threads_value.place(x = 133, y = 70)

    scrollbar.pack(side = tk.RIGHT, fill = tk.Y)    
    return (lb, tx)


def check_flags():
    global flag_sort_pid
    global flag_sort_name
    global flag_filter
    global flag_search

    if flag_sort_pid or flag_sort_name or \
        flag_filter or flag_search:            
            return True
    return False


def update(l):
    lb = l[0]
    tx = l[1]
    view_procs(lb, tx)
    p = Procs()
    p.get_processes()
    index = 0
    while True:
        v_task.set(p.get_num())
        v_uptime.set(get_uptime())
        v_thr.set(get_thread())
        if lb.size() == 0:
            print "heaaar"
            view_procs(lb, tx)
        if check_flags() or index == 1000:
            lb.delete(0, tk.END)
            view_procs(lb, tx)
            index = 0
        root.update()
        index += 1


def view_procs(box, tx):
    global flag_sort_pid
    global flag_sort_name
    global flag_filter
    global flag_search

    pr = Procs()
    procs = pr.get_processes() 

    if flag_sort_pid:
        procs = pr.sort_by_pid()
        flag_sort_pid = False
    if flag_sort_name:
        procs = pr.sort_by_name()
        flag_sort_name = False
    if flag_filter:
        text = tx.get(1.0, tk.END)
        if text != " " and text != "":
            procs = pr.filter(text)
        flag_filter = False
    if flag_search:
        text = tx.get(1.0, tk.END)
        if text != " " and text != "":
            procs = pr.search(text)
        flag_search = False

    for i in xrange(len(procs)):
        box.insert(i, str(procs[i]))
        box.itemconfig(i, foreground = "#6543B5")

root.after(1000, update(build_app()))
root.mainloop()
