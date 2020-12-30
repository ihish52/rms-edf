echo "Generating Output File"
./rms.exe
echo "Displaying RMS Plot"
python3 plot.py output_rms.txt
