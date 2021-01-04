echo "Generating Output File"
g++ edf.cpp -o edf.exe
./edf.exe
echo "Displaying EDF Plot"
python3 plot.py output_edf.txt
