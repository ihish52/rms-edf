import sys
import numpy as np
import matplotlib.pyplot as plt

#get name of output file to plot
outfile_name = sys.argv[1]

#read output file
with open(outfile_name) as f:
	out_f = f.read()

#parse relevant lines into list
data = out_f.split('\n')[1:-3]

#lists to store data to plot
time_list = []
exec_list = []
e_times = []
comp_list = []
c_times = []
miss_list = []
m_times = []

#iterate through data
for line in data:

    #split line by spaces
	line = line.split(' ')
	
    #add timestep to list
	if int(line[0]) not in time_list:
		time_list.append(int(line[0]))
	
    #add executing tasks to list
	if line[3] == 'Executes':
		exec_list.append(int(line[2]))
		e_times.append(int(line[0]))
	
    #add comnpleted tasks to list
	elif line[3] == 'Completes':
		comp_list.append(int(line[2]))
		c_times.append(int(line[0]))
		
    #add missed deadlines to list    
	elif line[3] == 'Misses':
		miss_list.append(int(line[2]))
		m_times.append(int(line[0]))
		
#print (time_list, exec_list, e_times, comp_list, c_times, miss_list, m_times)

#set up figure and subplots
fig = plt.figure()
ax1 = fig.add_subplot(111)

#turn on grid
ax1.grid()

#plot executing tasks
for ind, item in enumerate(exec_list):
    #plot executed tasks as multiple squares until next time step with offset for graphs visibility
	temp_x = np.linspace(e_times[ind]+0.1, e_times[ind]+0.95, 10, endpoint=False)
	temp_y = np.full(len(temp_x), exec_list[ind])
	exec_plot = ax1.scatter(temp_x, temp_y, c='b', marker = 's', s = 100, label = 'Executed')

#adding +1 to complete list
c_times = [x+1 for x in c_times]

#plot completed tasks and missed deadlines
comp_plot = ax1.scatter(c_times, comp_list, c='#89ff00', marker = '^', s = 100, label = 'Completed')
miss_plot = ax1.scatter(m_times, miss_list, c='#ff6f00', marker = 'x', s = 100, label = 'Misses')

#make x & y axes easier to read
plt.xticks(range(0,max(time_list)+2))
plt.yticks(range(0,max(exec_list)+2))

#show legend, x & y axes labels and plot title
ax1.legend((exec_plot, comp_plot, miss_plot), ('Executed', 'Completed', 'Missed'))
plt.xlabel('Time')
plt.ylabel('Task')
plt.title('Scheduling Results')

#show plot
plt.show()
		


