import array as ar
import tkinter as tk


def fibonacci_array():
	try:
		array_size = int(temp_array_size.get())
	except:
		entry_size.delete(0, 'end')
		entry_size.insert(0, "Error: array size must be an integer.")
		return

	if array_size < 1:
		entry_size.delete(0, 'end')
		entry_size.insert(0, "Error: array size must be positive.")
		return

	array = ar.fill_fibonacci(array_size)

	for i in range(len(array)):
		array[i] = str(array[i])

	array = ' '.join(array)
	entry_fib_array.delete(0, 'end')
	entry_fib_array.insert(0, array)

def process_array():
	array = temp_array.get().split()
	
	for i in range(len(array)):
		try:
			array[i] = int(array[i])
		except:
			entry_array.delete(0, 'end')
			entry_array.insert(0, "Error: array elements must be integers.")
			return

	new_array = ar.rm_repetitions(array)

	for i in range(len(new_array)):
		new_array[i] = str(new_array[i])

	new_array = ' '.join(new_array)
	entry_new_array.delete(0, 'end')
	entry_new_array.insert(0, new_array)

def clear_entry():
	entry_size.delete(0, 'end')

def clear_result():
	entry_fib_array.delete(0, 'end')

def clear_array():
	entry_array.delete(0, 'end')

def clear_new_array():
	entry_new_array.delete(0, 'end')

def copy_array():
	array = entry_fib_array.get()
	root.clipboard_append(array)
	root.update()

def copy_new_array():
	array = entry_new_array.get()
	root.clipboard_append(array)
	root.update()


root = tk.Tk()
root.title("Laboratory work 12")
root.geometry("550x230+500+400")

temp_array_size = tk.StringVar()
temp_fibonacci_array = tk.StringVar()
temp_array = tk.StringVar()

array_size = tk.IntVar()
 
array_size_label = tk.Label(text="Enter array size:", font='12px')
array_size_label.place(x='10', y='20')
entry_size = tk.Entry(textvariable=temp_array_size, font='12px', width='30')
entry_size.place(x='140', y='20')
enter_button = tk.Button(text="Enter", command=fibonacci_array)
enter_button.place(x='440', y='20')
clear_button = tk.Button(text="Clear", command=clear_entry)
clear_button.place(x='500', y='20')

fibonacci_label = tk.Label(text="Fibonacci array:", font='12px')
fibonacci_label.place(x='10', y='50')
entry_fib_array = tk.Entry(textvariable=temp_fibonacci_array, font='12px', 
	width='30')
entry_fib_array.place(x='140', y='50')
copy_button = tk.Button(text="Copy", command=copy_array)
copy_button.place(x='440', y='50')
clear_button = tk.Button(text="Clear", command=clear_result)
clear_button.place(x='500', y='50')

array_label = tk.Label(text="Enter array:", font='12px')
array_label.place(x='10', y='140')
entry_array = tk.Entry(textvariable=temp_array, font='12px', width='30')
entry_array.place(x='140', y='140')
enter_array_button = tk.Button(text="Enter", command=process_array)
enter_array_button.place(x='440', y='140')
clear_array_button = tk.Button(text="Clear", command=clear_array)
clear_array_button.place(x='500', y='140')

new_array_label = tk.Label(text="New array:", font='12px')
new_array_label.place(x='10', y='170')
entry_new_array = tk.Entry(font='12px', width='30')
entry_new_array.place(x='140', y='170')
copy_array_button = tk.Button(text="Copy", command=copy_new_array)
copy_array_button.place(x='440', y='170')
clear_new_button = tk.Button(text="Clear", command=clear_new_array)
clear_new_button.place(x='500', y='170')
 
root.mainloop()
