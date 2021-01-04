echo "Generating Output File"
g++ rms.cpp -o rms.exe
./rms.exe
echo "Displaying RMS Plot"
python3 plot.py output_rms.txt
