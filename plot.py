import sys
import numpy as np
import matplotlib.pyplot as plt

outfile_name = sys.argv[1]

with open(outfile_name) as f:
	out_f = f.read()
	
data = out_f.split('\n')[1:-2]

time_list = []
exec_list = []
e_times = []
comp_list = []
c_times = []
miss_list = []
m_times = []

for line in data:
	line = line.split(' ')
	
	if int(line[0]) not in time_list:
		time_list.append(int(line[0]))
	
	if line[3] == 'Executes':
		exec_list.append(int(line[2]))
		e_times.append(int(line[0]))
		
	elif line[3] == 'Completes':
		comp_list.append(int(line[2]))
		c_times.append(int(line[0]))
		
	elif line[3] == 'Misses':
		miss_list.append(int(line[2]))
		m_times.append(int(line[0]))
		
#print (time_list, exec_list, e_times, comp_list, c_times, miss_list, m_times)

fig = plt.figure()
ax1 = fig.add_subplot(111)

'''for ind, item in enumerate(exec_list):
	for i in range(e_times[ind], e_times[ind+1], 0.1):
		ax1.scatter(e_times[ind], exec_list[ind], c='b', marker = 's', label = 'Executed')'''
		
		

'''for ind, item in enumerate(exec_list):
		ax1.scatter([x * 0.01 for x in range(e_times[ind], e_times[ind]+1)], exec_list[ind], c='b', marker = 's', label = 'Executed')'''

#ax1.scatter(1, 2, c='b', marker = 's', label = 'Executed')

ax1.grid()

for ind, item in enumerate(exec_list):
	temp_x = np.linspace(e_times[ind]+0.1, e_times[ind]+0.95, 10, endpoint=False)
	temp_y = np.full(len(temp_x), exec_list[ind])
	exec_plot = ax1.scatter(temp_x, temp_y, c='b', marker = 's', s = 100, label = 'Executed')

#adding +1 to complete list
c_times = [x+1 for x in c_times]

#ax1.scatter(e_times, exec_list, c='b', marker = 's', label = 'Executed')
#ax1.barh(e_times, exec_list, label = 'Executed')
comp_plot = ax1.scatter(c_times, comp_list, c='#89ff00', marker = '^', s = 100, label = 'Completed')
miss_plot = ax1.scatter(m_times, miss_list, c='#ff6f00', marker = 'x', s = 100, label = 'Misses')

plt.xticks(range(0,max(time_list)+2))
plt.yticks(range(0,max(exec_list)+2))

ax1.legend((exec_plot, comp_plot, miss_plot), ('Executed', 'Completed', 'Missed'))
plt.xlabel('Time')
plt.ylabel('Task')
plt.title('Scheduling Results')


plt.show()
		


