# rms-edf
Implementation of RMS and EDF scheduling with graphs. 

Use RUN_EDF.sh and RUN_RMS.sh for EDF and RMS respectively. These bash scripts can be run to generate a particular scheduling output and plot the results. 

The output file and plot can also be generated manually using the below methods:

- Both rms.exe and edf.exe use the same input file. The output file for "rms.exe" is "output_rms.txt" and the output file for "edf.exe" is "output_edf.txt". The .exe files can be run be simply clicking on them after compiling.

- The file to plot the graph for output is "plot.py" and it takes one argument, which is the name of the output file, eg. "python3 plot.py output_rms.txt". Please view plots in full screen to see correct time scales with gridlines.

Please see the coursework report for a detailed list of commands.

Requirements:
1. g++ for compiling C files
2. Python 3.5 and above
3. numpy
4. matplotlib
