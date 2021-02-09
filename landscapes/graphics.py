import numpy as np
import matplotlib.pyplot as plt

x = [0, 8, 27, 64, 125, 216, 343, 512]
y1 = [0, 2.3, 3.3, 5.6, 9.9, 18.1, 33, 57]
y2 = [0, 1.4, 2.2, 4, 6.6, 12.5, 21.8, 38]
y3 = [0, 0.85, 1.2, 2.1, 4, 6.8, 14.6, 22.4]
y4 = [0, 0.5, 0.9, 1.75, 3.2, 6.5, 11.9, 20.6]
y5 = [0, 0.6, 0.84, 1.4, 2.6, 4.4, 9.5, 16]
y6 = [0, 0.63, 0.85, 1.4, 2.4, 4.38, 9.9, 14.393]

x7 = [8, 40, 473, 1258, 2516, 4528]
y7 = [31, 39, 54, 65, 82, 145]

y = np.vstack([y1, y2, y3, y4, y5, y6])

fig, ax = plt.subplots()
ax.set(xlabel='Количество сфер на сцене', ylabel='Время синтеза сцены (секунды)',
       title='Результаты анализа')
ax.grid()


ax.plot(x, y1, label="1 поток", color='blue', linestyle='dashed')
ax.plot(x, y2, label="2 потока", color='green', linestyle='dashdot')
ax.plot(x, y3, label="4 потоков", color='red', linestyle='-')
ax.plot(x, y4, label="8 потоков", color='orange', linestyle='--')
ax.plot(x, y5, label="16 потоков", color='black', linestyle='dotted')
ax.plot(x, y6, label="32 потоков", color='purple', linestyle=':')

#ax.plot(x7, y7, color='green', linestyle='dashed')

ax.legend()
plt.show()


#fig, ax = plt.subplots()
#ax.stackplot(x, y)
#plt.show()