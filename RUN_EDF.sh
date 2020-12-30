echo "Generating Output File"
./edf.exe
echo "Displaying EDF Plot"
python3 plot.py output_edf.txt
